#include<stdio.h>
#include<stdlib.h>

int* num;
int n;

int MAX(int a,int b) {
	if(a>b) 
    	return a;
    else
    	return b;
}

int MIN(int a,int b) {
	if(a<b) 
    	return a;
    else
    	return b;
}

int* maxmin(int x, int y)
{
    int* arr = (int*)malloc(2*sizeof(int));
    if(y-x<=1)
    {
        arr[0]=MAX(num[x],num[y]);
        arr[1]=MIN(num[x],num[y]);
        return arr;
    }
    else
    {
        int* arr2=maxmin(x,(x+y)/2);
        int* arr3=maxmin(((x+y)/2)+1,y);
        arr[0]=MAX(arr2[0],arr3[0]);
        arr[1]=MIN(arr2[1],arr3[1]);
        return arr;
    }
}

int main() {
    printf("Enter size of array : ");
    scanf("%d",&n);
    num=(int*)malloc(n*sizeof(int));
    srand(time(0);
    for(int i=0;i<n;i++) {
        num[i]=rand()%n;
    }
    int* ans =(int*)malloc(2*sizeof(int));
    ans=maxmin(0,n-1);
    printf("Max = %d\n Min = %d\n",ans[0],ans[1]);
    return 0;
}
