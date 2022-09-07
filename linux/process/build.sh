#! /bin/bash

echo "process"
gcc -o ./bin/process process.c

echo "main"
gcc -o ./bin/main main.c

echo "waitpid"
gcc -o ./bin/waitpid waitpid.c

echo "waitChildProcess"
gcc -o ./bin/waitChildProcess waitChildProcess.c

echo "waitChildProceeNonBlock"
gcc -o ./bin/waitChildProceeNonBlock waitChildProceeNonBlock.c