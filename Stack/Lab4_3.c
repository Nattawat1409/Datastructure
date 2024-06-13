// Nattawat Ruensumrit //
// 66070503420 //

#include <stdio.h>
int tower_of_hanoi(int n, char source, char target, char auxiliary) 
{
    if (n == 1) 
    {
        printf("Move disk 1 from %c to %c\n", source, target);
        return 1;
    } else {
        int moves = 0;
        moves += tower_of_hanoi(n-1, source, auxiliary, target);
        printf("Move disk %d from %c to %c\n", n, source, target);
        moves++;
        moves += tower_of_hanoi(n-1, auxiliary, target, source);
        return moves;
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    int moves = tower_of_hanoi(n, 'A', 'C', 'B');
    printf("Total moves: %d\n", moves);
    return 0;
}
