#!/bin/sh

usage="Usage: ./add.sh dirname"
if [ -z $1 ]; then
	echo ${usage}
	exit 0
fi

mkdir $1
cp template.go $1/
cd $1
mv template.go main.go
vim main.go
