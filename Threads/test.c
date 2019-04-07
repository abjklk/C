#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mata[3][3];
int matb[3][3];
int matc[3][3];

void *threadfunc(void *arg)
{
    int s = (int)arg;
    int j;
    for (j = 0; j < 3; j++)
        matc[s][j] = mata[s][j] + matb[s][j];
    s++;
}

int main()
{
    int i, j;
    double k;
    double totaltime;
    clock_t start, end;
    start = clock();
    srand(time(NULL));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mata[i][j] = i + j * 6;
            matb[i][j] = i + j * 8;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d\t", mata[i][j]);
        printf("\n");
    }

    printf("\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d\t", matb[i][j]);
        printf("\n");
    }

    int step = 0;
    pthread_t thread[3];
    for (i = 0; i < 3; i++)
    {
        pthread_create(&thread[i], NULL, &threadfunc, (void *)step);
        step++;
    }
    for (i = 0; i < 3; i++)
        pthread_join(thread[i], NULL);

    printf("\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d\t", matc[i][j]);
        printf("\n");
    }
    // for (k = -10000; k < 1000000; k++)
    // {
    //     printf(" ");
    // }
    end = clock();
    totaltime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken %f", totaltime);
}
