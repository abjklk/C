#include <stdio.h>
#include <stdlib.h>

int visited[10];


void dfs(int m[10][10], int v, int source)
{
    /// Temporary variable
    int i;


    /// Mark the source vertex as visited
    visited[source] = 1;

    for(i=0; i<v; i++)
    {
        if(m[source][i] == 1 && visited[i] == 0)
        {
            printf("%d\t", i);
            dfs(m, v, i);
        }
    }
}

int main()
{
    int i;
    int source = 4;
    int v = 5;
    /// Set all the vertices to not visited
    for (i= 0; i < v; i ++)
        visited[i] = 0;
    int m[10][10] =   {
                        {0, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1},
                        {1, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0}
                    };
    /// Call the dfs traversal
    printf("The DFS Traversal is\n");
    printf("%d\t", source);
    dfs(m, v, source);
}
