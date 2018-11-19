#include <stdio.h>
#include <stdlib.h>
struct song
{
    char song_name[10];
	char artist[10];
	char film[10];
	int yor;	
};
struct user
{
    char name[10];
	int age;
	char email[15];
	long int m_no;	
};
void delay(int N)
{
	int c,d;
    for (c = 1; c <=N; c++)
    {
       for (d = 1; d <=N; d++)
       {
	   }
    }	
}
void readsong(struct song *s)
{
	printf("Enter the Song Name:");
	gets(s->song_name);
	printf("Enter Artist Name:");
	gets(s->artist);
	printf("Enter Movie Name:");
	gets(s->film);
	printf("Enter year of release of the movie:");
	scanf("%d",&s->yor);	
}
void displaysong(struct song *s)
{
	printf("Song Name:");
	puts(s->song_name);
	printf("Artist Name:");
	puts(s->artist);
	printf("Movie Name:");
	puts(s->film);
	printf("Year of rlease:%d\n",s->yor);
}
