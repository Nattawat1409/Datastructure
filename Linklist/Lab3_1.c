#include <stdio.h>
#include <stdlib.h>
// Nattawat Ruensumrit //
// 66070503420 //
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printLinkedList(Node* head) 
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* insertAtHead(Node* head, int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Invalid\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Invalid\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) 
    {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) 
    {
      temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int main() 
{
    int n, option, value;

    // Input number of nodes
    scanf("%d", &n); //define size //

    // Input option for insertion (1 for beginning, 2 for end)
    scanf("%d", &option); // chose option //

    if (n == 0) 
    {
        printf("Invalid\n");
        return 1;
    }

    // Input values for the linked list nodes
    Node* head = NULL;
    for (int i = 0; i < n; i++) // store value in each node //
    {
        scanf("%d", &value);
        if (option == 1) 
        {
            head = insertAtHead(head, value); //  NULL  1  NUlL 2   NULL 3  NULL 4  NULL 5  //
        } else if (option == 2) 
        {
            head = insertAtEnd(head, value);
        } else {
            printf("Invalid\n");
            return 1;
        }
    }

    // Print the linked list after insertion
    printLinkedList(head);

    // Free the allocated memory for the linked list
    while (head != NULL) 
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
