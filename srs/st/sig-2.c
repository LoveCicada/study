/* ---------------------------------------------------------------- */
/* PROGRAM  sig-2.c:                                                */
/*    This is a simple program that illustrates the use of signal   */
/* handler and the setjmp/longjmp pair.  It catches Ctrl-C & alarm. */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <signal.h>
#include  <setjmp.h>
#include  <unistd.h>
#include  <stdlib.h>

#define   START         0
#define   FROM_CTRL_C   1
#define   FROM_ALARM    2

#define   ALARM         5

jmp_buf  JumpBuffer;                    /* a jump buffer            */

void     INThandler(int);               /* SIGINT handler           */
void     ALARMhandler(int);             /* SIGALRM handler          */

/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

void  main(void)
{
     int  JumpReturn;

     signal(SIGINT, INThandler);        /* install SIGINT handler   */
     signal(SIGALRM, ALARMhandler);     /* install SIGALRM handler  */

     while (1) {
          if ((JumpReturn = setjmp(JumpBuffer)) == START) { /* mark */
               alarm(ALARM);            /* install alarm clock      */
               pause();                 /* then, wait               */
          }
          else if (JumpReturn == FROM_CTRL_C) {   /* from Ctrl-C    */
          }                                       /* do nothing     */
          else if (JumpReturn == FROM_ALARM) {    /* from alarm     */
               printf("The alarm clock is reset to %d sec\n", ALARM);
          }
     }
}

/* ---------------------------------------------------------------- */
/* FUNCTION  INThandler:                                            */
/*    This function handles the SIGINT (Ctrl-C) signal.             */
/* ---------------------------------------------------------------- */

void  INThandler(int sig)
{
     char  c;

     signal(SIGALRM, SIG_IGN);          /* ignore other signals     */
     signal(SIGINT, SIG_IGN);
     printf("OUCH, you just hit a Ctrl-C\n"
            "Do you really want to quit? [y/n] ");
     c = getchar();                     /* do some processing       */
     if (c == 'y' || c == 'Y')
          exit(0);
     signal(SIGINT, INThandler);        /* reinstall handlers       */
     signal(SIGALRM, ALARMhandler);
     longjmp(JumpBuffer, FROM_CTRL_C);  /* jump back to main        */
}

/* ---------------------------------------------------------------- */
/* FUNCTION  ALARMhandler:                                          */
/*    This function handles the SIGALRM (alarm) signal.             */
/* ---------------------------------------------------------------- */

void  ALARMhandler(int  sig)
{
     signal(SIGINT, SIG_IGN);           /* ignore alarm signal      */
     signal(SIGALRM, SIG_IGN);
     printf("An alarm signal just arrived ...\n");
     alarm(0);                          /* reset the signal         */
     signal(SIGALRM, ALARMhandler);     /* reinstall handlers       */
     signal(SIGINT, INThandler);
     longjmp(JumpBuffer, FROM_ALARM);   /* jump back to main        */
}
