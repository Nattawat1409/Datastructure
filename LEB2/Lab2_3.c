#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

double sum(double *arr, int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}

double difference(double *arr, int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s -= arr[i];
    }
    return s;
}

int main()
{
    double *arr1 = (double*)malloc(MAX * sizeof(double));
    for (int i = 0; i < MAX; i++)
    {
        arr1[i] = i + 1;
    }
    double *arr2 = (double*)calloc(MAX,sizeof(double));
    for (int i = 0; i < MAX; i++)
    {
        arr2[i] = i + 1;
    }
    double s = sum(arr1, MAX);
    double m = difference(arr2, MAX);
    printf("%.0lf \n", s);
    printf("%.0lf \n", m);

    free(arr1);
    free(arr2);
    return 0;
}

// using malloc at arr1 and using calloc at arr2 //