#ifndef JUGADORES_H
#define JUGADORES_H

#include "estructuras.h"

// Estructura del Nodo para la Lista Circular
struct NodoJugador {
    Jugador dato;
    NodoJugador* siguiente;
};

// ==============================================================================
// --- JAVIER (Integrante 1) - MÓDULO 1: GESTIÓN DE JUGADORES (LISTA CIRCULAR) ---
// ==============================================================================
// Implementar aquí las funciones de la Lista Circular:
void registrarJugador(NodoJugador* &fin, Jugador nuevo);
void eliminarJugador(NodoJugador* &fin, int id);
void modificarJugador(NodoJugador* fin, int id, Jugador modificado);
void mostrarJugadores(NodoJugador* fin);

#endif
