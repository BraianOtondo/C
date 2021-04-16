#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"
#include "libro.h"
LIBRO CrearLibroPorParametro(char nombre[],int telefono){
LIBRO L=malloc(sizeof(struct EstructuraLibro));

strcpy(L->nombre,nombre);
L->telefono=telefono;
return L;
}
LIBRO CrearLibro(){
char nombre[20];
int telefono;
printf("Ingrese el nombre del libro:\n");
fflush(stdin);
gets(nombre);
printf("Ingrese el telefono:\n");
scanf("%d",&telefono);
return CrearLibroPorParametro(nombre,telefono);
}
void MostrarLibro(LIBRO libro){
printf("Nombre: %s\n",libro->nombre);
printf("Telefono: %d\n",libro->telefono);

}
