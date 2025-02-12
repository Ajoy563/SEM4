#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* arr,n;
clock_t start, end;
double total_t;

char* filename="insertion.txt";


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


double insertion_sort() {
	int i,j,temp;
	start=clock();
	for(i=1; i<n; i++) {
		temp=*(arr + i);
		j=i-1;
		while(j>=0 && *(arr + j) > temp) {
			*(arr+j+1)=*(arr+j);
			j=j-1;
		}
		*(arr+j+1)=temp;
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
	t=insertion_sort();
	printf("\nTime Complexity of %d is: %f\n", n,t);
	writefile("Array after Insertion sort: ");
	return 0;
}
