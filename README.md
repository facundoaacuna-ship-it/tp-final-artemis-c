# 🚀 Simulador de Misiones Artemis - Escenario 1: SLS (Lenguaje C)

**Trabajo Práctico Integrador Final**  
* **Universidad:** Universidad Tecnológica Nacional - Facultad Regional Resistencia (UTN FRRe)[cite: 1]
* **Carrera:** Ingeniería en Sistemas de Información[cite: 1]
* **Cátedra:** Algoritmos y Estructuras de Datos[cite: 1]
* **Comisión:** K1.2
* **Integrantes:**
  * Facundo Acuña (Legajo: 31709)
  * Facundo Nahuel Zapatero
  * Drago Valdez Picech
  * Joaquín Nicolás Vargas
---

## 📋 Descripción del Escenario y Reglas de Funcionamiento
El sistema simula por consola el ascenso y propulsión del cohete **Space Launch System (SLS)** elevando la cápsula Orion (Situación Problema 1)[cite: 2]. El programa modela un Movimiento Rectilíneo Uniformemente Variado (MRUV) dividido en fases[cite: 2]:
1. **Fase 1 (Propulsión con SRB):** Ascenso vertical desde el reposo con aceleración constante $a_1$ hasta el desacople de los propulsores sólidos en $t_1$[cite: 2, 3].
2. **Fase 2 (Núcleo Principal):** Aceleración $a_2$ hasta alcanzar la altitud objetivo $h$, donde se apagan los motores.
3. **Escenario de Falla (Caída Libre):** Cálculo de la altitud máxima $h_{\text{máx}}$ alcanzada por inercia bajo la acción de la gravedad $g$.
4. **Cargas $g$:** Cálculo de la aceleración cinemática ($a_1/g$) y la carga fisiológica aparente sentida por la tripulación ($(a_1+g)/g$)[cite: 3].

### Modos de Juego / Simulación
* **Modo Oficial:** Ejecuta la misión con los parámetros nominales establecidos por la NASA/cátedra ($a_1=20\text{ m/s}^2$, $t_1=120\text{ s}$, $a_2=12.5\text{ m/s}^2$, $h=160\text{ km}$)[cite: 2, 3].
* **Modo Ingeniero (Personalizado):** Permite ingresar parámetros propios con validación estricta de rangos físicos[cite: 3].
* **Vuelo Secuencial:** Muestra la telemetría segundo a segundo con una barra de progreso en ASCII.
* **Modo Trivia:** Cuestionario analítico con fundamentos físicos de la misión.
* **Exportación:** Genera automáticamente un archivo `reporte_mision.txt` con el resumen de desempeño[cite: 2].

---

## 🏗️ Arquitectura Modular del Proyecto
```text
tp-final-artemis-c/
├── main.c            # Menú principal interactivo, limpieza de pantalla y flujo general
├── simulador.h       # Constantes (#define), structs (ParametrosMision, ResultadosSimulacion) y prototipos[cite: 4]
├── simulador.c       # Lógica física, cálculos cinemáticos, barra ASCII y exportación a TXT[cite: 4]
├── validaciones.h    # Prototipos de lectura segura[cite: 4]
├── validaciones.c    # Lectura blindada mediante fgets() + sscanf() para evitar cuelgues
└── README.md         # Documentación del proyecto y registro de IA

## 🤖 Registro Obligatorio de Inteligencia Artificial (Bitácora de IA)
De acuerdo con los lineamientos de transparencia de la cátedra, se documenta el uso de herramientas de asistencia de IA Generativa durante el desarrollo del proyecto:

1. **Diseño de Arquitectura y Modularización:**
   * *Uso:* Consulta sobre cómo estructurar un proyecto en C dividiéndolo limpiamente en archivos de cabecera (`.h`) y de implementación (`.c`) evitando dependencias circulares.
   * *Adaptación:* Se implementaron guardas de inclusión (`#ifndef / #define / #endif`) y se estructuró la información mediante registros (`structs` como `ParametrosMision` y `ResultadosSimulacion`) pasados por referencia mediante punteros para optimizar el rendimiento y la memoria.

2. **Validación Robusta de Entradas en Consola:**
   * *Uso:* Consulta sobre métodos seguros en C para evitar que las funciones de lectura colapsen o entren en bucle infinito ante entradas alfabéticas erróneas.
   * *Adaptación:* Se implementó el módulo de validaciones combinando `fgets` y `sscanf` en bucles `do-while`, añadiendo además restricciones lógicas de rangos físicos (ej. validar que la aceleración sea positiva y que la altitud meta sea superior al desacople de los SRB).

3. **Verificación del Modelo Físico del SLS:**
   * *Uso:* Consulta teórica sobre la diferencia entre la aceleración neta del cohete respecto al suelo y la fuerza $g$ aparente sentida por la tripulación.
   * *Adaptación:* Se programaron métricas separadas en el motor físico (`calcularSimulacion`) para calcular tanto la relación cinemática como la fuerza normal fisiológica que experimentan los astronautas.