// Nattawat  Ruensumrit 660705034320//


#include<stdio.h>
#include<stdlib.h>
void conversion(int max, int index_max, int min , int index_min);

int main()
{
    int size;
    int *g;
    scanf("%d",&size);
    int *arr = (int*)malloc(size * sizeof(int));
    if(arr == NULL)
    {
        fprintf(stderr,"Memory allocate failed\n");
        return 1;
    }
    for(int i = 0; i < size; i++)
    {
        scanf("%d",arr+i);
    }

    int *val_max = arr;  // initailize to allocate  is pointer//
    int *val_min = arr;  // initailize to allocate  is pointer//  
    int index_max = 0 , index_min = 0 ;  // non pointer //

    for(g = arr + 1 ; g < arr + size; g++) // -1  for protect to appoarch a next number that be beyond the array size in this case that mean any some of memory location //
    {                                 
        if(*g > *val_max)       
        {   
            val_max = g;    // value of max //                        
            index_max = g - arr; //finding index =  current pointer - arr base address //
        }

        if(*g < *val_min)
        {
            val_min = g;    // value of min //
            index_min = g - arr; //finding index =  current pointer - arr base address //
        }
    }
    conversion(*val_max , index_max , *val_min , index_min);
    //printf("Value Max : %d %d \n",*val_max,index_max);            // pointer tell value  | non- pointer tell position//
    //printf("Value Min : %d %d \n",*val_min,index_min);            // pointer tell value  | non-pointer tell possiton//

    free(arr);
    return 0;
}

void conversion(int max ,int index_max , int min , int index_min)
{
    char *str = (char*)malloc(20000 * sizeof(char));
    sprintf(str,"%d %d", max, index_max);
    puts(str);
    
    sprintf(str,"%d %d", min, index_min);
    puts(str);
}