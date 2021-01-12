#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 9
#define max(a,b) (a>b)?printf("%d\n",a):printf("%d\n",b)
int stringstack[MAX];
int top = -1;

void push(int data)
{
    if(top==MAX-1){
        printf("OVERFLOW");
        return;
    }
    top++;
    stringstack[top]=data;
}

int pop()
{
    if(top==-1){
        printf("Underflow");
        return -1;
    }
    int item = stringstack[top];
    top--;
   return item;
}

int peek(){
    if(top==-1){
        return -1;
    }
    return stringstack[top];
}

int main()
{
    int i;
    printf("ENTER nums\n");
    // for(i=0;i<10;i++){
    //     int d;
    //     scanf("%d",&d);
    //     push(d);
    // }
    char d = 10;
    d = ~d;
    printf("%d\n",d);
    max(15,10);
    for(i=0;i<10;i++){
        printf("%d ",stringstack[i]);
    }
    for(i=0;i<10;i++){
        // push();
    }
    pop();
}
