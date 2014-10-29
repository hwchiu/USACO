#!/bin/sh
base="src/Section1/"
target=`ls ${base} | cat`
IFS=$'\n'
for dir in $target
do
	name=`ls ${base}${dir}"/" | cat | grep cpp | cut -f1 -d"."`
	sed "s/hamming/${name}/g" < Makefile > $base$dir"/Makefile"
done
