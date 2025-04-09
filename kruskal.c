#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct
{
    int u, v, w;
} Edge;

Edge edges[MAX];
int graph[MAX][MAX],parent[MAX], numVertices, numEdges;

int find(int i) 
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int u, int v)
{
    int setU,setV;
    setU = find(u);
    setV = find(v);
    if (setU != setV)
        parent[setV] = setU;
}

void sortEdges()
{
    int i, j;
    for (i = 0; i < numEdges - 1; i++)
    {
        for (j = 0; j < numEdges - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void printAdjacencyMatrix()
{
    int i, j;
    printf("\nAdjacency Matrix:\n   ");
    for (i = 0; i < numVertices; i++)
        printf("%3d", i);
    printf("\n");
    for (i = 0; i < numVertices; i++)
    {
        printf("%3d", i);
        for (j = 0; j < numVertices; j++)
            printf("%3d", graph[i][j]);
        printf("\n");
    }
}

void kruskalMST()
{
    int i, totalWeight = 0, u, v, w;
    printf("\nEdges in MST (using Kruskal's Algorithm):\n");
    for (i = 0; i < numVertices; i++)
        parent[i] = i;
    sortEdges();
    for (i = 0; i < numEdges; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (find(u) != find(v))
        {
            printf("%d -- %d (weight: %d)\n", u, v, w);
            totalWeight += w;
            unionSet(u, v);
        }
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

int main()
{
    clock_t start, end;
    int i, u, v, w;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    for (i = 0; i < numVertices; i++)// Initialize graph
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }
    printAdjacencyMatrix();
    start = clock();
    kruskalMST();
    end = clock();
    printf("CPU Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
