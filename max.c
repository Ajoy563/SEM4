#include<stdio.h>
#include<stdlib.h>

int* number;
int n;

int MAX(int a,int b)
{
    return a>b?a:b;
}
int MIN(int a,int b)
{
    return a<b?a:b;
}

int* maxmin(int x, int y)
{
    int* arr = (int*)malloc(2*sizeof(int));
    if(y-x<=1)
    {
        arr[0]=MAX(number[x],number[y]);
        arr[1]=MIN(number[x],number[y]);
        return arr;
    }
    else
    {
        int* arr2=maxmin(x,(x+y)/2);
        int max1=arr2[0];
        int min1=arr2[1];
        int* arr3=maxmin(((x+y)/2)+1,y);
        int max2=arr3[0];
        int min2=arr3[1];
        arr[0]=MAX(max1,max2);
        arr[1]=MIN(min1,min2);
        return arr;
    }
}

int main()
{
    printf("Enter size of array : ");
    scanf("%d",&n);
    number=(int*)malloc(n*sizeof(int));
    if(number==NULL)
    {
        printf("Error creating array\n");
        return 0;
    }
    printf("Enter elements : ");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    int* ans =(int*)malloc(2*sizeof(int));
    ans=maxmin(0,n-1);
    printf("Max = %d min = %d\n",ans[0],ans[1]);
    return 0;
}