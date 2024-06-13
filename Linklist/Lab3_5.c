//Nattawat Ruensumrit //
//66070503420 //


#include "stdio.h"
#include "stdlib.h"
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **tail, int data);
void delete(Node **tail, int data);

int main() {
    Node *tail = NULL;

    while (1) {
        char mode;
        scanf("%c", &mode);

        if (mode == 'I') {
            int data;
            scanf("%d", &data);
            insert(&tail, data);
        } else if (mode == 'D') {
            int data;
            scanf("%d", &data);
            delete(&tail, data);
        } else if (mode == 'E') {
            break;
        }
    }

    if (tail == NULL) {
        puts("Empty");
        return 0;
    }

    Node *current = tail->next;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != tail->next);

    puts("");

    return 0;
}

void insert(Node **tail, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*tail == NULL) {
        newNode->next = newNode;
        *tail = newNode;
        return;
    }

    Node *current = *tail;
    newNode->next = current->next;
    current->next = newNode;
    *tail = current->next;
}

void delete(Node **tail, int data) {
    if (*tail == NULL) {
        return;
    }

    Node *current = *tail;

    if (current->next == current && current->data == data) {
        *tail = NULL;
        free(current);
        return;
    }

    Node *temp = *tail;
    int found = 0;
    temp = temp->next;

    do {
        if (temp->next->data == data) {
            found++;
            break;
        }
        temp = temp->next;
    } while (temp != current->next);

    if (found == 0) {
        puts("Not found");
        return;
    }

    Node *temp2 = temp->next;
    temp->next = temp2->next;

    if (temp2 == *tail) {
        *tail = temp;
    }

    free(temp2);
    temp2 = NULL;
}
