/**
 * @file setjmp_longjmp2.c
 * @author loveCicada (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void test_setjmp_longjmp()
{
	printf("%s <---- here\n", __func__);
	longjmp(buf, 2);
	printf("you will never see it.\n");
}

int main(int argc, char* argv[])
{
	int nRet = 0;

	//! record
	nRet = setjmp(buf);
	printf("nRet = %d\n", nRet);
	if (0 == nRet) {
		printf("i will enter test_setjmp_longjmp--->\n");
		test_setjmp_longjmp();
	}
	else {
		printf("back to main.\n");
	}

	return 0;
}