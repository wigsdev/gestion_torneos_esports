# 🖥️ Presentación del Proyecto: Gestión de Torneos de eSports

---

## 🎴 DIAPOSITIVA 1: Portada
```text
┌──────────────────────────────────────────────────────────┐
│        SISTEMA DE GESTIÓN DE TORNEOS DE ESPORTS         │
│  Estructuras de Datos y Algoritmos Avanzados en C++      │
├──────────────────────────────────────────────────────────┤
│  Autores:                                                │
│  • Javier Flores  - Módulo 1 (Jugadores)                │
│  • Víctor         - Módulo 3 y 4 (Colas y Pilas)         │
│  • Wilmer         - Módulo 5, 6 y 7 (Algoritmos/Líder)   │
└──────────────────────────────────────────────────────────┘
```

---

## 🎴 DIAPOSITIVA 2: Planteamiento del Problema
*   **Desafío**: Administrar de manera eficiente el flujo competitivo de un torneo eSports (registro, colas FIFO, salón de la fama e historiales).
*   **Reglas del Juego**:
    *   ❌ Prohibido el uso de colecciones estándar (sin `std::vector`, `std::queue`, etc.).
    *   ⚙️ Gestión pura de memoria dinámica y punteros.
    *   📦 Modularización estricta en unidades de traducción (`.h` y `.cpp`).

---

## 🎴 DIAPOSITIVA 3: Arquitectura y Dependencias
*   **Nivel 1**: `estructuras.h` define los tipos fundamentales (`Jugador`, `Partida`, `Campeon`).
*   **Nivel 2 (Estructuras)**:
    *   `jugadores.h` / `.cpp`
    *   `cola.h` / `.cpp`
    *   `pila.h` / `.cpp`
*   **Nivel 3 (Lógica de control)**:
    *   `algoritmos.h` / `.cpp` (Motores de ordenamiento y reportes).
    *   `main.cpp` (Menús y control).
*   **Compilación**: Automatizada e incremental mediante `Makefile`.

---

## 🎴 DIAPOSITIVA 4: Gestión de Jugadores (Lista Circular)
```text
  ┌───────┐      ┌───────┐      ┌───────┐
  │ Jug 1 │ ───> │ Jug 2 │ ───> │ Jug 3 │ ──┐
  └───────┘      └───────┘      └───────┘   │
      ▲                                     │
      └─────────────────────────────────────┘
                 (Puntero al Fin)
```
*   **Nodo**: `NodoJugador` { `Jugador dato`, `NodoJugador* siguiente` }.
*   **Representación**: Puntero al último elemento (`fin`).
*   **Rendimiento**: Inserción al final en tiempo constante $O(1)$.
*   **Funciones**: Registro ($O(1)$), Eliminación ($O(N)$), Modificación y Listado completo.

---

## 🎴 DIAPOSITIVA 5: Inscripciones e Historial
*   **Cola de Espera (Inscripciones - FIFO)**:
    *   Control mediante punteros `frente` y `fin`.
    *   *Integración*: El jugador es desencolado y se registra en la lista circular en tiempo constante $O(1)$.
*   **Historial de Partidas**:
    *   Lista enlazada simple lineal.
    *   Almacena el registro histórico permanente.

---

## 🎴 DIAPOSITIVA 6: Salón de la Fama (Pila LIFO)
```text
  ┌───────────────────────────────────┐
  │ Cima: Campeón Torneo Reciente     │  ──> Consulta y Eliminación en O(1)
  ├───────────────────────────────────┤
  │ Nodo 2: Campeón Anterior          │
  ├───────────────────────────────────┤
  │ Base: Primer Campeón del Historial│
  └───────────────────────────────────┘
```
*   **Nodo**: `NodoCampeon` { `Campeon dato`, `NodoCampeon* siguiente` }.
*   **Eficiencia**: Push y Pop en la cima en $O(1)$.
*   **Acceso**: Consulta instantánea del campeón más reciente en $O(1)$.

---

## 🎴 DIAPOSITIVA 7: Motor de Búsquedas
*   **Búsqueda Secuencial ($O(N)$)**:
    *   Búsqueda por **Nickname** y **Nombre real**.
    *   Aplicada directamente sobre la lista circular.
*   **Búsqueda Binaria ($O(\log N)$)**:
    *   Vuelca temporalmente las direcciones de los nodos de la lista circular a un arreglo dinámico indexado.
    *   Permite saltos de memoria física y división logarítmica.

---

## 🎴 DIAPOSITIVA 8: Algoritmos de Ordenamiento
*   **Complejidad cuadrática ($O(N^2)$)**:
    *   **Burbuja** (por Edad).
    *   **Selección** (por Nickname).
    *   **Inserción** (por Nombre).
*   **Complejidad logarítmica ($O(N \log N)$)**:
    *   **Quick Sort** (descendente por Ranking).
    *   **Merge Sort** (ascendente por ID).
*   *Optimización*: Intercambio del contenido del struct `Jugador` en los nodos.

---

## 🎴 DIAPOSITIVA 9: Reportes Estadísticos y Recursividad
*   **Recursividad Pura**:
    *   Impresión de Ranking.
    *   Conteo de Jugadores.
    *   Suma acumulada de Rankings.
    *   Búsqueda por Nickname.
*   *Caso Base Crítico*: Detección del retorno al nodo cabeza (`nodo == fin->siguiente`).

---

## 🎴 DIAPOSITIVA 10: Conclusiones
*   La separación de cabeceras `.h` e implementaciones `.cpp` evita conflictos de enlace múltiple.
*   El uso de la estructura circular con puntero a `fin` optimiza las inserciones a $O(1)$ sin ciclos innecesarios.
*   El control de memoria manual exige la liberación rigurosa con `delete` para evitar fugas.
*   **Demostración Práctica en Consola (Demo en Vivo)**.
