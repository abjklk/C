#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//Algo 1
int main()
{
    int na,i,j,k,p,ch;
	int mat[MAX][MAX];

    while(1)
    {
	printf("Enter size of matrix\n");
    scanf("%d",&na);
    printf("\nEnter elements of matrix\n");

    //Input
	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
		{
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0 && mat[i][j]!=1)
            {
                printf("invalid input\n");
                exit(0);
            }
        }
	}

    int a[MAX][MAX];
    int b[MAX][MAX];
    //Assigning A & B
    for(i=0;i<na;i++)
    {
        for(j=0;j<na;j++)
        {
            a[i][j]=mat[i][j];
            b[i][j]=a[i][j];
        }
    }
    //Algorithm
   for(p=2;p<na;p++)
   {
        for(i=0; i<na; ++i)
         for(j=0; j<na; ++j)
          for(k=0; k<na; ++k)
                a[i][j]+=b[i][k]*mat[k][j];

        for(i=0; i<na; ++i)
         for(j=0; j<na; ++j)
                b[i][j]= b[i][j] || a[i][j]; 
   }

    printf("transitive matrix is\n");
	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}

    printf("Do you want to enter another matrix?\n1.yes\n2.no");
    scanf("%d",&ch);
    if(ch==2)
        exit(0);
    
    }

}