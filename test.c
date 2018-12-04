#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
 char str[20],c=' ';
 int i = 0;
 printf("enter pswd");
 while(i<=9)
 {
     str[i]=getch();
     c=str[i];
     if(c==13)break;
     else printf("*");
     i++;
 }  
 str[i]='\0';
 i=0;


}