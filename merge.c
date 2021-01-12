#include<stdlib.h>
#include<stdio.h>

void mergeSort(int arr[],int n){
    if(n>1){
        int i,j,k;
        int mid = n/2;
        int l[mid];
        int r[n-mid];
        for(i=0; i<mid;i++){
            l[i]=arr[i];
        }
        for(i=mid; i<n;i++){
            r[i-mid]=arr[i];
        }
        mergeSort(l,mid);
        mergeSort(r,n-mid);
        i = j = k = 0;
        while(i<mid && j<n-mid){
            if (l[i]<r[j]){
                arr[k]=l[i];
                i++;
            }else{
                arr[k]=r[j];
                j++;
            }
            k++;
        }
        while(i<mid){
            arr[k]=l[i];
            i++;
            k++;
        }
        while(j<n-mid){
            arr[k]=r[j];
            j++;
            k++;
        }
    }
}


int main()
{
    int arr[] = {5,4,3,2,1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,arr_size);

    printf("\nSorted array is \n");
    for(int i=0;i<arr_size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
