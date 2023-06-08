#include <stdio.h>

/* Conflicto de variables con el mismo nombre. */


void f1(void); /* Prototipo de función. */

int K = 5;     /* Variable global. */

int main(void) {
    printf("\t\tEstos son los valores de las variables locales y globales:");
    int I;
    for (I = 1; I <= 3; I++)
        f1();
    return 0;
}

void f1(void) {
    K += K;
    printf("\n\nEl valor de la variable local es: %d", K);
    K = K + K; /* Uso de la variable global. */
    printf("\nEl valor de la variable global es: %d", K);
}
