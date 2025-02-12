#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* arr,n;
clock_t start, end;
double total_t;

char* filename="bubble.txt";

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


double bubble_sort() {
	int i,j;
	start=clock();
	for(i=0; i<n; i++) {
		for(j=0; j<n-i-1; j++) {
			if(*(arr + j) > *(arr + j+1)){
				swap((arr + j), (arr +j+1));
			}
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
	t=bubble_sort();
	printf("\nTime Complexity of %d is: %f\n", n,t);
	writefile("Array after bubble sort: ");
	return 0;
}
