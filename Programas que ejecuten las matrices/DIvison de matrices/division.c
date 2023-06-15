#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filasA, int columnasA, int columnasB);

int main() {
    int filasA, columnasA, filasB, columnasB;
    int matrizA[MAX_SIZE][MAX_SIZE], matrizB[MAX_SIZE][MAX_SIZE], resultado[MAX_SIZE][MAX_SIZE];

    printf("Ingrese el n�mero de filas de la matriz A: ");
    scanf("%d", &filasA);

    printf("Ingrese el n�mero de columnas de la matriz A: ");
    scanf("%d", &columnasA);

    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Ingrese el n�mero de filas de la matriz B: ");
    scanf("%d", &filasB);

    printf("Ingrese el n�mero de columnas de la matriz B: ");
    scanf("%d", &columnasB);

    printf("Ingrese los elementos de la matriz B:\n");
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Verificar si las dimensiones son v�lidas para la multiplicaci�n de matrices
    if (columnasA != filasB) {
        printf("No se puede realizar la multiplicaci�n de matrices. Las dimensiones no son v�lidas.\n");
        return 1;
    }

    multiplyMatrices(matrizA, matrizB, resultado, filasA, columnasA, columnasB);

    printf("El resultado de la multiplicaci�n de las matrices es:\n");
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void multiplyMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filasA, int columnasA, int columnasB) {
    // Recorrer las filas de la matriz A
    for (int i = 0; i < filasA; i++) {
        // Recorrer las columnas de la matriz B
        for (int j = 0; j < columnasB; j++) {
            resultado[i][j] = 0;
            // Recorrer las columnas de la matriz A (o filas de la matriz B)
            for (int k = 0; k < columnasA; k++) {
                // Realizar la multiplicaci�n de los elementos correspondientes y acumular el resultado en la matriz resultado
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

