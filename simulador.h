#ifndef SIMULADOR_H
#define SIMULADOR_H

// --- CONSTANTES DE LA MISIÓN ARTEMIS (Escenario 1: SLS) ---
#define GRAVEDAD 9.80       // Aceleración de la gravedad (m/s^2)[cite: 3]
#define V0_INICIAL 0.0      // Velocidad inicial en plataforma (m/s)[cite: 2]
#define Y0_INICIAL 0.0      // Altitud inicial en plataforma (m)[cite: 2]

#define A1_DEFAULT 20.0     // Aceleración 1ra fase con SRB (m/s^2)[cite: 2]
#define T1_DEFAULT 120.0    // Tiempo de desacople de los SRB (s)[cite: 2, 3]
#define A2_DEFAULT 12.5     // Aceleración 2da fase núcleo (m/s^2)[cite: 3]
#define H_OBJETIVO 160000.0 // Altitud de apagado de motores (m)[cite: 3]

// --- ESTRUCTURAS DE DATOS ---
typedef struct {
    double a1;      // Aceleración primera fase
    double t1;      // Tiempo de desacople SRB
    double a2;      // Aceleración segunda fase
    double h_meta;  // Altitud objetivo de apagado
    double g;       // Aceleración de la gravedad
} ParametrosMision;

typedef struct {
    double v1;          // Velocidad al desacople SRB[cite: 3]
    double y1;          // Altitud recorrida al desacople SRB[cite: 3]
    double v2;          // Velocidad máxima al apagar motores[cite: 3]
    double h_max;       // Altitud máxima alcanzada en caída libre[cite: 3]
    double g_cinematica;// Múltiplo de aceleración cinemática (a1/g)[cite: 3]
    double g_aparente;  // Carga g fisiológica sentida por tripulación ((a1+g)/g)[cite: 3]
} ResultadosSimulacion;

// --- PROTOTIPOS DE FUNCIONES ---
void calcularSimulacion(ParametrosMision p, ResultadosSimulacion *r);
void mostrarReporte(ResultadosSimulacion r, int usarKmH);
void simularPasoAPaso(ParametrosMision p); // Tarea 3.5: Vuelo paso a paso
void mostrarTriviaFisica();                 // Tarea 3.5: Cuestionario de análisis

#endif