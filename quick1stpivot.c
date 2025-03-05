#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* a, n;

int partition(int p, int r) {
    int x, i, j, temp;
    x=a[p];
    i=p;
    for (j=p+1; j<=r; j++) {  
        if (a[j]<=x) {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i];
    a[i]=a[p];
    a[p]=temp;
    return i; 
}

void quicksort(int p, int r) {
    int q;
    if (p<r) {
        q=partition(p,r);  
        quicksort(p,q-1);   
        quicksort(q+1,r);   
    }
}

void insert() {
    int seed, i;
    srand(time(0));
    a=(int*)malloc(n * sizeof(int));
    for (i=0; i<n; i++) {
        a[i]=rand() % n;
    }
}

int main() {
    clock_t start, end;
    double t;
    printf("Enter the range: ");
    scanf("%d", &n);
    insert();
    start=clock();
    quicksort(0, n-1);  
    end=clock();
    t=(double)(end-start) / CLOCKS_PER_SEC;  
    printf("\nThe CPU time: %f\n", t);
    free(a);  
    return 0;
}

