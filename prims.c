//Prim's

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

struct Edge edge[MAX];
int graph[MAX][MAX];

int minKey(int key[], int mst[], int n)
{
    int min = (int)INFINITY, index = -1;

    for (int i = 0; i < n; i++)
        if (!mst[i] && key[i] < min)
        {
            min = key[i];
            index = i;
        }

    return index;
}


void printAdjMatrix(int n)
{
    printf("\nThe adjacency matrix: \n");
    for(int i=0; i<n; i++)
        printf("%3d ",i+1);
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%3d ", i+1);
        for(int j=0; j<n; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }
}

void PrimsMST(int n)
{
    int key[MAX], mst[MAX], parent[MAX], total=0;

    for (int i = 0; i < n; i++)
    {
        key[i] = (int)INFINITY;
        mst[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    printf("\nMinimum Spanning Tree:\n");
    printf("Edge\tWeight\n");

    for (int i = 0; i < n - 1; i++)
    {
        int u = minKey(key, mst, n);
        mst[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    for (int i = 1; i < n; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        total+= graph[i][parent[i]];
    }
    printf("\nThe total weight of MST is: %d\n", total);
}

int main()
{
    clock_t start, end;
    int n, m;
    double t;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter edges as (u v w):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        graph[edge[i].u][edge[i].v] = edge[i].w;
        graph[edge[i].v][edge[i].u] = edge[i].w;
    }
    
    printAdjMatrix(n);
    start = clock();
    PrimsMST(n);
    end = clock();

    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds\n", t);

    return 0;
}