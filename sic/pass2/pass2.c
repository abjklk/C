#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

int stringthex(char z[4])
{
    z=strrev(z);
    int k=0,hex=0;
    while(z[k]!='\0')
    {
        hex+=(int)(z[k]-48)*(pow(16,k));
        k++;
    }
    z=strrev(z);
    return hex;
}

int main()
{
    FILE *fp1;
    char buffer[1000];
    char array[100][100];
    char col[100][100][100];
    int i=0;
    int q=0;

    //Reading from file to buffer
    fp1=fopen("interm.txt","r");
    
    while((fscanf(fp1,"%[^\n]%*c",buffer))!=EOF)
    {
        strcpy(array[q],buffer);
        // printf("%s\n",buffer);
        q++;
    }
    fclose(fp1);

    int x=0;
    int startaddress=0;
    int lines=q,j=0;
    //Getting how many words in each line
    int linecount[q],count=0;
    for(i=0;i<lines;i++)
    {
        count=0;
        for(j=0;array[i][j]!='\0';j++)
        {
            if(array[i][j]=='\t')
                count++;
        }
        linecount[i]=count;
        // printf("linecount %d\n",linecount[i]);
    }

    //Putting them into 3dimensional array of characters
    int y=0;
    for(i=0;i<lines;i++)
    {
        // if(linecount[i]==2)
        //     y=1;
        // else
        //     y=2;

        char *token=strtok(array[i],"\t");
        while(token!=NULL)
        {
            strcpy(col[y][i],token);
            printf("Y: %d i: %d %s\n",y,i,col[y][i]);
            y++;
            token=strtok(NULL,"\t");
        }
    }
    
    if(strcmp(col[2][0],"START")==0)
    {
        x=stringthex(col[3][0]);
        printf("%x",x);
        startaddress=stringthex(col[3][0]);
        // sprintf(col[0][0], "%04x", x);
        // sprintf(col[0][1], "%04x", x);
    }
    printf("Starting address is: %x\n",startaddress);
}