#!/bin/env python3

import os
import sys
import subprocess
from tqdm import tqdm

# does not work because pybind11_mkdoc only provides a module script
#from pybind11_mkdoc import mkdoc
ignore_files = [
    # 'classhelper.hpp'
]

headers = []
for r, d, f in os.walk('../themachinethatgoesping/'):
    for file in f:
        if file.endswith('.hpp'):
            if file not in ignore_files:
                headers.append(r + '/' + file)
headers.sort()

# with open("mkdoc_log.txt",'w') as ofi:
#     for h in tqdm(headers):
#         new_path = "../themachinethatgoesping/docstrings/" + h.split("/themachinethatgoesping/")[-1].replace(".hpp",".doc.hpp")
#         #h = os.path.abspath(h)
#         #print(h, new_path)
#
#         subprocess.call([sys.executable, '-m', 'pybind11_mkdoc', '-o', new_path, h], stdout=ofi, stderr=ofi)


subprocess.call([sys.executable, '-m', 'pybind11_mkdoc', '-o', 'docstrings.hpp', headers], stdout=ofi, stderr=ofi)
# this only works using the xonsh shell which can call bash commands from python
# echo running python3 -m pybind11_mkdoc -o docstrings.hpp @(headers)
#python3 -m pybind11_mkdoc -o docstrings.hpp @(headers)
