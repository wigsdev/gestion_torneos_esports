#ifndef PILA_H
#define PILA_H

#include "estructuras.h"

// Estructura del Nodo para la Pila de Campeones
struct NodoCampeon {
    Campeon dato;
    NodoCampeon* siguiente;
};

// ==============================================================================
// --- VICTOR (Integrante 2) - MÓDULO 4: HISTORIAL DE CAMPEONES (PILA LIFO) ---
// ==============================================================================
// Implementar aquí las funciones de la Pila LIFO:
void pushCampeon(NodoCampeon* &cima, Campeon c);
void popCampeon(NodoCampeon* &cima);
void mostrarHistorial(NodoCampeon* cima);
void consultarUltimoCampeon(NodoCampeon* cima);

#endif
