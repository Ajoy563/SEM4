//StrassenMatrix

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct array2d
{
    int **arr;
    int rows;
    int cols;
} Matrix;

Matrix createMatrix(int rows, int cols)
{
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        mat.arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

void freeMatrix(Matrix mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        free(mat.arr[i]);
    }
    free(mat.arr);
}

void printMatrix(Matrix mat, const char *matname)
{
    printf("%s:\n", matname);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            printf("%d\t", mat.arr[i][j]);
        }
        printf("\n");
    }
}

Matrix add(Matrix a, Matrix b)
{
    int n = a.rows;
    Matrix c = createMatrix(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }
    return c;
}

Matrix sub(Matrix a, Matrix b)
{
    int n = a.rows;
    Matrix c = createMatrix(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.arr[i][j] = a.arr[i][j] - b.arr[i][j];
        }
    }
    return c;
}

Matrix multiply(Matrix a, Matrix b)
{
    int n = a.rows;
    if (n == 1)
    {
        Matrix c = createMatrix(1, 1);
        c.arr[0][0] = a.arr[0][0] * b.arr[0][0];
        return c;
    }

    int m = n / 2;
    Matrix a11 = createMatrix(m, m);
    Matrix a12 = createMatrix(m, m);
    Matrix a21 = createMatrix(m, m);
    Matrix a22 = createMatrix(m, m);

    Matrix b11 = createMatrix(m, m);
    Matrix b12 = createMatrix(m, m);
    Matrix b21 = createMatrix(m, m);
    Matrix b22 = createMatrix(m, m);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a11.arr[i][j] = a.arr[i][j];
            a12.arr[i][j] = a.arr[i][j + m];
            a21.arr[i][j] = a.arr[i + m][j];
            a22.arr[i][j] = a.arr[i + m][j + m];

            b11.arr[i][j] = b.arr[i][j];
            b12.arr[i][j] = b.arr[i][j + m];
            b21.arr[i][j] = b.arr[i + m][j];
            b22.arr[i][j] = b.arr[i + m][j + m];
        }
    }

    Matrix s1 = sub(b12, b22);
    Matrix s2 = add(a11, a12);
    Matrix s3 = add(a21, a22);
    Matrix s4 = sub(b21, b11);
    Matrix s5 = add(a11, a22);
    Matrix s6 = add(b11, b22);
    Matrix s7 = sub(a12, a22);
    Matrix s8 = add(b21, b22);
    Matrix s9 = sub(a11, a21);
    Matrix s10 = add(b11, b12);

    Matrix p1 = multiply(a11, s1);
    Matrix p2 = multiply(s2, b22);
    Matrix p3 = multiply(s3, b11);
    Matrix p4 = multiply(a22, s4);
    Matrix p5 = multiply(s5, s6);
    Matrix p6 = multiply(s7, s8);
    Matrix p7 = multiply(s9, s10);

    Matrix c11 = add(sub(add(p5, p4), p2), p6);
    Matrix c12 = add(p1, p2);
    Matrix c21 = add(p3, p4);
    Matrix c22 = sub(sub(add(p5, p1), p3), p7);

    Matrix c = createMatrix(n, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c.arr[i][j] = c11.arr[i][j];
            c.arr[i][j + m] = c12.arr[i][j];
            c.arr[i + m][j] = c21.arr[i][j];
            c.arr[i + m][j + m] = c22.arr[i][j];
        }
    }

    return c;
}

int main()
{
    int n;
    printf("Enter matrix size (power of 2): ");
    scanf("%d", &n);

    if (n > 0 && (n & (n - 1)) == 0)
    {

        Matrix mat1 = createMatrix(n, n);
        Matrix mat2 = createMatrix(n, n);

        printf("Enter elements for 1st matrix:\n");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mat1.arr[i][j]);

        printf("Enter elements for 2nd matrix:\n");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mat2.arr[i][j]);

        clock_t start = clock();
        Matrix mat3 = multiply(mat1, mat2);
        clock_t end = clock();

        printMatrix(mat3, "Resultant Matrix");

        printf("CPU TIME: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        freeMatrix(mat1);
        freeMatrix(mat2);
        freeMatrix(mat3);
    }
    else
    {
        printf("Invalid Matrix Size");
    }

    return 0;
}