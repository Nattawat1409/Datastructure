#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size;
    scanf("%d",&size);

    int *arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i< size ; i++)
    {
        scanf("%d",arr+i);
    }
    int idx ,val ;
    scanf("%d",&idx);
    scanf("%d",&val);
    
    for(int *j = arr; j < size + arr; j++)
    {
        if(*j == idx)
        {
            size++
            arr = (int*)realloc(arr,size * sizeof(int));
        }        
    }

    free(arr);
    return 0;
}