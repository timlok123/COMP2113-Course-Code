#!/bin/bash 

g++ -pedantic-errors -std=c++11 random.cpp -o random
./random <input.txt> output.txt

sum1=0
d=$1
Line="`cat output.txt`"

for i in $Line
do
  if [ $i -ge $d ]
  then 
    let "sum1+=1"
  fi
done

echo $sum1
