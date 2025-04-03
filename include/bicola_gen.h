#ifndef BICOLA_GEN_H
#define BICOLA_GEN_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    void **datos;
    int frente, final, capacidad;
} BicolaGen;

void inicializarBicolaGen(BicolaGen *bicola, int capacidad);
bool esVaciaBicolaGen(BicolaGen *bicola);
bool esLlenaBicolaGen(BicolaGen *bicola);
bool insertarFrenteBicolaGen(BicolaGen *bicola, void *valor);
bool insertarFinalBicolaGen(BicolaGen *bicola, void *valor);
bool eliminarFrenteBicolaGen(BicolaGen *bicola, void **valor);
bool eliminarFinalBicolaGen(BicolaGen *bicola, void **valor);
void liberarBicolaGen(BicolaGen *bicola);

#endif 
