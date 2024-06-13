#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Nattawat Ruensumrit //
//66070503420 //
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

void add(node **head, int data);
void del(node **head, int data);
void search(node **head, int data);
void print(node **head);

int main() 
{
    node *head = NULL;
    while (1) 
    {
        char *mode;
        scanf("%s", mode);
        if (strcmp(mode, "ADD") == 0) 
        {
            int data;
            scanf("%d", &data);
            add(&head, data);
        } else if (strcmp(mode, "DEL") == 0) 
        {
            int data;
            scanf("%d", &data);
            del(&head, data);
        } else if (strcmp(mode, "SCH") == 0) 
        {
            int data;
            scanf("%d", &data);
            search(&head, data);
        } else if (strcmp(mode, "END") == 0) 
        {
            break;
        }
    }
    print(&head);

    return 0;
}

void add(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    node *cur = *head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new_node;
    new_node->prev = cur;
}

// doing with removing first element
void del(node **head, int data) {
    if(*head == NULL){
        return ;
    }

    node *cur = *head;
    node *dummy = (node *)malloc(sizeof(node));
    dummy->next = *head;
    node *prev = dummy;

    while (cur) {
        if(cur->data == data){
            break;
        }
        prev=cur;
        cur=cur->next;
    }

    if(cur == NULL){
        return ;
    }

    if (cur->next == NULL && cur->prev == NULL) {
        // delete single ele
        *head = NULL;
    } else if (cur->prev == NULL) {
        // for deleting first node
        cur = cur->next;
        cur->prev = NULL;
        *head = cur;
    } else if (cur->next == NULL) {
        // deleting last node
        cur = cur->prev;
        cur->next = NULL;
        return;
    } else {
        prev->next = cur->next;
        prev->next->prev = prev;
    }
    free(cur);
}

void search(node **head, int data) {
    node *cur = *head;
    while (cur) {
        if(cur->data == data){
            break;
        }
        cur = cur->next;
    }
    if (cur == NULL) {
        printf("none\n");
        return ;
    }

    if (cur->prev != NULL) {
        printf("%d ", cur->prev->data);
    } else {
        printf("NULL ");
    }

    if (cur->next != NULL) {
        printf("%d\n", cur->next->data);
    } else {
        printf("NULL\n");
    }
}

void print(node **head) {
    node *cur = *head;
    int count = 0;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
        count++;
    }
    if (count == 0) {
        printf("none");
    }
    puts("");
    free(cur);
    node *prev = *head;
    while (prev && prev->next) {
        prev = prev->next;
    }
    int rev_count = 0;
    while (prev) {
        printf("%d ", prev->data);
        prev = prev->prev;
        rev_count++;
    }
    if (rev_count == 0) {
        printf("none");
    }
    puts("");
    free(prev);
}
