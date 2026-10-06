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
  bindings + tests. See skill `tmtgp-echosounders-format-step1`.
- ✅ **Step 2 (in progress):** typed per-record datagram classes with per-type containers and
  `datagram_interface.datagrams(t_id.Rxxxx)` typed access. See skill `tmtgp-echosounders-format-step2`.
  Files under `src/.../echosounders/s7k/datagrams/`. Fixed-RTH records were generated from a compact
  spec; per-beam/water-column records were hand-written with xtensor arrays.

  **Implemented (16 records, all validated on the Norbit test files where present):**
  - Generic/nav: 1000 ReferencePoint, 1003 Position, 1012 RollPitchHeave, 1013 Heading,
    1015 Navigation, 1016 Attitude.
  - Sonar/bathy: 7000 SonarSettings, 7002 MatchFilter, 7004 BeamGeometry, 7027 RawDetection,
    7610 SoundVelocity (incl. optional temperature/pressure), 7611 AbsorptionLoss, 7612 SpreadingLoss.
  - Water column: 7028 Snippet, 7042 CompressedWaterColumn.
  - File: 7200 FileHeader.
  - Struct packing / alignment, the Windows SIMD constraint and reserved-field completeness: see §12.

  **Remaining in-use records to add (layouts in §11 below; add via the step-2 pattern):**
  1009 SoundVelocityProfile, 7010 TVG, 7012 PingMotion, 7018 Beamformed (full water column),
  7022 SonarSourceVersion, 7030 InstallationParameters, 7058 SnippetBackscatteringStrength,
  7300 FileCatalog, 7503 RemoteControlSonarSettings, 7001 Configuration.

- ⏳ **Step 3 (later):** `PingDataInterface` / ping objects merging settings + detection + navigation +
  water column with calibration (mirror `kongsbergall`/`kmall`).

### Validation notes (Norbit test files, `/home/data/test_data/thomas_s7k/`)
- System: 400 kHz Norbit, exported by "BeamworX NavAQ 2023.1.1.0", device id 13003, off the Belgian
  coast (lat ≈ 51.24°N, lon ≈ 2.93°E). SonarSettings sound velocity ≈ 1501 m/s.
- 7027 `data_field_size` = **26** bytes/beam here (not the 34-byte MB-System struct) → the per-beam
  read MUST use the on-disk `data_field_size` as the stride.
- 7042 flags = 0x182 (magnitude-only, downsampled), 16-bit magnitude, effective sample rate ≈ 9766 Hz.

## 10. Sources index (for error tracing)

- DRF byte layout: spec §5 Table 5 + MB-System `mbsys_reson7k.h::s7k_header`.
- 7KTIME: spec §3 Table 3 + MB-System `s7k_time`.
- Record-type names: spec §Table 8 (`s7k_spec.txt` ~1263–1407) + CoFFee `CFF_s7K_record_types.m`.
- Per-record byte layouts: MB-System `mbsys_reson7k3.h` (struct `s7k3_<Record>`) cross-checked with the
  spec §10 record tables (e.g. 7028 Tables 75/76, 7042 Tables 83/84 in `s7k_spec.txt`).
- Sync/parse recovery (back up 1 byte on sync loss): CoFFee `CFF_s7k_file_info.m`.
- Backscatter/WC conversion: CoFFee `CFF_convert_S7Kdata_to_fData.m`, `CFF_get_R7042_flags.m`.
- Coordinate system: spec §9.

## 11. Byte layouts of the remaining records (from MB-System `mbsys_reson7k3.h` + spec)

All records start after the 64-byte DRF; multibyte fields are little-endian; RTH structs are packed.
`nalloc` fields in the MB-System structs are in-memory only — NOT on disk.

- **1009 SoundVelocityProfile** — RTH: position_flag u8, reserved u8*3, latitude f64, longitude f64,
  n u32 (samples). RD: n × { depth f32, sound_velocity f32 }.
- **7010 TVG** — RTH (50): serial u64, ping u32, multi_ping u16, n u32, reserved u32*8. RD: tvg[n] f32.
- **7012 PingMotion** — RTH (28): serial u64, ping u32, multi_ping u16, n u32, flags u16,
  error_flags u32. RD: frequency f32, pitch f32, then (per `flags` bits) roll[n] f32, heading[n] f32,
  heave[n] f32.
- **7018 Beamformed (full water column)** — RTH (52): serial u64, ping u32, multi_ping u16,
  number_beams u16, number_samples u32, reserved u32*8. RD per beam: amplitude[S] u16 & phase[S] i16
  **interleaved per sample** ([amp0][phase0][amp1][phase1]…), S = number_samples; phase_rad = i16/10430.
- **7022 SonarSourceVersion** — RTH: version string char[32] (null-terminated).
- **7030 InstallationParameters** — RTH (616, fixed): frequency f32; then 4×(len u16 + string char[128])
  for firmware/software/7k/protocol versions; then tx/rx/motion offsets (x,y,z f32 + roll,pitch,heading
  f32 each), motion_time_delay u16, position offsets (x,y,z f32), position_time_delay u16, waterline_z f32.
- **7058 SnippetBackscatteringStrength** — RTH (49): serial u64, ping u32, multi_ping u16,
  number_beams u16, error_flag u8, control_flags u32, absorption f32, reserved u32*6. RD per beam:
  beam_number u16, begin_sample u32, bottom_sample u32, end_sample u32, then bs[N] f32 (N = end−begin+1),
  and (if control_flags bit 6) footprints[N] f32. BS = 10·log10(σ) dB.
- **7300 FileCatalog** — RTH (14): size u32, version u16, n u32, reserved u32. RD: n × { sequence i32,
  time_d f64, pingrecord i32, size u32, offset u64, record_type u16, device_id u16, system_enumerator
  u16, 7KTIME(10), record_count u32, reserved u16*8 }.
- **7503 RemoteControlSonarSettings** — RTH (~260): the 7000 SonarSettings fields plus extended
  fields (Vernier, additional offsets, beam mode, depth gate tilt). Parse the leading 7000-equivalent
  fields; treat the tail defensively by record size.
- **7001 Configuration** — RTH: serial u64, number_devices u32(or u64). RD: per device a variable block
  { magic u32, description char[60], serial u64, info_length u32, info char[info_length] }. Parse the
  header and the per-device metadata; store the info blob raw.


## 12. Struct packing, alignment & the Windows SIMD constraint

The RTH/record structs are read/written as one contiguous block, so `sizeof(Content)` and every
field offset must exactly match the on-disk bytes. The 7k format is **byte-packed** (no padding
between fields), but the implementation packs **fine-grained — only where the natural C++ layout
would differ from the on-disk layout**, and pins every struct with a
`static_assert(sizeof(X) == <on-disk bytes>)` so a regression is caught at compile time on every
platform.

- **No `#pragma pack` needed** (natural layout already == on-disk): records whose fields are all
  4-byte (f32/u32) — **7611 AbsorptionLoss (8), 7612 SpreadingLoss (8), 1000 ReferencePoint (20),
  1012 RollPitchHeave (16), 1013 Heading (8)** and (minimal) **7610 SoundVelocity**. The 64-byte DRF
  header is likewise naturally aligned by design (every reserved field present) and is never packed.
- **`#pragma pack(push,1)` required** (natural layout would insert padding): 7004 BeamGeometry (12),
  7042 CompressedWaterColumn (44), 7200 FileHeader (316), 7002 MatchFilter (92), 1015 Navigation
  (45), 1003 Position (41), 7027 RawDetection (99), 7028 SnippetData (46), 7000 SonarSettings (160),
  and the AoS rows 1016 AttitudeSample (18), 7200 FileHeaderDeviceInfo (6), 7027 RawDetectionBeam
  (34), 7028 SnippetDataBeam (14).

### Windows / MSVC-STL SIMD on `bind_vector` rows
clang-cl & MSVC route `std::find/count/remove` (emitted by `nb::bind_vector` for the per-row vectors'
`__contains__`/`count`/`remove`) through a vectorized path that only supports element sizes 1/2/4/8
bytes and `static_assert`-fails for any other size — but **only** for "trivially equality comparable"
types (all-integer, no padding, *defaulted* `operator==`). Two packed all-integer rows hit this:
**FileHeaderDeviceInfo (6 B)** and **SnippetDataBeam (14 B)**. Fix: give just those two rows a
*user-provided* `operator==` (memberwise, not `= default`), which flips
`__is_trivially_equality_comparable` to false → scalar path. This keeps the exact 6/14-byte on-disk
layout and does **not** disable SIMD anywhere else (verified: a defaulted `==` reports
`__is_trivially_equality_comparable == 1`, the user-provided one `== 0`, with `sizeof` unchanged).
Rows that contain any float/double (AttitudeSample, RawDetectionBeam, CompressedWaterColumnBeam) are
never affected because floats aren't memcmp-comparable. The project-wide
`_USE_STD_VECTOR_ALGORITHMS=0` escape hatch is therefore **not** used (it would disable SIMD
globally). See `echosounders/meson.build` and the substruct headers.

### Reserved-field completeness (checked against spec v3.12)
All implemented records carry every reserved byte the spec defines (sizes match the spec exactly):
reserved u32×13 (7002), u32×15 (7027), u32×6 (7028), u32×1 (7042), trailing u16 (7000 & 7200),
and the DRF reserved u16/u32 fields. Two refinements made while verifying this:

- **7000 SonarSettings** — the spec splits "Tx pulse mode (u16)" + "Tx pulse reserved (u16)". These
  are now modelled explicitly: `t_tx_pulse_mode` is backed by `uint16_t` and a `_tx_pulse_reserved`
  u16 follows it (record size unchanged at 160 bytes).
- **7610 SoundVelocity** — now reads the **optional Temperature (f32, Kelvin) + Pressure (f32,
  Pascal)** that follow sound velocity on IO module >= V4.0.0.8 (spec Table 118). The record is
  variable-size (4-byte RTH or 12-byte RTH); presence is driven by the DRF record size, the optional
  pair is 0 when absent, and `has_temperature_and_pressure()` reports whether they are present.
