#!/bin/bash

for i in $(seq 1 8); do
    rm -rf tests/output/test${i}.out
    ./pasc tests/test${i}.psc >> tests/output/test${i}.out 
done
