#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 

char n[1024];
sem_t len;

void * read1(void *a)
{
        while(1){
                printf("Enter a string");
                scanf("%s",n);
                sem_post(&len);
        }
}

void * write1(void *a)
{
        while(1){
                sem_wait(&len);
                printf("The string entered is : ");
                printf("==== %s\n",n);
        }

}

int main()
{
        int status;
        pthread_t tr, tw;

        pthread_create(&tr,NULL,read1,(void *)NULL);
        pthread_create(&tw,NULL,write1,(void *)NULL);

        pthread_join(tr,NULL);
        pthread_join(tw,NULL);
        return 0;
}

