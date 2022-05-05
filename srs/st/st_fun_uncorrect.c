#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <pthread.h>

#define MAX_COUNT 5

typedef struct PCB_NODE* PCB_ptr;
typedef struct PCB_NODE {
	jmp_buf Environment;
	int Name;
	PCB_ptr Next;
}PCB;


jmp_buf MAIN;
jmp_buf SCHEDULE;

PCB_ptr Head;
PCB_ptr Current;
PCB_ptr work;

void _thread_create(void (*pfn)(int), int name)
{
	if (setjmp(MAIN) == 0)
	{
		pfn(name);
	}
}

void _thread_init(int arg)
{
	work = (PCB_ptr)malloc(sizeof(PCB));
	work->Name = arg;
	if (Head == NULL) {
		Head = work;
	}
	else {
		Current->Next = work;
	}
	work->Next = Head;
	Current = work;
	if (setjmp(work->Environment) == 0) {
		longjmp(MAIN, 1);
	}
}

void _thread_yield(void* arg)
{
	if (setjmp(Current->Environment) == 0) {
		longjmp(SCHEDULE, 1);
	}
}

void funct_1(int name)
{
	int i;

	_thread_init(name);
	while (1)
	{
		for (i = 1; i <= MAX_COUNT; i++) {
			printf("%s executing \n", __func__);
		}
		_thread_yield(&name);
	}
}

void funct_2(int name)
{
	int i;

	_thread_init(name);
	while (1)
	{
		for (i = 1; i <= MAX_COUNT; i++) {
			printf("	%s executing \n", __func__);
		}
		_thread_yield(&name);
	}
}

void funct_3(int name)
{
	int i;

	_thread_init(name);
	while (1)
	{
		for (i = 1; i <= MAX_COUNT; i++) {
			printf("		%s executing \n", __func__);
		}
		_thread_yield(&name);
	}
}

void funct_4(int name)
{
	int i;

	_thread_init(name);
	while (1)
	{
		for (i = 1; i <= MAX_COUNT; i++) {
			printf("			%s executing \n", __func__);
		}
		_thread_yield(&name);
	}
}

void Scheduler()
{
	if (setjmp(SCHEDULE) == 0) {
		longjmp(MAIN, 1);
	}
	Current = Current->Next;
	longjmp(Current->Environment, 1);
}

int main(int argc, char* argv[])
{
	Head = Current = NULL;

	_thread_create(funct_1, 1);
	_thread_create(funct_2, 2);
	_thread_create(funct_3, 3);
	_thread_create(funct_4, 4);

	if (setjmp(MAIN) == 0) {
		Scheduler();
	}

	longjmp(SCHEDULE, 1);

	return 0;
}