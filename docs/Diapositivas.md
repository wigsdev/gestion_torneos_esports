# 🖥️ Presentación del Proyecto: Sistema de Gestión de Torneos de eSports

---

## 🎴 DIAPOSITIVA 1: Portada
```text
┌──────────────────────────────────────────────────────────┐
│        SISTEMA DE GESTIÓN DE TORNEOS DE ESPORTS         │
│  Estructuras de Datos y Algoritmos Avanzados en C++      │
├──────────────────────────────────────────────────────────┤
│  Autores:                                                │
│  • Javier Flores  - Módulo 1 y 2 (Jugadores y Partidas)  │
│  • Víctor         - Módulo 3 y 4 (Colas y Pilas)         │
│  • Wilmer         - Módulo 5, 6 y 7 (Algoritmos/Líder)   │
└──────────────────────────────────────────────────────────┘
```

---

## 🎴 DIAPOSITIVA 2: Planteamiento del Problema
*   **Desafío**: Administrar de manera eficiente el flujo competitivo de un torneo eSports (registro, colas FIFO, salón de la fama e historiales).
*   **Restricciones (Rúbrica)**:
    *   ❌ Prohibido el uso de colecciones estándar (sin `vector`, `list`, `stack`, `queue`, `deque`).
    *   ⚙️ Todo debe construirse desde cero utilizando memoria dinámica y punteros.
    *   📦 Modularización estricta (`.h` y `.cpp`).

---

## 🎴 DIAPOSITIVA 3: Arquitectura y Dependencias
*   **Núcleo de Datos**: `estructuras.h` define los structs de negocio comunes (`Jugador`, `Partida`, `Campeon`).
*   **Distribución Modular**:
    *   `jugadores.h` / `.cpp`
    *   `partidas.h` / `.cpp`
    *   `cola.h` / `.cpp`
    *   `pila.h` / `.cpp`
    *   `algoritmos.h` / `.cpp`
*   **Compilación**: Automatizada mediante `Makefile` (soporta Windows `mingw32-make` y Linux `make`).

---

## 🎴 DIAPOSITIVA 4: Módulo 1: Gestión de Jugadores
*   **Estructura / Implementación**: Lista Circular (circularmente enlazada).
*   **Razón de Selección**: Los torneos avanzan ronda tras ronda.
*   **Datos Almacenados**:
    *   `ID` (Identificador único)
    *   `Nombre` (Nombre completo del competidor)
    *   `Nickname` (Apodo en el videojuego)
    *   `Edad` (Edad en años)
    *   `Puntaje Ranking` (Puntaje competitivo acumulado)
*   **Opciones Implementadas**:
    *   **Registrar jugador**: Inserción en tiempo constante $O(1)$ al final de la lista circular a través de puntero `fin`.
    *   **Eliminar jugador**: Desconexión y liberación de memoria del nodo en $O(N)$.
    *   **Modificar jugador**: Localización por ID y actualización de datos en $O(N)$.
    *   **Mostrar jugadores**: Recorrido circular completo imprimiendo el listado de competidores.

---

## 🎴 DIAPOSITIVA 5: Módulo 2: Gestión de Partidas
*   **Estructura / Implementación**: Lista Simple (linealmente enlazada).
*   **Guardar / Datos Registrados**:
    *   `Jugador A` (Primer contrincante)
    *   `Jugador B` (Segundo contrincante)
    *   `Ganador` (Nombre/Nickname del vencedor)
    *   `Fecha` (Fecha del encuentro)
*   **Propósito / Operaciones**:
    *   Registrar resultado de partida (inserción simple en el historial).
    *   Mostrar historial completo de partidas (recorrido secuencial lineal).

---

## 🎴 DIAPOSITIVA 6: Módulo 3: Cola de Inscripciones
*   **Estructura / Implementación**: Cola (Estructura lineal FIFO - First In, First Out).
*   **Opciones Implementadas**:
    *   **Inscribir jugador**: Encolar al final de la estructura de espera ($O(1)$).
    *   **Mostrar cola**: Visualizar secuencialmente los jugadores en espera de ser admitidos.
    *   **Atender inscripción**: Desencolar al primer jugador en espera ($O(1)$) y registrarlo directamente en el Módulo 1 (Lista Circular).

---

## 🎴 DIAPOSITIVA 7: Módulo 4: Historial de Campeones
*   **Estructura / Implementación**: Pila (Estructura lineal LIFO - Last In, First Out).
*   **Guardar / Información**: Campeón de cada torneo.
*   **Funciones Implementadas**:
    *   **Mostrar historial**: Imprime recursiva o iterativamente todos los campeones registrados en la pila, desde el más reciente hasta el más antiguo.
    *   **Consultar último campeón**: Visualizar al campeón en la cima de la pila sin desapilar ($O(1)$).
    *   *Adicional*: Apilar nuevo campeón (Push) y eliminar último registrado (Pop).

---

## 🎴 DIAPOSITIVA 8: Módulo 5: Búsquedas
*   **Búsqueda Secuencial ($O(N)$)**:
    *   **Buscar por Nickname**: Búsqueda secuencial en la lista circular (case-insensitive).
    *   **Buscar por Nombre**: Búsqueda secuencial en la lista circular (case-insensitive).
*   **Búsqueda Binaria ($O(\log N)$)**:
    *   **Buscar por ID**: Búsqueda binaria.
    *   *Mecánica*: Vuelca temporalmente los punteros de los nodos de la lista circular a un arreglo dinámico para permitir el acceso aleatorio directo y realizar la división de intervalos logarítmicos.

---

## 🎴 DIAPOSITIVA 9: Módulo 6: Ordenamientos
Se implementaron cinco algoritmos clásicos de ordenamiento, cada uno aplicando un criterio de orden específico sobre los datos de los jugadores:
*   **Burbuja (Bubble Sort)**: Ordena **Por edad** (de manera ascendente, $O(N^2)$).
*   **Selección (Selection Sort)**: Ordena **Por nickname** (de manera alfabética, $O(N^2)$).
*   **Inserción (Insertion Sort)**: Ordena **Por nombre** (de manera alfabética, $O(N^2)$).
*   **Quick Sort**: Ordena **Por ranking** (de manera descendente, $O(N \log N)$).
*   **Merge Sort**: Ordena **Por ID** (de manera ascendente, $O(N \log N)$).

---

## 🎴 DIAPOSITIVA 10: Módulo 7: Recursividad
Operaciones críticas implementadas bajo enfoque puramente recursivo (sin bucles iterativos `for`/`while`):
*   **Mostrar ranking recursivamente**: Recorrido de los jugadores mostrando su nickname y puntaje en orden inverso o directo.
*   **Contar jugadores recursivamente**: Cuenta el número total de nodos activos en la lista circular.
*   **Calcular suma de puntajes recursivamente**: Suma acumulada de los puntajes de ranking de todos los jugadores registrados.
*   **Buscar jugador recursivamente**: Búsqueda recursiva basada en el nickname.
*   *Manejo de Caso Base*: Control riguroso del puntero de retorno al primer nodo (`nodo == fin->siguiente`) para evitar la recursión infinita en la lista circular.

---

## 🎴 DIAPOSITIVA 11: Conclusiones
*   La separación de cabeceras e implementaciones (.h/.cpp) previene errores de definición de símbolos.
*   El diseño circular de jugadores optimiza las operaciones cíclicas del torneo.
*   El uso de la estructura circular con puntero a `fin` reduce la inserción a $O(1)$.
*   Las validaciones de unicidad de ID y búsquedas case-insensitive robustecen la integridad de los datos.
*   **Demostración Práctica en Consola (Demo en Vivo)**.
