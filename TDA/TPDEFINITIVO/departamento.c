#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "integrante.h"
#include "materia.h"
#include "carrera.h"
#include "departamento.h"
DEPARTAMENTO CrearDepartamentoPorTeclado(){
char nombre[40];
char director[40];
printf("Ingrese nombre del departamento:\n");
fflush(stdin);
gets(nombre);
printf("Ingrese el nombre y apellido del director\n");
fflush(stdin);
gets(director);
return CrearDepartamento(nombre,director);
}
DEPARTAMENTO CrearDepartamento(char nombre[40],char director[40]){
DEPARTAMENTO D=malloc(sizeof(struct EstructuraDepartamento));
strcpy(D->nombre,nombre);
strcpy(D->director,director);
D->CantCarreras=0;
return D;
}

void DestruirDepartamento(DEPARTAMENTO departamento){
printf("El departamento %s ha sido destruido\n",GetNombreDepartamento(departamento));
free(departamento);
}
void MostrarDepartamento(DEPARTAMENTO departamento){

printf("Nombre de Departamento: %s\n",GetNombreDepartamento(departamento));
printf("Nombre del director de Departamento: %s\n",GetDirectorDepartamento(departamento));

}
void SetNombreDepartamento(DEPARTAMENTO departamento,char nombre[]){
strcpy(departamento->nombre,nombre);
}
void SetDirectorDepartamento(DEPARTAMENTO departamento,char director[]){
strcpy(departamento->director,director);
}
char *GetNombreDepartamento(DEPARTAMENTO departamento){
return departamento->nombre;
}
char *GetDirectorDepartamento(DEPARTAMENTO departamento){
return departamento->director;
}
void AgregarCarreraADepartamento(DEPARTAMENTO departamento,CARRERA carrera){
if((departamento->CantCarreras)>10){
    printf("No se puede ingresar mas carreras\n");
}
else{
departamento->carrera[departamento->CantCarreras]=carrera;
departamento->CantCarreras=(departamento->CantCarreras)+1;
}
}
int BuscarCarreraEnElDepartamento(DEPARTAMENTO departamento){
int i,pos;
char nombrebuscar [40];
printf("Ingrese el nombre de la carrera a buscar:\n");
fflush(stdin);
gets(nombrebuscar);

bool band=false;
i=0;
while((band==false)&&(i<(departamento->CantCarreras))){
    if(strcmp(nombrebuscar,departamento->carrera[i]->nombre)==0){
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
void QuitarCarreraADepartamento(DEPARTAMENTO departamento,int pos){
int i;
if(pos==(departamento->CantCarreras)-1){
    departamento->CantCarreras=(departamento->CantCarreras)-1;
}
else{
    for(i=pos;i<(departamento->CantCarreras)-1;i++){
        departamento->carrera[i]=departamento->carrera[i+1];
    }
    departamento->CantCarreras=(departamento->CantCarreras)-1;
}

}
