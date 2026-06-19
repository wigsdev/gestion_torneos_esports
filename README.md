# 🎮 Sistema de Gestión de Torneos de Videojuegos (eSports)

![C++ Version](https://img.shields.io/badge/C%2B%2B-11%20%2F%2014%20%2F%2017-blue.svg?style=for-the-badge&logo=c%2B%2B)
![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg?style=for-the-badge&logo=github)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg?style=for-the-badge)
![License](https://img.shields.io/badge/license-MIT-green.svg?style=for-the-badge)

Gestor de torneos de eSports diseñado bajo restricciones de memoria de bajo nivel. Implementa estructuras de datos dinámicas y estáticas personalizadas desde cero en C++, prescindiendo en su totalidad de la biblioteca estándar de plantillas (STL).

---

## 📋 Características Principales

*   **Flujo FIFO de Inscripción**: Control exacto de lista de espera mediante una estructura de **Cola** personalizada.
*   **Emparejamientos Dinámicos**: Gestión activa de competidores a través de una **Lista Enlazada Circular**.
*   **Historial de Encuentros**: Auditoría de partidas disputadas mediante una **Lista Enlazada Simple**.
*   **Salón de la Fama**: Registro histórico de campeones utilizando una estructura de **Pila**.
*   **Motor de Analíticas**:
    *   Algoritmos de ordenamiento clásicos (Burbuja, Selección, Inserción, Quick Sort, Merge Sort).
    *   Sistemas de búsqueda secuencial y binaria.
    *   Reportes analíticos implementados mediante funciones recursivas.

---

## 📂 Estructura del Repositorio

```
📂 gestion_torneos_esports/
├── 📂 docs/                      # Documentación técnica detallada
├── 📄 .gitignore                 # Exclusiones de Git
├── 📄 Makefile                   # Automatización de compilación
├── 📄 README.md                  # Presentación del proyecto (este archivo)
├── 📄 estructuras.h              # Definición de structs de negocio comunes
├── 📄 jugadores.h / jugadores.cpp # Módulo de Lista Circular (Jugadores)
├── 📄 partidas.h / partidas.cpp   # Módulo de Lista Simple (Partidas)
├── 📄 cola.h / cola.cpp           # Módulo de Cola (Inscripciones)
├── 📄 pila.h / pila.cpp           # Módulo de Pila (Campeones)
├── 📄 algoritmos.h / algoritmos.cpp # Módulo de Búsquedas, Recursión y Ordenamiento
└── 📄 main.cpp                   # Orquestador del sistema y menú interactivo
```

---

## 🛠️ Compilación y Ejecución Quick Start

### Requisitos
*   Compilador **GCC/G++** instalado en el sistema.
*   Utilidad **Make** (opcional, en Windows MinGW usar `mingw32-make`).

### Ejecución con Makefile (Recomendado)

**En Windows (MinGW / Git Bash):**
```bash
# Compilar el código
mingw32-make

# Ejecutar el programa
./main

# Limpiar archivos compilados anteriores
mingw32-make clean
```

**En Linux / macOS:**
```bash
# Compilar el código
make

# Ejecutar el programa
./main

# Limpiar archivos compilados anteriores
make clean
```

### Ejecución Manual
```bash
g++ -std=c++11 -Wall main.cpp algoritmos.cpp cola.cpp pila.cpp jugadores.cpp -o main
./main
```

---

## 📖 Documentación del Proyecto

Para profundizar en la lógica, flujos de desarrollo y diseños de este sistema, consulta los siguientes documentos técnicos (enlaces relativos compatibles con GitHub):

*   📄 **[Plan de Implementación y Tareas](./docs/plan_implementacion.md)**: Detalle técnico sobre la división de módulos y firmas de funciones asignadas a cada integrante.
*   📄 **[Guía de Colaboración de Git](./docs/guia_git_colaboracion.md)**: Guía paso a paso para la clonación, creación de ramas y envío de Pull Requests.
*   📄 **[Especificación de Arquitectura](./docs/arquitectura_proyecto.md)**: Detalle del acoplamiento modular, dependencias entre cabeceras `.h` y el flujo de la unidad de traducción.
*   📄 **[Explicación de Algoritmos](./docs/explicacion_algoritmos.md)**: Análisis detallado de los ordenamientos, búsquedas y lógica recursiva.
*   📄 **[Diagramas de Nodos](./docs/diagramas_nodos.md)**: Representaciones gráficas de los nodos en memoria RAM.
*   📄 **[Diagramas de Flujo](./docs/diagramas_flujo.md)**: Lógica visual del flujo de admisión y algoritmo de ordenamiento.
*   📄 **[Diapositivas de Exposición](./docs/Diapositivas.md)**: Diapositivas de contenido sintetizado listas para la presentación y defensa grupal del proyecto.

---

## ⚖️ Licencia

Este proyecto está bajo la Licencia MIT. Para más detalles, consulte el archivo de licencia del repositorio.
