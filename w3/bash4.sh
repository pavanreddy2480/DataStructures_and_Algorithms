#!/bin/bash
rm -r box_2
mkdir box_2
#cd box_2
for i in {1..5}
do
#	touch file$i.txt
	a=$((10*($i-1)+1))
	b=$((10*($i-1)+2))
	c=$((10*($i-1)+3))
	d=$((10*($i-1)+4))
	e=$((10*($i-1)+5))
	echo "$a $b $c $d $e" >>./box_2/file$i.txt
#	echo>>file$i.txt
	a=$((10*($i-1)+6))
	b=$((10*($i-1)+7))
	c=$((10*($i-1)+8))
	d=$((10*($i-1)+9))
	e=$((10*($i-1)+10))
	echo "$a $b $c $d $e" >> ./box_2/file$i.txt
done
#cd ..
