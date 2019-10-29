#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int i;
    int flag=0;
    char buf[100];
    char *tok;
    char service[500][20];
    char ports[500][10];
    char one[5],two[5];
    fp = fopen("/mnt/c/Windows/System32/drivers/etc/services","r");
    int ct=0;
    while ((fscanf(fp, "%[^\n]%*c", buf)) != EOF )
    {
        
        if(buf[0]!='#')
        {
            tok = strtok(buf,"                ");
            int i=0;
            while (tok!= NULL)
            {
                if(i==0)
                {
                    strcpy(service[ct],tok);
                }
                if(i==1)
                {
                    strcpy(ports[ct],tok);
                }
            
                tok = strtok(NULL,"                ");
                i++;
            }   
        }
        ct++;
    }
    fclose(fp);
    
    printf("Enter port number: ");
    scanf("%s",one);
    printf("Enter protocol: ");
    scanf("%s",two);
    strcat(one,"/");
    strcpy(buf,one);
    strcat(buf,two);
    
    for(i=0;i<ct;i++)
    {
        if(strcmp(buf,ports[i])==0)
        {
            printf("Service Found: %s",service[i]);
            flag=1;
        }
    }
    if(!flag)
        printf("NOT FOUND");
}