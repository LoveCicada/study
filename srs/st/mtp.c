/* ------------------------------------------------------- */
/* PROGRAM  mtp.c:                                         */
/*   This program shows a poorman's multithreaded kernel   */
/* using setjmp() and longjmp().                           */
/*                                                         */
/*                                       Ching-Kuang Shene */
/*                                         August 31, 1998 */
/* ------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>
#include  <setjmp.h>

#define   MAX_COUNT   5

/* ------------------------------------------------------- */
/*                     Data Structures                     */
/* ------------------------------------------------------- */

typedef struct PCB_NODE  *PCB_ptr; /* pointer to a PCB     */

typedef struct PCB_NODE {          /* a PCB:               */
     jmp_buf   Environment;        /*   jump buffer        */
     int       Name;               /*   thread name: unused*/
     PCB_ptr   Next;               /*   next PCB           */
}  PCB;          

/* ------------------------------------------------------- */
/*                      External Data                      */
/* ------------------------------------------------------- */

jmp_buf   MAIN;                    /* jump buffer for main */
jmp_buf   SCHEDULER;               /* for the scheduler    */

PCB_ptr   Head;                    /* head of the PCBs     */
PCB_ptr   Current;                 /* current executing    */
PCB_ptr   work;                    /* working variable     */

/* ------------------------------------------------------- */
/*                    Macro THREAD_CREATE                  */
/*   This macro creates a thread.                          */
/* ------------------------------------------------------- */

#define   THREAD_CREATE(function, name) {                   \
                    if (setjmp(MAIN) == 0)                  \
                         (function)(name);                  \
               }
                    
/* ------------------------------------------------------- */
/*                 Macro THREAD_INIT                       */
/*   This macro allocates a PCB for a thread and puts it   */
/*   into the scheduling chain, which is a circular list.  */
/* ------------------------------------------------------- */

#define   THREAD_INIT(name)     {                           \
                    work = (PCB_ptr) malloc(sizeof(PCB));   \
                    work->Name = name;                      \
                    if (Head == NULL)                       \
                         Head = work;                       \
                    else                                    \
                         Current->Next = work;              \
                    work->Next = Head;                      \
                    Current = work;                         \
                    if (setjmp(work->Environment) == 0)     \
                         longjmp(MAIN, 1);                  \
               }
                         
/* ------------------------------------------------------- */
/*                  Macro THREAD_YIELD                     */
/*   This macro simulates yielding control by jumping      */
/*   into the scheduler.  The scheduler picks the next     */
/*   thread to run.                                        */
/* ------------------------------------------------------- */

#define   THREAD_YIELD(name)    {                           \
                    if (setjmp(Current->Environment) == 0)  \
                    longjmp(SCHEDULER, 1);                  \
               }

/* ------------------------------------------------------- */
/* FUNCTION  funct_1():                                    */
/*   A function to be run as a thread.                     */
/* ------------------------------------------------------- */

void  funct_1(int  name)
{
     int  i;
     
     THREAD_INIT(name);            /* initialize as thread */
     while (1) {                   /* running the thread   */
          for (i = 1; i <= MAX_COUNT; i++)
               printf("funct_1() executing\n");
          THREAD_YIELD(name);      /* yield control        */
     }
}
                              
/* ------------------------------------------------------- */
/* FUNCTION  funct_2():                                    */
/*   A function to be run as a thread.                     */
/* ------------------------------------------------------- */

void  funct_2(int  name)
{
     int  i;
     
     THREAD_INIT(name);
     while (1) {
          for (i = 1; i <= MAX_COUNT; i++)
               printf("   funct_2() executing\n");
          THREAD_YIELD(name);
     }
}
                              
/* ------------------------------------------------------- */
/* FUNCTION  funct_3():                                    */
/*   A function to be run as a thread.                     */
/* ------------------------------------------------------- */

void  funct_3(int  name)
{
     int  i;
     
     THREAD_INIT(name);
     while (1) {
          for (i = 1; i <= MAX_COUNT; i++)
               printf("      funct_3() executing\n");
          THREAD_YIELD(name);
     }
}
                              
/* ------------------------------------------------------- */
/* FUNCTION  funct_4():                                    */
/*   A function to be run as a thread.                     */
/* ------------------------------------------------------- */

void  funct_4(int  name)
{
     int  i;
     
     THREAD_INIT(name);
     while (1) {
          for (i = 1; i <= MAX_COUNT; i++)
               printf("         funct_4() executing\n");
          THREAD_YIELD(name);
     }
}
                              
/* ------------------------------------------------------- */
/* FUNCTION  Scheduler():                                  */
/*   The scheduler is first called by the main program to  */
/* setup an entry point.  Then, it is re-entered through   */
/* a longjmp() from the THREAD_YIELD() macro.              */
/* ------------------------------------------------------- */

void  Scheduler(void)
{
     if (setjmp(SCHEDULER) == 0)
          longjmp(MAIN, 1);
     Current = Current->Next;
     longjmp(Current->Environment, 1);         
}
                         
/* ------------------------------------------------------- */
/*              The main program starts here               */
/*   The main program calls each threads, allowing then to */
/*   initializing themselves.  Then, calls the scheduler.  */
/*   Finally, jumps to the scheduler to start the system.  */
/* ------------------------------------------------------- */

void  main(void)
{
     Head = Current = NULL;        /* initialize pointers  */
     
     THREAD_CREATE(funct_1, 1);    /* initialize threads   */
     THREAD_CREATE(funct_2, 2);
     THREAD_CREATE(funct_3, 3);
     THREAD_CREATE(funct_4, 4);
     
     if (setjmp(MAIN) == 0)        /* initialize scheduler */   
          Scheduler();
     longjmp(SCHEDULER,1);         /* start scheduler      */
}
     
          
                                        