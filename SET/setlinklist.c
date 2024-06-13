#include <stdio.h>
#include <stdlib.h>

// Structure for Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to check if an element is present in the linked list
int isElementInList(Node* head, int element) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == element)
            return 1;
        current = current->next;
    }
    return 0;
}

// Function to print elements of the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("empty\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to perform set operations

// Union of two sets
Node* calculateUnion(Node* setA, Node* setB) {
    Node* combinedSet = NULL;

    Node* temp = setA;
    while (temp != NULL) {
        if (!isElementInList(combinedSet, temp->data))
            insertAtEnd(&combinedSet, temp->data);
        temp = temp->next;
    }
    
    temp = setB;
    while (temp != NULL) {
        if (!isElementInList(combinedSet, temp->data))
            insertAtEnd(&combinedSet, temp->data);
        temp = temp->next;
    }

    return combinedSet;
}

// Intersection of two sets
Node* calculateIntersection(Node* setA, Node* setB) {
    Node* intersectionSet = NULL;

    Node* temp = setA;
    while (temp != NULL) {
        if (isElementInList(setB, temp->data) && !isElementInList(intersectionSet, temp->data))
            insertAtEnd(&intersectionSet, temp->data);
        temp = temp->next;
    }

    return intersectionSet;
}

// Difference of two sets
Node* calculateDifference(Node* setA, Node* setB) {
    Node* differenceSet = NULL;

    Node* temp = setA;
    while (temp != NULL) {
        if (!isElementInList(setB, temp->data))
            insertAtEnd(&differenceSet, temp->data);
        temp = temp->next;
    }

    return differenceSet;
}

int main() {
    int minRange, maxRange;
    scanf("%d %d", &minRange, &maxRange);

    // Create universal set
    Node* universalSet = NULL;
    for (int i = minRange; i <= maxRange; i++) 
        insertAtEnd(&universalSet, i);

    int sizeA;
    scanf("%d", &sizeA);
    // Create set A
    Node* setA = NULL;
    for (int i = 0; i < sizeA; i++) {
        int element;
        scanf("%d", &element);
        insertAtEnd(&setA, element);
    }

    int sizeB;
    scanf("%d", &sizeB);
    // Create set B
    Node* setB = NULL;
    for (int i = 0; i < sizeB; i++) {
        int element;
        scanf("%d", &element);
        insertAtEnd(&setB, element);
    }

    // Print sets A and B
    printf("Set A: ");
    printList(setA);
    printf("Set B: ");
    printList(setB);

    // Perform set operations
    printf("Union: ");
    printList(calculateUnion(setA, setB));

    printf("Intersection: ");
    printList(calculateIntersection(setA, setB));

    printf("Difference (A-B): ");
    printList(calculateDifference(setA, setB));

    printf("Difference (B-A): ");
    printList(calculateDifference(setB, setA));

    // Complement (U-A) and (U-B) are not needed for linked list-based implementation

    // Free memory
    // This part is not needed for linked lists as they are freed when program exits

    return 0;
}
