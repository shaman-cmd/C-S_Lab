#!/bin/bash
echo "enter the two strings"
read n1
read n2
if [ "$n1" == "$n2" ];then
echo "the two strings are equal"
else
echo "the two are strings are not equal"
if [ "$n1" > "$n2" ];then
echo "string1 is bigger than string2"
else
echo "string2 is bigger than string1"
fi
fi
