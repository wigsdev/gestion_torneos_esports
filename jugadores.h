#ifndef JUGADORES_H
#define JUGADORES_H

#include "estructuras.h"

// Estructura del Nodo para la Lista Circular
struct NodoJugador {
    Jugador dato;
    NodoJugador* siguiente;
};

// --- TODO (Integrante 1) ---

// Implementar aquí las funciones de la Lista Circular:

// - registrarJugador
void registrarJugador(NodoJugador* &cabeza, Jugador nuevoJugador ); // inicializado en el Main
// - eliminarJugador
void eliminarJugador(NodoJugador* &cabeza, int id);// se va a buscar con el ID
// - modificarJugador
void modificarJugador(NodoJugador* cabeza, int id, Jugador modificado); // solo por valor -> dirección
// - mostrarJugadores
void mostrarJugadores (NodoJugador* cabeza); // 

#endif
