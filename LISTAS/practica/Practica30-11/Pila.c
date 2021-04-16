#include <stdlib.h>
#include <stdio.h>
#include "Pila.h"

void push(Pila* p, Persona per){
    insertarInicio(p, per);
}
void pop(Pila* p, Persona *retorno){
    removerInicio(p,retorno);
}

Persona* top(Pila* p){
    Persona persona;

    obtenerElemento(p, &persona, 0);
    return persona;
}
