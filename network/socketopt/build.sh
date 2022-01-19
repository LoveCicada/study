#! /bin/bash



echo "print_sockopt"
gcc -o ./bin/print_sockopt print_sockopt.c

echo "snd_rcv_buf"
gcc -o ./bin/snd_rcv_buf snd_rcv_buf.c

echo "sock_type"
gcc -o ./bin/sock_type sock_type.c