#include <stdio.h>
#include "validaciones.h"

// Función para leer un número flotante validando errores de entrada
double leerFlotanteSeguro(const char *mensaje) {
    double valor;
    char buffer[100];
    int valido = 0;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Intentamos convertir el texto ingresado a un número double
            if (sscanf(buffer, "%lf", &valor) == 1) {
                valido = 1;
            } else {
                printf("  [ERROR] Entrada invalida. Por favor, ingrese un numero valido.\n");
            }
        }
    } while (!valido);

    return valor;
}

// Función para leer un número entero validando errores de entrada
int leerEnteroSeguro(const char *mensaje) {
    int valor;
    char buffer[100];
    int valido = 0;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &valor) == 1) {
                valido = 1;
            } else {
                printf("  [ERROR] Entrada invalida. Por favor, ingrese un numero entero valido.\n");
            }
        }
    } while (!valido);

    return valor;
}