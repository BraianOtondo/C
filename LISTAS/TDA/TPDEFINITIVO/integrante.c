#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "integrante.h"

INTEGRANTE CrearIntegrantePorTeclado(){
    char nombre[20];
    char apellido[20];
    int dni;
    char DocOAlum;

printf("ES DOCENTE O ALUMNO(D/A):\n");
fflush(stdin);
scanf("%c",&DocOAlum);
while((DocOAlum!='D')&&(DocOAlum!='A')){
printf("Por favor ingrese bien las opciones...\n");
printf("ES DOCENTE O ALUMNO(D/A):\n");
fflush(stdin);
scanf("%c",&DocOAlum);
}
    printf("Ingrese Nombre:\n");
    fflush(stdin);
    gets(nombre);

      printf("Ingrese apellido:\n");
    fflush(stdin);
    gets(apellido);

    printf("Ingrese DNI:\n");
    scanf("%d",&dni);
return CrearIntegrante( DocOAlum, nombre,apellido,dni);
}
INTEGRANTE CrearIntegrante(char DocOAlum,char nombre[20],char apellido[20],int dni){
INTEGRANTE I=malloc(sizeof(struct EstructuraIntegrante));
I->DocOAlum=DocOAlum;
strcpy(I->nombre,nombre);
strcpy(I->apellido,apellido);
I->dni=dni;
return I;
}
void MostrarIntegrante(INTEGRANTE integrante){
if(integrante->DocOAlum=='A'){
    printf("\nALUMNO\n");
}
else{
    printf("\nDOCENTE\n");
}
printf("Nombre:%s\n",integrante->nombre);
printf("Apellido: %s\n",integrante->apellido);
printf("DNI: %d\n",integrante->dni);
}
void DestruirIntegrante(INTEGRANTE integrante){
printf("El integrante %s ha sido eliminado\n",GetNombreIntegrante(integrante));
free(integrante);
}
void SetNombreIntegrante(INTEGRANTE integrante,char nombre[]){//* O []
strcpy(integrante->nombre,nombre);
}
void SetApellidoIntegrante(INTEGRANTE integrante,char apellido[]){
strcpy(integrante->apellido,apellido);               // CADA I ES INDEPENDIENTE
}
void SetDniIntegrante(INTEGRANTE integrante, int dni){
integrante->dni=dni;
}
void SetAlumODoc(INTEGRANTE integrante,char AlumODoc){
integrante->DocOAlum=AlumODoc;                            //CON VECTOR SI *
}
char *GetNombreIntegrante(INTEGRANTE integrante){
return integrante->nombre;
}
char *GetApellidoIntegrante(INTEGRANTE integrante){
return integrante->apellido;
}
char GetDocOAlumIntegrante(INTEGRANTE integrante){
return integrante->DocOAlum;
}
int GetDniIntegrante(INTEGRANTE integrante){
return integrante->dni;
}
