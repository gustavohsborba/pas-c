#!/bin/bash

rm -rf tests/output/*

for file in $(ls tests/*.psc); do
    ./pasc ${file} > "tests/output/$(basename $file | cut -f1 -d".").out"
done
