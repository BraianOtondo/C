#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "integrante.h"
#include "materia.h"
MATERIA CrearMateriaPorTeclado(){
int codigo;
char nombre[50];

printf("Ingrese nombre de materia:\n");
fflush(stdin);
gets(nombre);
printf("Ingrese codigo de materia:\n");
scanf("%d",&codigo);

return CrearMateria(codigo,nombre);
}
MATERIA CrearMateria(int codigo,char nombre[50]){
MATERIA M=malloc(sizeof(struct EstructuraMateria));
M->codigo=codigo;
strcpy(M->nombre,nombre);
M->CantidadIngrantes=0;
return M;
}
void MostrarMateria(MATERIA materia){ //MUESTRA TODOS LOS INTEGRANTE DE LA MATERIA
   // int i;                              // Y LA MATERIA
printf("Materia: %s\n",GetNombreMateria(materia));
printf("Codigo:%d\n",GetCodigoMateria(materia));
}
void DestruirMateria(MATERIA materia){
printf("La materia de %s ha sido eliminada\n",GetNombreMateria(materia));
free(materia);
}
void AgregarIntegranteAMateria(MATERIA materia,INTEGRANTE integrante){
if((materia->CantidadIngrantes)>50){
    printf("No se pueden agregar mas de 50 integrantes\n");
}
else{
materia->integrante[materia->CantidadIngrantes]=integrante;
materia->CantidadIngrantes=(materia->CantidadIngrantes)+1;
}
}
void QuitarIntegranteAMateria(MATERIA materia,int pos){
int i;

if(pos==(materia->CantidadIngrantes)-1){
    materia->CantidadIngrantes=(materia->CantidadIngrantes)-1;
}
else{
    for(i=pos;i<(materia->CantidadIngrantes)-1;i++){
        materia->integrante[i]=materia->integrante[i+1];
    }
    materia->CantidadIngrantes=(materia->CantidadIngrantes)-1;
}
}

void SetNombreMateria(MATERIA materia,char nombre[]){
strcpy(materia->nombre,nombre);
}
void SetCodigoMateria(MATERIA materia, int codigo){
materia->codigo=codigo;
}
char *GetNombreMateria(MATERIA materia){
return materia->nombre;
}
int GetCodigoMateria(MATERIA materia){
return materia->codigo;
}
int BuscarIntegranteMateria(MATERIA materia){
int dni,i,pos;
printf("Ingrese el dni del integrante a buscar:\n");
scanf("%d",&dni);
bool band=false;
i=0;
while((band==false)&&(i<(materia->CantidadIngrantes))){
    if((materia->integrante[i]->dni)==dni){
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
/*void OrdenarIntegrantesEnMateria(MATERIA materia,INTEGRANTE aux_integrante){



    int i,j;
    for(i=0;i<(materia->CantidadIngrantes);i++){
        for(j=0;j<(materia->CantidadIngrantes)-1;j++){
         if(strcmp(materia->integrante[j]->nombre,materia->integrante[j+1]->nombre)==1)
        {
                strcpy(aux_integrante->nombre, materia->integrante[j]->nombre);
                strcpy(materia->integrante[j]->nombre,materia->integrante[j+1]->nombre);
                strcpy(materia->integrante[j+1]->nombre,aux_integrante->nombre);
            }

        }
    }
}*/


