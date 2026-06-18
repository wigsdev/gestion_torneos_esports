#include "algoritmos.h"

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
