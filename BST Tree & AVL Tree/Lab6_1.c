// Nattawat  Ruensumrit //
// 6070503420 //
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

// If there is no node in parent is not matched to the input =  "not found" //



int print_tree(int *max_tree , int max_idx)
{
    for(int i = 0 ; i < max_idx; i++)
    {
        if(max_tree[i] == -999) //if empty //
        {
            printf("null ");
        }else{ //if not empty //
            printf("%d ",max_tree[i]);
        }
    }

    return 0 ;
}


void creating_root(int *max_tree , int *size_root , int *count)
{
    if(*count >= 1)
    {
        puts("cannot create duplicated root");
        return;
    }

    scanf("%d",size_root);       // for storing the value of size root using pointer to dereferrent to effect with main function//
    max_tree[0] = *size_root;    // create origin head node //
    (*count)++;                 //using poiner too dereferent cound number to impact with main func and whole code //
}



void INSL(int *max_tree, int max_idx, int size_root) // begin at 0 // // func odd //
{
    int ref_idx_left = -1, par_left, value_left, k = -1;
    scanf("%d %d", &par_left, &value_left); // 78 12(3) // 59 40

    for (int j = 0; j < max_idx; j++) // algorithms for searching
    {
        if (max_tree[j] == par_left)
        {
            k = j; // if found check point // to get  new refferent node to be current //
        }
    }

    if (k == -1)
    {
        puts("not found");
        return;
    }
    else if ((2 * k) + 2 > max_idx) // leaf node checkig if it exceed the idx of lead node //
    {
        puts("overflow"); // exceed
        return;
    }
    else if (max_tree[(k * 2) + 1] != -999) // just in case when a leaf node it not empty to check all posibility //
    {
        puts("node already presented");
        return;
    }else{
        max_tree[(k * 2) + 1] = value_left; // if tree is empty free feel to store value //
    }

    return;
}

void INSR(int *max_tree, int max_idx, int size_root) // func even //
{

    int ref_idx_right = -1, par_right, value_right, k = -1;
    scanf("%d %d", &par_right, &value_right);

    for (int i = 0; i < max_idx; i++) // searching //
    {
        if (max_tree[i] == par_right)
        {
            k = i; // if found check point // to get  new refferent node to be current //
        }
    }
    if (k == -1)
    {
        puts("not found");
        return;
    }
    else if ((2 * k) + 3 > max_idx) // leaf node checkig if it exceed the idx of lead node // // next index if > max_idx (must not exceed) //
    {
        puts("overflow");
        return;
    } 
    else if (max_tree[(2 * k) + 2] != -999) // just in case when a leaf node it not empty to check all posibility //
    {
        puts("node already presented");
        return;
    }
    else
    {
        max_tree[(k * 2) + 2] = value_right;
    }
    return;
}




int main()
{
    int max_idx, count = 0 , size_root;
    char option[200];
    scanf("%d",&max_idx);   //max size index //
    int *max_tree = (int*)malloc(max_idx * sizeof(int));   // creating array //
    for(int i = 0; i < max_idx; i++)
    {
        max_tree[i] = -999; // rest all idx to empty //
    }
    while(1)
    {
        scanf("%s",option);  // pick root //

        if(strcmp(option,"ROOT") == 0)
        {
            creating_root(max_tree , &size_root ,&count);  // dereferrence size root only this function to update value //
        }

        if(strcmp(option,"INSL") == 0)
        {
            INSL( max_tree, max_idx , size_root);
        }else if(strcmp(option,"INSR") == 0)
        {
            INSR( max_tree , max_idx , size_root);
        }

        if(strcmp(option,"END") == 0) // to finish the infinity loop //
        {
            print_tree(max_tree , max_idx);
            free(max_tree);
            return 0;
        }
    }

    return 0;
}



//ถ้ามี node ที่ต้องการ จะ insert อยุ่เเล้ว printf("node already presented ")
//if target index out of bound of array = "overflow" //
