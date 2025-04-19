#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binary_search(int arr[], int lb, int ub, int x) {
	int mid;
	if(lb>ub)
		return -1;
	else {
		mid = lb + (ub - lb)/2;
		if(arr[mid]==x)
			return mid;
		else if(arr[mid] > x)
			return binary_search(arr,lb,mid,x );
		else
			return binary_search(arr,mid+1,ub,x );
	}
}

int main() {
	int n,i,item,idx;
	clock_t start, end;
	double t;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	printf("\nEnter elements: ");
	int* arr=(int*)calloc(n, sizeof(int));
	for(i=0; i<n; i++) {
		scanf("%d", (arr+i));
	}
	printf("\nEnter element to know the position: ");
	scanf("%d", &item);
	start=clock();
	idx=binary_search(arr, 0, n-1, item);
	end=clock();
	t=(double)(end-start)/CLOCKS_PER_SEC;
	if(idx==-1)
		printf("\nElement not found!");
	else
		printf("\nThe element %d found at %d\n",item,idx);
	printf("The CPU time is: %f\n", t);
	return 0;
}
		
	
