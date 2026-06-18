#include <iostream>
#include "jugadores.h"

using namespace std;

void registrarJugador(NodoJugador* &cabeza, Jugador nuevoJugador){

    NodoJugador* nuevoNodo = new NodoJugador(); // instanciamos 
    nuevoNodo -> dato = nuevoJugador; // parcialmente ya llenado en el main

    if(cabeza == nullptr){
        cabeza = nuevoNodo;
        cabeza -> siguiente = cabeza; // esto es porque es circular
    }else{
        // buscamos el ultimo nodo por el metodo simple
        NodoJugador* actual = cabeza; // guardamos en una variable para no perder el puntero
        while(actual -> siguiente != cabeza){

            actual = actual ->siguiente; 
        }
        
    }


}