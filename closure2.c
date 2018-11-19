#include <stdio.h>
#define MAX 10
//Algo 1
int main()
{
    int na,i,j,k;
	int mat[MAX][MAX];
	printf("Enter size of matrix\n");
    scanf("%d",&na);
    printf("\nEnter elements of matrix\n");

	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			scanf("%d",&mat[i][j]);
	}

    int a[MAX][MAX];
    for(i=0;i<na;i++)
    {
        for(j=0;j<na;j++)
            a[i][j]=mat[i][j];
    }

    int b[MAX][MAX];
    for(i=0;i<na;i++)
    {
        for(j=0;j<na;j++)
            b[i][j]=a[i][j];
    }

   for(i=2;i<na;i++)
   {
        for(i=0; i<na; ++i)
         for(j=0; j<na; ++j)
          for(k=0; k<na; ++k)
                a[i][j]+=a[i][k]*mat[k][j];

        for(i=0; i<na; ++i)
         for(j=0; j<na; ++j)
                b[i][j]=b[i][j] || a[i][j]; 
   }

    printf("transitive matrix is\n");
	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}

}