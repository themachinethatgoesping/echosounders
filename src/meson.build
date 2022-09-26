# SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# -- setup variables --
base_path = meson.current_source_dir()

# -- C++ projects --
subdir('themachinethatgoesping')

# -- catch2 tests --
if get_option('build_tests').enabled()
    catch2 = subproject('catch2')
    catch2 = catch2.get_variable('catch2_with_main_dep')
    
    subdir('tests')
endif


# -- python modules --
pymod = import('python').find_installation(get_option('python_path'), required : get_option('build_pythonmodule'))

if get_option('build_pythonmodule').enabled()

    if pymod.found()
        #numpy (copied from https://github.com/mesonbuild/meson/issues/9598)
        # NumPy include directory - needed in all submodules
        py3 = find_program('python3', 'python')
        incdir_numpy = run_command(py3,
        [
            '-c',
            'import os; os.chdir(".."); import numpy; print(numpy.get_include())'
        ],
        check: true
        ).stdout().strip()

        inc_np = include_directories(incdir_numpy)
        numpy_dep = declare_dependency(include_directories: inc_np)


        python3_dep = pymod.dependency()

        pybind11_dep = dependency('pybind11', required : false)

        if not pybind11_dep.found()
            pybind11_project = subproject('pybind11')
            pybind11_dep     = pybind11_project.get_variable('pybind11_dep')
        endif


        # -- put python module stuff here --

        # set path where to install sources (pythonpath/site-packages/projectnamespace)
        pythoninstallpath = pymod.get_install_dir() + projectnamespace + '/'
        message('python module install directory:', pythoninstallpath)


        #put module folders here
        subdir('pymodule')

    endif
endif
