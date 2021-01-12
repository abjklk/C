#include <stdio.h>

float CumulativeDiscount(float arr[],int n){
	int i;
	float d = 100;
	for(i=0;i<n;i++){
		d = d *((100-arr[i])/100);
	}
	return(100.0-d);
}

int main(){
	float arr[3];
	arr[0]=10.0;
	arr[1]=20.0;
	arr[2]=30.0;
	int n = 3;
	float result = CumulativeDiscount(arr,n);
	printf("%f",result);
}
