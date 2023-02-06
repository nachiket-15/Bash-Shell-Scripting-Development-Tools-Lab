#!/bin/bash
echo $((12+7)) is correct
echo
a=4
b=8
echo $((a=a+b))
echo $a
echo
a=4
((a++))
echo $a
echo
b=8
unset b
((b--))
echo $b
echo
a=1
let a++
echo $a
