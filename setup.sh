#!/bin/bash

build_dir=build

if [[ ! -e $build_dir ]]; then
	mkdir $build_dir
	cd $build_dir
	cmake ..
elif [[ ! -d $build_dir ]]; then
	echo "Build directory ($build_dir) exists, but it is not a directory."
else
	echo "Build directory ($build_dir) exists. Nothing to do."
fi
