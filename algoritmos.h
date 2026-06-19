#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "estructuras.h"
#include "jugadores.h"

// ==============================================================================
// --- VICTOR (Integrante 2) - MÓDULO 5: MOTORES DE BÚSQUEDA (SECUENCIAL) ---
// ==============================================================================
// Declarar aquí las búsquedas secuenciales:
// - NodoJugador* buscarPorNickname(NodoJugador* fin, string nickname);
// - NodoJugador* buscarPorNombre(NodoJugador* fin, string nombre);

// ==============================================================================
// --- WILMER (Integrante 3 - LÍDER) - MÓDULO 5: MOTORES DE BÚSQUEDA (BINARIA) ---
// ==============================================================================
// Declarar aquí la búsqueda binaria por ID (con copia temporal a arreglo):
// - NodoJugador* buscarPorIDBinaria(NodoJugador* fin, int id);
int contarNodos(NodoJugador* fin);
NodoJugador* buscarPorIDBinaria(NodoJugador* fin, int id);
// ==============================================================================
// --- WILMER (Integrante 3 - LÍDER) - MÓDULO 6: ALGORITMOS DE ORDENAMIENTO ---
// ==============================================================================
// Declarar aquí los ordenamientos sobre la lista circular de jugadores:
void ordenarPorEdadBurbuja(NodoJugador* fin);
void ordenarPorNicknameSeleccion(NodoJugador* fin);
void ordenarPorNombreInsercion(NodoJugador* fin);
// - void ordenarPorRankingQuickSort(NodoJugador* fin);
// - void ordenarPorIDMergeSort(NodoJugador* fin);

// ==============================================================================
// --- WILMER (Integrante 3 - LÍDER) - MÓDULO 7: REPORTES ESTADÍSTICOS RECURSIVOS ---
// ==============================================================================
// Declarar aquí los reportes analíticos utilizando recursividad:
// - void mostrarRankingRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta);
// - int contarJugadoresRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta);
// - int sumarPuntajesRecursivo(NodoJugador* nodo, NodoJugador* fin, bool primeraVuelta);
// - NodoJugador* buscarJugadorRecursivo(NodoJugador* nodo, NodoJugador* fin, string nickname, bool primeraVuelta);

#endif
