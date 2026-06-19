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
        actual -> siguiente = nuevoNodo;
        nuevoNodo -> siguiente = cabeza;
    }
    cout<<"Se registro exitoxamente al "<< nuevoJugador.nickname<<endl;
    
}

void eliminarJugador(NodoJugador* &cabeza, int id){

if (cabeza == nullptr) { // La lista esta vacia 
        cout << " No hay jugadores para eliminar"<< endl;
        return;
    }

    NodoJugador* actual = cabeza;
    NodoJugador* previo = nullptr; 
    // Se va a formar 3 casos  
    // Caso 1  cuando hay solo un elemento y la lista se va a quedar vacia 
    if (actual->siguiente == cabeza && actual->dato.id == id) {
        
        cabeza = nullptr;
        // lo eliminamos 
        delete actual;    
        cout<< " Jugador eliminado. Por el momento no hay participantes"<< endl;
        return; 
    }
  
    NodoJugador* ultimo = cabeza; // ponemos un auxliar  para saber el ultimo

    while (ultimo->siguiente != cabeza) { // lo mandamos a recorrer hasta el ultimo 
        ultimo = ultimo->siguiente;
    }

    // Comenzamos la busqueda por todo la lista con el id
    do {
        // Si el ID coincide, entramos a la lógica de borrado 
        if (actual->dato.id == id) {
            
                // caso 2 se borra la caveza
            if (actual == cabeza) {
                // ponemos que cabeza pasa al siguiente noddo
                cabeza = actual->siguiente; 
                // aca es donde se utiliza el ultimo 
                ultimo->siguiente = cabeza; 
            } 
            
            // caso 3 cualquiera que no sea la cabeza
            else {
             
                previo->siguiente = actual->siguiente; 
            }

        
            delete actual; // lo destruimos 
            cout << "Jugador eliminado correctamente de la lista.";

            return; 
        }
        // recorrido
        previo = actual;             
        actual = actual->siguiente;  

     
    } while (actual != cabeza); 

   
    cout << "No existe ningun jugador con el ID " << id << endl;
}
 


void modificarJugador(NodoJugador* cabeza, int id, Jugador modificado){

    if (cabeza == nullptr) { // La lista esta vacia 
        cout << " No hay jugadores para eliminar"<< endl;
        return;
    }

NodoJugador* actual = cabeza;

  
    do {
        
        if (actual->dato.id == id) {
            
            // reemplazamos con el jugador modificado previamente 
            actual->dato = modificado ; 
            
            cout << " Datos del jugador actualizados correctamente en la lista"<<endl;
            return;
        }

        
        actual = actual->siguiente;

    
    } while (actual != cabeza);

    
    cout << "\n[X] Error: No se encontro ningun jugador con el ID " << modificado.id << ".\n";
}





void mostrarJugadores (NodoJugador* cabeza){

    if (cabeza == nullptr) { // La lista esta vacia 
            cout << "No hay jugadores para mostrar"<< endl;
            return;
        }
    NodoJugador* actual = cabeza;
    do {
       
        cout << "ID: " << actual->dato.id 
             << " | Nickname: " << actual->dato.nickname 
             << " | Ranking: " << actual->dato.ranking << endl;

      
        actual = actual->siguiente;

    
    } while (actual != cabeza);
}