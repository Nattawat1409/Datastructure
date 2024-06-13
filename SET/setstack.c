#include <stdio.h>
#include <stdlib.h>

// Structure for Stack
typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Function to create a stack
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

// Print the elements of the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to perform set operations

// Union of two sets
void calculateUnion(Stack* setA, Stack* setB) {
    Stack* combinedSet = createStack(setA->capacity + setB->capacity);

    while (!isEmpty(setA)) {
        int item = pop(setA);
        if (!isElementInStack(combinedSet, item))
            push(combinedSet, item);
    }
    while (!isEmpty(setB)) {
        int item = pop(setB);
        if (!isElementInStack(combinedSet, item))
            push(combinedSet, item);
    }

    printStack(combinedSet);
    free(combinedSet->array);
    free(combinedSet);
}

// Intersection of two sets
void calculateIntersection(Stack* setA, Stack* setB) {
    Stack* intersectionSet = createStack(setA->capacity);

    while (!isEmpty(setA)) {
        int item = pop(setA);
        if (isElementInStack(setB, item) && !isElementInStack(intersectionSet, item))
            push(intersectionSet, item);
    }

    printStack(intersectionSet);
    free(intersectionSet->array);
    free(intersectionSet);
}

// Difference of two sets
void calculateDifference(Stack* setA, Stack* setB) {
    Stack* differenceSet = createStack(setA->capacity);

    while (!isEmpty(setA)) {
        int item = pop(setA);
        if (!isElementInStack(setB, item))
            push(differenceSet, item);
    }

    printStack(differenceSet);
    free(differenceSet->array);
    free(differenceSet);
}

// Function to check if an element is present in the stack
int isElementInStack(Stack* stack, int element) {
    for (int i = 0; i <= stack->top; i++) {
        if (stack->array[i] == element)
            return 1;
    }
    return 0;
}

int main() {
    int minRange, maxRange;
    scanf("%d %d", &minRange, &maxRange);

    // Create universal set
    Stack* universalSet = createStack(maxRange - minRange + 1);
    for (int i = maxRange; i >= minRange; i--) 
        push(universalSet, i);

    int sizeA;
    scanf("%d", &sizeA);
    // Create set A
    Stack* setA = createStack(sizeA);
    for (int i = 0; i < sizeA; i++) {
        int element;
        scanf("%d", &element);
        push(setA, element);
    }

    int sizeB;
    scanf("%d", &sizeB);
    // Create set B
    Stack* setB = createStack(sizeB);
    for (int i = 0; i < sizeB; i++) {
        int element;
        scanf("%d", &element);
        push(setB, element);
    }

    // Print sets A and B
    printf("Set A: ");
    printStack(setA);
    printf("Set B: ");
    printStack(setB);

    // Perform set operations
    printf("Union: ");
    calculateUnion(setA, setB);

    printf("Intersection: ");
    calculateIntersection(setA, setB);

    printf("Difference (A-B): ");
    calculateDifference(setA, setB);

    printf("Difference (B-A): ");
    calculateDifference(setB, setA);

    // Complement (U-A) and (U-B) are not needed for stack-based implementation

    // Free memory
    free(universalSet->array);
    free(universalSet);
    free(setA->array);
    free(setA);
    free(setB->array);
    free(setB);

    return 0;
}
