#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hi{
    int data;
    char a[10];
};

int main()
{
    FILE *fp;
    struct hi in;
    fp=fopen("a.txt","r");
    while(fread(&in, sizeof(struct hi), 1, fp))
        printf("id= %d name = %s",in.data,in.a);
    fclose(fp);
}