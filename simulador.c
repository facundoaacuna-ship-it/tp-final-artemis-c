#include <stdio.h>
#include <math.h>
#include "simulador.h"

void calcularSimulacion(ParametrosMision p, ResultadosSimulacion *r) {
    r->v1 = V0_INICIAL + (p.a1 * p.t1);
    r->y1 = Y0_INICIAL + (V0_INICIAL * p.t1) + (0.5 * p.a1 * p.t1 * p.t1);

    double delta_y2 = p.h_meta - r->y1;
    double v2_cuadrado = (r->v1 * r->v1) + (2.0 * p.a2 * delta_y2);
    r->v2 = sqrt(v2_cuadrado);

    double delta_y_subida = (r->v2 * r->v2) / (2.0 * p.g);
    r->h_max = p.h_meta + delta_y_subida;

    r->g_cinematica = p.a1 / p.g;
    r->g_aparente = (p.a1 + p.g) / p.g;
}

void mostrarReporte(ResultadosSimulacion r) {
    printf("\n==========================================================\n");
    printf("        REPORTE DE TELEMETRIA - MISION ARTEMIS (SLS)      \n");
    printf("==========================================================\n");
    printf(" [FASE 1] Desacople de los SRB (t = 120.0 s):\n");
    printf("   - Rapidez al desacople (v1) : %.2f m/s  (%.2f km/h)\n", r.v1, r.v1 * 3.6);
    printf("   - Altitud recorrida (y1)    : %.2f m   (%.2f km)\n", r.y1, r.y1 / 1000.0);
    printf("----------------------------------------------------------\n");
    printf(" [FASE 2] Apagado de Motores Nucleo (h = 160.0 km):\n");
    printf("   - Rapidez maxima (v2)       : %.2f m/s  (%.2f km/h)\n", r.v2, r.v2 * 3.6);
    printf("----------------------------------------------------------\n");
    printf(" [FASE 3] Escenario de Emergencia / Caida Libre:\n");
    printf("   - Altitud maxima (h_max)    : %.2f m  (%.2f km)\n", r.h_max, r.h_max / 1000.0);
    printf("----------------------------------------------------------\n");
    printf(" [FACTORES G] Carga Fisiologica de la Tripulacion:\n");
    printf("   - Aceleracion neta (a1 / g) : %.2f g\n", r.g_cinematica);
    printf("   - Carga G aparente (sentida): %.2f g\n", r.g_aparente);
    printf("==========================================================\n");
}

// Tarea 3.5: Simulador de Vuelo por Pasos (telemetría secuencial cada 20 segundos)
void simularPasoAPaso(ParametrosMision p) {
    printf("\n==========================================================\n");
    printf("       SIMULACION DE VUELO SECUENCIAL (PASO A PASO)       \n");
    printf("==========================================================\n");
    printf("  Tiempo (s) | Altitud (m)  | Rapidez (m/s) | Fase de Vuelo\n");
    printf("----------------------------------------------------------\n");
    
    double t_actual = 0;
    double dt = 20.0; // Intervalos de 20 segundos
    
    while (t_actual <= p.t1) {
        double y = 0.5 * p.a1 * t_actual * t_actual;
        double v = p.a1 * t_actual;
        printf("  %9.1f  | %12.2f | %13.2f | Fase 1 (SRB)\n", t_actual, y, v);
        t_actual += dt;
    }
    
    // Simular tramo final hasta h_meta
    double y1 = 0.5 * p.a1 * p.t1 * p.t1;
    double v1 = p.a1 * p.t1;
    double delta_y2 = p.h_meta - y1;
    double t2_total = delta_y2 / (v1 + 100.0); // Estimación aproximada de tiempo en Fase 2
    
    printf("  %9.1f  | %12.2f | %13.2f | Desacople SRB\n", p.t1, y1, v1);
    printf("  [INFO] Motores principales activos hasta h = %.1f m...\n", p.h_meta);
    printf("==========================================================\n");
}

// Tarea 3.5: Cuestionario de Análisis Físico (Modo Trivia)
void mostrarTriviaFisica() {
    printf("\n==========================================================\n");
    printf("          CUESTIONARIO DE ANALISIS FISICO (TRIVIA)        \n");
    printf("==========================================================\n");
    printf(" P1: ¿Por que la aceleracion sentida por la tripulacion\n");
    printf("     es mayor que la aceleracion neta del cohete?\n");
    printf(" R: Porque el asiento debe ejercer una fuerza normal (N)\n");
    printf("    que soporte el peso de la persona (mg) y ademas le\n");
    printf("    imprima la aceleracion de ascenso: N = m(a1 + g).\n");
    printf("----------------------------------------------------------\n");
    printf(" P2: ¿Que ley fisica explica el ascenso tras apagar motores?\n");
    printf(" R: La 1ra Ley de Newton (Inercia) combinada con la conservacion\n");
    printf("    de la energia, frenando progresivamente por la gravedad.\n");
    printf("==========================================================\n");
}