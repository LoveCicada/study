#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char * argv[])
{
    FILE *fp =NULL;
    char buf[20];
    fp = fopen("1.txt", "w+");
    if(NULL == fp)
    {
        perror("fopen");
        exit(-1);
    }
    memset(buf, 0, sizeof(buf));
    fwrite("standard_io", 1, 12, fp);
    fseek( fp, 0, SEEK_SET );
    fread(buf, 1, 12, fp);
    printf("%s\n", buf);
    fclose(fp);
    return 0;
}

/**
 * @brief result
 * 
 * ./bin/standard_io
 * standard_io
 * 
 */