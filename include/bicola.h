#ifndef BICOLA_H
#define BICOLA_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *datos;
    int frente, final, capacidad;
} Bicola;

void inicializarBicola(Bicola *bicola, int capacidad);
bool esVaciaBicola(Bicola *bicola);
bool esLlenaBicola(Bicola *bicola);
bool insertarFrenteBicola(Bicola *bicola, int valor);
bool insertarFinalBicola(Bicola *bicola, int valor);
bool eliminarFrenteBicola(Bicola *bicola, int *valor);
bool eliminarFinalBicola(Bicola *bicola, int *valor);
void liberarBicola(Bicola *bicola);

#endif 
