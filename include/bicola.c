#include "bicola.h"
#include <stdio.h>

void inicializarBicola(Bicola *bicola, int capacidad) {
    bicola->datos = (int *)malloc(capacidad * sizeof(int));
    bicola->frente = -1;
    bicola->final = -1;
    bicola->capacidad = capacidad;
}

bool esVaciaBicola(Bicola *bicola) {
    return bicola->frente == -1;
}

bool esLlenaBicola(Bicola *bicola) {
    return (bicola->final + 1) % bicola->capacidad == bicola->frente;
}

bool insertarFrenteBicola(Bicola *bicola, int valor) {
    if (esLlenaBicola(bicola)) return false;
    if (esVaciaBicola(bicola)) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->frente = (bicola->frente - 1 + bicola->capacidad) % bicola->capacidad;
    }
    bicola->datos[bicola->frente] = valor;
    return true;
}

bool insertarFinalBicola(Bicola *bicola, int valor) {
    if (esLlenaBicola(bicola)) return false;
    if (esVaciaBicola(bicola)) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->final = (bicola->final + 1) % bicola->capacidad;
    }
    bicola->datos[bicola->final] = valor;
    return true;
}

bool eliminarFrenteBicola(Bicola *bicola, int *valor) {
    if (esVaciaBicola(bicola)) return false;
    *valor = bicola->datos[bicola->frente];
    if (bicola->frente == bicola->final) {
        bicola->frente = bicola->final = -1;
    } else {
        bicola->frente = (bicola->frente + 1) % bicola->capacidad;
    }
    return true;
}

bool eliminarFinalBicola(Bicola *bicola, int *valor) {
    if (esVaciaBicola(bicola)) return false;
    *valor = bicola->datos[bicola->final];
    if (bicola->frente == bicola->final) {
        bicola->frente = bicola->final = -1;
    } else {
        bicola->final = (bicola->final - 1 + bicola->capacidad) % bicola->capacidad;
    }
    return true;
}

void liberarBicola(Bicola *bicola) {
    free(bicola->datos);
}
