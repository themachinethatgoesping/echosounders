# GitHub Copilot Instructions for echosounders

This repository contains libraries to read, write, and process single- and multibeam echo sounder file formats.

## Build System

The project uses **Meson** as the build system with C++20 standard.

### Initial Setup

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install -y build-essential ccache pkg-config cmake python3-pip libboost-all-dev libcurl4-openssl-dev

# Install Meson and Python dependencies
pip install meson meson-python ninja pytest numpy
pip install -r requirements.txt
```

### Configure and Build

```bash
# Configure the build
meson setup builddir -Dunity=on -Dunity_size=9999999 -Dpython.install_env=auto -Dprefix=/usr/

# Compile the project
meson compile -C builddir/

# Install the project
meson install -C builddir/
```

**Important**: Always configure with `-Dunity=on -Dunity_size=9999999` for faster compilation.

## Testing

### C++ Tests

Run C++ tests using Meson:

```bash
meson test -C builddir/ --print-errorlogs
```

**Always run C++ tests after making changes to C++ code.**

### Python Tests

Run Python tests using pytest:

```bash
pytest -v
```

Python tests are located in `python/tests/` as specified in `pytest.ini`.

**Always run pytest after making changes to Python bindings or Python code.**

### Complete Test Suite

To run all tests (C++ and Python):

```bash
meson test -C builddir/ --print-errorlogs && pytest -v
```

## Code Formatting

### C++ Code Style

The project uses **clang-format** with a Mozilla-based style defined in `.clang-format`.

**Key formatting rules:**
- Indent: 2 spaces
- Brace style: Allman (braces on new lines for classes, functions, structs)
- Line width: 100 characters
- Align consecutive assignments and declarations
- C++20 standard

**Always format C++ code before committing:**

```bash
clang-format -i <file.cpp>
# Or format all files
find src -name "*.hpp" -o -name "*.cpp" | xargs clang-format -i
```

### Python Code Style

Follow standard Python conventions (PEP 8) for Python code.

## Project Structure

```
.
├── src/                          # C++ source code
│   ├── themachinethatgoesping/   # Main library code
│   ├── pymodule/                 # Python bindings (pybind11)
│   ├── nanomodule/               # Python bindings (nanobind)
│   └── tests/                    # C++ tests
├── python/                       # Python package
│   └── tests/                    # Python tests
├── subprojects/                  # Meson subprojects (dependencies)
├── scripts/                      # Build and validation scripts
└── unittest_data/                # Test data files
```

## Key Conventions

### File Organization
- Header files: `.hpp` extension
- Source files: `.cpp` extension
- Python bindings are in separate modules (pymodule, nanomodule)
- Tests are co-located with source code in `tests/` directories

### Naming Conventions
- Namespace: `themachinethatgoesping::echosounders`
- Files and directories: lowercase with underscores
- Classes: PascalCase
- Functions/methods: camelCase or snake_case (check existing code)

### Code Patterns
- Use modern C++20 features
- Align consecutive assignments and declarations for readability
- Document public APIs with docstrings
- Python bindings use both pybind11 and nanobind

## Dependencies

### Core Dependencies
- **Boost**: Used for iostreams and other utilities
- **pugixml**: XML parsing (included as subproject)
- **themachinethatgoesping libraries**: tools, algorithms, navigation, meta

### Python Dependencies
- numpy >= 1.26.0
- pandas >= 2.1.0
- tqdm
- pyarrow
- pytest (for testing)
- pybind11 >= 3.0.1
- nanobind >= 2.9.1

**Check `requirements.txt` and `meson.build` for current dependency versions.**

## CI/CD Integration

The repository has automated CI/CD workflows:

- **ci-linux.yml**: Linux builds on Ubuntu and Arch
- **ci-mac.yml**: macOS builds
- **ci-windows.yml**: Windows builds
- **ci-copilot.yml**: Optimized workflow for Copilot-generated PRs

**Tests run automatically on all pull requests.** The Copilot CI workflow provides quick validation (~5-10 minutes) followed by comprehensive testing.

### CI Quick Check
For fast local validation similar to CI quick check:

```bash
./scripts/validate-copilot-ci.sh
```

## Making Changes

### Workflow for Code Changes

1. **Make changes** to C++ or Python code
2. **Format code** (if C++): `clang-format -i <files>`
3. **Build**: `meson compile -C builddir/`
4. **Test C++**: `meson test -C builddir/ --print-errorlogs`
5. **Test Python**: `pytest -v`
6. **Commit** with descriptive message
7. **Push** and create PR - CI will run automatically

### Adding New Features

- **Add tests** alongside new features
- **Update documentation** if adding public APIs
- **Follow existing patterns** in the codebase
- **Check both C++ and Python** if changes affect bindings

### Bug Fixes

- **Add regression test** if possible
- **Verify fix with tests** before committing
- **Check related code** for similar issues

## Common Tasks

### Adding a New C++ Class

1. Create `.hpp` file in appropriate directory under `src/themachinethatgoesping/echosounders/`
2. Follow existing class structure and naming conventions
3. Add to appropriate `meson.build` file
4. Add tests in corresponding `tests/` directory
5. Format with clang-format
6. Build and test

### Adding Python Bindings

1. Add bindings in `src/pymodule/` or `src/nanomodule/`
2. Follow existing binding patterns
3. Add Python tests in `python/tests/`
4. Test with pytest

### Updating Dependencies

1. Update version in `meson.build` or `requirements.txt`
2. Test thoroughly on all platforms via CI
3. Document breaking changes if any

## License and Headers

- **License**: MPL-2.0 (Mozilla Public License 2.0)
- **SPDX headers**: All files should include SPDX license headers
- **Copyright**: 2022 - 2025 Peter Urban, Ghent University

**Example header:**
```cpp
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
```

## Additional Resources

- **CI Setup Guide**: `.github/COPILOT_SETUP.md`
- **Testing Guide**: `.github/TESTING.md`
- **Meson Documentation**: https://mesonbuild.com/
- **Project README**: `README.rst`

## Tips for Success

- ✅ **Always run tests** before committing
- ✅ **Use ccache** for faster rebuilds (configured in CI)
- ✅ **Check CI logs** if builds fail
- ✅ **Follow existing code patterns** for consistency
- ✅ **Format C++ code** with clang-format before committing
- ✅ **Add tests** for new features and bug fixes
- ✅ **Document public APIs** with clear docstrings
- ⚠️ **Do not modify unrelated code** to keep changes focused
- ⚠️ **Check both C++ and Python** when making cross-language changes
