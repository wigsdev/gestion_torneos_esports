# 🖥️ Esquema de Diapositivas para la Exposición

Este documento contiene la estructura y contenido sugerido diapositiva por diapositiva para que el grupo prepare la presentación de la defensa del proyecto.

---

### **Diapositiva 1: Portada**
*   **Título**: Sistema de Gestión de Torneos de Videojuegos (eSports)
*   **Subtítulo**: Estructuras de Datos y Algoritmos Avanzados en C++
*   **Contenido**:
    *   Nombre de la materia / Bootcamp.
    *   Nombres de los 4 integrantes.
    *   Fecha de exposición.

---

### **Diapositiva 2: Introducción y Objetivos**
*   **Título**: Planteamiento del Problema
*   **Contenido**:
    *   **Necesidad**: Administrar la logística de un torneo competitivo (Inscripción, emparejamientos, historial de partidas y campeones).
    *   **Objetivo**: Implementar una aplicación robusta en consola utilizando estructuras de datos personalizadas desde cero (sin STL).
    *   **Restricción principal**: Gestión pura de memoria dinámica y punteros.

---

### **Diapositiva 3: Arquitectura Modular y Flujo de Dependencias**
*   **Contenido**:
    *   **Distribución de Código**: Modularización en archivos de cabecera (`.h`) y archivo principal de ejecución (`main.cpp`).
    *   **Relación de Dependencias**: Flujo de inclusión de cabeceras estructurado jerárquicamente a partir de `estructuras.h`.
    *   **Guardas de Cabecera**: Implementación de directivas `#ifndef` / `#define` para evitar duplicidad de tipos durante el procesamiento de unidades de traducción.
    *   **Estructura del Proyecto**: Descripción física de los 7 archivos fuentes que componen la base del sistema.


---

### **Diapositiva 4: Gestión de Jugadores (Lista Circular)**
*   **Título**: Módulo de Jugadores - Lista Enlazada Circular
*   **Contenido**:
    *   **Estructura**: `NodoJugador` (`dato`, `siguiente`).
    *   **Por qué Circular**: Los torneos ocurren en ciclos y rondas repetitivas.
    *   **Operaciones principales**: Registrar, eliminar por ID, modificar y listar.
    *   *Apoyo visual*: Diagrama de nodos de la lista circular (extraído de `diagramas_nodos.md`).

---

### **Diapositiva 5: Inscripciones y Partidas (Cola y Lista Simple)**
*   **Título**: Flujo del Torneo - Colas y Listas Simples
*   **Contenido**:
    *   **Cola de Inscripciones (FIFO)**: Los jugadores se encolan al registrarse y son atendidos por orden de llegada.
    *   **Lista Simple de Partidas**: Almacena de forma lineal e ilimitada el registro histórico de los enfrentamientos.
    *   *Apoyo visual*: Diagrama de la Cola y la Lista Simple.

---

### **Diapositiva 6: Historial de Campeones (Pila)**
*   **Título**: Salón de la Fama - Estructura Pila (LIFO)
*   **Contenido**:
    *   **Estructura**: `NodoCampeon` (`dato`, `siguiente`).
    *   **Por qué Pila**: Queremos consultar de forma inmediata al último campeón del torneo más reciente ($O(1)$) e ir bajando en el historial hacia atrás.
    *   **Operaciones**: Push (nuevo campeón), Pop (remover último), Top (consultar campeón más reciente).

---

### **Diapositiva 7: Motor de Búsquedas y Algoritmos Recursivos**
*   **Título**: Búsquedas y Recursividad
*   **Contenido**:
    *   **Búsquedas**:
        *   Secuencial (por nombre y nickname en $O(N)$).
        *   Binaria (por ID en $O(\log N)$ usando un arreglo temporal indexado).
    *   **Lógica Recursiva**:
        *   Recorrido y conteo de jugadores.
        *   Suma de puntajes de ranking.
        *   Búsqueda de nodos sin ciclos repetitivos.

---

### **Diapositiva 8: Algoritmos de Ordenamiento**
*   **Título**: Ordenamiento Multivariable
*   **Contenido**:
    *   Implementación de 5 algoritmos clásicos adaptados a punteros:
        1.  **Burbuja** ($O(N^2)$) - por Edad.
        2.  **Selección** ($O(N^2)$) - por Nickname.
        3.  **Inserción** ($O(N^2)$) - por Nombre.
        4.  **Quick Sort** ($O(N \log N)$) - por Ranking (Recursivo).
        5.  **Merge Sort** ($O(N \log N)$) - por ID (Recursivo).
    *   *Nota*: Optimización mediante el intercambio del contenido de los nodos en lugar de reconectar punteros.

---

### **Diapositiva 9: Conclusiones y Demostración**
*   **Título**: Conclusiones del Proyecto
*   **Contenido**:
    *   Apropiación de conceptos de punteros y asignación de memoria.
    *   Beneficios de la modularización en el desarrollo grupal profesional.
    *   **Demo en vivo**: Compilación y ejecución del sistema en la consola de comandos.
