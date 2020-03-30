#!/bin/bash

function abort {
    echo ""
    echo -e "\033[1;31m$1\033[0m"
    exit 1
}

source .pyenv/bin/activate || abort "Could not activate project's Python3 virtual environment - please set it up first with the setup.sh script"

if [[ "$1" == "-h" ]] || [[ "$1" == "--help" ]]; then
    echo "Usage: runt_test.sh [OPTIONS]
Example:
    run_test.sh --with-cov
Options:
    -h --help:      Print help
    -c --with-cov:  Generate coverage file for run test. Coverage file: coverage.xml"

elif [[ "$1" == "--with-cov" ]] || [[ "$1" == "-c" ]]; then
    python3 -m pytest --junitxml=unittest-results.xml -v --cov=. --cov-report xml --cov-config .coveragerc
elif [[ $# -eq 0 ]]; then
    python3 -m pytest  -v
else
    abort "Unrecognized option: $1"
fi

