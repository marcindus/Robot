#!/usr/bin/env bash

function abort {
    echo ""
    echo -e "\033[1;31m$1\033[0m"
    exit 1
}

function okay {
    echo ""
    echo -e "\033[1;32m$1\033[0m"
}

function step {
    echo -e "\033[1;97m$1\033[0m"
}

PYENV=.pyenv
FULL_PYENV="`pwd`/${PYENV}"
step "\nAttempting to set up a Python3 virtual environment for this project in:\n${FULL_PYENV}\n"

command -v virtualenv > /dev/null || abort "FATAL: there is no virtualenv tool installed - please install it before running this script"
python3 -m virtualenv -p python3 "${PYENV}" || abort "FATAL: Could not initialize Python3 virtual environment ${PYENV} - for details please see the output above"
source "${PYENV}/bin/activate" || abort "FATAL: Could not activate Python3 virtual environment ${PYENV} - for details please see the output above"
pip3 install -r requirements.txt || abort "FATAL: Could not install required dependencies in Python3 virtual environment in '${FULL_PYENV}' - for details please see the output above"

okay "Project set up - for this project please use the following virtual environment:\n${FULL_PYENV}"
