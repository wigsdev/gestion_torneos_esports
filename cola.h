#ifndef COLA_H
#define COLA_H

#include "estructuras.h"

// Estructura del Nodo para la Cola de Espera
struct NodoCola {
    Jugador dato;
    NodoCola *siguiente;
};


// ==============================================================================
// --- VICTOR (Integrante 2) - MÓDULO 3: COLA DE INSCRIPCIONES (COLA FIFO) ---
// ==============================================================================
// Implementar aquí las funciones de la Cola FIFO:
void encolarInscripcion(NodoCola* &frente, NodoCola* &fin, Jugador j);
void mostrarCola(NodoCola* frente);
Jugador desencolarInscripcion(NodoCola* &frente, NodoCola* &fin);

#endif
