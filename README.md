# tp-final-artemis-c
Simulador de Misiones Artemis en C - Escenario 1 (SLS)

# Simulador de Misiones Artemis - Escenario 1: SLS (Lenguaje C)

Trabajo Práctico Integrador Final - Algoritmos y Estructuras de Datos  
**Universidad Tecnológica Nacional - Facultad Regional Resistencia (UTN FRRe)**  
**Carrera:** Ingeniería en Sistemas de Información  

---

## 🚀 Descripción del Proyecto
Este sistema interactivo por consola simula la primera fase de despegue y propulsión del cohete **Space Launch System (SLS)** elevando la nave Orion, modelando las ecuaciones de movimiento rectilíneo uniformemente acelerado (MRUV), desprendimiento de cohetes SRB, apagado de motores a altitud objetivo y un escenario analítico de emergencia por caída libre.

## 📁 Estructura del Código (Modularización en C)
El proyecto se encuentra estrictamente modularizado en archivos `.c` y `.h`[cite: 4]:
- **`main.c`**: Gestiona el menú principal de navegación y el flujo interactivo del usuario[cite: 4].
- **`simulador.h`**: Contiene las constantes físicas (`#define`), definición de estructuras (`struct`) y prototipos públicos[cite: 4].
- **`simulador.c`**: Implementa los algoritmos de cálculo físico, cinemática y factores de gravedad[cite: 3, 4].
- **`validaciones.h` / `validaciones.c`**: Mecanismos de lectura segura para evitar errores o bucles ante entradas no numéricas[cite: 2, 4, 8].

## ⚙️ Instrucciones de Compilación y Ejecución
Para compilar el proyecto utilizando el compilador de GCC desde la terminal, ejecute el siguiente comando (incluyendo la bandera `-lm` para la librería matemática):

```bash
gcc main.c simulador.c validaciones.c -o simulador -lm