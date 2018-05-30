#!/bin/bash

for((i=1;i<=6;i++))
do
    ./mkdata > $i.in
    ./run < $i.in > $i.out
done
