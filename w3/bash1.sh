#!/bin/bash
rm -r box
mkdir box
a=new_
for file in *
do
	cp $file ./box/$a$file
done
