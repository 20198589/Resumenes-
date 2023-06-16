#include <stdio.h>

const int PRO = 2;
const int MES = 12;
const int YEAR = 1;

void Lectura(float [][MES][YEAR], int, int, int);
void Funcion1(float [][MES][YEAR], int, int, int);
void Funcion2(float [][MES][YEAR], int, int, int);
void Funcion3(float [][MES][YEAR], int, int, int);

void main(void)
{
    float LLU[PRO][MES][YEAR];
    Lectura(LLU, PRO, MES, YEAR);
    Funcion1(LLU, PRO, MES, YEAR);
    Funcion2(LLU, PRO, MES, YEAR);
    Funcion3(LLU, 18, MES, 5);
}

void Lectura(float A[][MES][YEAR], int F, int C, int P)
{
    int K, I, J;
    for (K = 0; K < P; K++)
    {
        for (I = 0; I < F; I++)
        {
            for (J = 0; J < C; J++)
            {
                printf("Ano: %d\tProvincia: %d\tMes: %d: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
        }
    }
}

void Funcion1(float A[][MES][YEAR], int F, int C, int P)
{
    int I, K, J, EMAY = -1;
    float ELLU = -1.0, SUM;
    for (I = 0; I < F; I++)
    {
        SUM = 0.0;
        for (K = 0; K < P; K++)
        {
            for (J = 0; J < C; J++)
            {
                SUM += A[I][J][K];
            }
        }
        SUM /= P * C;
        if (SUM > ELLU)
        {
            ELLU = SUM;
            EMAY = I;
        }
    }
    printf("\n\nProvincia con mayor registro de lluvias: %d", EMAY + 1);
    printf("\nRegistro: %.2f", ELLU);
}

void Funcion2(float A[][MES][YEAR], int F, int C, int P)
{
    int I, J, EMEN;
    float ELLU = 1000, SUM;
    for (I = 0; I < F; I++)
    {
        SUM = 0;
        for (J = 0; J < C; J++)
        {
            SUM += A[I][J][P - 1];
        }
        SUM /= C;
        if (SUM < ELLU)
        {
            ELLU = SUM;
            EMEN = I;
        }
    }
    printf("\n\nProvincia con menor registro anual de lluvias en el ultimo ano: %d", EMEN + 1);
    printf("\nRegistro anual: %.2f", ELLU);
}

void Funcion3(float A[][MES][YEAR], int F, int C, int P)
{
    int J, EMES = -1;
    float ELLU = -1.0;
    for (J = 0; J < C; J++)
    {
        if (A[F - 1][J][P - 1] > ELLU)
        {
            ELLU = A[F - 1][J][P-1];
            EMES = J;
        }
        printf("\n\nMes: %d Lluvias: %.2f", EMES+1, ELLU);
    }
}
