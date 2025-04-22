//Fractional knapsack

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortByRatio(int n, int profit[], int weight[], double ratio[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(&ratio[j], &ratio[j + 1]);
                swapInt(&profit[j], &profit[j + 1]);
                swapInt(&weight[j], &weight[j + 1]);
            }
        }
    }
}

void fractionalKnapsack(int n, int capacity, int profit[], int weight[])
{
    double *ratio = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));
    double totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)profit[i] / weight[i];
        x[i] = 0.0;
    }

    sortByRatio(n, profit, weight, ratio);
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= remainingCapacity)
        {
            x[i] = 1.0;
            totalProfit += profit[i];
            remainingCapacity -= weight[i];
        }
        else
        {
            x[i] = (double)remainingCapacity / weight[i];
            totalProfit += x[i] * profit[i];
            break;
        }
    }

    printf("Solution vector (fractions of items taken): ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", x[i]);
    }
    printf("\n");
    printf("Total Profit: %.2f\n", totalProfit);

    free(ratio);
    free(x);
}

int main()
{
    int n, capacity;
    clock_t start, end;
    double t;

    scanf("%d", &n);
    int *profit = (int *)malloc(n * sizeof(int));
    int *weight = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &profit[i], &weight[i]);
    }

    scanf("%d", &capacity);

    start = clock();
    fractionalKnapsack(n, capacity, profit, weight);
    end = clock();

    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", t);

    free(profit);
    free(weight);

    return 0;
}