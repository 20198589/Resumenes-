#include <stdio.h>

#define MAX_SIZE 10

void subtractMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas);

int main() {
    int filas, columnas;
    int matrizA[MAX_SIZE][MAX_SIZE], matrizB[MAX_SIZE][MAX_SIZE], resultado[MAX_SIZE][MAX_SIZE];

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Ingrese los elementos de la matriz B:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Llamada a la función para restar las matrices
    subtractMatrices(matrizA, matrizB, resultado, filas, columnas);

    printf("El resultado de la resta de las matrices es:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void subtractMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    // Recorrer cada elemento de las matrices A y B
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // Restar los elementos correspondientes y almacenar el resultado en la matriz resultado
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

