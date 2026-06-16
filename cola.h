#ifndef COLA_H
#define COLA_H

#include "estructuras.h"

// Estructura del Nodo para la Cola de Espera
struct NodoCola {
    Jugador dato;
    NodoCola* siguiente;
};

// --- TODO (Integrante 2) ---
// Implementar aquí las funciones de la Cola:
// - encolarInscripcion
// - mostrarCola
// - desencolarInscripcion (atender inscripción)

#endif
