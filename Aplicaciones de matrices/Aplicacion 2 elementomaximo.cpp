#include <stdio.h>

#define MAX_SIZE 10

int findMaxElement(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas);

int main() {
    int filas, columnas;
    int matriz[MAX_SIZE][MAX_SIZE];

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);  // Lectura del número de filas desde la entrada estándar

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);  // Lectura del número de columnas desde la entrada estándar

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {  // Bucle para recorrer las filas de la matriz
        for (int j = 0; j < columnas; j++) {  // Bucle para recorrer las columnas de la matriz
            scanf("%d", &matriz[i][j]);  // Lectura de los elementos de la matriz desde la entrada estándar
        }
    }

    int maxElement = findMaxElement(matriz, filas, columnas);  // Llamada a la función para encontrar el elemento máximo

    printf("El elemento máximo en la matriz es: %d\n", maxElement);  // Impresión del elemento máximo en la salida estándar

    return 0;  // Finalización del programa y retorno de 0 para indicar que se ejecutó correctamente
}

int findMaxElement(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    int maxElement = matriz[0][0];  // Inicialización del máximo con el primer elemento de la matriz

    // Recorrido de cada elemento de la matriz
    for (int i = 0; i < filas; i++) {  // Bucle para recorrer las filas de la matriz
        for (int j = 0; j < columnas; j++) {  // Bucle para recorrer las columnas de la matriz
            // Si el elemento actual es mayor que el máximo actual, actualizar el máximo
            if (matriz[i][j] > maxElement) {
                maxElement = matriz[i][j];
            }
        }
    }

    return maxElement;  // Retorno del elemento máximo encontrado
}

