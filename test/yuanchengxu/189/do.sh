#!/bin/bash

for((i=2;i<=6;i++))
do
    ./mkdata > $i.in
    sleep 1
    ./run < $i.in > $i.out
done
