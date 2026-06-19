#include "cola.h"
#include <iostream>

using namespace std;

// Implementar aquí las funciones de la Cola FIFO:

// 1. Encolar una nueva inscripción
void encolarInscripcion(NodoCola* &frente, NodoCola* &fin, Jugador j) {
    NodoCola* nuevo = new NodoCola();
    nuevo->dato = j;
    nuevo->siguiente = nullptr;

    if (fin == nullptr) {
        frente = nuevo;
        fin    = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }

    cout << ">> Jugador '" << j.nickname
         << "' agregado a la lista de espera." << endl;
}

// 2. Mostrar todos los elementos de la cola
void mostrarCola(NodoCola* frente) {
    if (frente == nullptr) {
        cout << ">> La cola de inscripciones está vacía." << endl;
        return;
    }

    cout << "\n--- Lista de Espera (Cola FIFO) ---" << endl;
    NodoCola* actual = frente;
    int posicion = 1;
    while (actual != nullptr) {
        cout << "  [" << posicion++ << "] "
             << "ID: "       << actual->dato.id
             << " | Nombre: "   << actual->dato.nombre
             << " | Nickname: " << actual->dato.nickname
             << " | Edad: "     << actual->dato.edad
             << " | Ranking: "  << actual->dato.ranking
             << endl;
        actual = actual->siguiente;
    }
    cout << "-----------------------------------" << endl;
}

// 3. Desencolar (atender) una inscripción
Jugador desencolarInscripcion(NodoCola* &frente, NodoCola* &fin) {
    Jugador jugadorAtendido = frente->dato;
    NodoCola* nodoAEliminar = frente;

    frente = frente->siguiente;

    if (frente == nullptr) {
        fin = nullptr;
    }

    delete nodoAEliminar;

    return jugadorAtendido;
}
