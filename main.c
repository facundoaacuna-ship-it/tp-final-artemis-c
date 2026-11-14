#include <stdio.h>
#include "simulador.h"
#include "validaciones.h"

int main() {
    int opcion;
    
    do {
        printf("\n==================================================\n");
        printf("     SIMULADOR DE MISIONES ARTEMIS - SLS (UTN)    \n");
        printf("==================================================\n");
        printf("1. Ejecutar Simulacion Oficial Artemis (Default)\n");
        printf("2. Simulacion Personalizada (Modo Ingeniero)\n");
        printf("3. Salir\n");
        printf("==================================================\n");
        
        opcion = leerEnteroSeguro("Seleccione una opcion (1-3): ");
        
        switch (opcion) {
            case 1: {
                printf("\n[INFO] Ejecutando con parametros nominales oficiales...\n");
                ParametrosMision p = {
                    .a1 = A1_DEFAULT,
                    .t1 = T1_DEFAULT,
                    .a2 = A2_DEFAULT,
                    .h_meta = H_OBJETIVO,
                    .g = GRAVEDAD
                };
                ResultadosSimulacion r;
                calcularSimulacion(p, &r);
                mostrarReporte(r);
                break;
            }
            case 2: {
                printf("\n[INFO] Ingrese los parametros personalizados de la mision:\n");
                ParametrosMision p;
                p.g = GRAVEDAD; 
                p.a1 = leerFlotanteSeguro("  - Aceleracion 1ra fase a1 (m/s^2) [Ej: 20.0]: ");
                p.t1 = leerFlotanteSeguro("  - Tiempo de desacople SRB t1 (s) [Ej: 120.0]: ");
                p.a2 = leerFlotanteSeguro("  - Aceleracion 2da fase a2 (m/s^2) [Ej: 12.5]: ");
                p.h_meta = leerFlotanteSeguro("  - Altitud objetivo h (m) [Ej: 160000.0]: ");
                
                ResultadosSimulacion r;
                calcularSimulacion(p, &r);
                mostrarReporte(r);
                break;
            }
            case 3:
                printf("\nSaliendo del simulador de la mision Artemis. ¡Hasta luego!\n");
                break;
            default:
                printf("\n[ERROR] Opcion no valida. Seleccione entre 1 y 3.\n");
        }
    } while (opcion != 3);

    return 0;
}