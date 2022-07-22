#!/bin/bash
rm -r box_2
mkdir box_2
#cd box_2
for i in {1..5}
do
#	touch file$i.txt
	a=$((10*($i-1)+1))
	for (( c=1; c<=5; c++ ))
	do
		echo "$a" >>./box_2/file$i.txt
		((a++))
	done
#	echo>>file$i.txt
	b=$((10*($i-1)+6))
	for (( c=1; c<=5; c++ ))
	do
		echo "$b" >> ./box_2/file$i.txt
		((b++))
	done
done
#cd ..
