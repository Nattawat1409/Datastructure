//Nattawat  Ruensumrit // 
// 66070503420 //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure to hold character and its priority
struct CharPriority {
    char character;
    int priority;
};

// Function to calculate priority of a character
int get_priority(char ch) 
{
    if (isalpha(ch)) 
    {
        switch (tolower(ch)) 
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return 3; // Vowels have priority 3
            default:
                return 1; // then consonants have priority 1
        }
    } else {
        return 2; // Non-alphabet characters have priority 2
    }
}

// Function to compare CharPriority structs for sorting
int compare(const void *a, const void *b) {
    struct CharPriority *charA = (struct CharPriority *)a;
    struct CharPriority *charB = (struct CharPriority *)b;
    if (charA->priority != charB->priority) {
        return charB->priority - charA->priority; // Sort by priority in descending order
    } else {
        return -1; // Maintain original order for characters with same priority
    }
}

// Function to transform input string
void transform_string(char *input) {
    struct CharPriority charArray[strlen(input)];
    int i;
    // Populate the CharPriority array
    for (i = 0; input[i] != '\0'; i++) {
        charArray[i].character = input[i];
        charArray[i].priority = get_priority(input[i]);
    }
    // Sort the CharPriority array
    qsort(charArray, i, sizeof(struct CharPriority), compare);
    // Print the transformed string
    for (int j = 0; j < i; j++) {
        printf("%c", charArray[j].character);
    }
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    // Remove newline character if present
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    transform_string(input);
    printf("\n");
    return 0;
}
