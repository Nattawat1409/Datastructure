// Nattawat Ruensumrit 3420 //

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MinHeap {
    int *arr;
    int size;
} MinHeap;

MinHeap *init_heap();
void insert(MinHeap **root, int val);
void delete(MinHeap **root, int val);
void print_heap(MinHeap *heap);
void deallocate(MinHeap *root);

int main() {
    MinHeap *heap = init_heap();
    char mode[256];

    while (true) {
        scanf("%s", mode);
        if (strcmp(mode, "INSERT") == 0) {
            int val;
            while (scanf("%d", &val) == 1)
                insert(&heap, val);
        } else if (strcmp(mode, "DELETE") == 0) {
            int val;
            while (scanf("%d", &val) == 1)
                delete(&heap, val);
        } else if (strcmp(mode, "PRINT") == 0) {
            print_heap(heap);
        } else if (strcmp(mode, "EXIT") == 0) {
            break;
        }
    }

    deallocate(heap);

    return 0;
}

MinHeap *init_heap() {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->arr = NULL;
    return heap;
}

void insert(MinHeap **root, int val) {
    MinHeap *heap = *root;
    heap->size += 1;
    heap->arr = (int *)realloc(heap->arr, sizeof(int) * heap->size);
    heap->arr[heap->size - 1] = val;

    int target_idx = heap->size - 1;
    int parent_idx = (target_idx - 1) / 2;

    while (target_idx > 0 && heap->arr[target_idx] < heap->arr[parent_idx]) {
        int temp = heap->arr[parent_idx];
        heap->arr[parent_idx] = heap->arr[target_idx];
        heap->arr[target_idx] = temp;

        target_idx = parent_idx;
        parent_idx = (target_idx - 1) / 2;
    }
}

void delete(MinHeap **root, int val) {
    MinHeap *heap = *root;
    int target_idx;

    for (target_idx = 0; target_idx < heap->size; target_idx++) {
        if (heap->arr[target_idx] == val)
            break;
    }

    if (target_idx == heap->size)
        return;

    int temp = heap->arr[target_idx];
    heap->arr[target_idx] = heap->arr[heap->size - 1];
    heap->arr[heap->size - 1] = temp;

    heap->size--;
    heap->arr = (int *)realloc(heap->arr, sizeof(int) * heap->size);

    for (int i = 0; i < heap->size; i++) {
        int smallest = i;
        if ((2 * i) + 1 < heap->size && heap->arr[(2 * i) + 1] < heap->arr[smallest])
            smallest = (2 * i) + 1;

        if ((2 * i) + 2 < heap->size && heap->arr[(2 * i) + 2] < heap->arr[smallest])
            smallest = (2 * i) + 2;

        if (smallest != i) {
            int temp = heap->arr[i];
            heap->arr[i] = heap->arr[smallest];
            heap->arr[smallest] = temp;
        }
    }
}

void print_heap(MinHeap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void deallocate(MinHeap *root) {
    free(root->arr);
    free(root);
}
