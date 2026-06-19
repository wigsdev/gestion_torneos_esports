#include <iostream>
#include <string>
#include "estructuras.h"
#include "jugadores.h"
#include "partidas.h"
#include "cola.h"
#include "pila.h"
#include "algoritmos.h"

using namespace std;

// ==============================================================================
// FUNCIONES AUXILIARES DE VALIDACIÓN DE UNICIDAD DE ID
// ==============================================================================
bool existeID(NodoJugador* fin, int id) {
    if (fin == nullptr) return false;
    NodoJugador* actual = fin->siguiente; // cabeza
    do {
        if (actual->dato.id == id) return true;
        actual = actual->siguiente;
    } while (actual != fin->siguiente);
    return false;
}

bool existeIDEnCola(NodoCola* frente, int id) {
    NodoCola* actual = frente;
    while (actual != nullptr) {
        if (actual->dato.id == id) return true;
        actual = actual->siguiente;
    }
    return false;
}

// ==============================================================================
// 1. PUNTEROS GLOBALES / DE CONTROL DE LAS ESTRUCTURAS
// ==============================================================================
NodoJugador* listaJugadores = nullptr; // Módulo 1: Lista Circular de Jugadores (Javier)
NodoPartida* listaPartidas = nullptr;   // Módulo 2: Lista Simple de Partidas (Javier)
NodoCola* colaFrente = nullptr;         // Módulo 3: Cola de Inscripción - Frente (Victor)
NodoCola* colaFin = nullptr;            // Módulo 3: Cola de Inscripción - Fin (Victor)
NodoCampeon* pilaCampeones = nullptr;   // Módulo 4: Pila de Campeones (Victor)

// ==============================================================================
// 2. DECLARACIÓN DE MENÚS Y SUBMENÚS
// ==============================================================================
void menuPrincipal() {
    cout << "\n==========================================" << endl;
    cout << "  SISTEMA DE GESTIÓN DE TORNEOS DE ESPORTS  " << endl;
    cout << "==========================================" << endl;
    cout << "1. Gestión de Jugadores (Lista Circular)" << endl;
    cout << "2. Cola de Inscripciones (Cola FIFO)" << endl;
    cout << "3. Historial de Partidas (Lista Simple)" << endl;
    cout << "4. Salón de la Fama (Pila LIFO)" << endl;
    cout << "5. Reportes Estadísticos (Recursivos)" << endl;
    cout << "6. Salir del Sistema" << endl;
    cout << "Selecciona una opción: ";
}

void submenuJugadores() {
    cout << "\n------------------------------------------" << endl;
    cout << "          GESTIÓN DE JUGADORES" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Registrar nuevo jugador" << endl;
    cout << "2. Eliminar jugador (por ID)" << endl;
    cout << "3. Modificar jugador (por ID)" << endl;
    cout << "4. Mostrar lista de jugadores" << endl;
    cout << "5. Buscar jugador (Secuencial / Binaria)" << endl;
    cout << "6. Ordenar jugadores (Burbuja / Selección / Inserción / Quick / Merge)" << endl;
    cout << "7. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuInscripciones() {
    cout << "\n------------------------------------------" << endl;
    cout << "          COLA DE INSCRIPCIONES" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Inscribir jugador en cola de espera" << endl;
    cout << "2. Mostrar lista de espera" << endl;
    cout << "3. Atender inscripción (Desencolar y registrar en torneo)" << endl;
    cout << "4. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuPartidas() {
    cout << "\n------------------------------------------" << endl;
    cout << "          HISTORIAL DE PARTIDAS" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Registrar resultado de partida" << endl;
    cout << "2. Mostrar todas las partidas jugadas" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuCampeones() {
    cout << "\n------------------------------------------" << endl;
    cout << "          SALÓN DE LA FAMA (PILA)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Registrar nuevo campeón de torneo" << endl;
    cout << "2. Consultar último campeón" << endl;
    cout << "3. Ver historial de campeones completo" << endl;
    cout << "4. Eliminar último campeón registrado" << endl;
    cout << "5. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuReportes() {
    cout << "\n------------------------------------------" << endl;
    cout << "        REPORTES Y ESTADÍSTICAS RECURSIVAS" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Mostrar ranking de jugadores" << endl;
    cout << "2. Contar total de jugadores en el torneo" << endl;
    cout << "3. Sumar puntajes de ranking totales" << endl;
    cout << "4. Buscar jugador por nickname" << endl;
    cout << "5. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

// ==============================================================================
// 3. FUNCIÓN PRINCIPAL (ORQUESTADOR)
// ==============================================================================
int main() {
    int opcionPrincipal;

    do {
        menuPrincipal();
        if (!(cin >> opcionPrincipal)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (opcionPrincipal) {
            case 1: { // GESTIÓN DE JUGADORES (Integrante 1 - Javier - Módulo 1)
                int op;
                do {
                    submenuJugadores();
                    cin >> op;
                    switch (op) {
                        case 1: {
                            int id;
                            cout << "Ingrese ID: "; cin >> id;
                            if (existeID(listaJugadores, id) || existeIDEnCola(colaFrente, id)) {
                                cout << ">> [ERROR] El ID " << id << " ya está registrado o en cola de espera. Registro cancelado." << endl;
                                break;
                            }
                            Jugador nuevo;
                            nuevo.id = id;
                            cout << "Ingrese Nombre: "; cin.ignore(); getline(cin, nuevo.nombre);
                            cout << "Ingrese Nickname: "; getline(cin, nuevo.nickname);
                            cout << "Ingrese Edad: "; cin >> nuevo.edad;
                            cout << "Ingrese Puntaje Ranking: "; cin >> nuevo.ranking;
                            // LLAMADA INTEGRANTE 1 (Javier - Módulo 1):
                            registrarJugador(listaJugadores, nuevo);
                            break;
                        }
                        case 2: {
                            int id;
                            cout << "Ingrese el ID del jugador a eliminar: "; cin >> id;
                            // LLAMADA INTEGRANTE 1 (Javier - Módulo 1):
                            eliminarJugador(listaJugadores, id);
                            break;
                        }
                        case 3: {
                            int id;
                            cout << "Ingrese el ID del jugador a modificar: "; cin >> id;
                            Jugador mod;
                            cout << "Ingrese nuevo Nombre: "; cin.ignore(); getline(cin, mod.nombre);
                            cout << "Ingrese nuevo Nickname: "; getline(cin, mod.nickname);
                            cout << "Ingrese nueva Edad: "; cin >> mod.edad;
                            cout << "Ingrese nuevo Puntaje: "; cin >> mod.ranking;
                            mod.id = id;
                            // LLAMADA INTEGRANTE 1 (Javier - Módulo 1):
                            modificarJugador(listaJugadores, id, mod);
                            break;
                        }
                        case 4:
                            // LLAMADA INTEGRANTE 1 (Javier - Módulo 1):
                            mostrarJugadores(listaJugadores);
                            break;
                        case 5: { // Búsquedas (Integrantes 2 y 3 - Módulo 5)
                            int opB;
                            cout << "\n1. Buscar por Nickname (Secuencial - Victor)" << endl;
                            cout << "2. Buscar por Nombre (Secuencial - Victor)" << endl;
                            cout << "3. Buscar por ID (Binaria - Wilmer)" << endl;
                            cout << "Seleccione tipo de búsqueda: "; cin >> opB;
                            if (opB == 1) {
                                string nick;
                                cout << "Ingrese Nickname a buscar: "; cin.ignore(); getline(cin, nick);
                                // LLAMADA INTEGRANTE 2 (Victor - Módulo 5):
                                NodoJugador* res = buscarPorNickname(listaJugadores, nick);
                                if (res != nullptr) {
                                    cout << "Jugador encontrado por Búsqueda Secuencial!" << endl;
                                    cout << "ID: " << res->dato.id 
                                         << " | Nombre: " << res->dato.nombre 
                                         << " | Nickname: " << res->dato.nickname 
                                         << " | Edad: " << res->dato.edad
                                         << " | Ranking: " << res->dato.ranking << endl;
                                } else {
                                    cout << "Jugador con Nickname '" << nick << "' no encontrado." << endl;
                                }
                            } else if (opB == 2) {
                                string nom;
                                cout << "Ingrese Nombre a buscar: "; cin.ignore(); getline(cin, nom);
                                // LLAMADA INTEGRANTE 2 (Victor - Módulo 5):
                                NodoJugador* res = buscarPorNombre(listaJugadores, nom);
                                if (res != nullptr) {
                                    cout << "Jugador encontrado por Búsqueda Secuencial!" << endl;
                                    cout << "ID: " << res->dato.id 
                                         << " | Nombre: " << res->dato.nombre 
                                         << " | Nickname: " << res->dato.nickname 
                                         << " | Edad: " << res->dato.edad
                                         << " | Ranking: " << res->dato.ranking << endl;
                                } else {
                                    cout << "Jugador con Nombre '" << nom << "' no encontrado." << endl;
                                }
                            } else if (opB == 3) {
                                int id;
                                cout << "Ingrese ID a buscar: "; cin >> id;
                                // LLAMADA INTEGRANTE 3 (Wilmer - Módulo 5):
                                NodoJugador* res = buscarPorIDBinaria(listaJugadores, id);
                                if (res != nullptr) {
                                    cout << "Jugador encontrado por Búsqueda Binaria!" << endl;
                                    cout << "ID: " << res->dato.id 
                                         << " | Nombre: " << res->dato.nombre 
                                         << " | Nickname: " << res->dato.nickname 
                                         << " | Edad: " << res->dato.edad
                                         << " | Ranking: " << res->dato.ranking << endl;
                                } else {
                                    cout << "Jugador con ID " << id << " no encontrado." << endl;
                                }
                            }
                            break;
                        }
                        case 6: { // Ordenamientos (Integrante 3 - Wilmer - Módulo 6)
                            int opO;
                            cout << "\n1. Ordenar por Edad (Burbuja)" << endl;
                            cout << "2. Ordenar por Nickname (Selección)" << endl;
                            cout << "3. Ordenar por Nombre (Inserción)" << endl;
                            cout << "4. Ordenar por Ranking (Quick Sort)" << endl;
                            cout << "5. Ordenar por ID (Merge Sort)" << endl;
                            cout << "Seleccione tipo de ordenamiento: "; cin >> opO;
                            if (opO == 1) {
                                ordenarPorEdadBurbuja(listaJugadores);
                            } else if (opO == 2) {
                                ordenarPorNicknameSeleccion(listaJugadores);
                            } else if (opO == 3) {
                                ordenarPorNombreInsercion(listaJugadores);
                            } else if (opO == 4) {
                                ordenarPorRankingQuickSort(listaJugadores);
                            } else if (opO == 5) {
                                ordenarPorIDMergeSort(listaJugadores);
                            }
                            break;
                        }
                    }
                } while (op != 7);
                break;
            }
            case 2: { // COLA DE INSCRIPCIONES (Integrante 2 - Victor - Módulo 3)
                int op;
                do {
                    submenuInscripciones();
                    cin >> op;
                    switch (op) {
                        case 1: {
                            int id;
                            cout << "Ingrese ID: "; cin >> id;
                            if (existeID(listaJugadores, id) || existeIDEnCola(colaFrente, id)) {
                                cout << ">> [ERROR] El ID " << id << " ya está registrado o en cola de espera. Registro cancelado." << endl;
                                break;
                            }
                            Jugador j;
                            j.id = id;
                            cout << "Ingrese Nombre: "; cin.ignore(); getline(cin, j.nombre);
                            cout << "Ingrese Nickname: "; getline(cin, j.nickname);
                            cout << "Ingrese Edad: "; cin >> j.edad;
                            cout << "Ingrese Puntaje Ranking: "; cin >> j.ranking;
                            // LLAMADA INTEGRANTE 2 (Victor - Módulo 3):
                            encolarInscripcion(colaFrente, colaFin, j);
                            break;
                        }
                        case 2:
                            // LLAMADA INTEGRANTE 2 (Victor - Módulo 3):
                            mostrarCola(colaFrente);
                            break;
                        case 3: { // Atender inscripción
                            // INTEGRACIÓN DE LA COLA A LA LISTA CIRCULAR (INTEGRANTES 1 Y 2)
                            
                            if (colaFrente == nullptr) {
                                cout << "No hay jugadores en lista de espera." << endl;
                            } else {
                                // Desencola (Victor - Integrante 2 - M3) e Inserta (Javier - Integrante 1 - M1)
                                Jugador jAtendido = desencolarInscripcion(colaFrente, colaFin);
                                if (existeID(listaJugadores, jAtendido.id)) {
                                    cout << ">> [ERROR] No se pudo admitir al jugador. El ID " << jAtendido.id << " ya fue registrado directamente." << endl;
                                } else {
                                    registrarJugador(listaJugadores, jAtendido);
                                    cout << "Jugador " << jAtendido.nickname << " admitido en el torneo." << endl;
                                }
                            }                            
                            break;
                        }
                    }
                } while (op != 4);
                break;
            }
            case 3: { // HISTORIAL DE PARTIDAS (Integrante 1 - Javier - Módulo 2)
                int op;
                do {
                    submenuPartidas();
                    cin >> op;
                    switch (op) {
                        case 1: {
                            Partida p;
                            cout << "Ingrese Nickname Jugador A: "; cin.ignore(); getline(cin, p.jugadorA);
                            cout << "Ingrese Nickname Jugador B: "; getline(cin, p.jugadorB);
                            cout << "Ingrese Nickname del Ganador: "; getline(cin, p.ganador);
                            cout << "Ingrese Fecha (DD/MM/AAAA): "; getline(cin, p.fecha);
                            // LLAMADA INTEGRANTE 1 (Javier - Módulo 2):
                            registrarPartida(listaPartidas, p);
                            break;
                        }
                        case 2:
                            // LLAMADA INTEGRANTE 1 (Javier - Módulo 2):
                            mostrarPartidas(listaPartidas);
                            break;
                    }
                } while (op != 3);
                break;
            }
            case 4: { // HISTORIAL DE CAMPEONES (Integrante 2 - Victor - Módulo 4)
                int op;
                do {
                    submenuCampeones();
                    cin >> op;
                    switch (op) {
                        case 1: {
                            Campeon c;
                            cout << "Ingrese Nickname del Campeón: "; cin.ignore(); getline(cin, c.nickname);
                            cout << "Ingrese Nombre del Torneo: "; getline(cin, c.nombreTorneo);
                            // LLAMADA INTEGRANTE 2 (Victor - Módulo 4):
                            pushCampeon(pilaCampeones, c);
                            break;
                        }
                        case 2:
                            // LLAMADA INTEGRANTE 2 (Victor - Módulo 4):
                            consultarUltimoCampeon(pilaCampeones);
                            break;
                        case 3:
                            // LLAMADA INTEGRANTE 2 (Victor - Módulo 4):
                            mostrarHistorial(pilaCampeones);
                            break;
                        case 4:
                            // LLAMADA INTEGRANTE 2 (Victor - Módulo 4):
                            popCampeon(pilaCampeones);
                            break;
                    }
                } while (op != 5);
                break;
            }
            case 5: { // REPORTES ESTADÍSTICOS RECURSIVOS (Integrante 3 - Wilmer - Módulo 7)
                int op;
                do {
                    submenuReportes();
                    cin >> op;
                    switch (op) {
                        case 1:
                            // LLAMADA INTEGRANTE 3 (Wilmer - Módulo 7 - Recursivo):
                            mostrarRankingRecursivo(listaJugadores ? listaJugadores->siguiente : nullptr, listaJugadores, true);
                            break;
                        case 2: {
                            // LLAMADA INTEGRANTE 3 (Wilmer - Módulo 7 - Recursivo):
                            int total = contarJugadoresRecursivo(listaJugadores ? listaJugadores->siguiente : nullptr, listaJugadores, true);
                            cout << "Total de jugadores: " << total << endl;
                            break;
                        }
                        case 3: {
                            // LLAMADA INTEGRANTE 3 (Wilmer - Módulo 7 - Recursivo):
                            int suma = sumarPuntajesRecursivo(listaJugadores ? listaJugadores->siguiente : nullptr, listaJugadores, true);
                            cout << "Suma total de puntajes de ranking: " << suma << endl;
                            break;
                        }
                        case 4: {
                            string nick;
                            cout << "Ingrese Nickname a buscar recursivamente: "; cin.ignore(); getline(cin, nick);
                            // LLAMADA INTEGRANTE 3 (Wilmer - Módulo 7 - Recursivo):
                            NodoJugador* res = buscarJugadorRecursivo(listaJugadores ? listaJugadores->siguiente : nullptr, listaJugadores, nick, true);
                            if (res != nullptr) {
                                cout << "Jugador encontrado recursivamente!" << endl;
                                cout << "Nombre: " << res->dato.nombre << " | Ranking: " << res->dato.ranking << endl;                            
                            } else {
                                cout << "Jugador con nickname '" << nick << "' no fue encontrado." << endl;
                            }
                            break;
                        }
                    }
                } while (op != 5);
                break;
            }            
            case 6:
                cout << "\nSaliendo del sistema..." << endl;
                break;
            default:
                cout << "\nOpción inválida." << endl;
        }
    } while (opcionPrincipal != 6);

    return 0;
}
