#!/bin/bash

BUILD_DIR="build"

if [ "$1" == "clean" ]; then
    echo "Cleaning build directory..."

    rm -rf $BUILD_DIR

    echo "Build directory removed."
    exit 0
fi

if [ "$1" == "rebuild" ]; then
    echo "Rebuilding project..."

    rm -rf $BUILD_DIR
fi

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake ..
make