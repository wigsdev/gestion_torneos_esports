# 🔗 Diagramas de Nodos del Sistema

Este documento describe de forma gráfica cómo se estructuran los nodos y punteros en la memoria RAM para cada una de las 4 estructuras de datos personalizadas implementadas en el proyecto.

---

## 1. Módulo 1: Lista Circular Simple (Gestión de Jugadores)
La lista circular no apunta a `nullptr` al final. En su lugar, el último nodo apunta de vuelta al primer nodo de la lista. Se utiliza un puntero `fin` (al último elemento) para tener acceso en $O(1)$ tanto al inicio como al final.

```mermaid
graph LR
    subgraph Lista Circular
        node1[Jugador 1] --> node2[Jugador 2]
        node2 --> node3["Jugador 3 (último)"]
        node3 -->|siguiente| node1
    end
    finPuntero["Puntero *fin"] -.-> node3
```

---

## 2. Módulo 2: Lista Enlazada Simple (Gestión de Partidas)
Cada nodo contiene la información de un enfrentamiento y un puntero único que apunta al siguiente elemento. El último nodo de la lista apunta a `nullptr`.

```mermaid
graph LR
    subgraph Lista Simple
        cabeza["Puntero *cabeza"] -.-> node1[Partida 1]
        node1 -->|siguiente| node2[Partida 2]
        node2 -->|siguiente| node3["Partida 3 (último)"]
        node3 -->|siguiente| NULL[nullptr]
    end
```

---

## 3. Módulo 3: Cola FIFO (Inscripciones)
Una cola lineal para el registro ordenado. Los elementos entran por el extremo posterior (`fin`) y se retiran/atienden por el extremo anterior (`frente`).

```mermaid
graph LR
    subgraph Cola de Inscripciones
        frente["Puntero *frente"] -.-> node1["Jugador A (Primero en llegar)"]
        node1 -->|siguiente| node2[Jugador B]
        node2 -->|siguiente| node3["Jugador C (Último en llegar)"]
        node3 -->|siguiente| NULL[nullptr]
        fin["Puntero *fin"] -.-> node3
    end
```

---

## 4. Módulo 4: Pila LIFO (Historial de Campeones)
El historial se guarda de manera que el último campeón registrado sea el primero en mostrarse. La inserción y eliminación ocurren únicamente sobre el puntero `cima`.

```mermaid
graph TD
    subgraph Pila de Campeones
        cima["Puntero *cima"] -.-> node3["Campeón 3 (Último torneo)"]
        node3 -->|siguiente| node2[Campeón 2]
        node2 -->|siguiente| node1["Campeón 1 (Primer torneo)"]
        node1 -->|siguiente| NULL[nullptr]
    end
```
