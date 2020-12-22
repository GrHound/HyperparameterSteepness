#!/bin/bash
tolstart=0.4
tolend=0.01
nsteps=200

echo "set terminal png" > tmp.gnu
echo "set output 'curves.png'" >> tmp.gnu
echo "set title 'Tolerance from $tolstart to $tolend in $nsteps for several alpha'" >> tmp.gnu
echo -n "plot " >> tmp.gnu

first=1
for alpha in 0.1 0.2 0.4 0.8 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0
do
  if [ "$first" != 1 ]; then
    echo -n ", " >> tmp.gnu
  fi
  b="curve-from-$tolstart-to-$tolend-alpha=$alpha" 
  steepness $tolstart $tolend $alpha $nsteps > $b.curve
  echo -n "'$b.curve' w l lw 2 title 'alpha=$alpha'" >> tmp.gnu
  first=0
  echo "Made: $b.curve"
done
gnuplot < tmp.gnu
echo "See curves.png"
rm tmp.gnu
