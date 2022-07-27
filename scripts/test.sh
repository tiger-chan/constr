#!/usr/bin/env bash

pushd /build  > /dev/null
ctest -C $1
popd  > /dev/null
