
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define exit_if(r, ...)                                                                          \
    if (r) {                                                                                     \
        printf(__VA_ARGS__);                                                                     \
        printf("\t%s:%d error no: %d error msg %s\n", __FILE__, __LINE__, errno, strerror(errno)); \
        exit(1);                                                                                 \
    }

void test()
{
    exit_if(1, "TEST");
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}

/**
 * @brief result
 * TEST    test-macro.c:16 error no: 0 error msg Success
 */