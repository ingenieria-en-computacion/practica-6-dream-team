#include "bicola_gen.h"
#include <stdio.h>

void inicializarBicolaGen(BicolaGen *bicola, int capacidad) {
    bicola->datos = (void **)malloc(capacidad * sizeof(void *));
    bicola->frente = -1;
    bicola->final = -1;
    bicola->capacidad = capacidad;
}

bool esVaciaBicolaGen(BicolaGen *bicola) {
    return bicola->frente == -1;
}

bool esLlenaBicolaGen(BicolaGen *bicola) {
    return (bicola->final + 1) % bicola->capacidad == bicola->frente;
}

bool insertarFrenteBicolaGen(BicolaGen *bicola, void *valor) {
    if (esLlenaBicolaGen(bicola)) return false;
    if (esVaciaBicolaGen(bicola)) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->frente = (bicola->frente - 1 + bicola->capacidad) % bicola->capacidad;
    }
    bicola->datos[bicola->frente] = valor;
    return true;
}

bool insertarFinalBicolaGen(BicolaGen *bicola, void *valor) {
    if (esLlenaBicolaGen(bicola)) return false;
    if (esVaciaBicolaGen(bicola)) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->final = (bicola->final + 1) % bicola->capacidad;
    }
    bicola->datos[bicola->final] = valor;
    return true;
}

bool eliminarFrenteBicolaGen(BicolaGen *bicola, void **valor) {
    if (esVaciaBicolaGen(bicola)) return false;
    *valor = bicola->datos[bicola->frente];
    if (bicola->frente == bicola->final) {
        bicola->frente = -1;
        bicola->final = -1;
    } else {
        bicola->frente = (bicola->frente + 1) % bicola->capacidad;
    }
    return true;
}

bool eliminarFinalBicolaGen(BicolaGen *bicola, void **valor) {
    if (esVaciaBicolaGen(bicola)) return false;
    *valor = bicola->datos[bicola->final];
    if (bicola->frente == bicola->final) {
        bicola->frente = -1;
        bicola->final = -1;
    } else {
        bicola->final = (bicola->final - 1 + bicola->capacidad) % bicola->capacidad;
    }
    return true;
}

void liberarBicolaGen(BicolaGen *bicola) {
    free(bicola->datos);
}
