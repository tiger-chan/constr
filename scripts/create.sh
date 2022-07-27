#!/usr/bin/env bash

BUILD=${1:-Release}
TESTS_FLAG=${2:-Off}

echo Configuring CMAKE with ${BUILD} and TESTS: ${TESTS_FLAG}
cmake -B /build -DCMAKE_BUILD_TYPE=${BUILD} -DCONSTR_BUILD_TESTING=${TESTS_FLAG}
