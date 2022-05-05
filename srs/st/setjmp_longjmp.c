
#include <setjmp.h>
#include <stdio.h>

jmp_buf buf;

void test_setjmp_longjmp(void)
{
    longjmp(buf ,1);
    printf("You will never see this, because i was longjmp.\n");
}

int main(int argc, char* argv[])
{
    if(setjmp(buf)){
        printf("start\n");
    }else{
        test_setjmp_longjmp();
    }

    printf("end\n");
    return 0;
}