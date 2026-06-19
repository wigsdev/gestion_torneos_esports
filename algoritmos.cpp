#include "algoritmos.h"
#include "estructuras.h"
#include "jugadores.h"

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
