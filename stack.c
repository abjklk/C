#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stringstack[50];
int top = -1;

void push(char s)
{
    top++;
    stringstack[top]=s;
}

char pop(char s)
{
    char item = stringstack[top];
    top--;
   return item;
}

int main()
{
    char str[50];
    int i;
    printf("ENTER string");
    gets(str);
    for(i=0;i<strlen(str);i++)
        push(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i]=pop(str[i]);
    puts(str);
}
