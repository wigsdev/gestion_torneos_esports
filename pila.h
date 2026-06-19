#ifndef PILA_H
#define PILA_H

#include "estructuras.h"

// Estructura del Nodo para la Pila de Campeones
struct NodoCampeon {
    Campeon dato;
    NodoCampeon* siguiente;
};

// --- TODO (Integrante 3) ---
// Implementar aquí las funciones de la Pila:
// - pushCampeon

void pushCampeon(NodoCampeon* &cima, Campeon c) {
    NodoCampeon* nuevo = new NodoCampeon();
    nuevo->dato = c;
    nuevo->siguiente = cima; 
    cima = nuevo;            

    cout << ">> Campeón '" << c.nickname
         << "' del torneo '" << c.nombreTorneo
         << "' registrado en el Salón de la Fama." << endl;
}

// - popCampeon

void popCampeon(NodoCampeon* &cima) {
    if (cima == nullptr) {
        cout << ">> El Salón de la Fama está vacío. No hay campeones que eliminar." << endl;
        return;
    }

    NodoCampeon* nodoAEliminar = cima;
    cout << ">> Eliminando a '" << cima->dato.nickname
         << "' (Torneo: " << cima->dato.nombreTorneo
         << ") del registro." << endl;

    cima = cima->siguiente; 
    delete nodoAEliminar;   
}

// - mostrarHistorial

void mostrarHistorial(NodoCampeon* cima) {
    if (cima == nullptr) {
        cout << ">> El Salón de la Fama está vacío." << endl;
        return;
    }

    cout << "\n=== SALÓN DE LA FAMA - HISTORIAL DE CAMPEONES ===" << endl;
    NodoCampeon* actual = cima;
    int posicion = 1;
    while (actual != nullptr) {
        cout << "  [" << posicion++ << "] "
             << "Nickname: " << actual->dato.nickname
             << " | Torneo: " << actual->dato.nombreTorneo
             << endl;
        actual = actual->siguiente;
    }
    cout << "==================================================" << endl;
}

// - consultarUltimoCampeon

void consultarUltimoCampeon(NodoCampeon* cima) {
    if (cima == nullptr) {
        cout << ">> El Salón de la Fama está vacío. Aún no hay campeones registrados." << endl;
        return;
    }

    cout << "\n--- Último Campeón Registrado ---" << endl;
    cout << "  Nickname : " << cima->dato.nickname    << endl;
    cout << "  Torneo   : " << cima->dato.nombreTorneo << endl;
    cout << "---------------------------------" << endl;
}

#endif
