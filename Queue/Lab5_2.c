#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void enqueue(int rear , int head)
{
    int value;
    scanf("%d",&value);
    head++;
    rear++;
    return;
}
int main()
{
    char cmd;
    int option = true;
    int rear = -1 , head = -1;
    while(option)
    {
        scanf(" %c",&cmd);
        if(cmd == 'l') //enqueue//
        {
            enqueue(rear , head);
        }
        if(cmd ==  'g')
        {
            
        }
        if(cmd == 'e')
        {
            option = false;
            return 0;
        }
    }

    return 0;
}