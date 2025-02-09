#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* arr,n;
clock_t start,end;
double total_t;

char* filename="output.txt";

void Writefile(char* heading) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }
    fprintf(file,"\n%s", heading);
    for(int i=0; i<n; i++) {
        fprintf(file, "%d ", *(arr + i));
    }
    fprintf(file, "\n");
    fclose(file);
}

void Readfile() {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }
    else {
        char c;
        while((c=fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
}

void delete_file() {
    if (remove("output.txt") == 0) 
        printf("\nTHANK YOU.");
}


void insert() {
    int i,seed;
    printf("\nEnter the range of numbers(10 to 1000000): ");
    scanf("%d",&n);
    printf("\nSeed number used to seed the random-number generator");
    printf("\nEnter seed: ");
    scanf("%d",&seed);
    srand(seed);
    arr=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        *(arr + i) = rand()%n;
    }
    Writefile("Original Array: ");
}

void swap(int* a, int* b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

double bubble_sort() {
    int i,j;
    start=clock();
    for(i=0; i<n; i++){
        int flag=0;
        for(j=0; j<n-i-1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                flag=1;
                swap((arr + j),(arr + j + 1));

            }
        }
        if (flag==0) {
            break;
        }
    }
    end=clock();
    total_t=(double)(end-start)/CLOCKS_PER_SEC;
    Writefile("After Bubble Sort: ");
    return total_t;
}

double selection_sort() {
    int i,j,min_idx,temp,flag;
    start=clock();
    for(i=0; i<n; i++) {
        min_idx=i;
        flag=0;
        for(j=i+1; j<n; j++){
            if(*(arr + min_idx) > *(arr + j)) {
                min_idx=j;
                flag=1;
            }
        }
        if(flag==1) {
            swap((arr + min_idx),(arr + i));
        }
    }
    end=clock();
    total_t=(double)(end-start)/CLOCKS_PER_SEC;
    Writefile("After Selection Sort: ");
    return total_t;
}

double insertion_sort() {
    int i,j,temp;
    start=clock();
    for(i=1; i<n; i++) {
        temp = *(arr + i);
        j=i-1;
        while(j>=0 && *(arr + j)>temp){
            *(arr + j + 1) = *(arr + j);
            j=j-1;
        }
        *(arr + j + 1) = temp;
    }
    end=clock();
    total_t=(double)(end-start)/CLOCKS_PER_SEC;
    Writefile("After Insertion Sort: ");
    return total_t;
}

int main() {
    int c,n;
    double t;
    while(1){
        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Read File\n5. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d",&c);
        switch(c) {
            case 1:
                insert();
                t=bubble_sort();
                printf("\nOutput will be written to output.txt");
                printf("\nTime Complexity: %f\n", t);
                break;
            case 2:
                insert();
                printf("\nOriginal Array: ");
                Readfile();
                printf("\nAfter Selection Sort: ");
                t=selection_sort();
                printf("\nTime Complexity: %f\n", t);
                break;
            case 3:
                insert();
                printf("\nOriginal Array: ");
                Readfile();
                printf("\nAfter Insertion Sort: ");
                t=insertion_sort();
                printf("\nTime Complexity: %f\n", t);
                break;
                
            case 4: 
                Readfile();
                break;
            case 5:
                delete_file();
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;

}