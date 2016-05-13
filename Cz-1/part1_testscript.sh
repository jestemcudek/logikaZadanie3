#!/bin/bash

A=(4 3 0 0 4 2 -1)
B=(9 4 2 8 2 1 2)
C=(3 6 3 4 7 1 5)
D=(2 3 2 2 5 1 3)
E=(1 1 6 1 2 1 5)
F=(1 1 1 1 1 5 1)
G=(4 4 3 1 4 0 2)

mainResults=(0 0 1 1 0 1 0)
negatedResults=(1 1 0 0 1 0 1)

echo "Normalne"
g++ -o main part1_norm.cpp

for i in `seq 0 6`; do
x=`./main ${A[$i]} ${B[$i]} ${C[$i]} ${D[$i]} ${E[$i]} ${F[$i]} ${G[$i]}`
# echo $x
# echo ${mainResults[$i]}
if [  $x == ${mainResults[$i]} ] ; then
echo "OK"
fi
if [  $x != ${mainResults[$i]} ] ; then
echo "input"  ${A[$i]} ${B[$i]} ${C[$i]} ${D[$i]} ${E[$i]} ${F[$i]} ${G[$i]}
echo "output" $x
echo "expected output" ${mainResults[$i]}
fi
done

echo "Zanegowane"
g++ -o negated part1_negated.cpp

for i in `seq 0 6`; do
x=`./negated ${A[$i]} ${B[$i]} ${C[$i]} ${D[$i]} ${E[$i]} ${F[$i]} ${G[$i]}`
# echo $x
#echo ${negatedResults[$i]}
if [  $x == ${negatedResults[$i]} ] ; then
echo "OK"
fi
if [  $x != ${negatedResults[$i]} ] ; then
echo "input"  ${A[$i]} ${B[$i]} ${C[$i]} ${D[$i]} ${E[$i]} ${F[$i]} ${G[$i]}
echo "output" $x
echo "expected output" ${negatedResults[$i]}
fi
done
