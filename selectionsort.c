#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* arr,n;
clock_t start, end;
double total_t;

char* filename="selection.txt";

void swap(int *a, int *b) {
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void writefile(char* heading) {
	FILE* file=fopen(filename, "a");
	if(file==NULL) {
		printf("Unable to open!");
	}
	fprintf(file, "\n%s", heading);
	for(int i=0; i<n; i++) {
		fprintf(file, "%d ", *(arr+i));
	}
	fclose(file);
		
}


double selection_sort() {
	int i,j,min_idx,flag;
	start=clock();
	for(i=0; i<n; i++) {
		min_idx=i;
		flag=0;
		for(j=i+1; j<n; j++) {
			if(*(arr + j) < *(arr + min_idx)){
				min_idx=j;
				flag=1;
			}
		}
		if(flag==1) {
			swap((arr + min_idx), (arr + i));
		}
	}	
	end=clock();
	total_t=(double)(end-start)/CLOCKS_PER_SEC;
	return total_t;
}

void insert() {
	int seed,i;
	srand(time(0));
	arr=(int*)calloc(n,sizeof(int));
	for(i=0; i<n; i++) {
		*(arr+i)=rand()%n;
	}
	writefile("Original Array: ");
}

int main() {
	double t;
	printf("\nEnter the range of Numbers(10 to 1000000): ");
	scanf("%d",&n);
	insert();
	t=selection_sort();
	printf("\nTime Complexity of %d is: %f\n", n,t);
	writefile("Array after Selection sort: ");
	return 0;
}
