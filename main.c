#include <stdio.h>
#include "simulador.h"
#include "validaciones.h"

int main() {
    int opcion;
    
    do {
        printf("\n==========================================================\n");
        printf("     SIMULADOR DE MISIONES ARTEMIS - SLS (UTN FRRe)       \n");
        printf("==========================================================\n");
        printf("1. Ejecutar Simulacion Oficial Artemis (Default)[cite: 2, 3]\n");
        printf("2. Simulacion Personalizada con Validacion (Modo Ingeniero)[cite: 3]\n");
        printf("3. Simulador de Vuelo por Pasos (Telemetria)[cite: 3]\n");
        printf("4. Cuestionario de Analisis Fisico (Modo Trivia)\n");
        printf("5. Salir\n");
        printf("==========================================================\n");
        
        opcion = leerEnteroSeguro("Seleccione una opcion (1-5): ");
        
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
                printf("\n[INFO] Ingrese los parametros (Se validaran rangos fisicos):\n");
                ParametrosMision p;
                p.g = GRAVEDAD; 
                
                // Tarea 4.2 & 4.3: Validaciones estrictas de rangos físicos realistes
                do {
                    p.a1 = leerFlotanteSeguro("  - Aceleracion 1ra fase a1 (> 0 m/s^2): ");
                    if (p.a1 <= 0) printf("  [ERROR] La aceleracion debe ser positiva.\n");
                } while (p.a1 <= 0);

                do {
                    p.t1 = leerFlotanteSeguro("  - Tiempo de desacople t1 (> 0 s): ");
                    if (p.t1 <= 0) printf("  [ERROR] El tiempo debe ser mayor a 0.\n");
                } while (p.t1 <= 0);

                do {
                    p.a2 = leerFlotanteSeguro("  - Aceleracion 2da fase a2 (> 0 m/s^2): ");
                    if (p.a2 <= 0) printf("  [ERROR] La aceleracion debe ser positiva.\n");
                } while (p.a2 <= 0);

                double y1_aprox = 0.5 * p.a1 * p.t1 * p.t1;
                do {
                    p.h_meta = leerFlotanteSeguro("  - Altitud objetivo h (m): ");
                    if (p.h_meta <= y1_aprox) {
                        printf("  [ERROR] La altitud meta (%.1f m) debe ser mayor a la altitud de desacople SRB (%.1f m).\n", p.h_meta, y1_aprox);
                    }
                } while (p.h_meta <= y1_aprox);
                
                ResultadosSimulacion r;
                calcularSimulacion(p, &r);
                mostrarReporte(r);
                break;
            }
            case 3: {
                ParametrosMision p = {
                    .a1 = A1_DEFAULT,
                    .t1 = T1_DEFAULT,
                    .a2 = A2_DEFAULT,
                    .h_meta = H_OBJETIVO,
                    .g = GRAVEDAD
                };
                simularPasoAPaso(p);
                break;
            }
            case 4:
                mostrarTriviaFisica();
                break;
            case 5:
                printf("\nSaliendo del simulador de la mision Artemis. ¡Exitos en la defensa!\n");
                break;
            default:
                printf("\n[ERROR] Opcion no valida. Seleccione entre 1 y 5.\n");
        }
    } while (opcion != 5);

    return 0;
}