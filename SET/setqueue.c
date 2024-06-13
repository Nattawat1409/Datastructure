#include <stdio.h>
#include <stdlib.h>

// Structure for Queue
typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function to create a queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to print elements of a queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("empty\n");
        return;
    }
    int i;
    for (i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->array[i]);
    printf("\n");
}

// Function to check if an element is present in the queue
int isElementInQueue(Queue* queue, int element) {
    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        if (queue->array[i] == element)
            return 1;
    }
    return 0;
}

// Function to perform set operations

// Union of two sets
void calculateUnion(Queue* setA, Queue* setB) {
    Queue* combinedSet = createQueue(setA->capacity + setB->capacity);

    while (!isEmpty(setA)) {
        int item = dequeue(setA);
        if (!isElementInQueue(combinedSet, item))
            enqueue(combinedSet, item);
    }
    while (!isEmpty(setB)) {
        int item = dequeue(setB);
        if (!isElementInQueue(combinedSet, item))
            enqueue(combinedSet, item);
    }

    printQueue(combinedSet);
    free(combinedSet->array);
    free(combinedSet);
}

// Intersection of two sets
void calculateIntersection(Queue* setA, Queue* setB) {
    Queue* intersectionSet = createQueue(setA->capacity);

    while (!isEmpty(setA)) {
        int item = dequeue(setA);
        if (isElementInQueue(setB, item) && !isElementInQueue(intersectionSet, item))
            enqueue(intersectionSet, item);
    }

    printQueue(intersectionSet);
    free(intersectionSet->array);
    free(intersectionSet);
}

// Difference of two sets
void calculateDifference(Queue* setA, Queue* setB) {
    Queue* differenceSet = createQueue(setA->capacity);

    while (!isEmpty(setA)) {
        int item = dequeue(setA);
        if (!isElementInQueue(setB, item))
            enqueue(differenceSet, item);
    }

    printQueue(differenceSet);
    free(differenceSet->array);
    free(differenceSet);
}

int main() {
    int minRange, maxRange;
    scanf("%d %d", &minRange, &maxRange);

    // Create universal set
    Queue* universalSet = createQueue(maxRange - minRange + 1);
    for (int i = minRange; i <= maxRange; i++) 
        enqueue(universalSet, i);

    int sizeA;
    scanf("%d", &sizeA);
    // Create set A
    Queue* setA = createQueue(sizeA);
    for (int i = 0; i < sizeA; i++) {
        int element;
        scanf("%d", &element);
        enqueue(setA, element);
    }

    int sizeB;
    scanf("%d", &sizeB);
    // Create set B
    Queue* setB = createQueue(sizeB);
    for (int i = 0; i < sizeB; i++) {
        int element;
        scanf("%d", &element);
        enqueue(setB, element);
    }

    // Print sets A and B
    printf("Set A: ");
    printQueue(setA);
    printf("Set B: ");
    printQueue(setB);

    // Perform set operations
    printf("Union: ");
    calculateUnion(setA, setB);

    printf("Intersection: ");
    calculateIntersection(setA, setB);

    printf("Difference (A-B): ");
    calculateDifference(setA, setB);

    printf("Difference (B-A): ");
    calculateDifference(setB, setA);

    // Complement (U-A) and (U-B) are not needed for queue-based implementation

    // Free memory
    free(universalSet->array);
    free(universalSet);
    free(setA->array);
    free(setA);
    free(setB->array);
    free(setB);

    return 0;
}
