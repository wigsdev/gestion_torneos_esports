#include <iostream>
#include "partidas.h"

using namespace std;

void registrarPartida(NodoPartida* &cabeza, Partida nuevaPartida) {
    //Instanciamos la lista
    NodoPartida* nuevoNodo = new NodoPartida();
    nuevoNodo->dato = nuevaPartida;
    nuevoNodo->siguiente = nullptr; // Al ser lista simple, el último siempre apunta a la nada

    //Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        // Si ya hay datos, usamos un explorador para llegar hasta el final
        NodoPartida* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        // Conectamos el último nodo con nuestro nuevo nodo
        actual->siguiente = nuevoNodo;
    }
    cout << "Partida registrada exitosamente: " << endl
     << nuevaPartida.jugadorA << " vs " << nuevaPartida.jugadorB << endl;

}

void mostrarPartidas(NodoPartida* cabeza) {
    // lista vacia 
    if (cabeza == nullptr) {
        cout << "\n[!] El historial de partidas esta vacio. No hay encuentros registrados.\n";
        return;
    }

    // Preparamos el explorador en el inicio
    NodoPartida* actual = cabeza;
    
    // Recorremos con un 'while' clásico  de la clase hasta que el explorador caiga en nullptr
    while (actual != nullptr) {

        cout << "Fecha: " << actual->dato.fecha 

             << " | " << actual->dato.jugadorA << " vs " << actual->dato.jugadorB 

             << " | Ganador: " << actual->dato.ganador <<endl;
        
        // Para que salte de nodo en nodo
        actual = actual->siguiente;
    }
    
}