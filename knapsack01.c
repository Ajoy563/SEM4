#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int a, int b) {
	return a > b ? a : b;
}

void knapsack01(int n, int m, int p[], int w[]) {
	int i,j,t[n+1][m+1], total;
	for(i=0; i<=m; i++) { 
		t[0][i]=0;
	}
	for(i=0; i<=n; i++) {
		t[i][0]=0;
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=m; j++) {
			if(j-w[i-1]>=0) {
				total=max(t[i-1][j], p[i-1] + t[i-1][j-w[i-1]]);
				t[i][j]=total;
			}
			else {
				total=t[i-1][j];
				t[i][j]=total;
			}
		}
	}
	printf("\n0/1 Knapsack:\n");
	for(i=0; i<=n; i++) {
		for(j=0; j<=m; j++) {
			printf("%d\t", t[i][j]);
		}
		printf("\n");
	}
	printf("\nTotal Profit is: %d", t[n][m]);
	
	int rem = m, sol[n];
    for(i = n; i > 0; i--) {
        if(t[i][rem] != t[i-1][rem]) {
            sol[i-1]=1;
            rem-= w[i-1];
        }
        else {
        	sol[i-1]=0;
    	}
    }
    printf("\nthe solution vector is:{");
    for(i=0; i<n; i++) {
    	printf("%d ", sol[i]);
 	}
    printf("}\n");
}

int main() {
	int i,n,m,r;
	clock_t s,e;
	double t;
	printf("Enter no. of objects: ");
	scanf("%d", &n);
	printf("Enter capacity of the bag: ");
	scanf("%d", &m);
	int* p=(int*)malloc(n*sizeof(int));
	int* w=(int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++){
		printf("\nEnter Profit and Weight of knapsack%d: ", i+1);
		scanf("%d%d",&p[i], &w[i]);
	}
	s=clock();
	knapsack01(n,m,p,w);
	e=clock();
	t=(double)(e-s)/CLOCKS_PER_SEC;
	printf("\nCPU time is: %f\n", t);
	return 0;
}
