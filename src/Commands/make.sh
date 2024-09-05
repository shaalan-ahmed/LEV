#!/bin/bash

clear

compiler=g++

main=../Main/main.cpp
declarations=../Declarations/declarations.cpp

executable=main

list="$declarations "

for entry in ../Classes/*; do
  if [ -d "$entry" ]; then
    filename="${entry}/${entry##*/}.cpp"
    list+="$filename "
  fi
done

$compiler $main $list -o $executable

./$executable

rm $executable
