#!/bin/bash

for((i=1;i<=6;i++))
do
    ./run < $i.in > $i.out
done
