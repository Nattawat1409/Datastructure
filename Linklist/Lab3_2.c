#include "stdio.h"
#include "stdlib.h"
//Nattawat Ruensumrit//
//66070503420//
typedef struct node {
    int value;
    struct node *next;
}node;


void insert(node **head, int searchValue, int insertValue);
void combine(node **head, int searchValue, int insertValue);

int main() 
{
    int n;
    scanf("%d", &n);
    node *head = (node *)malloc(sizeof(node));
    node *currentNode = head;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        currentNode->next = (node *)malloc(sizeof(node));
        currentNode->next->value = val;
        currentNode = currentNode->next;
    }
    head = head->next;
    while (1) {
        char mode;
        scanf("%c", &mode);
        if (mode == 65) {
            int searchValue, insertValue;
            scanf("%d %d", &searchValue, &insertValue);
            combine(&head, searchValue, insertValue);
        } else if (mode == 66) {
            int searchValue, insertValue;
            scanf("%d %d", &searchValue, &insertValue);
            insert(&head, searchValue, insertValue);
        } else if (mode == 69) {
            break;
        }
    }
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    puts("");

    return 0;
}

void combine(node **head, int searchValue, int insertValue) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = insertValue;
    newNode->next = NULL;

    node *currentNode = *head;
    while (currentNode) {
        if (currentNode->value == searchValue) {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return;
        }
        currentNode = currentNode->next;
    }
    free(currentNode);
}

void insert(node **head, int searchValue, int insertValue) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = insertValue;
    newNode->next = NULL;

    node *currentNode = *head;
    if (currentNode->value == searchValue) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    node *preCurrentNode = *head;
    currentNode = currentNode->next;
    while (currentNode) {
        if (currentNode->value == searchValue) {
            preCurrentNode->next = newNode;
            newNode->next = currentNode;
            return;
        }
        preCurrentNode = preCurrentNode->next;
        currentNode = currentNode->next;
    }
    free(currentNode);
}
