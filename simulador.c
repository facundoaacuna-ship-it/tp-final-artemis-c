#include <stdio.h>
#include <math.h>
#include "simulador.h"

// Función que realiza todos los cálculos físicos del Escenario 1
void calcularSimulacion(ParametrosMision p, ResultadosSimulacion *r) {
    // 1. Fase 1: Desacople de los SRB (t1)
    r->v1 = p.v0 + (p.a1 * p.t1);
    r->y1 = p.y0 + (p.v0 * p.t1) + (0.5 * p.a1 * p.t1 * p.t1);

    // 2. Fase 2: Desde el desacople hasta la altitud objetivo (h_meta)
    double delta_y2 = p.h_meta - r->y1;
    double v2_cuadrado = (r->v1 * r->v1) + (2.0 * p.a2 * delta_y2);
    r->v2 = sqrt(v2_cuadrado);

    // 3. Escenario de falla / Caída libre a partir de h_meta con velocidad v2
    double delta_y_subida = (r->v2 * r->v2) / (2.0 * p.g);
    r->h_max = p.h_meta + delta_y_subida;

    // 4. Aceleraciones y múltiplos de gravedad (g)
    r->g_cinematica = p.a1 / p.g;
    r->g_aparente = (p.a1 + p.g) / p.g;
}

// Función para mostrar el reporte analítico avanzado por consola
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