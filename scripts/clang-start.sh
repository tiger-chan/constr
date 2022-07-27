#!/usr/bin/env bash

docker run -it --rm --name=constr_clang \
	--mount type=bind,source=${PWD},target=/src \
	--mount type=bind,source=${PWD}/build/clang,target=/build \
	constr-clang:latest \
	bash