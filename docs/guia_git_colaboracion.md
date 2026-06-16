# 🐙 Guía de Trabajo Colaborativo en Git y GitHub

Esta guía describe el flujo de trabajo paso a paso que cada integrante del equipo debe seguir para clonar el repositorio, trabajar en su propio módulo de forma aislada y unificar el código final sin sobrescribir el trabajo de sus compañeros.

---

## Paso 1: Clonar el Repositorio por Primera Vez

Cada estudiante debe abrir su terminal (se recomienda Git Bash en Windows) y clonar el repositorio del bootcamp en su computadora local.

1.  Abre la terminal en la carpeta donde deseas guardar tus proyectos (por ejemplo, en tu carpeta de Documentos o una carpeta de desarrollo dedicada).
2.  Ejecuta el comando de clonación utilizando el repositorio del líder (`wigsdev`):
    ```bash
    git clone https://github.com/wigsdev/gestion_torneos_esports.git
    ```
3.  Navega hacia la carpeta del proyecto recién clonado:
    ```bash
    cd gestion_torneos_esports
    ```


---

## Paso 2: Crear y Moverse a una Rama Propia

**Regla de Oro**: Nunca programes directamente sobre la rama `main`. Debes crear una rama independiente para tu módulo.

1.  Asegúrate de estar en `main` y tener el código actualizado:
    ```bash
    git checkout main
    git pull
    ```
2.  Crea tu propia rama de trabajo. Usa un nombre representativo según tu rol (reemplaza `tu-modulo` por `jugadores`, `partidas-cola`, `pila` o `ordenamiento`):
    ```bash
    git checkout -b feature/tu-modulo
    ```
    *(Este comando crea la rama y te mueve a ella inmediatamente).*

---

## Paso 3: Flujo de Trabajo Diario (Programar y Guardar)

Trabaja **únicamente** en el archivo `.h` que te fue asignado en el plan de implementación.

Cuando termines una sesión de programación o hayas completado una función:

1.  Verifica qué archivos has modificado:
    ```bash
    git status
    ```
2.  Prepara tu archivo modificado para guardarlo:
    ```bash
    git add nombre_de_tu_archivo.h
    ```
3.  Registra tus cambios con un mensaje claro y descriptivo en pasado:
    ```bash
    git commit -m "Implementado el registro y eliminación de jugadores en la lista circular"
    ```
4.  Sube tus cambios a GitHub (la primera vez debes usar `-u origin`):
    ```bash
    git push -u origin feature/tu-modulo
    ```
    *(En las siguientes subidas de la misma rama, bastará con ejecutar solo `git push`).*

---

## Paso 4: Mantener tu Rama Actualizada con `main`

A medida que tus compañeros terminen sus módulos y los unan a la rama `main`, tu código local se irá quedando desactualizado. Debes traer los cambios de `main` a tu rama periódicamente:

1.  Guarda o haz commit de tus cambios actuales en tu rama.
2.  Cámbiate a `main` y descarga lo nuevo:
    ```bash
    git checkout main
    git pull
    ```
3.  Regresa a tu rama e integra los cambios de `main`:
    ```bash
    git checkout feature/tu-modulo
    git merge main
    ```
4.  Si hay conflictos de fusión (Git Conflict), la terminal te avisará. Abre los archivos indicados, decide qué código conservar, guarda, haz `git add` y luego `git commit` para finalizar la fusión.

---

## Paso 5: Unificación y Fusión del Código Final (Líder Técnico)

Una vez que hayas terminado tu módulo al 100% y compile sin errores en tu computadora:

1.  Realiza el último `git push` de tu rama a GitHub.
2.  Entra al repositorio en la página de **GitHub**.
3.  Verás un botón amarillo que dice **"Compare & pull request"**. Haz clic en él.
4.  Escribe un resumen de lo que implementaste y crea el **Pull Request (PR)**.
5.  El **Líder de Equipo** revisará que tu código compile correctamente:
    *   Si está correcto, el líder aceptará el PR haciendo clic en **"Merge pull request"**.
    *   Tu código ahora forma parte oficial de la rama `main`.
6.  Una vez fusionado, todos los integrantes deben actualizar su rama `main` local ejecutando:
    ```bash
    git checkout main
    git pull
    ```
