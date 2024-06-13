#include <stdio.h>
#include <stdlib.h>

//Nattawat  Ruensumrit //
//Sec A //
//Student Number : 66070503420 //
void printArray(int size, int array[]) 
{
    if (size == 0) 
    {
        printf("empty\n");
        return;
    }
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", array[i]);
    }
    puts("");
}

int isElementInArray(int size, int *array, int element) 
{
    for (int i = 0; i < size; i++) 
    {
        if (array[i] == element) 
        {
            return 1;
        }
    }
    return 0;
}

int createSetFromArray(int size, int array[], int *set) 
{
    int setIndex = 0;
    for (int i = 0; i < size; i++) 
    {
        if (i == 0 || array[i] != array[i - 1]) 
        {
            set[setIndex] = array[i];
            setIndex++;
        }
    }
    return setIndex;
}

int createSetInRange(int size, int *array, int minRange, int maxRange) 
{
    int setSize = 0;
    for (int i = 0; i < size; i++) 
    {
        int element;
        scanf("%d", &element);
        if (i == 0 || array[setSize - 1] != element) 
        {
            if (element >= minRange && element <= maxRange) 
            {
                array[setSize] = element;
                setSize++;
            }
        }
    }
    return setSize;
}

void generateUniverse(int minRange, int maxRange, int *universe) 
{
    int index = 0;
    for (int i = minRange; i <= maxRange; i++) 
    {
        universe[index] = i;
        index++;
    }
}

void calculateUnion(int sizeA, int sizeB, int *setA, int *setB) 
{
    int *combinedSet = (int *)malloc((sizeA + sizeB) * sizeof(int));

    int indexA = 0, indexB = 0;
    int combinedIndex = 0;
    while (indexA < sizeA && indexB < sizeB) 
    {
        if (setA[indexA] < setB[indexB]) 
        {
            combinedSet[combinedIndex] = setA[indexA];
            indexA++;
        } else if (setA[indexA] > setB[indexB]) {
            combinedSet[combinedIndex] = setB[indexB];
            indexB++;
        } else {
            combinedSet[combinedIndex] = setA[indexA];
            indexA++;
            indexB++;
        }
        combinedIndex++;
    }
    for (int i = indexA; i < sizeA; i++) 
    {
        combinedSet[combinedIndex] = setA[i];
        combinedIndex++;
    }
    for (int j = indexB; j < sizeB; j++) 
    {
        combinedSet[combinedIndex] = setB[j];
        combinedIndex++;
    }
    printArray(combinedIndex, combinedSet);
    free(combinedSet);
}

void calculateIntersection(int sizeA, int sizeB, int *setA, int *setB) 
{
    
    int *intersectionSet = (int *)malloc(sizeA * sizeof(int));
    int index = 0;
    for (int i = 0; i < sizeA; i++) 
    {
        if (isElementInArray(sizeB, setB, setA[i])) 
        {
            intersectionSet[index] = setA[i];
            index++;
        }
    }

    int *finalSet = (int *)malloc(index * sizeof(int));
    int finalSetSize = createSetFromArray(index, intersectionSet, finalSet);
    printArray(finalSetSize, finalSet);
    free(intersectionSet);
    free(finalSet);
}

void calculateDifference(int sizeA, int sizeB, int *setA, int *setB) 
{
    int *differenceSet = (int *)malloc(sizeA * sizeof(int));
    int index = 0;
    for (int i = 0; i < sizeA; i++) 
    {
        if (!isElementInArray(sizeB, setB, setA[i])) 
        {
            differenceSet[index] = setA[i];
            index++;
        }
    }
    int *finalSet = (int *)malloc(index * sizeof(int));
    int finalSetSize = createSetFromArray(index, differenceSet, finalSet);
    printArray(finalSetSize, finalSet);
    free(differenceSet);
    free(finalSet);
}

int main() 
{
    int minRange, maxRange;
    scanf("%d %d", &minRange, &maxRange);

    int *universalSet = (int *)malloc((maxRange - minRange + 1) * sizeof(int));
    generateUniverse(minRange, maxRange, universalSet);

    int sizeA;
    scanf("%d", &sizeA);
    int *setA = (int *)malloc(sizeA * sizeof(int));
    int setSizeA = createSetInRange(sizeA, setA, minRange, maxRange);

    int sizeB;
    scanf("%d", &sizeB);
    int *setB = (int *)malloc(sizeB * sizeof(int));
    int setSizeB = createSetInRange(sizeB, setB, minRange, maxRange);

    printArray(setSizeA, setA);
    printArray(setSizeB, setB);

    // find Union
    calculateUnion(setSizeA, setSizeB, setA, setB);

    // find Intersection
    calculateIntersection(setSizeA, setSizeB, setA, setB);

    // find  Difference (A-B)
    calculateDifference(setSizeA, setSizeB, setA, setB);

    // find Difference (B-A)
    calculateDifference(setSizeB, setSizeA, setB, setA);

    // find Complement (U-A)
    calculateDifference(maxRange - minRange + 1, setSizeA, universalSet, setA);

    // find Complement (U-B)
    calculateDifference(maxRange - minRange + 1, setSizeB, universalSet, setB);

    free(universalSet);
    free(setA);
    free(setB);

    return 0;
}
