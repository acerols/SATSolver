#!/bin/sh

cd build 
make
cd ../

./build/SATSolver ./test/test.cnf >> ./test/test1out.txt
./build/SATSolver ./test/test2.cnf >> ./test/test2out.txt
