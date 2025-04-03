#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *datos;
    int frente, final, capacidad;
} ColaCircular;

void inicializarColaCircular(ColaCircular *cola, int capacidad);
bool esVaciaColaCircular(ColaCircular *cola);
bool esLlenaColaCircular(ColaCircular *cola);
bool encolarColaCircular(ColaCircular *cola, int valor);
bool desencolarColaCircular(ColaCircular *cola, int *valor);
void liberarColaCircular(ColaCircular *cola);

#endif 
