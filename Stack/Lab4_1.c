#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Nattawat Ruensummrit //
    // 66070503420 //


typedef struct {
    int value;
    int top;
} stack;

void push(stack *StackAll, int size);
void pop(stack *StackAll);
void show(stack *StackAll);
bool isFull(stack *StackAll, int size);
bool isEmpty(stack *StackAll);


int main() 
{
    int size, option;
    scanf("%d", &size);
    if (size <= 0) 
    {
        printf("Please enter a positive number.\n");
        return 1;
    }

    stack *StackAll = (stack *)malloc(size * sizeof(stack));
    StackAll->top = -1;

    while (true) // infinity loop till it get a false option //
    {
        scanf("%d", &option);
        switch (option) 
        {
            case 1:
                push(StackAll, size);
                break;
            case 2:
                pop(StackAll);
                break;
            case 3:
                show(StackAll);
                free(StackAll); //free memory after display the element within stack // // for protect the memory leak //
                return 0;
            case 4:
                printf("Exiting...\n");
                free(StackAll);
                return 0;
            default:
                printf("Invalid choice.\n");
                free(StackAll);
                return 1;
        }
    }

    return 0;
}

// DON'T FORGOT TO USE PRINTF IN SEPARATE FUNCTION PUTS IS NOT ALLOW //
void push(stack *StackAll, int size) 
{
    if (isFull(StackAll, size)) 
    {
        printf("Stack Overflow.\n"); // the size of stack had exceed //
        exit(1);
    } else {
        StackAll->top++; // begin at StackAll->top = -1 which is -1 + 1 = 0 //
        scanf("%d", &StackAll[StackAll->top].value);
    }
}


void pop(stack *StackAll) // remove the top of stack for fristly //
{
    if (isEmpty(StackAll)) 
    {
        printf("Stack Underflow.\n"); // deleted any without any element within an stack array //
        exit(1);
    } else {
        StackAll->top--;
    }
}

void show(stack *StackAll) 
{
    if (isEmpty(StackAll)) 
    {
        printf("Stack is empty.\n");
    } else {
        for (int i = StackAll->top; i >= 0; i--) 
        {
            printf("%d\n", StackAll[i].value);
        }
                                                    // no need to add exit (0) because we have a return 0 with in main program done after we show the correctly output to show the stack //
    }
}

bool isFull(stack *StackAll, int size) 
{
    return StackAll->top == size - 1; // maximum size of array let say size  =  9  that mean maximum index  = 8 //
}

bool isEmpty(stack *StackAll) 
{
    return StackAll->top == -1;
}
