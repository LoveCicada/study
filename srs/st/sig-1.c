/* ---------------------------------------------------------------- */
/* PROGRAM  sig-1.c:                                                */
/*    This is a simple program that illustrates the use of signal   */
/* handler and the setjmp/longjmp pair.  It catches Ctrl-C.         */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <signal.h>
#include  <setjmp.h>
#include  <stdlib.h>
#include  <unistd.h>

jmp_buf  JumpBuffer;                    /* a jump buffer            */

void     INThandler(int);               /* the Ctrl-C handler       */

/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

void  main(void)
{
     signal(SIGINT, INThandler);        /* install Ctrl-C handler   */

     while (1) {                        /* loop & wait Ctrl-C       */
          if (setjmp(JumpBuffer) == 0) {     /* set a return mark   */
             printf("Hit Ctrl-C at anytime ... \n");
             pause();                   /* pause until Ctrl-C comes */
          }
     }
}

/* ---------------------------------------------------------------- */
/* FUNCTION  INThandler:                                            */
/*    This function handles the SIGINT (Ctrl-C) signal.             */
/* ---------------------------------------------------------------- */

void  INThandler(int  sig)
{
     char  c;

     signal(sig, SIG_IGN);              /* ignore Ctrl-C for now    */
     printf("OUCH, did you hit Ctrl-C?\n"
            "Do you really want to quit? [y/n] ");
     c = getchar();
     if (c == 'y' || c == 'Y')
          exit(0);
     else {
          signal(SIGINT, INThandler);   /* reinstall before return  */
          longjmp(JumpBuffer, 1);       /* return to the setjmp mark*/
     }
}
