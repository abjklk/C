#include <stdio.h>
#include <string.h>

int main(){
    int n,i;
    scanf("%d",&n);
    int os=0;
    int es=0;
    for(i=0;i<n;i++){
        int money,hno;
        char owner[30];
        scanf("%d %d %s",&money,&hno,&owner);
        if(i&1){
            os+=money;
        }else{
            es+=money;
        }
    }
    if (os>es){
        printf("%d",os); 
    }else{
        printf("%d",es); 
    }
    return 0;
}