#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int matriz[MAX_SIZE][MAX_SIZE];  // Declaración de una matriz utilizando un arreglo bidimensional
    int filas, columnas;

    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);  // Lectura del número de filas desde la entrada estándar

    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);  // Lectura del número de columnas desde la entrada estándar

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {  // Bucle para recorrer las filas de la matriz
        for (int j = 0; j < columnas; j++) {  // Bucle para recorrer las columnas de la matriz
            scanf("%d", &matriz[i][j]);  // Lectura de los elementos de la matriz desde la entrada estándar
        }
    }

    printf("La matriz ingresada es:\n");
    for (int i = 0; i < filas; i++) {  // Bucle para recorrer las filas de la matriz
        for (int j = 0; j < columnas; j++) {  // Bucle para recorrer las columnas de la matriz
            printf("%d ", matriz[i][j]);  // Impresión de los elementos de la matriz en la salida estándar
        }
        printf("\n");  // Impresión de un salto de línea para separar las filas de la matriz
    }

    return 0;  // Finalización del programa y retorno de 0 para indicar que se ejecutó correctamente
}
// En resumen, el código permite al usuario ingresar una matriz y muestra la matriz ingresada. Puede ser útil para verificar si los elementos de la matriz se 
//ingresaron correctamente o para realizar operaciones adicionales en la matriz más adelante en el programa.
