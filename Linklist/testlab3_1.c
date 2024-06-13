#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}node;
void create_linkedlist(int measure);
int main()
{
    int size;
    scanf("%d",&size);
    create_linkedlist(size);
    return 0;
}

void create_linkedlist(int measure)
{
    int i = 1;
    node *head = NULL;
    node *current = NULL;
    while(i <= measure)
    {
        node *newnode = malloc(sizeof(node)); //allocate memory for each newnode depend on the size from input //
        scanf("%d",&newnode->value);  // 1   2   3   4   5 //
        newnode->next = NULL;
        if(newnode == NULL)
        {
            printf("Memory is failed\n");
            exit(1);
        }

        if(head == NULL)
        {                        //   1  //                 // 2 //                     //3 //
            head = newnode;     // 3 -> = newnode//         // 2 NULL  = newnode//      // 12 NULL  = newnode//
            current = newnode;  // 3 NULL  = newnode//        // 2 NULL //               //12 NULL // 
        }else{
            current->next = newnode; // make if more small //
            current = newnode; // make it more smaller than pervious time //
        }
        i++;
    }                   // current will update = head that,In current at 1st node that 3 | NULL //
    current = head; //begin to print current in the loop since at a first node that is head // // current = head 3 NULL //
    while(current != NULL)
    {
        printf("%d ",current->value);  //current->3 | newnode//
        current = current->next;      // current going deep into inner of list for next of next node addresss //
    }
    printf("\n");
}