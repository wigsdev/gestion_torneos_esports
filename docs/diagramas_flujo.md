# 📊 Diagramas de Flujo del Sistema

Este documento contiene los diagramas de flujo de los algoritmos y procesos clave del sistema de gestión de torneos.

---

## 1. Proceso de Inscripción y Admisión (Módulo 3)
Describe cómo ingresa un jugador a la cola de espera y cómo es atendido para pasar a formar parte de la lista oficial de competidores del torneo.

```mermaid
flowchart TD
    Start([Inicio]) --> Op1["Usuario selecciona Registrar Inscripción"]
    Op1 --> Input["Ingresar Nickname y Edad del Jugador"]
    Input --> Action1["Insertar Jugador al final de la Cola - encolar"]
    Action1 --> Decision{"¿Atender Inscripción?"}
    Decision -- Sí --> Action2["Retirar primer elemento de la Cola - desencolar"]
    Action2 --> Action3["Insertar elemento retirado en la Lista Circular de Jugadores"]
    Action3 --> End([Fin])
    Decision -- No --> End
```
## 2. Ordenamiento por Burbuja (Bubble Sort) sobre Lista Circular (Módulo 6)
Diagrama de la implementación de `ordenarPorEdadBurbuja` que recorre la lista circular comparando elementos adyacentes hasta dar la vuelta y retornar si no hay más intercambios.

```mermaid
flowchart TD
    Start([Inicio]) --> CheckEmpty{"¿fin == nullptr?"}
    CheckEmpty -- Sí --> End([Fin])
    CheckEmpty -- No --> LoopDo["Hacer (do)"]
    LoopDo --> Init["intercambiado = false
actual = fin->siguiente (cabeza)"]
    Init --> LoopWhile{"¿actual->siguiente != fin->siguiente?"}
    LoopWhile -- Sí --> Compare{"¿actual->dato.edad > actual->siguiente->dato.edad?"}
    Compare -- Sí --> Swap["Intercambiar datos de los nodos
intercambiado = true"]
    Swap --> Advance["actual = actual->siguiente"]
    Compare -- No --> Advance
    Advance --> LoopWhile
    LoopWhile -- No --> LoopCond{"¿intercambiado == true?"}
    LoopCond -- Sí --> LoopDo
    LoopCond -- No --> End
```

---

## 3. Registro e Historial de Campeones en Pila LIFO (Módulo 4)
Diagrama de flujo que ilustra el registro de un nuevo campeón (apilar - push) y la consulta del campeón más reciente en el torneo (cima - top).

### Registrar nuevo campeón (Push)
```mermaid
flowchart TD
    StartPush([Inicio: registrarCampeon]) --> Input["Recibir datos del campeón (c)"]
    Input --> NewNode["Crear nuevoNodo en memoria dinámica"]
    NewNode --> Assign["nuevoNodo->dato = c
nuevoNodo->siguiente = cima"]
    Assign --> UpdateCima["cima = nuevoNodo"]
    UpdateCima --> EndPush([Fin])
```

### Consultar último campeón (Top)
```mermaid
flowchart TD
    StartTop([Inicio: consultarUltimoCampeon]) --> CheckCima{"¿cima == nullptr?"}
    CheckCima -- Sí --> Empty["Mostrar: Historial vacío"]
    CheckCima -- No --> Show["Mostrar: cima->dato.nickname e info de torneo"]
    Empty --> EndTop([Fin])
    Show --> EndTop
```
