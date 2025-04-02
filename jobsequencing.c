#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int job(int n, int jobid[], int p[], int d[]) {
	int i,j,total=0,maxdead;
	maxdead=d[0];
	for(i=1; i<=n; i++) {
		if(maxdead<d[i]){
			maxdead=d[i];
		}
	}
	int job[maxdead];
	for(i=0; i<maxdead; i++) {
		job[i]=-1;
	}
	for(i=0; i<n; i++) {
		for(j=d[i]-1; j>=0; j--) {
			if(job[j]==-1) {
				job[j]=jobid[i];
				total+=p[i];
				break;
			}
		}
	}
	printf("\nSolution vector is: {");
	for(i=0; i<maxdead ; i++) {
		if(job[i]!=-1)
			 printf("J%d ",job[i]);
	}
	printf("}\n");
	return total;
}
int main() {
	int i,n,r;
	clock_t s,e;
	double t;
	printf("Enter no. of jobs: ");
	scanf("%d", &n);
	int* p=(int*)malloc(n*sizeof(int));
	int* d=(int*)malloc(n*sizeof(int));
	int* jobid=(int*)malloc(n*sizeof(int));
	printf("\nEnter the profits in decreasing order!");
	for(i=0; i<n; i++){
		printf("\nEnter Profit and Deadline of job%d: ", i+1);
		jobid[i]=i+1;
		scanf("%d%d",&p[i], &d[i]);
	}
	s=clock();
	r=job(n,jobid,p,d);
	e=clock();
	t=(double)(e-s)/CLOCKS_PER_SEC;
	printf("\nTotal Profit is: %d", r);
	printf("\nCPU time is: %f", t);
	return 0;
}
