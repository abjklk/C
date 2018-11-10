#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void sort(int a[MAX],int n)
{
	 int i, j, temp;
        for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j)
            {
                if (a[i] > a[j]) 
                {
                    temp =  a[i];
                    a[i] = a[j];
                    a[j] = temp;
 
                }
			}
        }
}
int deleterep(int a[MAX],int n)//delete repeated elements
{
	int i,j,k;        
    for(i=0;i<n;++i)
        for(j=i+1;j<n;)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<n-1;++k)
                    a[k]=a[k+1];   
                --n;
            }
            else
                ++j;
        }
   // printf("\n");
    // printf("Elements of set are :");
    // for(i=0;i<n;++i)
    //     printf("%d ",a[i]);
	return n;
}
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
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		mat[i][j]=0;
	}
	printf("How many elements are in set?\n");
    scanf("%d",&na);
    printf("\nEnter elements of set A\n");
	 for(i=0;i<na;++i)
        scanf("%d",&a[i]);
	sort(a,na);
	deleterep(a,na);
	na=deleterep(a,na);
    printf("Elements of set are :");
    for(i=0;i<na;++i)
        printf("%d ",a[i]);
	printf("\nEnter the number of ordered pairs :\n");
	scanf("%d",&no);
	if(no > (na*na))
	{
		printf("\nToo many ordered pairs!\n");
		exit(0);
	}
	printf("\nEnter the ordered pairs :\n");
	for(i=0;i<no;i++)
	{
		scanf("%d,%d",&d,&c);
		mat[d][c]=1;
	}
	
	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			mat[i][j]=mat[a[i]][a[j]];	
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
	//printf("transitive matrix is:");
	// for(i=0;i<na;i++)
	// {
	// 	for(j=0;j<na;j++)
	// 		printf("%d ",mat2[i][j]);
	// 	printf("\n");
	// }

	printf("Transitive closure is\nRt = { ");
	for(i=0;i<na;i++)
	{
		for(j=0;j<na;j++)
			if(mat[i][j]==1 && mat[a[i]][a[j]]!=1 && i!=j) 
			{
				printf("(%d,%d),",a[i],a[j]);
			}
	}
	printf("}");
}
