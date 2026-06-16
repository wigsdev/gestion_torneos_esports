# PLAN DE IMPLEMENTACIÓN Y DISTRIBUCIÓN - PROYECTO 2 (GRUPO 2)
## SISTEMA DE GESTIÓN DE TORNEOS DE VIDEOJUEGOS (eSports)

Este documento describe la arquitectura técnica, los modelos de datos comunes y la distribución del trabajo para los 4 integrantes del grupo. El archivo `proyecto_grupo2.md` servirá como ancla para auditar los requerimientos funcionales y comprobar el avance.

---

## 1. Arquitectura de Archivos Propuesta

Para evitar conflictos de fusión en Git (Git Merge Conflicts) al trabajar 4 personas de forma simultánea, se recomienda dividir el código en archivos de cabecera (`.h`) y de implementación, o en archivos temáticos que se incluyan en el `main.cpp`:

```
📂 projects/projects_of_the_fourth_month/
├── 📄 proyecto_grupo2.md            # Ancla de requerimientos
├── 📄 plan_implementacion_grupo2.md # Plan de trabajo (este archivo)
├── 📄 estructuras.h                 # Definición de structs de negocio comunes
├── 📄 jugadores.h                   # Lista Circular de Jugadores (Integrante 1)
├── 📄 partidas.h                    # Lista Simple de Partidas (Integrante 2)
├── 📄 cola.h                        # Cola de Inscripciones (Integrante 2)
├── 📄 pila.h                        # Pila e Historial de Campeones (Integrante 3)
├── 📄 algoritmos.h                  # Búsquedas, Recursividad y Ordenamientos (Integrantes 3 y 4)
└── 📄 main.cpp                      # Menú principal e integración (Integrante 4)
```

---

## 2. Modelos de Datos Comunes (`estructuras.h`)

Para que todo el software encaje sin problemas, todos los archivos deben usar los mismos tipos de datos.

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

### 🧑‍💻 Integrante 1: Gestión de Jugadores (Lista Circular)
**Responsabilidad**: Crear el almacenamiento principal de los jugadores activos.
*   **Estructuras de Datos**:
    ```cpp
    struct NodoJugador {
        Jugador dato;
        NodoJugador* siguiente;
    };
    ```
*   **Funciones requeridas** (en `jugadores.h`):
    *   `void registrarJugador(NodoJugador* &fin, Jugador nuevo)`: Inserta en la lista circular (se recomienda mantener el puntero al último nodo `fin` para inserciones en $O(1)$).
    *   `void eliminarJugador(NodoJugador* &fin, int id)`: Busca un jugador por su ID y lo remueve manteniendo la propiedad circular.
    *   `void modificarJugador(NodoJugador* fin, int id, Jugador modificado)`: Modifica datos de un jugador por su ID.
    *   `void mostrarJugadores(NodoJugador* fin)`: Imprime la lista completa dando una sola vuelta.

---

### 🧑‍💻 Integrante 2: Partidas y Cola de Inscripción
**Responsabilidad**: Diseñar el flujo de ingreso al torneo (Cola) y el historial de enfrentamientos (Lista Simple).
*   **Estructuras de Datos**:
    ```cpp
    // Para la lista simple de partidas
    struct NodoPartida {
        Partida dato;
        NodoPartida* siguiente;
    };

    // Para la cola de inscripciones
    struct NodoCola {
        Jugador dato; // Jugador en espera de registrarse
        NodoCola* siguiente;
    };
    ```
*   **Funciones requeridas** (en `cola.h` y `partidas.h`):
    *   `void encolarInscripcion(NodoCola* &frente, NodoCola* &fin, Jugador j)`: Añade un jugador al final de la cola.
    *   `void mostrarCola(NodoCola* frente)`: Imprime los jugadores en lista de espera.
    *   `Jugador desencolarInscripcion(NodoCola* &frente, NodoCola* &fin)`: Remueve y retorna el primer jugador de la cola para ser ingresado formalmente.
    *   `void registrarPartida(NodoPartida* &cabeza, Partida p)`: Inserta un registro de enfrentamiento al inicio o final de la lista simple.
    *   `void mostrarPartidas(NodoPartida* cabeza)`: Imprime el historial de enfrentamientos.

---

### 🧑‍💻 Integrante 3: Historial de Campeones (Pila), Búsquedas y Recursividad
**Responsabilidad**: Programar la pila de campeonatos pasados, las búsquedas de información y los reportes analíticos recursivos.
*   **Estructura de la Pila**:
    ```cpp
    struct NodoCampeon {
        Campeon dato;
        NodoCampeon* siguiente;
    };
    ```
*   **Funciones requeridas** (en `pila.h` y `algoritmos.h`):
    *   `void pushCampeon(NodoCampeon* &cima, Campeon c)`: Inserta un campeón en la pila.
    *   `void popCampeon(NodoCampeon* &cima)`: Elimina el último campeón.
    *   `void mostrarHistorial(NodoCampeon* cima)`: Muestra todos los campeones (recorriendo la pila sin destruirla).
    *   `void consultarUltimoCampeon(NodoCampeon* cima)`: Muestra el elemento en la cima (`.top`).
    *   **Búsquedas**:
        *   `NodoJugador* buscarPorNickname(NodoJugador* fin, string nickname)`: Búsqueda secuencial.
        *   `NodoJugador* buscarPorNombre(NodoJugador* fin, string nombre)`: Búsqueda secuencial.
        *   `NodoJugador* buscarPorIDBinaria(NodoJugador* fin, int id)`: Búsqueda binaria. *(Nota: Requiere pasar la lista a un arreglo temporal indexado o asegurar que esté ordenada).*
    *   **Recursividad**:
        *   `void mostrarRankingRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta)`: Imprime el ranking.
        *   `int contarJugadoresRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta)`: Retorna la cantidad de nodos.
        *   `int sumarPuntajesRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta)`: Suma todos los rankings.
        *   `NodoJugador* buscarJugadorRecursivo(NodoJugador* nodo, NodoJugador* fin, string nickname, bool primeraVuelta)`: Busca recursivamente.

---

### 🧑‍💻 Integrante 4: Algoritmos de Ordenamiento e Integración
**Responsabilidad**: Escribir los algoritmos de ordenamiento avanzados adaptados a listas enlazadas, estructurar el menú principal del sistema (`main()`) y unificar el trabajo grupal.
*   **Funciones de Ordenamiento** (en `algoritmos.h`):
    *   `void ordenarPorEdadBurbuja(NodoJugador* fin)`
    *   `void ordenarPorNicknameSeleccion(NodoJugador* fin)`
    *   `void ordenarPorNombreInsercion(NodoJugador* fin)`
    *   `void ordenarPorRankingQuickSort(NodoJugador* fin)`
    *   `void ordenarPorIDMergeSort(NodoJugador* fin)`
    *(Tip: Para facilitar los ordenamientos complejos sobre listas enlazadas, se pueden intercambiar los valores internos `Jugador dato` de los nodos sin tener que reestructurar los punteros, similar a como se hizo en el ejercicio 8 de la clase).*
*   **Integración (`main.cpp`)**:
    *   Diseñar el menú interactivo con opciones claras que conecten la entrada del usuario con los métodos de los Integrantes 1, 2 y 3.

---

## 4. Flujo de Integración y Trabajo en Git

1.  **Rama `main` limpia**: Nadie trabaja directamente en la rama `main`.
2.  **Ramas individuales**: Cada integrante crea una rama con su nombre o tarea:
    *   `feature/jugadores` (Integrante 1)
    *   `feature/partidas-cola` (Integrante 2)
    *   `feature/pila-busquedas` (Integrante 3)
    *   `feature/ordenamientos-menu` (Integrante 4)
3.  **Primer archivo común**: El Integrante 4 sube a `main` el archivo `estructuras.h` vacío con los structs básicos. Todos los demás hacen `git pull` para obtenerlo.
4.  **Desarrollo en paralelo**: Cada desarrollador programa sus funciones dentro de sus respectivos archivos `.h`.
5.  **Integración final**: Se unen las ramas a `main` una a una y el Integrante 4 crea el menú final en `main.cpp` para unificar el sistema.
