#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>

int num_dig(int a){
    int ct = 0;
    while(a>0){
        a/=10;
        ct++;
    }
    return ct;
}

void display(int a[]){
    int i;
    for(i=0;i<10;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    display(a);
    char b[4] = "BACD";
    printf("%s",b);
}