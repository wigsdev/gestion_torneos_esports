# ==============================================================================
#           MAKEFILE - SISTEMA DE GESTIÓN DE TORNEOS DE VIDEOJUEGOS
# ==============================================================================

# Compilador a utilizar
CXX = g++

# Banderas del compilador (-Wall activa todas las advertencias principales)
CXXFLAGS = -std=c++11 -Wall

# Nombre del archivo ejecutable de salida
TARGET = main

# Archivos cabecera de los que depende la compilación
HEADERS = estructuras.h jugadores.h partidas.h cola.h pila.h algoritmos.h

# Archivos fuente principales
SRCS = main.cpp algoritmos.cpp cola.cpp pila.cpp jugadores.cpp partidas.cpp

# Regla por defecto: compilar todo
all: $(TARGET)

# Enlace del ejecutable
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regla para limpiar los binarios y ejecutables temporales (Compatible con Git Bash / MinGW)
clean:
	rm -f $(TARGET) $(TARGET).exe
