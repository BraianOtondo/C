#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEnC.h"
#include "persona.h"


struct PersonaEstructura{
        char nombre[20];
        char apellido[30];
        int dni;

        };


Persona crearPersona(){

Persona p = malloc(sizeof(struct PersonaEstructura));


char nombre[20];
char apellido[20];
fflush(stdin);
printf("Cual es el nombre: \n");
fflush(stdin);
gets(nombre);

strcpy(p->nombre, nombre);

fflush(stdin);
printf("Cual es el apellido: \n");
gets(apellido);

strcpy(p->apellido, apellido);

fflush(stdin);
printf("Cual es el dni:\n");
scanf("%d", &p->dni);

return p;
}


void mostrarPersona(Persona p){

printf("nombre: %s  ----- apellido: %s  ------- DNI:  %d  \n", p->nombre, p->apellido, p->dni);
}
