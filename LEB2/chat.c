#include <stdio.h>

void customPrintInt(int value) 
{
    if (value < 0) {
        putchar('-');
        value = -value;
    }

    if (value == 10 || value == 20) {
        putchar('1');
        putchar('0');
    } 
    else if (value % 10 == 0) 
    {
        putchar('1');
        putchar('0' + value % 10);
    } 
    else 
    {
        int reversed = 0;
        while (value > 0) 
        {
            int digit = value % 10;
            reversed = reversed * 10 + digit;
            value /= 10;
        }

        while (reversed > 0) 
        {
            int digit2 = reversed % 10;
            putchar('0' + digit2);
            reversed /= 10;
        }
    }

    putchar('\n');
}

int main() 
{
    int number;
    scanf("%d", &number);
    customPrintInt(number);
    return 0;
}
