#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INF 1000000

void printsolution(int **dist, int V, int d) {
	printf("\nD%d predecessor matrix:\n", d);
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			if(dist[i][j]==INF) {
				printf("%7s\t", "INF");
			}
			else {
				printf("%7d\t", dist[i][j]);
			}
			
		}
		printf("\n");
    }
}
void floydwarshall(int **graph, int V) {
	int **dist, i, j, k, d=0;
	dist=(int **)malloc(V*sizeof(int*));
	for(i=0; i<V; i++) 
		dist[i]=(int *)malloc(V*sizeof(int));
	for(i=0; i<V; i++) 
		for(j=0; j<V; j++) 
		dist[i][j]=graph[i][j];
	
	printsolution(dist, V, d);
	d++;
	for(k=0; k<V; k++){
		for(i=0; i<V; i++) {
			for(j=0; j<V; j++){
				if(dist[i][k] != INF && dist[k][j] != INF) {
					if(dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j]= dist[i][k] + dist[k][j];
				}
			}
		}
		printsolution(dist, V, d);
		d++;
	}
	for(i=0; i<V; i++)
		free(dist[i]);
	free(dist);
}
int main() {
	int V, i, j;
	clock_t s, e;
	double t;
	printf("Enter the Vertices: ");
	scanf("%d", &V);
	int **graph=(int **)malloc(V*sizeof(int*));
	for(i=0; i<V; i++)
		graph[i]=(int*)malloc(V* sizeof(int));
	
	printf("Enter the adjacency matrix:\n");
	for(i=0; i<V; i++) {
		for(j=0; j<V; j++) {
			scanf("%d", &graph[i][j]);
			if(graph[i][j] == 0 && i != j) {
				graph[i][j]=INF;
			}
		}
	}
	s=clock();
	floydwarshall(graph, V);
	e=clock();
	t=(double)(e-s)/CLOCKS_PER_SEC;
	printf("\nThe CPU time is:%f\n", t);
	for(i=0; i<V; i++)
		free(graph[i]);
	free(graph);
	return 0; 
}
