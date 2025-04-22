#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n;
int left(int i){
    return 2*i;
}
int right(int i){
    return (2*i)+1;
}

void max_heapify(int arr[], int i) {
    int largest,temp;
    int l=left(i);
    int r=right(i);
    if(l<=n && arr[l] > arr[i])
        largest=l;
    else 
        largest=i;
    if(r<=n && arr[r]>arr[largest])
        largest=r;
    if(largest != i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        max_heapify(arr, largest);
    }
}

void build_max_heap(int arr[], int n) {
    for(int i=n/2 -1; i>=0; i--){
        max_heapify(arr,i);
    }
}

void heapsort(int* arr, int n){
    build_max_heap(arr,n);
    for(int i=n-1; i>=1; i--) {
        int t=arr[i];
        arr[i]=arr[0];
        arr[0]=t;
        max_heapify(arr,1);
    }
}

int main() {
    int i;
    clock_t s,e;
    double t;
    printf("Enter the range of array: ");
    scanf("%d", &n);
    int* arr=(int*)calloc(n, sizeof(int));
    printf("\nEnter elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", (arr+i));
    }
    for(i=0; i<n; i++) {
        printf("%d ", *(arr+i));
    }
    s=clock();
    heapsort(arr,n);
    e=clock();
    t=(double)(e-s)/CLOCKS_PER_SEC;
    printf("\nThe CPU time is: %f\n", t);
    return 0;
}