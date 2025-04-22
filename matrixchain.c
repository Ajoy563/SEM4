//MatrixChain

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void PrintOptimalParens(int s[10][10], int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void MatrixChainOrder(int p[], int n)
{
    int m[10][10], s[10][10];
    int i, j, k, l, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (l = 2; l < n; l++)
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = (int)INFINITY;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }

    printf("Minimum number of multiplications is: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    PrintOptimalParens(s, 1, n - 1);
    printf("\n");
}

int main()
{
    int n, i;
    clock_t start, end;
    double t;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int *p = (int *)malloc((n + 1) * sizeof(int));

    printf("Enter dimensions of matrices (length %d): ", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]); 

    start = clock();
    MatrixChainOrder(p, n + 1);
    end = clock();

    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", t);

    return 0;
}