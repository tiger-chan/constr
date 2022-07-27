#!/usr/bin/env bash

docker run -it --rm --name=constr_gcc \
	--mount type=bind,source=${PWD},target=/src \
	--mount type=bind,source=${PWD}/build/gcc,target=/build \
	constr-gcc:latest \
	bash