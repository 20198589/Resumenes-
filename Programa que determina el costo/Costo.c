#include <stdio.h>

float calcularGastoCombustible(float distancia, float eficienciaMinima, float eficienciaMaxima, float costoGasolina) {
    float eficienciaPromedio = (eficienciaMinima + eficienciaMaxima) / 2;
    float consumoCombustible = (eficienciaPromedio / 100) * distancia;
    float gastoCombustible = consumoCombustible * costoGasolina;
    return gastoCombustible;
}

float calcularGastosVarios(float costoLlanta, float rendimientoLlanta, float costoSeguro, float kilometrajeAnual, float costoAceite, float cambioAceiteKm) {
    float gastoLlantas = (kilometrajeAnual / rendimientoLlanta) * costoLlanta;
    float gastoSeguro = costoSeguro * (kilometrajeAnual / 1000);
    float gastoAceite = (kilometrajeAnual / cambioAceiteKm) * costoAceite;
    float gastosVarios = gastoLlantas + gastoSeguro + gastoAceite;
    return gastosVarios;
}

int main() {
    char cliente[100];
    float distancia, costoGasolina, eficienciaMinima, eficienciaMaxima, costoLlanta, costoSeguro, costoAceite;
    float rendimientoLlanta = 45000;  // Promedio de rendimiento de llantas
    float cambioAceiteKm = 25000;  // Kilómetros recomendados para el cambio de aceite
    
    // Solicitar datos al usuario
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", cliente);
    printf("Ingrese la distancia a recorrer (en km): ");
    scanf("%f", &distancia);
    printf("Ingrese el costo de la gasolina (en RD$ por galón): ");
    scanf("%f", &costoGasolina);
    printf("Ingrese la eficiencia mínima del vehículo (en L/100km): ");
    scanf("%f", &eficienciaMinima);
    printf("Ingrese la eficiencia máxima del vehículo (en L/100km): ");
    scanf("%f", &eficienciaMaxima);
    printf("Ingrese el costo de las llantas (en RD$ por unidad): ");
    scanf("%f", &costoLlanta);
    printf("Ingrese el costo del seguro (en RD$ al año): ");
    scanf("%f", &costoSeguro);
    printf("Ingrese el costo del cambio de aceite (en RD$): ");
    scanf("%f", &costoAceite);
    
    // Calcular gastos
    float gastoCombustible = calcularGastoCombustible(distancia, eficienciaMinima, eficienciaMaxima, costoGasolina);
    float gastosVarios = calcularGastosVarios(costoLlanta, rendimientoLlanta, costoSeguro, distancia, costoAceite, cambioAceiteKm);
    float total = gastoCombustible + gastosVarios;
    
    // Imprimir tabla con los resultados
    printf("\nTabla de Costos:\n");
    printf("Cliente\t\tDistancia\tGasto Combustible\tGastos Varios\t\tTotal\n");
    printf("%s\t%.2f\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n", cliente, distancia, gastoCombustible, gastosVarios, total);
    
    return 0;
}

