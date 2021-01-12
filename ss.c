#include <stdio.h>

int NumberOfCarries(int num1, int num2);
int main(){
    int num1=23;
    int num2=563;
    int result = NumberOfCarries(num1,num2);
    printf("%d",result);
    return 0;
}

int NumberOfCarries(int num1, int num2){
    int ctr = 0;
    int i;
    if(num1 == 0 && num2 == 0)
        return 0;
    int z = 0;
    for(i=0;i<10;i++){
      z = num1%10 + num2%10 + z;
      if (z > 9){
        z = 1;
      }
      else{
        z = 0;
      }
      ctr += z;
      num1 =num1/10;
      num2 = num2/10;
    }
    return ctr;
}