#include <stdlib.h>
#include "ListaEnC.h"
#ifndef PILA
#define PILA

typedef ListaEnc Pila;


void push(Pila* p, Persona per);
void pop(Pila* p, Persona* retorno);
Persona* top(Pila* p);





#endif // PILA



