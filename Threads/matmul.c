#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// maximum size of matrix
#define MAX 4

// maximum number of threads
#define MAX_THREAD 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void *multi(void *arg)
{
    int i, j, k;
    int core = step_i++;
    // Each thread computes 1/4th of matrix multiplication
    for (i = core * MAX / 4; i < (core + 1) * MAX / 4; i++)
        for (j = 0; j < MAX; j++)
            for (k = 0; k < MAX; k++)
                matC[i][j] += matA[i][k] * matB[k][j];
}

// Driver Code
int main()
{
    int i;
    int j;
    // Generating random values in matA and matB
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }

    // Displaying matA
    // cout << endl     << "Matrix A" << endl;
    printf("Matrix A \n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            printf("%d\t", matA[i][j]);
        printf("\n");
    }

    // Displaying matB
    printf("Matrix B \n");

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            printf("%d\t", matB[i][j]);
        printf("\n");
    }

    // declaring four threads
    pthread_t threads[MAX_THREAD];

    // Creating four threads, each evaluating its own part
    for (i = 0; i < MAX_THREAD; i++)
    {
        int *p;
        pthread_create(&threads[i], NULL, multi, (void *)(p));
    }

    // joining and waiting for all threads to complete
    for (i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);

    // Displaying the result matrix
    printf("\nMultiplication of A and B\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            printf("%d\t", matC[i][j]);
        printf("\n");
    }
    return 0;
}
