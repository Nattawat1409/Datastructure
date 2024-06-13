#include <stdio.h>
#include <stdlib.h>
//Nattawat Ruensumrit//
// 66070503420 //
typedef struct DynArray {
    int size;
    int *data;
} DynArray;

DynArray *initArray();
void push(DynArray *arr, int val);
void displayArray(DynArray *arr);
int calculateIndex(int idx, int size);
DynArray *getSlice(DynArray *arr, int start, int end, int step);

int main() {
    DynArray *arr = initArray();
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        push(arr, temp);
    }

    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);

    if (step == 0) {
        start = calculateIndex(start, arr->size);
        push(arr, arr->data[start]);
    } else {
        DynArray *slicedArr = getSlice(arr, start, end, step);
        displayArray(slicedArr);
        free(slicedArr->data);
        free(slicedArr);
    }

    free(arr->data);
    free(arr);

    return 0;
}

DynArray *initArray() {
    DynArray *arr = (DynArray *)malloc(sizeof(DynArray));
    arr->size = 0;
    arr->data = NULL;
    return arr;
}

void push(DynArray *arr, int val) {
    arr->size++;
    arr->data = realloc(arr->data, sizeof(int) * arr->size);
    arr->data[arr->size - 1] = val;
}

void displayArray(DynArray *arr) {
    if (arr->size == 0) {
        printf("empty\n");
        return;
    }

    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }

    printf("\n");
}

int calculateIndex(int idx, int size) {
    int res = idx % size;
    return res < 0 ? res + size : res;
}

DynArray *getSlice(DynArray *arr, int start, int end, int step) {
    DynArray *slicedArr = initArray();

    if (start < 0) {
        start = calculateIndex(start, arr->size);
    }

    if (end < 0) {
        end = calculateIndex(end, arr->size);
    }

    if (start >= 0 && start < arr->size && end >= 0 && end <= arr->size) {
        if (step > 0) {
            for (int i = start; i < end; i += step) {
                push(slicedArr, arr->data[i]);
            }
        } else if (step < 0) {
            for (int i = start; i > end; i += step) {
                push(slicedArr, arr->data[i]);
            }
        }
    }

    return slicedArr;
}
