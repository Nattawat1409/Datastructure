#include <stdio.h>
#include <stdlib.h>
//Nattawt Ruensumrit 660705034020 //
typedef struct {
    int rows;
    int cols;
    int data[100][100]; // let given maximum size of matrix is 100*100 //
} Matrix;

int main() {
    Matrix matrix;

    scanf("%d %d", &matrix.rows, &matrix.cols);

    if (matrix.rows != matrix.cols) {
        printf("ERROR\n");
        return 1;
    }
    //take the element value //
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            scanf("%d", &matrix.data[i][j]);
        }
    }

    //find the  sum of the primary diagonal//
    int primarySum = 0;
    for (int i = 0; i < matrix.rows; i++) {
        primarySum += matrix.data[i][i];
    }

    //find the  sum of the secondary diagonal//
    int secondarySum = 0;
    for (int i = 0; i < matrix.rows; i++) {
        secondarySum += matrix.data[i][matrix.cols - 1 - i];
    }


    printf("Primary: %d\n", primarySum);
    printf("Secondary: %d\n", secondarySum);

    return 0;
}
