# PLAN DE IMPLEMENTACIÓN Y DISTRIBUCIÓN - PROYECTO 2 (GRUPO 2)
## SISTEMA DE GESTIÓN DE TORNEOS DE VIDEOJUEGOS (eSports)

Este documento describe la arquitectura técnica, los modelos de datos comunes y la distribución del trabajo para los 3 integrantes del grupo.

---

## 1. Arquitectura de Archivos Propuesta

Para evitar conflictos de fusión en Git al trabajar de forma simultánea, se divide el código en archivos de cabecera (`.h`) organizados de la siguiente manera:

```
📂 projects/projects_of_the_fourth_month/
├── 📄 proyecto_grupo2.md            # Ancla de requerimientos
├── 📄 plan_implementacion.md        # Plan de trabajo (este archivo)
├── 📄 estructuras.h                 # Definición de structs de negocio comunes
├── 📄 jugadores.h                   # Módulo 1 (Integrante 1 - Javier)
├── 📄 partidas.h                    # Módulo 2 (Integrante 1 - Javier)
├── 📄 cola.h                        # Módulo 3 (Integrante 2 - Victor)
├── 📄 pila.h                        # Módulo 4 (Integrante 2 - Victor)
├── 📄 algoritmos.h                  # Módulos 5, 6 y 7 (Compartido Javier, Victor y Wilmer)
└── 📄 main.cpp                      # Menú principal e integración (Integrante 3 - Wilmer)
```

---

## 2. Modelos de Datos Comunes (`estructuras.h`)

Para que todo el software encaje sin problemas, todos los archivos deben usar los mismos tipos de datos básicos.

```cpp
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
using namespace std;

// Datos básicos del Jugador
struct Jugador {
    int id;
    string nombre;
    string nickname;
    int edad;
    int ranking;
};

// Datos del historial de Partidas
struct Partida {
    string jugadorA; // Nickname
    string jugadorB; // Nickname
    string ganador;  // Nickname del ganador
    string fecha;    // DD/MM/AAAA
};

// Datos de Campeón
struct Campeon {
    string nickname;
    string nombreTorneo;
};

#endif
```

---

## 3. Asignación de Roles e Interfaces Técnicas

### 🧑‍💻 Integrante 1 (Javier)
**Responsabilidad**: Crear el almacenamiento de jugadores activos y el registro lineal de partidas.

*   **Módulo 1: Gestión de Jugadores (Lista Circular)**
    *   *Firma:* `void registrarJugador(NodoJugador* &fin, Jugador nuevo)`: Inserta en la lista circular (mantiene `fin` para $O(1)$).
    *   *Firma:* `void eliminarJugador(NodoJugador* &fin, int id)`: Busca un jugador por ID y lo remueve manteniendo la circularidad.
    *   *Firma:* `void modificarJugador(NodoJugador* fin, int id, Jugador modificado)`: Modifica datos por ID.
    *   *Firma:* `void mostrarJugadores(NodoJugador* fin)`: Imprime la lista de competidores.
    *   *Ubicación:* `jugadores.h`

*   **Módulo 2: Historial de Partidas (Lista Simple)**
    *   *Firma:* `void registrarPartida(NodoPartida* &cabeza, Partida p)`: Inserta un enfrentamiento al final de la lista simple.
    *   *Firma:* `void mostrarPartidas(NodoPartida* cabeza)`: Muestra el historial completo de encuentros.
    *   *Ubicación:* `partidas.h`

---

### 🧑‍💻 Integrante 2 (Victor)
**Responsabilidad**: Diseñar los flujos lineales temporales (Cola FIFO y Pila LIFO) y el motor de búsquedas directas.

*   **Módulo 3: Cola de Inscripciones (Cola FIFO)**
    *   *Firma:* `void encolarInscripcion(NodoCola* &frente, NodoCola* &fin, Jugador j)`: Inserta un jugador al final de la cola.
    *   *Firma:* `void mostrarCola(NodoCola* frente)`: Imprime la lista de espera actual.
    *   *Firma:* `Jugador desencolarInscripcion(NodoCola* &frente, NodoCola* &fin)`: Remueve y retorna el primer jugador en cola.
    *   *Ubicación:* `cola.h`

*   **Módulo 4: Historial de Campeones (Pila LIFO)**
    *   *Firma:* `void pushCampeon(NodoCampeon* &cima, Campeon c)`: Apila un campeón.
    *   *Firma:* `void popCampeon(NodoCampeon* &cima)`: Elimina el último campeón registrado.
    *   *Firma:* `void mostrarHistorial(NodoCampeon* cima)`: Muestra todos los campeones de la pila.
    *   *Firma:* `void consultarUltimoCampeon(NodoCampeon* cima)`: Muestra el campeón en el tope.
    *   *Ubicación:* `pila.h`

*   **Módulo 5: Motores de Búsqueda (Búsquedas Secuenciales)**
    *   *Firma:* `NodoJugador* buscarPorNickname(NodoJugador* fin, string nickname)`: Búsqueda secuencial.
    *   *Firma:* `NodoJugador* buscarPorNombre(NodoJugador* fin, string nombre)`: Búsqueda secuencial.
    *   *Ubicación:* `algoritmos.h`

---

### 🧑‍💻 Integrante 3 (Wilmer - Líder)
**Responsabilidad**: Desarrollar la búsqueda compleja binaria, los ordenamientos clásicos de la lista circular, las estadísticas analíticas recursivas y orquestar el sistema.

*   **Módulo 5: Motores de Búsqueda (Búsqueda Binaria)**
    *   *Firma:* `NodoJugador* buscarPorIDBinaria(NodoJugador* fin, int id)`: Búsqueda binaria indexando a un arreglo de punteros temporal.
    *   *Ubicación:* `algoritmos.h`

*   **Módulo 6: Algoritmos de Ordenamiento (5 algoritmos)**
    *   *Firmas:* `ordenarPorEdadBurbuja`, `ordenarPorNicknameSeleccion`, `ordenarPorNombreInsercion`, `ordenarPorRankingQuickSort`, `ordenarPorIDMergeSort` (aplicados sobre la lista circular intercambiando el campo `Jugador dato` de los nodos).
    *   *Ubicación:* `algoritmos.h`

*   **Módulo 7: Reportes Estadísticos Recursivos**
    *   *Firma:* `void mostrarRankingRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta)`: Ranking recursivo.
    *   *Firma:* `int contarJugadoresRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta)`: Total de jugadores.
    *   *Firma:* `int sumarPuntajesRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta)`: Suma de rankings.
    *   *Firma:* `NodoJugador* buscarJugadorRecursivo(NodoJugador* nodo, NodoJugador* fin, string nickname, bool primeraVuelta)`: Búsqueda recursiva.
    *   *Ubicación:* `algoritmos.h`

*   **Integración e Interfaz (`main.cpp` + `Makefile`)**
    *   Codificar el orquestador principal del juego, controlando la interacción de admisión de jugadores y el menú dinámico interactivo de consola.

---

## 4. Flujo de Integración y Trabajo en Git

1.  **Rama `main` limpia**: La rama principal se mantiene estable y compilable en todo momento.
2.  **Ramas individuales (3 integrantes)**:
    *   `feature/jugadores-partidas` (Javier - Integrante 1)
    *   `feature/lineales-busqueda-secuencial` (Victor - Integrante 2)
    *   `feature/ordenamientos-recursion-lider` (Wilmer - Integrante 3)
3.  **Desarrollo en paralelo**: Cada desarrollador programa sus funciones dentro de sus respectivos archivos `.h` locales.
4.  **Integración final**: Se unen las ramas a `main` una a una y el líder realiza las comprobaciones generales de compilación y lógica.
