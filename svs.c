#include<stdio.h>
  
void damn(int n,int a[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int emp = a[j];
                a[j]=a[j+1];
                a[j+1]=emp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
}

int main()
{
    int num;
    printf("Enter number");
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    damn(num,arr);
}

