//Nattawat Ruensumrit 66070503420

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
int front = -1, rear = -1;

int isFull(int size)
{
    return ((rear + 1) % size == front);
}

void enqueue(int *queue, int size) 
{
    if (isFull(size)) 
    {
        printf("Queue Overflow\n");
        return;
    }

    int element;
    printf("to enqueue: ");
    scanf("%d", &element);

    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    queue[rear] = element;
}

int isEmpty() 
{
    return (front == -1);
}

int dequeue(int *queue, int size) 
{
    int element;
    if (isEmpty()) 
    {
        printf("Queue Underflow\n");
        return -1;
    } 
    else if (front == rear) 
    {
        element = queue[front];
        front = -1;
        rear = -1;
    } 
    else 
    {
        element = queue[front];
        front = (front + 1) % size;
    }
    return element;
}


void printQueue(int *queue, int size) 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i != (rear + 1) % size; i = (i + 1) % size) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() 
{
    int size;
    printf("size : ");
    scanf("%d", &size);
    int *queue = (int*)malloc(size * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    printf("E for enqueue , D for dequeue , Q for exit\n");
    char option;
    while(true) 
    {

        scanf(" %c", &option);
        switch (option) 
        {
            case 'E': // to enqueue //
                enqueue(queue, size);
                break;
            case 'D': // to dequeue //
                dequeue(queue, size);
                break;
            case 'Q': // to quit exit program //
                free(queue);
                return 0;
            default:
                printf("Invalid option\n");
                return 1;
        }

        printQueue(queue , size); // to display queue in each time //
    }

    return 0;
}