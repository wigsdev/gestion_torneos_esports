# 📄 Arquitectura del Sistema y Proceso de Compilación Modular

Este documento describe la especificación técnica de la arquitectura de software del proyecto, detallando la distribución de los componentes en archivos de cabecera (`.h`), la resolución de dependencias y el flujo de compilación.

---

## 1. Diseño de Arquitectura Modular

Para garantizar una alta cohesión y un bajo acoplamiento, el código fuente del sistema se organiza de forma distribuida en módulos temáticos. Esta separación física facilita la mantenibilidad del código, el desarrollo en paralelo y la escalabilidad de las estructuras.

### Árbol de Dependencias
El flujo de inclusión de archivos se organiza de forma jerárquica para evitar dependencias cíclicas:

```
                  [ estructuras.h ]
                         |
       +-----------------+-----------------+
       |                 |                 |
 [ jugadores.h ]   [ partidas.h ]     [ cola.h ]
       |                 |                 |
       +-----------------+                 |
       |                 |                 |
       |           [ pila.h ]              |
       |                 |                 |
       +-----------------+-----------------+
                         |
                  [ algoritmos.h ]
                         |
                    [ main.cpp ]
```

---

## 2. Especificación de los Archivos de Cabecera (.h)

Los archivos `.h` (Headers) contienen la declaración de estructuras de datos (nodos) y las firmas/implementaciones de las funciones correspondientes a cada módulo.

### Directivas de Preprocesamiento (Header Guards)
Para evitar la duplicación de definiciones al realizar inclusiones múltiples en tiempo de compilación, todos los archivos `.h` implementan guardas de cabecera mediante directivas del preprocesador:

```cpp
#ifndef NOMBRE_ARCHIVO_H
#define NOMBRE_ARCHIVO_H

// Declaraciones e implementaciones de código

#endif
```
Estas directivas garantizan que el compilador procese el contenido del archivo una única vez en la unidad de traducción, independientemente de cuántas veces sea incluido.

---

## 3. Descripción de Componentes

1.  **`estructuras.h` (Núcleo de Datos)**:
    *   *Propósito*: Define las estructuras de datos de negocio (`Jugador`, `Partida`, `Campeon`).
    *   *Dependencias*: Ninguna.
2.  **`jugadores.h` (Gestión Circular)**:
    *   *Propósito*: Define `NodoJugador` e implementa las operaciones para la lista circular.
    *   *Dependencias*: `estructuras.h`.
3.  **`partidas.h` y `cola.h` (Historial e Inscripciones)**:
    *   *Propósito*: Definen e implementan la lista simple de partidas y la cola FIFO de espera.
    *   *Dependencias*: `estructuras.h`.
4.  **`pila.h` (Salón de la Fama)**:
    *   *Propósito*: Define `NodoCampeon` e implementa las operaciones de pila (LIFO).
    *   *Dependencias*: `estructuras.h`.
5.  **`algoritmos.h` (Motor de Procesamiento)**:
    *   *Propósito*: Agrupa algoritmos de ordenamiento (Burbuja, Selección, Inserción, QuickSort, MergeSort), búsquedas y recursividad.
    *   *Dependencias*: `estructuras.h`, `jugadores.h`.
6.  **`main.cpp` (Orquestador Principal)**:
    *   *Propósito*: Inicializa las cabeceras, contiene la función de punto de entrada `main()` y la interfaz de consola del usuario.

---

## 4. Proceso de Compilación (Translation Unit)

C++ compila archivos mediante unidades de traducción. En este proyecto:
*   `main.cpp` actúa como la unidad de traducción principal.
*   Al compilar `main.cpp`, el preprocesador reemplaza recursivamente cada directiva `#include` por el contenido de los archivos cabecera indicados.
*   El compilador recibe un único código continuo estructurado en memoria y genera el ejecutable `main` (o `main.exe` en entornos Windows).
