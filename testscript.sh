#!/bin/sh

THIS_FILE_PATH="$PWD/$0"
cd ${THIS_FILE_PATH}

rm ./test/*.txt
INDEX=1
OUT_FILE_NAME=testout

IN_FILE_INDEX=1
IN_FILE_NAME=test

cd build 
make
cd ../

./build/SATSolver ./test/${IN_FILE_NAME}${INDEX}.cnf >> ./test/${OUT_FILE_NAME}${INDEX}.txt
: expr $((INDEX+=1))
./build/SATSolver ./test/${IN_FILE_NAME}${INDEX}.cnf >> ./test/${OUT_FILE_NAME}${INDEX}.txt
: expr $((INDEX+=1))
./build/SATSolver ./test/${IN_FILE_NAME}${INDEX}.cnf >> ./test/${OUT_FILE_NAME}${INDEX}.txt
: expr $((INDEX+=1))
./build/SATSolver ./test/${IN_FILE_NAME}${INDEX}.cnf >> ./test/${OUT_FILE_NAME}${INDEX}.txt
