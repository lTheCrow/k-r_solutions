@echo off

cd compiled
gcc ..\grepclone.c get_line.o strindex.o -I ..\includes -o ..\grepclone.exe
cd ..
