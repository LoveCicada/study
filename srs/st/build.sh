#! /bin/bash

gcc -o ./bin/st st.c -g  
gcc -o ./bin/st2 st2.c -g 
gcc -o ./bin/mtp mtp.c -g
gcc -o ./bin/st_fun_uncorrect st_fun_uncorrect.c -g
gcc -o ./bin/sig-1 sig-1.c -g
gcc -o ./bin/sig-2 sig-2.c -g
gcc -o ./bin/fact fact.c -g


gcc -o ./bin/setjmp_longjmp setjmp_longjmp.c -g 