// Nattawat  Ruensumrit 660705034320//
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int size, search;
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int)); // using malloc // 
    if (arr == NULL) 
    { 
        fprintf(stderr, "Memory allocation failed\n");
        return 1; 
    }
    
    for (int i = 0; i < size; i++) 
    {                               // size  = 5 //
        scanf("%d", arr + i);       // storing value in specifies value in each index //
    }

    scanf("%d", &search); // pick up 0  or 1 //

    if(size < 2)
    {
        printf("none");
        return 0;
    }

    if (search == 1)  // odd //
    { // Print elements at odd indices
        for (int *p = arr + 1; p < arr + size; p += 2) 
        {
            printf("%d ",*p);
        }
    }else if (search == 0)  // even //
    { // Print elements at even indices 
        for (int *p = arr; p < arr + size; p += 2) 
        {
            printf("%d ", *p);
        }
    }

    free(arr);

    return 0;
}
