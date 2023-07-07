#include <stdio.h>
#include <string.h>

struct tabla {
    char nombre[20];
    float distancia;
    float gastoCombustible;
    float gastosVarios;
};

float calcularGastoCombustible(float distancia, int eficiencia) {
    float consumoPorKm = eficiencia / 100.0;
    float gastoCombustible = distancia * consumoPorKm * 51.75;
    return gastoCombustible;
}

float calcularGastosVarios(float costoLlantas, float costoSeguro, float costoAceite) {
    float gastosLlantas = costoLlantas / 45000.0;
    float gastosSeguro = costoSeguro / 15000.0;
    float gastosAceite = costoAceite / 25000.0;
    float gastosVarios = gastosLlantas + gastosSeguro + gastosAceite;
    return gastosVarios;
}

float calcularCostoGasolinaPorKilometro(float eficiencia, float* precioGasolinaPorLitro) {
    *precioGasolinaPorLitro = 273.0 / 3.785;
    float consumoPorKm = eficiencia / 100.0;
    float costoGasolinaPorKm = *precioGasolinaPorLitro / consumoPorKm;
    return costoGasolinaPorKm;
}

void obtenerInformacion(struct tabla *datos) {
    printf("Nombre del cliente: ");
    scanf("%s", datos->nombre);

    printf("Distancia a recorrer (Km): ");
    scanf("%f", &(datos->distancia));
}

void imprimirTabla(struct tabla *datos, int eficienciaMin, int eficienciaMax,
                   float costoLlantas, float costoSeguro, float costoAceite) {
    printf("Cliente\t\tDistancia\tEficiencia\tGasto Combustible\tGastos Varios\tCosto Gasolina por Km\tTotal\n");
    for (int eficiencia = eficienciaMin; eficiencia <= eficienciaMax; eficiencia++) {
        datos->gastoCombustible = calcularGastoCombustible(datos->distancia, eficiencia);
        datos->gastosVarios = calcularGastosVarios(costoLlantas, costoSeguro, costoAceite);
        float precioGasolinaPorLitro;
        float costoGasolinaPorKm = calcularCostoGasolinaPorKilometro(eficiencia, &precioGasolinaPorLitro);
        float total = datos->gastoCombustible + datos->gastosVarios;
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\t\t\t%.2f\t\t\t%.2f\t\t\t\t%.2f\n", datos->nombre, datos->distancia, eficiencia,
               datos->gastoCombustible, datos->gastosVarios, costoGasolinaPorKm, total);
    }
}

int main() {
    struct tabla datos;
    int eficienciaMin, eficienciaMax;
    float costoLlantas, costoSeguro, costoAceite;

    printf("Cálculo de costo por visita.\n");
    obtenerInformacion(&datos);

    printf("Eficiencia Mínima del Vehículo (L/100km): ");
    scanf("%d", &eficienciaMin);

    printf("Eficiencia Máxima del Vehículo (L/100km): ");
    scanf("%d", &eficienciaMax);

    printf("Costo de las llantas (RD$xUnidad): ");
    scanf("%f", &costoLlantas);

    printf("Costo del seguro anual (RD$): ");
    scanf("%f", &costoSeguro);

    printf("Costo del cambio de aceite (RD$): ");
    scanf("%f", &costoAceite);

    imprimirTabla(&datos, eficienciaMin, eficienciaMax, costoLlantas, costoSeguro, costoAceite);

    return 0;
}

