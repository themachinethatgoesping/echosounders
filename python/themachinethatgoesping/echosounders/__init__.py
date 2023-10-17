# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

import importlib
from pkgutil import extend_path as __extend_path__

# c++ module
from themachinethatgoesping.echosounders_cppy import *  # flake8: noqa

# python only modules
from . import index_functions# flake8: noqa

__version__ = "@PROJECT_VERSION@"