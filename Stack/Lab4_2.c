#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Nattawat  Ruensumrit //
 // 66070503420 //
 
typedef struct list {
    int data;
    struct list *next;
} list;

void push(list **node) 
{
    list *newNode = (list *)malloc(sizeof(list));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    scanf("%d", &newNode->data);
    newNode->next = *node;
    *node = newNode;
}

void isempty(list *node) 
{
    if (node == NULL)
        printf("1\n");
    else
        printf("0\n");
}

void pop(list **node) 
{
    if (*node == NULL) 
    {
        printf("empty\n");
        return;
    }
    list *temp = *node;
    printf("%d\n", temp->data);
    *node = temp->next;
    free(temp);
}

void top(list *node) 
{
    if (node == NULL) 
    {
        printf("empty\n");
        return;
    }
    printf("%d\n", node->data);
}

int main() 
{
    char option;
    list *node = NULL;
    while (true) 
    {
        scanf(" %c", &option); // Added space before %c to consume whitespace/newline characters
        switch (option) 
        {
            case 'p':
                push(&node);
                break;
            case 'o':
                pop(&node);
                break;
            case 't':
                top(node);
                break;
            case 'e':
                isempty(node);
                break;
            case 'q':
                while (node != NULL) 
                { // Free all allocated memory before exiting
                    list *temp = node;
                    node = node->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }

    }
    
    return 0;
}
