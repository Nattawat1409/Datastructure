// Nattwat Ruensurmit // 
#include <stdio.h>
#include <stdlib.h>

int insertArray(int *array, int size, int index, int value);
int deleteArray(int *array, int size, int index);
int mergeArray(int *array1, int size1, int *array2, int size2);
void printArray(int array[], int size);

int main()
{
    int size1, size2;
    scanf("%d", &size1);
    if (size1 < 1 || size1 > 10000)
    {
        return 0;
    }
    int *array1 = (int *)malloc(size1 * sizeof(int)), temp;
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &temp);
        *(array1 + i) = temp;
    }
    scanf("%d", &size2);
    if (size2 < 1 || size2 > 10000)
    {
        return 0;
    }
    int *array2 = (int *)malloc(size2 * sizeof(int));
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &temp);
        *(array2 + i) = temp;
    }
    int indexInsert, indexDelete, numInsert;
    scanf("%d", &indexInsert);
    scanf("%d", &numInsert);
    scanf("%d", &indexDelete);
    size1 = insertArray(array1, size1, indexInsert, numInsert);
    size1 = deleteArray(array1, size1, indexDelete);
    size1 = mergeArray(array1, size1, array2, size2);
    free(array1);
    free(array2);
    return 0;
}

int insertArray(int *array, int size, int index, int value)
{
    array = (int *)realloc(array, (size + 1) * sizeof(int));
    for (int i = size; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = value;
    printArray(array, size + 1);
    return (size + 1);
}

int deleteArray(int *array, int size, int index)
{
    if (index + 1 > size || size == 0)
    {
        printf("Index out of bounds\n");
        return size;
    }
    for (int i = index; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    printArray(array, size - 1);
    return (size - 1);
}

int mergeArray(int *array1, int size1, int *array2, int size2)
{
    int *array3 = (int *)malloc((size1 + size2) * sizeof(int));
    for (int i = 0; i < size1; i++)
    {
        array3[i] = array1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        array3[size1 + i] = array2[i];
    }
    printArray(array3, size1 + size2);
    free(array3);
    return (size1 + size2);
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
