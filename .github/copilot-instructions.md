# GitHub Copilot Instructions for echosounders

## Repository Overview

This repository contains libraries to read, write, and process single- and multibeam echo sounder file formats. The project is written in C++ with Python bindings.

## Build System

- **Build System**: Meson with Ninja backend
- **Dependencies**: Boost, Eigen3, pugixml, catch2 (for tests)
- **C++ Standard**: C++20
- **Test Framework**: Catch2 for C++, pytest for Python

## Key Commands

### Building the Project
```bash
# Setup build directory
meson setup builddir -Dunity=on -Dunity_size=9999999 -Dpython.install_env=auto -Dprefix=/usr/

# Compile
meson compile -C builddir/

# Run C++ tests
meson test -C builddir/ --print-errorlogs

# Install project
meson install -C builddir/

# Run Python tests
pytest -v
```

### Development Workflow
1. Always run the complete test suite before making changes
2. Build and test incrementally after each change
3. Ensure both C++ and Python tests pass
4. Follow the existing code style (.clang-format is provided)

## CI/CD Workflows

The repository has three main CI workflows:
- **ci-linux.yml**: Tests on Ubuntu containers (latest and 22.04) and Arch Linux
- **ci-windows.yml**: Tests on Windows 2025 with MSVC
- **ci-mac.yml**: Tests on macOS 15

All workflows must pass before merging.

## Important Files and Directories

- `src/`: Main source code
  - `src/themachinethatgoesping/echosounders/`: Core C++ library
  - `src/tests/`: C++ test files using Catch2
  - `src/pymodule/`: Python bindings
- `python/`: Python package files
- `unittest_data/`: Test data files
- `meson.build`: Root build configuration
- `meson_options.txt`: Build options

## Code Structure

### C++ Code Organization
- Header files use `.hpp` extension
- Test files use `.test.cpp` extension
- Code is organized into namespaces following the directory structure
- Uses modern C++20 features

### Key Components
- **Kongsbergall**: Support for Kongsberg .all format files
- **Simradraw**: Support for Simrad .raw format files  
- **GSF**: Support for Generic Sensor Format files
- **Filetemplates**: Base templates for file format handling
- **Pingtools**: Tools for ping data processing

## Testing Guidelines

### C++ Tests
- Use Catch2 framework with TEST_CASE macros
- Test files are located in `src/tests/` with `.test.cpp` extension
- Tests are automatically discovered by meson build system
- Use descriptive test names with tags like `[kongsbergall]`

### Python Tests
- Use pytest framework
- Test files follow pytest naming conventions
- Tests are run with `pytest -v`

## Making Changes

When making changes:
1. **Understand the context**: Read relevant existing code and tests
2. **Make minimal changes**: Focus on the specific issue or feature
3. **Maintain consistency**: Follow existing patterns and naming conventions
4. **Test thoroughly**: Ensure all tests pass after your changes
5. **Update tests if needed**: Add new tests for new functionality

## Auto-fix Guidelines

When tests fail, you should:
1. Analyze the test failure output carefully
2. Identify the root cause (compilation error, runtime error, logic error)
3. Make the minimal necessary change to fix the issue
4. Re-run tests to verify the fix
5. Ensure no other tests are broken by your change

## Dependencies and Subprojects

The project uses several subprojects managed by Meson:
- `tools`: Core utilities (themachinethatgoesping_tools)
- `algorithms`: Mathematical algorithms  
- `navigation`: Navigation utilities
- `meta`: Project metadata
- `pugixml`: XML parsing library
- `catch2`: C++ testing framework

These are automatically fetched and built by the build system.