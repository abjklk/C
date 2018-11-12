#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int max(int a,int b)
	{  
		if(a>b)
 		 return(a);
		else
 		 return(b);
	}
int main()
{
	//set A
	int na,no,i,d,c,j,k;
	int a[MAX],mat[MAX][MAX];
	printf("Enter size of matrix\n");
    scanf("%d",&na);
    printf("\nEnter elements of matrix\n");

	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			scanf("%d",&mat[i][j]);
	}
	printf("matrix is\n");
	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	
	for(k=0;k<na;k++) //Warshall's Algorithm used. Why? coz efficient.
 	 for(i=0;i<na;i++)
  	  for(j=0;j<na;j++)
  		  mat[i][j]=max(mat[i][j],mat[i][k]&&mat[k][j]);
	printf("transitive matrix is:\n");
	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}
