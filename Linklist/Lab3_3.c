//Nattawat Ruensumrit //
//66070503420 //

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node //
Node *createNode(int value) 
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
    
}

// Function to insert a node at the end of the linked list
Node *insertEnd(Node *head, int value) 
{
    Node *newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete the first node of the linked list //
Node *deleteFirst(Node *head) {
    if (head == NULL) 
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list //
Node *deleteLast(Node *head) {
    if (head == NULL) 
    {
        return NULL;
    }
    if (head->next == NULL) 
    {
        free(head);
        return NULL;
    }
    Node *current = head;
    Node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    free(current);
    if (prev != NULL) {
        prev->next = NULL;
    }
    return head;
}

// Function for delete the first node with a specific value //
Node *deleteByValue(Node *head, int value) 
{
    if (head == NULL) 
    {
        return NULL;
    }
    if (head->data == value) 
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
    return head;
}

// Function for print the remaining nodes in the linked list
void printList(Node *head) 
{
    if (head == NULL) {
        printf("none\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    int n, value;
    scanf("%d", &n);

    // Create the for the  original linked list //
    Node *head = NULL;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Perform deletions based on user input //
    char mode;
    while (1) {
        scanf(" %c", &mode);  

        if (mode == 'F') 
        {
            head = deleteFirst(head);
        } else if (mode == 'L') 
        {
            head = deleteLast(head);
        } else if (mode == 'N') 
        {
            int x;
            scanf("%d", &x);
            head = deleteByValue(head, x);
        } else if (mode == 'E') 
        {
            break;  // Exit the loop when mode = E //
        }
    }

    // Print the remaining nodes of linked list //
    printList(head);

    // Free memory from allocate //
    while (head != NULL) 
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
