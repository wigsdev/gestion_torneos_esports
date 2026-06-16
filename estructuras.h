#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
using namespace std;

// Estructura del Jugador
struct Jugador {
    int id;
    string nombre;
    string nickname;
    int edad;
    int ranking;
};

// Estructura para el Historial de Partidas
struct Partida {
    string jugadorA;
    string jugadorB;
    string ganador;
    string fecha;
};

// Estructura de Campeón
struct Campeon {
    string nickname;
    string nombreTorneo;
};

#endif
