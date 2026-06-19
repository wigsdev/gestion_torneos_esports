#include <iostream>
#include "jugadores.h"

using namespace std;

// 1. Registrar jugador en lista circular - O(1) inserción al final
void registrarJugador(NodoJugador* &fin, Jugador nuevo) {
    NodoJugador* nuevoNodo = new NodoJugador();
    nuevoNodo->dato = nuevo;

    if (fin == nullptr) {
        nuevoNodo->siguiente = nuevoNodo;
        fin = nuevoNodo;
    } else {
        nuevoNodo->siguiente = fin->siguiente; // el nuevo nodo apunta a la cabeza
        fin->siguiente = nuevoNodo;            // el anterior fin apunta al nuevo nodo
        fin = nuevoNodo;                       // el nuevo nodo ahora es el fin
    }
    cout << ">> Se registró exitosamente al jugador '" << nuevo.nickname << "'." << endl;
}

// 2. Eliminar jugador de lista circular - O(N) búsqueda y eliminación
void eliminarJugador(NodoJugador* &fin, int id) {
    if (fin == nullptr) {
        cout << ">> No hay jugadores para eliminar." << endl;
        return;
    }

    NodoJugador* actual = fin->siguiente; // cabeza
    NodoJugador* previo = fin;            // el anterior a la cabeza es el fin

    do {
        if (actual->dato.id == id) {
            if (actual == fin && actual->siguiente == fin) {
                // Caso 1: Solo hay un nodo en la lista
                fin = nullptr;
            } else {
                previo->siguiente = actual->siguiente;
                if (actual == fin) {
                    // Caso 2: Estamos eliminando el último nodo, movemos el puntero fin
                    fin = previo;
                }
            }
            delete actual;
            cout << ">> Jugador con ID " << id << " eliminado correctamente de la lista." << endl;
            return;
        }
        previo = actual;
        actual = actual->siguiente;
    } while (actual != fin->siguiente);

    cout << ">> No existe ningún jugador con el ID " << id << "." << endl;
}

// 3. Modificar datos de jugador
void modificarJugador(NodoJugador* fin, int id, Jugador modificado) {
    if (fin == nullptr) {
        cout << ">> No hay jugadores para modificar." << endl;
        return;
    }

    NodoJugador* actual = fin->siguiente; // cabeza
    do {
        if (actual->dato.id == id) {
            actual->dato = modificado;
            cout << ">> Datos del jugador actualizados correctamente en la lista." << endl;
            return;
        }
        actual = actual->siguiente;
    } while (actual != fin->siguiente);

    cout << ">> Error: No se encontró ningún jugador con el ID " << id << "." << endl;
}

// 4. Mostrar jugadores con todos sus campos y formato adecuado
void mostrarJugadores(NodoJugador* fin) {
    if (fin == nullptr) {
        cout << ">> No hay jugadores para mostrar." << endl;
        return;
    }

    cout << "\n--- Lista de Jugadores Registrados ---" << endl;
    NodoJugador* actual = fin->siguiente; // cabeza
    do {
        cout << "  ID: "       << actual->dato.id 
             << " | Nombre: "   << actual->dato.nombre
             << " | Nickname: " << actual->dato.nickname 
             << " | Edad: "     << actual->dato.edad
             << " | Ranking: "  << actual->dato.ranking << endl;
        actual = actual->siguiente;
    } while (actual != fin->siguiente);
    cout << "--------------------------------------" << endl;
}
