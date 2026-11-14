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

void mostrarReporte(ResultadosSimulacion r, int usarKmH) {
    printf("\n==========================================================\n");
    printf("        REPORTE DE TELEMETRIA - MISION ARTEMIS (SLS)      \n");
    printf("==========================================================\n");
    if (usarKmH) {
        printf(" [FASE 1] Desacople de los SRB (t = 120.0 s):\n");
        printf("   - Rapidez al desacople (v1) : %.2f km/h\n", r.v1 * 3.6);
        printf("   - Altitud recorrida (y1)    : %.2f km\n", r.y1 / 1000.0);
        printf("----------------------------------------------------------\n");
        printf(" [FASE 2] Apagado de Motores Nucleo (h = 160.0 km):\n");
        printf("   - Rapidez maxima (v2)       : %.2f km/h\n", r.v2 * 3.6);
        printf("----------------------------------------------------------\n");
        printf(" [FASE 3] Escenario de Emergencia / Caida Libre:\n");
        printf("   - Altitud maxima (h_max)    : %.2f km\n", r.h_max / 1000.0);
    } else {
        printf(" [FASE 1] Desacople de los SRB (t = 120.0 s):\n");
        printf("   - Rapidez al desacople (v1) : %.2f m/s\n", r.v1);
        printf("   - Altitud recorrida (y1)    : %.2f m\n", r.y1);
        printf("----------------------------------------------------------\n");
        printf(" [FASE 2] Apagado de Motores Nucleo (h = 160.0 km):\n");
        printf("   - Rapidez maxima (v2)       : %.2f m/s\n", r.v2);
        printf("----------------------------------------------------------\n");
        printf(" [FASE 3] Escenario de Emergencia / Caida Libre:\n");
        printf("   - Altitud maxima (h_max)    : %.2f m\n", r.h_max);
    }
    printf("----------------------------------------------------------\n");
    printf(" [FACTORES G] Carga Fisiologica de la Tripulacion:\n");
    printf("   - Aceleracion neta (a1 / g) : %.2f g\n", r.g_cinematica);
    printf("   - Carga G aparente (sentida): %.2f g\n", r.g_aparente);
    printf("==========================================================\n");
}

// Simulador de Vuelo por Pasos con Barra de Progreso ASCII (Tarea 5.2)
void simularPasoAPaso(ParametrosMision p) {
    printf("\n==========================================================\n");
    printf("    SIMULACION DE ASCENSO SECUENCIAL Y BARRA DE PROGRESO  \n");
    printf("==========================================================\n");
    
    double t_actual = 0;
    double dt = 20.0;
    
    while (t_actual <= p.t1) {
        double y = 0.5 * p.a1 * t_actual * t_actual;
        int porcentaje = (int)((y / p.h_meta) * 100.0);
        if (porcentaje > 100) porcentaje = 100;
        
        printf(" [%3.0f s] Altura: %8.1f m | Progreso: [", t_actual, y);
        int bloques = porcentaje / 10;
        for (int i = 0; i < 10; i++) {
            if (i < bloques) printf("#");
            else printf("-");
        }
        printf("] %d%%\n", porcentaje);
        
        t_actual += dt;
    }
    printf("==========================================================\n");
}

void mostrarTriviaFisica() {
    printf("\n==========================================================\n");
    printf("          CUESTIONARIO DE ANALISIS FISICO (TRIVIA)        \n");
    printf("==========================================================\n");
    printf(" P1: ¿Por que la aceleracion sentida por la tripulacion\n");
    printf("     es mayor que la aceleracion neta del cohete?\n");
    printf(" R: Porque el asiento debe ejercer una fuerza normal (N)\n");
    printf("    que soporte el peso (mg) y acelere la masa: N = m(a1 + g).\n");
    printf("----------------------------------------------------------\n");
    printf(" P2: ¿Que ley fisica explica el ascenso tras apagar motores?\n");
    printf(" R: La 1ra Ley de Newton (Inercia) y la conservacion de energia.\n");
    printf("==========================================================\n");
}