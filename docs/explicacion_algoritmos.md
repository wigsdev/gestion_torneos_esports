# 🧠 Explicación Técnica de Algoritmos

Este documento proporciona una descripción detallada de la lógica, complejidad computacional y adaptación para listas enlazadas de los algoritmos implementados en el proyecto.

---

## 1. Algoritmos de Búsqueda (Módulo 5)

### A. Búsqueda Secuencial (Nickname y Nombre)
*   **Lógica**: Recorre la lista circular desde el primer nodo hasta dar una vuelta completa o encontrar el elemento. Compara el campo de texto (`nombre` o `nickname`) de cada nodo con el valor buscado.
*   **Complejidad**: 
    *   *Peor caso*: $O(N)$ (el elemento no existe o está al final).
    *   *Mejor caso*: $O(1)$ (el elemento está en la primera posición).

### B. Búsqueda Binaria (ID)
*   **Lógica**: La búsqueda binaria requiere acceso aleatorio ($O(1)$) y datos ordenados. En listas enlazadas, el acceso aleatorio es $O(N)$.
*   **Adaptación**: Para mantener la eficiencia de la búsqueda binaria, se vuelcan temporalmente los punteros de los jugadores a un arreglo estático de punteros de tamaño $N$, se aplica la búsqueda binaria tradicional dividiendo el rango a la mitad (`medio = (izq + der) / 2`), y luego se retorna el nodo correspondiente.
*   **Complejidad**: $O(\log N)$ para la búsqueda en sí, con un costo previo de $O(N)$ para la transferencia al arreglo.

---

## 2. Algoritmos de Ordenamiento (Módulo 6)

Todos los algoritmos de ordenamiento se adaptan para listas enlazadas intercambiando el miembro `dato` (la estructura `Jugador`) entre los nodos, evitando la reconexión de punteros que es más compleja y lenta.

### A. Ordenamiento Burbuja (Burbuja por Edad)
*   **Lógica**: Compara elementos adyacentes y los intercambia si están en el orden incorrecto. Repite hasta que no haya intercambios.
*   **Complejidad**: $O(N^2)$ promedio y peor caso.

### B. Ordenamiento por Selección (Selección por Nickname)
*   **Lógica**: Busca el elemento más pequeño (alfabéticamente por nickname) en la sublista no ordenada y lo intercambia con el elemento al inicio de esa sección.
*   **Complejidad**: $O(N^2)$ en todos los casos.

### C. Ordenamiento por Inserción (Inserción por Nombre)
*   **Lógica**: Toma cada elemento e insértalo en su posición correcta dentro de la parte ya ordenada de la lista.
*   **Complejidad**: $O(N^2)$ en peor caso; $O(N)$ en el mejor caso (lista ya ordenada).

### D. Quick Sort (Quick Sort por Ranking)
*   **Lógica**: Divide y vencerás. Elige un pivote, particiona la lista de manera que los menores al pivote queden a la izquierda y los mayores a la derecha, y ordena las sublistas de forma recursiva.
*   **Complejidad**: $O(N \log N)$ promedio; $O(N^2)$ en el peor caso.

### E. Merge Sort (Merge Sort por ID)
*   **Lógica**: Divide y vencerás. Divide la lista por la mitad recursivamente, ordena las sublistas y luego las fusiona de forma ordenada.
*   **Complejidad**: $O(N \log N)$ estable en todos los casos.

---

## 3. Funciones Recursivas (Módulo 7)

La recursividad se utiliza para recorrer y procesar la lista circular de jugadores de forma elegante, reemplazando los ciclos iterativos.

### A. Mostrar Ranking Recursivamente
*   **Caso Base**: El nodo actual es igual a `fin` (hemos dado la vuelta completa).
*   **Caso Recursivo**: Imprimir el jugador actual y llamar a la función pasando `nodo->siguiente`.

### B. Contar Jugadores Recursivamente
*   **Caso Base**: `nodo == fin` $\to$ Retorna 1.
*   **Caso Recursivo**: Retorna `1 + contarJugadores(nodo->siguiente, fin)`.

### C. Sumar Puntajes de Ranking
*   **Caso Base**: `nodo == fin` $\to$ Retorna el puntaje del último jugador.
*   **Caso Recursivo**: Retorna `nodo->dato.ranking + sumarPuntajes(nodo->siguiente, fin)`.

### D. Buscar Jugador Recursivamente
*   **Caso Base 1**: El jugador coincide con el nickname buscado $\to$ Retorna el nodo.
*   **Caso Base 2**: `nodo == fin` y no coincide $\to$ Retorna `nullptr`.
*   **Caso Recursivo**: Llamar a buscar con `nodo->siguiente`.
