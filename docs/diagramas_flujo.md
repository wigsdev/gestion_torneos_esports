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

---

## 2. Ordenamiento por Burbuja (Bubble Sort) sobre Lista Enlazada
Diagrama del algoritmo para ordenar la lista intercambiando los campos de datos de los nodos.

```mermaid
flowchart TD
    Start([Inicio]) --> Init["Establecer intercambiado = false, actual = cabeza"]
    Init --> Check{"¿actual->siguiente != ultimoLeido?"}
    Check -- Sí --> Compare{"¿actual->dato > actual->siguiente->dato?"}
    Compare -- Sí --> Swap["Intercambiar valores en RAM"]
    Swap --> SetFlag["intercambiado = true"]
    SetFlag --> Move["actual = actual->siguiente"]
    Compare -- No --> Move
    Move --> Check
    Check -- No --> Last["ultimoLeido = actual"]
    Last --> Loop{"¿intercambiado == true?"}
    Loop -- Sí --> Init
    Loop -- No --> End([Fin - Lista Ordenada])
```

---

## 3. Algoritmo de Verificación de Expresión Balanceada (Pilas)
Muestra la lógica utilizada para evaluar si los delimitadores matemáticos de agrupación abren y cierran en el orden correcto.

```mermaid
flowchart TD
    Start([Inicio]) --> Loop["Leer siguiente carácter de la expresión"]
    Loop --> CheckOpen{"¿Es apertura? '(', '[', '{'"}
    CheckOpen -- Sí --> Push["pila.push c"]
    Push --> CheckEnd
    CheckOpen -- No --> CheckClose{"¿Es cierre? ')', ']', '}'"}
    CheckClose -- Sí --> CheckEmpty{"¿pila.empty?"}
    CheckEmpty -- Sí --> Invalid["Retornar Falso - Desbalanceada"]
    CheckEmpty -- No --> Compare["cima = pila.top"]
    Compare --> Match{"¿cima y actual coinciden?"}
    Match -- Sí --> Pop["pila.pop"]
    Pop --> CheckEnd
    Match -- No --> Invalid
    CheckClose -- No --> CheckEnd
    CheckEnd{"¿Fin de la cadena?"}
    CheckEnd -- No --> Loop
    CheckEnd -- Sí --> FinalEmpty{"¿pila.empty?"}
    FinalEmpty -- Sí --> Valid["Retornar Verdadero - Balanceada"]
    FinalEmpty -- No --> Invalid
    Valid --> End([Fin])
    Invalid --> End
```
