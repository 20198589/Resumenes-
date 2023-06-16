#include <stdio.h>
#define CANTIDAD_P 5

void Lectura1(int [CANTIDAD_P][12]);
void Lectura2(float [], int);
void Funcion1(int [][12], int, int, float *, float *);
void Funcion2(float *, int);
void Funcion3(float *, int);

void main(void) {
    int FAB[CANTIDAD_P][12] = {0};
    float COS[CANTIDAD_P], VEN[CANTIDAD_P];

    Lectura1(FAB);
    Lectura2(COS, CANTIDAD_P);
    Funcion1(FAB, CANTIDAD_P, 12, COS, VEN);
    Funcion2(VEN, CANTIDAD_P);
    Funcion3(VEN, CANTIDAD_P);
}

void Lectura1(int A[][12]) {
    int MES, PRO, CAN;

    printf("\nIngrese mes, tipo de producto y cantidad vendida: ");
    scanf("%d %d %d", &MES, &PRO, &CAN);

    while (MES != -1 && PRO != -1 && CAN != -1) {
        A[MES - 1][PRO - 1] += CAN;
        printf("Ingrese mes, tipo de producto y cantidad vendida: ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

void Lectura2(float A[], int N) {
    int I;

    for (I = 0; I < N; I++) {
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void Funcion1(int A[][12], int F, int C, float V1[], float V2[]) {
    int I, J, SUM;

    printf("\n");
    for (I = 0; I < F; I++) {
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J];
        V2[I] = V1[I] * SUM;
        printf("\nTotal de ventas del producto %d: %8.2f", I + 1, V2[I]);
    }
}

void Funcion2(float A[], int C) {
    int I;
    float SUM = 0.0;

    for (I = 0; I < C; I++)
        SUM += A[I];

    printf("\n\nTotal de ventas de la fabrica: %.2f", SUM);
}

void Funcion3(float A[], int C) {
    int I, TPR = 0;
    float VEN = A[0];

    for (I = 1; I < C; I++) {
        if (VEN < A[I]) {
            TPR = I;
            VEN = A[I];
        }
    }

    printf("\n\nTipo de Producto mas vendido: %d \t Ventas: %.2f", TPR + 1, VEN);
}
