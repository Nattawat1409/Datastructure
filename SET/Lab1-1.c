#include<stdio.h>
int main()
{
    int n,check = 0;
    int count = 0;
    scanf("%d",&n);
    int set[n]; // 1 2 3 5 //
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&set[i]);
    }

    for(int f = 0; f<n; f++) //0 1 2 3 4 //  //1 2 3 5 0 //
    {                       //before found duplicate element //
        for(int r = f+1; r<n; r++) //_ 1 2 3  //   //_ 2 3 5  //
        {
            if(set[f] == set[r]) //set[3] == set[4] // 
            {
                for(int t = r; t<n; t++) //t = r ; t = value at index 3 begin at 3 //
                {
                    set[t] = set[t+1]; //set[4] = set[5] // //because set[5] = 0 //
                                       //after found duplicate element//
                }
                n--;
                r--;
            }else{
                continue;
            }
        }
    }
    for(int a = 0; a<n; a++)
    {
        count++;
    }
    printf("%d\n",count);

    for(int w =0; w<n; w++)
    {
        printf("%d ",set[w]);
    }
    return 0;
}