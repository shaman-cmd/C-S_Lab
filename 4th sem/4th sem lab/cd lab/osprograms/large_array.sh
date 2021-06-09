#!/bin/bash 
echo "enter array elements "
read -a A
echo "length : ${#A[@]}"
echo "array elements are :"
for i in ${A[@]} ; do
echo $i;
done
max=${A[0]}
for ((i=0;i<length; do 
if [ $i -gt $max ]; then
max=$i;
fi
done
echo " largest : $max "
