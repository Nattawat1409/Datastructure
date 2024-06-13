// Nattawat  Ruensumrit 3420 //

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MaxHeap {
    int *arr;
    int size;
} MaxHeap;

MaxHeap *init_heap();
void insert(MaxHeap **root, int val);
void delete(MaxHeap **root, int val);
void print_heap(MaxHeap *heap);
void deallocate(MaxHeap *root);

int main() {
    MaxHeap *heap = init_heap();
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

MaxHeap *init_heap() {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->size = 0;
    heap->arr = NULL;
    return heap;
}

void insert(MaxHeap **root, int val) {
    MaxHeap *heap = *root;
    heap->size += 1;
    heap->arr = (int *)realloc(heap->arr, sizeof(int) * heap->size);
    heap->arr[heap->size - 1] = val;

    int target_idx = heap->size - 1;
    int parent_idx = (target_idx - 1) / 2;

    while (target_idx > 0 && heap->arr[target_idx] > heap->arr[parent_idx]) {
        int temp = heap->arr[parent_idx];
        heap->arr[parent_idx] = heap->arr[target_idx];
        heap->arr[target_idx] = temp;

        target_idx = parent_idx;
        parent_idx = (target_idx - 1) / 2;
    }
}

void delete(MaxHeap **root, int val) {
    MaxHeap *heap = *root;
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
        int largest = i;
        if ((2 * i) + 1 < heap->size && heap->arr[(2 * i) + 1] > heap->arr[largest])
            largest = (2 * i) + 1;

        if ((2 * i) + 2 < heap->size && heap->arr[(2 * i) + 2] > heap->arr[largest])
            largest = (2 * i) + 2;

        if (largest != i) {
            int temp = heap->arr[i];
            heap->arr[i] = heap->arr[largest];
            heap->arr[largest] = temp;
        }
    }
}

void print_heap(MaxHeap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void deallocate(MaxHeap *root) {
    free(root->arr);
    free(root);
}
