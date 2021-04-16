#include <stdlib.h>
#include <stdio.h>
#include "Cola.h"
#include "ListaEnC.c"
#include "Pila.h"
#include "persona.h"
void encolar(Cola* c, Persona p){

    insertarInicio(c, p);
}
void desencolar(Cola* c, Persona* p){
    removerFin(c, p);
}
void peek(Cola* c, Persona* p){
    int tam = 0;
    obtenerTamanio(c, &tam);
    obtenerElemento(c, p, tam - 1);
}
