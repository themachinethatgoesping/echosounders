# Teledyne RESON s7k (7k) Data Format — Research & Reference

> Reference notes for implementing the `.s7k` (7k) reader in
> `themachinethatgoesping/echosounders`. Keep this document up to date as records are
> implemented. Every non-obvious fact should cite a source so errors can be traced back.

## 1. Primary source (authoritative)

- **7k Data Format Definition, v3.12 (April 2020)** — the official Teledyne RESON specification.
  - Local copy: [DATA_FORMAT_DEFINITION_7k_Data_Format.pdf](./DATA_FORMAT_DEFINITION_7k_Data_Format.pdf)
    (281 pages) and extracted text [s7k_spec.txt](./s7k_spec.txt).
  - Downloaded from: https://github.com/TileDB-Inc/7k/blob/master/DATA%20FORMAT%20DEFINITION%20-%20%207k%20Data%20Format.pdf
  - Section references below (e.g. "spec §5") point at this PDF / `s7k_spec.txt` line numbers.

## 2. Open-source implementations reviewed (cite these when in doubt)

| Project | Lang | Location / URL | Notes |
|---|---|---|---|
| **MB-System** | C | workspace: `/home/ssd/src/MB-System/src/mbio/` — `mbsys_reson7k.h/.c`, `mbsys_reson7k3.h`, `mbr_reson7kr.c`, `mbr_reson7k3.c` | Best C reference for exact struct byte layouts (`s7k_header`, `s7k_time`, per-record structs). Reson format ids 88/89. |
| **CoFFee** | MATLAB | workspace: `/home/ssd/src/themachinethatgoesping/CoFFee/read_data_files/Reson/` — `CFF_s7K_record_types.m`, `CFF_read_s7k.m`, `CFF_s7k_file_info.m`, `CFF_read_s7k_from_fileinfo.m`, `CFF_convert_S7Kdata_to_fData.m` | Record-type name table (spec v3.12); sync/parsing logic; backscatter & water-column conversion formulas. |
| **Kluster** | Python | https://github.com/noaa-ocs-hydrography/kluster | Does **not** read s7k directly — delegates to the **`prr3`** driver (Reson Record Reader v3) in HSTB-drivers https://github.com/noaa-ocs-hydrography/drivers . Supports Reson 7125, T20, T51. Limited record subset. |
| **pyread7k** | Python | https://pypi.org/project/pyread7k/ (official Teledyne-Marine; GitHub source currently unavailable/private) | Record parsers + DataRecordFrame utilities. |

## 3. File structure (spec §7)

- A `.s7k` file is a sequence of complete 7k records **without** network frames.
- Recommended: first record is a **7200 File Header**, usually followed by **7001 Configuration**,
  and the **last** record is a **7300 File Catalog**.
- Records are logged in receive order (ping records are chronological; other data may not be).
- Each record = **DRF (Data Record Frame)** + **RTH (Record Type Header)** + optional **RD (Record
  Data)** + optional **OD (Optional Data)** + **Checksum (u32)**. (spec §4)
- Byte order: **little-endian** throughout.

## 4. Data Record Frame (DRF) — the datagram header (spec §5, Table 5) ✅ implemented

Fixed **64-byte** header. `Offset` field = 60 (bytes from the sync pattern to the RTH). Data
section starts at byte 64. Cross-checked against MB-System `s7k_header` and `s7k_time`.

| Offset | Field | Type | Notes |
|---|---|---|---|
| 0  | Protocol Version | u16 | == 5 |
| 2  | Offset | u16 | == 60 (sync → RTH) |
| 4  | Sync Pattern | u32 | **0x0000FFFF** |
| 8  | Size | u32 | total record size: version field → end of checksum (incl. embedded data) |
| 12 | Optional Data Offset | u32 | 0 = none |
| 16 | Optional Data Identifier | u32 | |
| 20 | 7KTIME | u8×10 | see below |
| 30 | Record Version | u16 | currently 1 |
| 32 | **Record Type Identifier** | u32 | the datagram identifier (see Table below) |
| 36 | Device Identifier | u32 | which device produced the record (see §8) |
| 40 | Reserved | u16 | |
| 42 | System Enumerator | u16 | distinguishes devices with the same id (dual-head, dual-freq) |
| 44 | Reserved | u32 | |
| 48 | Flags | u16 | bit 0: checksum valid; bit 15: recorded (vs live) data |
| 50 | Reserved | u16 | |
| 52 | Reserved | u32 | |
| 56 | Total records in fragmented set | u32 | 0 in files |
| 60 | Fragment number | u32 | 0 in files |
| 64 | DATA SECTION … then Checksum (u32) | | checksum is the last 4 bytes of every record |

**7KTIME** (spec §3, Table 3; MB-System `s7k_time`), 10 bytes at offset 20:

| Off | Field | Type | Range |
|---|---|---|---|
| 20 | Year | u16 | e.g. 2023 |
| 22 | Day | u16 | day of year, 1–366 |
| 24 | Seconds | f32 | 0.0–60.0 |
| 28 | Hours | u8 | 0–23 |
| 29 | Minutes | u8 | 0–59 |

Timestamp → unix time: `year_month_day_to_unixtime(year, 1, 1) + (day-1)*86400 + hours*3600 +
minutes*60 + seconds`. All-zero 7KTIME means "no time available" → NaN.

## 5. Record-type table (spec §Table 8, `s7k_spec.txt` lines ~1263–1407) ✅ enum implemented

Implemented in `s7k/types.hpp` as `t_S7KDatagramIdentifier` (values = the record numbers).
OCR note: the spec text renders footnote markers glued to numbers (e.g. "70001"=7000, "70181"=7018).

Generic sensor records (1000–1999): 1000 Reference point, 1001 Sensor offset position,
1002 …calibrated, 1003 Position, 1004 Custom attitude, 1005 Tide, 1006 Altitude,
1007 Motion over ground, 1008 Depth, 1009 Sound velocity profile, 1010 CTD, 1011 Geodesy,
1012 Roll pitch heave, 1013 Heading, 1014 Survey line, 1015 Navigation, 1016 Attitude,
1017 Pan tilt, 1020 Sonar installation identifiers. Also 2004 Sonar pipe environment,
3001 Contact output.

SeaBat 7k records (7000–7999): 7000 Sonar settings, 7001 Configuration, 7002 Match filter,
7003 Firmware/hardware config, 7004 Beam geometry, 7006 Bathymetric data (**deprecated**, use
7027), 7007 Side-scan, 7008 Generic water column (**deprecated**, use 7018/7028), 7009 Vertical
depth, 7010 TVG values, 7011 Image data, 7012 Ping motion, 7014 Adaptive gate, 7017 Detection
setup, **7018 Beamformed data** (WC magnitude+phase), 7021 BITE, 7022 Sonar source version,
7023 8k wet-end version, 7026 Detection, **7027 Raw detection data** (bathymetry, preferred),
**7028 Snippet data** (WC), 7029 Vernier processing (filtered), 7030 Sonar installation
parameters, 7031 BITE summary, 7041 Compressed beamformed intensity, **7042 Compressed water
column data**, 7047 Segmented raw detection, 7048 Calibrated beam data, 7050 System events,
7051 System event message, 7052 RDR recording status, 7053 Subscriptions, 7055 Normalization
status, 7057 Calibrated side-scan, 7058 Snippet backscattering strength, 7059 MB2 status,
7200 File header, 7300 File catalog, 7400 Time message, 7500–7504 Remote control family,
7510 SV filtering, 7511 System lock status, 7515 Timestamp, 7610 Sound velocity,
7611 Absorption loss, 7612 Spreading loss, 7613 Profile avg salinity, 7614 Profile avg
temperature, 7777 Filler record. Plus 8100 8k-series sonar data.

**Observed in the test files** (`/home/data/test_data/thomas_s7k/`, Norbit-style survey):
1003, 1012, 1013, 7000, 7027, 7028, 7042, 7200.

### Priority records for MBES processing (roadmap)
1. **7000 Sonar Settings** — per-ping tx/rx params (frequency, power, gain, pulse, sample rate).
2. **7004 Beam Geometry** — per-beam angles & beamwidths.
3. **7027 Raw Detection Data** — bathymetry (detection point/sample, rx angle, quality per beam).
4. **7018 Beamformed / 7028 Snippet / 7042 Compressed WC** — water-column amplitude (+phase).
5. **1003 Position, 1012 Roll/Pitch/Heave, 1013 Heading, 1015/1016 Nav/Attitude** — navigation.
6. **7030 Installation Parameters, 1000 Reference Point** — geometry/offsets.

## 6. Coordinate reference system (spec §9)

- **Sonar reference frame (MBES):** X = across-ship (→ starboard), Y = along-ship (→ forward),
  Z = vertical (→ **up**). Reference point = centre of receiver face (X,Z) and centre of
  projector (Y). Tx offset = projector reference relative to receiver reference. (spec §9.1.1)
- **Beam order:** beam 0 = first beam on the **port** side (§9.1.2). Reversed-head systems are
  re-ordered in post-processing.
- **Position (1003):** latitude/longitude in **radians** (f64), datum from record **1011 Geodesy**
  (WGS84 by default). Height in metres.
- **Attitude (1012/1016):** roll/pitch/heave in radians/metres; heading (1013) in radians.
- ⚠️ Sign/handedness conventions differ from Kongsberg (Z-up here). Verify against MB-System
  `mbsys_reson7k` when implementing geometry.

## 7. Backscatter & water-column conversion (source: CoFFee `CFF_convert_S7Kdata_to_fData.m`)

- **Backscatter from 7027 intensity (uint16):** `BS_dB = 20·log10(raw / 65535)`.
  ⚠️ CoFFee notes the "Power Selection" unit in s7k is ambiguous (doc says dB re 1 µPa, but
  typical values look like watts → `10·log10`). Verify per dataset.
- **Water-column amplitude (7018/7028, uint16):** `amp_dB = 20·log10(raw / 65535)`.
  7058 is already calibrated (dB). 
- **Water-column phase (7018/7028, int16):** `phase_rad = raw / 10430` (≈ ±π).
- **7042 Compressed WC:** flags decode the amplitude/phase packing — see CoFFee
  `CFF_get_R7042_flags.m` (and spec §10 for 7042).
- **TVG (7010):** sample-based gain curve; not pre-applied to snippet data.

## 8. Multi-vendor: Norbit, R2Sonic, BlueView, SBES (device_identifier @ DRF offset 36)

The 7k format is **device-agnostic** — the same DRF + record types are reused, and the
**Device Identifier** field (and Appendix B in the spec) identifies the source hardware. Therefore
"reading Norbit / R2Sonic converted to s7k" = reading the same records, just with different device
ids and possibly different subsets/optional-data.

- **Norbit** (WBMS series) logs `.s7k` directly (the test files here are Norbit ultfarms surveys).
- **R2Sonic** can output 7k-compatible records.
- **BlueView** (forward-looking / SBES imaging, a Teledyne brand) uses the 7k container — the spec
  even defines a "BlueView Data Record Frame" (spec TOC, `s7k_spec.txt` line 369). SBES channel
  settings appear in the 10000+ range.
- Practical implication: implement records generically (keyed by record type). Keep device-specific
  quirks (optional-data presence, field meanings) behind the Device Identifier / System Enumerator.

## 9. Implementation status in `themachinethatgoesping/echosounders`

- ✅ **Step 1 (done):** DRF header read/parse/display + datagram indexing + raw iteration + Python
  bindings + tests. See skill `echosounders-format-step1`. Files under
  `src/themachinethatgoesping/echosounders/s7k/`.
- ⏳ Next: per-record parsers (7000 → 7004 → 7027 → nav records → water column), then
  `PingDataInterface` / ping objects (mirror `kongsbergall`/`kmall`).

## 10. Sources index (for error tracing)

- DRF byte layout: spec §5 Table 5 + MB-System `mbsys_reson7k.h::s7k_header`.
- 7KTIME: spec §3 Table 3 + MB-System `s7k_time`.
- Record-type names: spec §Table 8 (`s7k_spec.txt` ~1263–1407) + CoFFee `CFF_s7K_record_types.m`.
- Sync/parse recovery (back up 1 byte on sync loss): CoFFee `CFF_s7k_file_info.m`.
- Backscatter/WC conversion: CoFFee `CFF_convert_S7Kdata_to_fData.m`, `CFF_get_R7042_flags.m`.
- Coordinate system: spec §9.
