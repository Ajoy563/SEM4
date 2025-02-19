#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
clock_t start,end;
double total_t;
int *arr,n;
void merge(int p, int q, int r) {
	int n1,n2,i=0,j=0,k;
	n1=q-p+1;
	n2=r-q;
	int* left=(int*)malloc((n1+2)*sizeof(int));
	int* right=(int*)malloc((n2+2)*sizeof(int));
	for(i=0;i<n1;i++) {
		left[i]=arr[p+i];
	}
	for(j=0; j<n2; j++) {
		right[j]=arr[q+j+1];
	}
	left[n1]=(int)INFINITY;
	right[n2]=(int)INFINITY;
	i=0;
	j=0;
	for(k=p;k<=r;k++){
		if(left[i]<=right[j]) {
			arr[k]=left[i];
			i++;
		}
		else {
			arr[k]=right[j];
			j++;
	    }
	}
}

void merge_sort(int p, int r) {
    int q;
    if (p<r) {
	q=(p+r)/2;
	merge_sort(p,q);
	merge_sort(q+1, r);
	merge(p,q,r);
    }
}

void insert() {
	int seed,i;
	srand(time(0));
	arr=(int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++) {
		arr[i]=rand()%n;
	}
}



int main() {
	int* arr,n,i;
	clock_t start,end;
	double t; 
	printf("Enter the range: ");
	scanf("%d",&n);
	insert();
	start=clock();
	merge_sort(0,n-1);
	end=clock();
	t=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nThe CPU time:%f\n",t);
	
    return 0;
}
