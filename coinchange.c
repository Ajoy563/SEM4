#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void coinchange(int inp[], int arr[], int n, int x) {
	for(int i=0; i<n; i++){
		while(inp[i]<=x) {
			x-=inp[i];
			arr[i]++;
		}
	}	
}

int main() {
	int i,n,x;
	clock_t s,e;
	printf("Enter the range of array: ");
	scanf("%d", &n);
	int* inp=(int*)malloc(n*sizeof(int));
	int* arr=(int*)malloc(n*sizeof(int));
	printf("\nEnter elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &inp[i]);
	for(i=0; i<n; i++)
		arr[i]=0;	
	printf("\nEnter the amount: ");
	scanf("%d", &x);
	s=clock();
	coinchange(inp,arr,n,x);
	e=clock();
	printf("\nSolution vector are: ");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	double t=(double)(e-s)/CLOCKS_PER_SEC;
	printf("\nThe CPU time is: %f\n",t);
	free(arr);
	free(inp);
	return 0;
}
