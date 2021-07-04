@echo off

mkdir compiled
cd compiled

gcc -c ..\get_line.c
gcc -c ..\strindex.c

cd ..