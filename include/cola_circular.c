#include "cola_circular.h"
#include <stdio.h>

void inicializarColaCircular(ColaCircular *cola, int capacidad) {
    cola->datos = (int *)malloc(capacidad * sizeof(int));
    cola->frente = -1;
    cola->final = -1;
    cola->capacidad = capacidad;
}

bool esVaciaColaCircular(ColaCircular *cola) {
    return cola->frente == -1;
}

bool esLlenaColaCircular(ColaCircular *cola) {
    return (cola->final + 1) % cola->capacidad == cola->frente;
}

bool encolarColaCircular(ColaCircular *cola, int valor) {
    if (esLlenaColaCircular(cola)) return false;
    if (esVaciaColaCircular(cola)) {
        cola->frente = cola->final = 0;
    } else {
        cola->final = (cola->final + 1) % cola->capacidad;
    }
    cola->datos[cola->final] = valor;
    return true;
}

bool desencolarColaCircular(ColaCircular *cola, int *valor) {
    if (esVaciaColaCircular(cola)) return false;
    *valor = cola->datos[cola->frente];
    if (cola->frente == cola->final) {
        cola->frente = cola->final = -1;
    } else {
        cola->frente = (cola->frente + 1) % cola->capacidad;
    }
    return true;
}

void liberarColaCircular(ColaCircular *cola) {
    free(cola->datos);
}
