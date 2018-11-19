#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mp.h"
int main()
{
	int N,i;
	char ch1,ch2,ch3,p[15],cp;
	char pw[15]="AkshayGaurav";
	struct user NU;
	struct song s[2];
	FILE *fp1;
	printf("\n\n\n\n---------------------------------------------------------------------WELCOME TO MUSIC PLAYER-----------------------------------------------------------------------------\n\n\t\t\t\t\t\t\t\t\tGENERIC MUSIC PLAYER\n");
	printf("Press Enter Key to Start the Application:");
	scanf("%c",&ch1);
	if(ch1=='\n')
	{
		delay(5000);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    	for(i=0;i<10;i++)
	    {
		  printf("|-|-|-|-|-|\t");
		  delay(15000);
	    }
	    system("cls");
	    printf("\n\n\n\n\n\n\n\n\n\n\n1-NEW USER?\n2-ALREADY HAVE AN ACCOUNT?\n3-Administrators?\n");
	    printf("Enter your Choice:");
	    scanf("%c",&ch2);
	    scanf("%*c");
	    if(ch2=='1')
	    {
	    	system("cls");
	    	printf("\n\n\n\n\n\n---------WELCOME NEW USER----------\n\n\n\n\n------------------------------------------------------------------------------------\n");
	    	printf("Fill Up The Below Form And Create Your Account:\n\n");
	    	printf("Name:");
	    	gets(NU.name);
	    	printf("Age:");
	    	scanf("%d",&NU.age);
	    	printf("Mobile no:");
	    	scanf("%ld",&NU.m_no);
            scanf("%*c");
	    	printf("E-mail ID:");
	    	gets(NU.email);
	    	system("cls");
	    	printf("WELCOME\nUSER NAME:");
	    	puts(NU.name);
	    	
		}
		else if(ch2=='2')
        {
   	
        }
        else if(ch2=='3')
        {
   	     system("cls");
   	     printf("Enter the password:");
   	     gets(p);
   	     cp=strcmp(p,pw);
   	     if(cp==0)
   	        {
   		    system("cls");
   	        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWELCOME ADMINISTRATORS\n"); 
			printf("1-ADD SONGS TO DATABASE.\n2-RESPOND TO REQUESTS.\n3-REMOVE USERS.\n");
			scanf("%c",&ch3);
			scanf("%*c");
			if(ch3=='1')
			{
				readsong(&s[0]);
				displaysong(&s[0]);
				fopen("DB.txt","a");
				fwrite(s,sizeof(struct song),1,fp1);
				fclose(fp1);
			}	
	        }
        }
   }
   else
   {
   	system("cls");
   	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTHANK YOU FOR TRYING US OUT!!!!!\n");
   }
   
   
	
}

