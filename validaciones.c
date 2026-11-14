#include <stdio.h>
#include "validaciones.h"

double leerFlotanteSeguro(const char *mensaje) {
    double valor;
    char buffer[100];
    int valido = 0;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf", &valor) == 1) {
                valido = 1;
            } else {
                printf("  [ERROR] Entrada invalida. Ingrese un numero real.\n");
            }
        }
    } while (!valido);

    return valor;
}

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
                printf("  [ERROR] Entrada invalida. Ingrese un numero entero.\n");
            }
        }
    } while (!valido);

    return valor;
}