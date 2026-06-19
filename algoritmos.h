#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "estructuras.h"
#include "jugadores.h"

// ==========================================
// --- TODO (Integrante 3) - BÚSQUEDAS Y RECURSIVIDAD ---
// ==========================================
// - buscarPorNickname (secuencial)

NodoJugador* buscarPorNickname(NodoJugador* fin, string nickname) {
    if (fin == nullptr) return nullptr;

    NodoJugador* actual = fin->siguiente; 
    do {
        if (actual->dato.nickname == nickname) return actual;
        actual = actual->siguiente;
    } while (actual != fin->siguiente);

    return nullptr;
}

// - buscarPorNombre (secuencial)

NodoJugador* buscarPorNombre(NodoJugador* fin, string nombre) {
    if (fin == nullptr) return nullptr;

    NodoJugador* actual = fin->siguiente; // cabeza
    do {
        if (actual->dato.nombre == nombre) return actual;
        actual = actual->siguiente;
    } while (actual != fin->siguiente);

    return nullptr;
}

// - buscarPorIDBinaria
// - mostrarRankingRecursivo
// - contarJugadoresRecursivo
// - sumarPuntajesRecursivo
// - buscarJugadorRecursivo


// ==========================================
// --- TODO (Integrante 4) - ORDENAMIENTOS ---
// ==========================================
// - ordenarPorEdadBurbuja
// - ordenarPorNicknameSeleccion
// - ordenarPorNombreInsercion
// - ordenarPorRankingQuickSort
// - ordenarPorIDMergeSort

#endif
