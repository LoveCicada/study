/* ---------------------------------------------------------------- */
/* PROGRAM  fact.c:                                                 */
/*    This program illustrates the use of setjmp() and longjmp() to */
/* perform a "non-local goto".                                      */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <setjmp.h>
#include  <stdlib.h>

jmp_buf   JumpBuffer;                   /* a jump buffer            */

void      factorial(int);               /* computing n!             */
void      fact(int, int, int);          /* this is THE working funct*/

int       result;                       /* will hold the result     */

/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

void  main(int argc, char *argv[])
{
     int  n;

     if (argc != 2) {                   /* two command line args?   */
          printf("Use %s n\n", argv[0]);
          exit(0);
     }
     n = (int) atoi(argv[1]);           /* get command line arg     */
     if (setjmp(JumpBuffer) == 0) {     /* set a return mark        */
          factorial(n);                 /* compute n!               */
          printf("Don't  worry  about  this,  since it is never executed\n");
          exit(0);
     }
     else                               /* factorial returns here   */
          printf("fact(%d) = %d\n", n, result);
     exit(0);
}

/* ---------------------------------------------------------------- */
/* FUNCTION  factorial:                                             */
/*    This function converts the input to a recursive call.         */
/* ---------------------------------------------------------------- */

void  factorial(int n)
{
     fact(1, 1, n);
}

/* ---------------------------------------------------------------- */
/* FUNCTION  fact:                                                  */
/*    This is the REAL computation part.  Fact() takes the previous */
/* result in Result, a counter in Count, and the upper bound in n.  */
/* If the Counter <= n, the new result is Result*Count, and call    */
/* itself recursively.  The final result is saved in a global       */
/* variable 'result'.  Finally, a longjmp() is used to skip ALL     */
/* recursive calls and return to the main().                        */
/* ---------------------------------------------------------------- */

void  fact(int Result, int Count, int n)
{
     if (Count <= n)
          fact(Result*Count, Count+1, n);
     else {
          result = Result;
          longjmp(JumpBuffer, 1);
     }
}