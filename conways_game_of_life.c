#include <stdio.h>
#include <Windows.h>

const int rows;
const int columns;

void initializeMatrix (int M[rows][columns]) {
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j ++) {
            M[i][j] = 0;
        }
    }
}


void readMatrix (int M[rows][columns]) {
    for (int i = 1; i < rows - 1; i ++) {
        for (int j = 1; j < columns - 1; j ++) {
            scanf("%d", &M[i][j]);
        }
    }
}


void printMatrix (int M[rows][columns]) {
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j ++) {
            printf("%d ", M[i][j]);
        } 
        printf("\n");
    }
    printf("\n");
}


void copyMatrix (int M[rows][columns], int N[rows][columns]) {
    for (int i = 1; i < rows - 1; i ++) {
        for (int j = 1; j < columns - 1; j ++) {
            M[i][j] = N[i][j];
        }
    }
}


int liveCellCount (int M[rows][columns], int row, int column) {
    int liveCellCount = 0;

    for (int i = row - 1; i < row + 2; i ++) {
        for (int j = column - 1; j < column + 2; j ++) {
            if (i == row && j == column) {
                continue;
            }

            else if (M[i][j] == 1) {
                liveCellCount ++;
            }
        }
    }

    return liveCellCount;
}


void playGame (int M[rows][columns], int N[rows][columns]) {
    for (int i = 1; i < rows - 1; i ++) {
        for (int j = 1; j < columns - 1; j ++) {
            int liveCells = liveCellCount(M, i, j);

            if (liveCells == 2 || liveCells == 3) {
                N[i][j] = 1;
            }

            else {
                N[i][j] = 0;
            }
        }
    }
}


int lifeCheck (int M[rows][columns]) {
    for (int i = 1; i < rows - 1; i ++) {
        for (int j = 1; j < columns - 1; j ++) {
            if (M[i][j] == 1) {
                return 1;
            }
        }
    }

    return 0;
}


int main () {
    scanf("%d %d", &rows, &columns);
    int M[rows][columns], N[rows][columns];

    initializeMatrix(M);
    initializeMatrix(N);

    readMatrix(M);

    while (lifeCheck(M)) {
        playGame(M, N);
        copyMatrix(M, N);
        initializeMatrix(N);
        printMatrix(M);
        
        Sleep(1000);
    }

    return 0;
}
