#include<stdio.h>
#include<string.h>
// Nattawat  Ruensumrit 66070503420 //
struct dict {
    char key[100];
    char value[100];
};

void editdict(struct dict *dic, int size, char *editKey, char *editValue) {
    int changed = 0;

    for (int i = 0; i < size; i++) 
    {
        if (strcmp(dic[i].key, editKey) == 0)  //we need to use string compare for checking  from string.h //
        {
            strcpy(dic[i].value, editValue); // we need to use string copy to create and edit to contain the word //
            changed = 1;
            break;
        }
    }

    if (!changed) {
        printf("No change\n");
    }
}

void printdict(struct dict *dic, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%s : %s\n", dic[i].key, dic[i].value);
    }
}

int main() 
{
    int size;
    scanf("%d", &size);

    struct dict dic[size];

    for (int i = 0; i < size; i++) 
    {
        scanf("%s %s", dic[i].key, dic[i].value);
    }

    char editKey[100], editValue[100];
    scanf("%s %s", editKey, editValue);

    editdict(dic, size, editKey, editValue); //using function //
    printdict(dic, size); //using function //

    return 0;
}
