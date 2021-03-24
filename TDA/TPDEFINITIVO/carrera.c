#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "integrante.h"
#include "materia.h"
#include "carrera.h"
CARRERA CrearCarrera(char nombre[40],char titulo[40]){
CARRERA C=malloc(sizeof(struct EstructuraCarrera));
strcpy(C->nombre,nombre);
strcpy(C->titulo,titulo);
C->CantMaterias=0;
return C;
}
CARRERA CrearCarreraPorTeclado(){
char nombre[40];
char titulo[40];
printf("Ingrese nombre de la carrera:\n");
fflush(stdin);
gets(nombre);
printf("Ingrese titulo de la carrera:\n");
fflush(stdin);
gets(titulo);
return CrearCarrera(nombre,titulo);
}
void AgregarMateriaACarrera(CARRERA carrera, MATERIA materia){
if((carrera->CantMaterias)>40){
    printf("No se puede ingresar mas de 40 materias\n");
}
else{
carrera->materia[carrera->CantMaterias]=materia;
carrera->CantMaterias=(carrera->CantMaterias)+1;
}
}
void QuitarMateriaACarrera(CARRERA carrera,int pos){
int i;
if(pos==(carrera->CantMaterias)-1){
    carrera->CantMaterias=(carrera->CantMaterias)-1;
}
else{
    for(i=pos;i<(carrera->CantMaterias)-1;i++){
        carrera->materia[i]=carrera->materia[i+1];
    }
    carrera->CantMaterias=(carrera->CantMaterias)-1;
}
}
void MostrarCarrera(CARRERA carrera){

printf("Nombre de la carrera: %s\n",GetNombreCarrera(carrera));
printf("Titulo de la carrera: %s\n",GetTituloCarrera(carrera));
}
void DestruirCarrera(CARRERA carrera){
printf("La carrera de %s ha sido eliminada\n",GetNombreCarrera(carrera));
free(carrera);
}
void SetNombreCarrera(CARRERA carrera,char nombre[]){
strcpy(carrera->nombre,nombre);
}
void SetTituloCarrera(CARRERA carrera, char titulo[]){
strcpy(carrera->titulo,titulo);
}
char *GetNombreCarrera(CARRERA carrera){
return carrera->nombre;
}
char *GetTituloCarrera(CARRERA carrera){
return carrera->titulo;
}
int BuscarMateriaEnCarrera(CARRERA carrera){
int codigo,i,pos;
printf("Ingrese el codigo de materia a buscar:\n");
scanf("%d",&codigo);

bool band=false;
i=0;
while((band==false)&&(i<(carrera->CantMaterias))){
    if((carrera->materia[i]->codigo)==codigo){
    band=true;
    pos=i;
    }
    i++;
}
if(band==false){
    return -1;
}
else{
    return pos;
}
}
