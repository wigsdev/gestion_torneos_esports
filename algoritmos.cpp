#include "algoritmos.h"
#include "estructuras.h"
#include "jugadores.h"
#include <algorithm>

// ==============================================================================
// --- WILMER (Integrante 3 - LÍDER) - MÓDULO 5: MOTORES DE BÚSQUEDA (BINARIA) ---
// ==============================================================================
// Implementación de la búsqueda binaria por ID (con copia temporal a arreglo):

// Implementación de contarNodos
int contarNodos(NodoJugador* fin) {
    if (fin == nullptr) {
        return 0;
    }
    int N = 0;
    NodoJugador* actual = fin->siguiente;
    do {
        N++;
        actual = actual->siguiente;
    } while (actual != fin->siguiente);
    return N;
}

// Implementación de buscarPorIDBinaria
NodoJugador* buscarPorIDBinaria(NodoJugador* fin, int id) {
    if (fin == nullptr) {
        return nullptr;    
    }
    int N = contarNodos(fin);
    NodoJugador** arr = new NodoJugador*[N];
    NodoJugador* actual = fin->siguiente;

    for (int i = 0; i < N; i++) {
        arr[i] = actual;
        actual = actual->siguiente;   
    }

    int izquierda = 0;
    int derecha = N - 1;
    NodoJugador* resultado = nullptr;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio]->dato.id == id) {
            resultado = arr[medio];
            break;        
        }
        
        if (arr[medio]->dato.id < id) {
            izquierda = medio + 1;        
        } else {
            derecha = medio - 1;
        }        
    }
    delete[] arr;
    return resultado;
}

// Implementación de los ordenamientos sobre la lista circular de jugadores:

// 1. Ordenamientos burbuja (Por Edad)
void ordenarPorEdadBurbuja(NodoJugador *fin) {
    if (fin == nullptr) {
        return; // lista vacia nada que ordenar    
    }

    bool intercambiado;
    do {
        intercambiado = false;
        NodoJugador* actual = fin->siguiente; // apunta al primer nodo (cabeza)

        // recorrermos la lista circular comparando elementos adyacentes
        while (actual->siguiente != fin->siguiente) {
            if (actual->dato.edad > actual->siguiente->dato.edad) {
                // intercambiamos los datos de tipo jugador entre los nodos
                Jugador temp = actual->dato;
                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = temp;

                intercambiado = true; // indicamos que hubo un cambio en esta pasada
            }
            actual = actual->siguiente; // avanzamos al siguiente nodo
        
        }
    }while (intercambiado); // si en una pasada completa hubo algún cambio, repetimos.
}

// 2. Ordenamiento por seleccion (Por nickname)
void ordenarPorNicknameSeleccion(NodoJugador *fin) {
    if (fin == nullptr) {
        return; // lista vacía, noda que ordenar    
    }

    NodoJugador* actual = fin->siguiente; // empezamos en la cabeza
    do {
        NodoJugador* minimo = actual;
        NodoJugador* busqueda = actual->siguiente;

        // recorremos el resto de la lista circular buscando el nickname menor
        while (busqueda != fin->siguiente) {
            if (busqueda->dato.nickname < minimo->dato.nickname) {
                minimo = busqueda;            
            }
            busqueda = busqueda->siguiente;
        }

        // si el menor es distinto al actual, intercambiamos los datos
        if (minimo != actual) {
            Jugador temp = actual->dato;
            actual->dato = minimo->dato;
            minimo->dato = temp;        
        }
        actual = actual->siguiente;
    }while (actual != fin->siguiente);
}

// ordenamiento por inserción (por nombre)
void ordenarPorNombreInsercion(NodoJugador *fin) {
    // si la lista está vacía o tiene un solo elemento, ya está ordenado
    if (fin == nullptr || fin->siguiente == fin) {
        return;    
    }

    NodoJugador* actual = fin->siguiente->siguiente; // empezamos a evaluar desde el segundo nodo
    while (actual != fin->siguiente) {
        Jugador val = actual->dato; // copiamos el dato del nodo en evaluacion
        NodoJugador* anterior = fin->siguiente; // empezamos a comparar desde la cabeza
        
        // recorremos desde la cabeza hasta el nodo actual
        while (anterior != actual) {
            if (anterior->dato.nombre > val.nombre) {
                // intercambio de datos para desplazar la informacion ordenada
                Jugador temp = anterior->dato;
                anterior->dato = actual->dato;
                actual->dato = temp;            
            }
            anterior = anterior->siguiente;        
        }
        actual = actual->siguiente;
    }
}

// funcion auxilar interna para ordenar el arreglo usando QuickSort (Descendente por Ranking)
// nota: implementado mediante el esquema de partición de Hoare (dos punteros i y j)
void quickSortArray(Jugador arr[], int izquierda, int derecha) {
    if (izquierda >= derecha) {
        return;    
    }

    int i = izquierda;
    int j = derecha;
    // seleccionamos el pivote usando la formula segura contra desbordamiento
    Jugador pivote = arr[izquierda + (derecha - izquierda) / 2];

    while (i <= j) {
        // para ordenar de mayor a menor (descendente):
        // Avanzamos 'i' mientras el ranking sea mayor que el pivote
        while (arr[i].ranking > pivote.ranking) {
            i++;        
        }
        // retrocedemos 'j' mientras el ranking sea menor que el pivote
        while (arr[j].ranking < pivote.ranking) {
            j--;        
        }
        if (i <= j) {
            // intercambiamos los elementos de tipo jugador usando variable temporal 'temp'
            Jugador temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;        
        }
    }

    // llamadas recursivas para subdividir el arreglo
    quickSortArray(arr, izquierda, j);
    quickSortArray(arr, i, derecha);
}

// 4. ordenamiento QuickSort (Por ranking - descendente)
void ordenarPorRankingQuickSort(NodoJugador* fin) {
    if (fin == nullptr || fin->siguiente == fin) {
        return;    
    }
    int N = contarNodos(fin);
    // creamos una arreglo dinámico para copiar los datos reales
    Jugador* arr = new Jugador[N];

    // copiamos los datos de la lista circular al arreglo
    NodoJugador* actual = fin->siguiente;
    for (int i = 0; i < N; i++) {
        arr[i] = actual->dato;
        actual = actual->siguiente;    
    }

    // ejecutamos quicksort sobre el arreglo de structs
    quickSortArray(arr, 0, N - 1);

    // copiamos los datos ya ordenados del arreglo de regreso a la lista circular
    actual = fin->siguiente;
    for (int i = 0; i < N; i++) {
        actual->dato = arr[i];
        actual = actual->siguiente;    
    }

    // liberamos la memoria del arreglo temporal para evitar fuga de memoria
    delete [] arr;
}

// función auxiliar interna para fusionar dos sub-arreglos ordenados (Merge)
void merge(Jugador arr[], int izuquierda, int medio, int derecha) {
    int n1 = medio - izuquierda + 1;
    int n2 = derecha - medio;

    // creamos arreglos auxiliares temporales
    Jugador* L = new Jugador[n1];
    Jugador* R = new Jugador[n2];

    // copiamos los datos a los arreglos auxiliares L[] y R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[izuquierda + i];    
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[medio + 1 + j];    
    }

    // fusionamos los arreglos temporales de regreso en arr[izquierda..derecha]
    int i = 0; // indice inicial del primer sub-arreglo (izquerda)
    int j = 0; // indice inicial del segundo sub-arreglo (derecho)
    int k = izuquierda; // indice inicial del arreglo fusionado

    while (i < n1 && j < n2) {
        // ordenamiento por ID de forma ASCENDENTE (de menor a mayor ID)
        if (L[i].id <= R[j].id) {
            arr[k] = L[i];
            i++;        
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copiamos los elementos restantes de L[], si quedan alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;    
    }

    // copiamos los elementos restantes de R[], si quedan alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;    
    }

    // liberamos la memoria de los arreglos auxiliares
    delete [] L;
    delete [] R;
}

// función auxiliar recursiva de MergeSort
void mergeSortArray(Jugador arr[], int izquierda, int derecha) {
    if (izquierda >= derecha) {
        return; // caso base: un solo elemento    
    }

    int medio = izquierda + (derecha - izquierda) / 2; // evitamos desboradamientos

    // dividimos y ordenamos de forma recursiva ambas mitades
    mergeSortArray(arr, izquierda, medio);
    mergeSortArray(arr, medio + 1, derecha);

    // fusionamos las dos mitades ordenadas
    merge(arr, izquierda, medio, derecha);
}

// 5. ordenamiento MergeSort (Por ID - Ascendente)
void ordenarPorIDMergeSort(NodoJugador *fin) {
    if (fin == nullptr || fin->siguiente == fin) {
        return; // lista vacía o con un solo elemento    
    }

    int N = contarNodos(fin);
    Jugador* arr = new Jugador[N]; // reservamos el arreglo dinámico

    // copiamos la lista circular al arreglo
    NodoJugador* actual = fin->siguiente;
    for (int i = 0; i < N; i++) {
        arr[i] = actual->dato;
        actual = actual->siguiente;   
    }

    // ejecutamos MergeSort sobre el arreglo de structs
    mergeSortArray(arr, 0, N - 1);

    // copiamos los datos ordenados del arreglo de regreso a lo lista circular
    actual = fin->siguiente;
    for (int i = 0; i < N; i++) {
        actual->dato = arr[i];
        actual = actual->siguiente;
    }

    delete[] arr; // liberamos el arreglo dinámico
} 