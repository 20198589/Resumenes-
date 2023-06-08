#include <stdio.h>

/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 números primos. */

const int TAM = 100;

void Imprime(int[], int);
void Primo(int, int*);

void main(void)
{
    int P[TAM] = {2}; // Se corrige el valor inicial del arreglo de primos
    int FLA, J = 1, PRI = 3; // Se corrige el valor inicial de J
    while (J < TAM) // Se cambia <= a <
    {
        FLA = 1;
        Primo(PRI, &FLA);
        if (FLA)
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);
}

void Primo(int A, int *B)
{
    int DI = 2; // Se corrige el valor inicial de DI a 2
    while (*B && (DI <= (A / 2))) // Se cambia < a <=
    {
        if ((A % DI) == 0)
            *B = 0;
        DI++;
    }
}

void Imprime(int Primos[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}
