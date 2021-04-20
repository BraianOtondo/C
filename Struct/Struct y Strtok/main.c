#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
struct Empresa{
int anio;
float venta;
};
typedef struct Empresa EMPRESA;
int CantEmpresa(){
int cant;
char aux[50]=" ";
cant=0;
FILE *archivo=fopen("venta.txt","r");
while(!feof(archivo)){

    if(!feof(archivo)){
            fgets(aux,50,archivo);
        if(strcmp(aux," ")==1){
            cant++;
        }
    }
}
return cant;
}
void CargarEmpresaPorLectura(EMPRESA empresa[],int pos,char aux[50]){
char *token;
token=strtok(aux,";");
int cadena=0;
while(token){
    switch(cadena){
    case 0: empresa[pos].anio=atoi(token);
    break;
    case 1: empresa[pos].venta=atof(token);
    break;

    }
    cadena++;
    token=strtok(NULL,";");
}
}
void Leertxt(EMPRESA empresa[]){
char aux[50]=" ";
int pos=0;
FILE *archivo=fopen("venta.txt","r");
while(!feof(archivo)){
    if(!feof(archivo)){
        fgets(aux,50,archivo);
        if(strcmp(aux," ")==1){
            CargarEmpresaPorLectura(empresa,pos,aux);
             pos++;
        }
    }

}
fclose(archivo);
}
void CargarATxt(EMPRESA empresa[],int n){
int i;
FILE *archivo=fopen("venta.txt","a");
fprintf(archivo,"\n");
for(i=0;i<n;i++){
fprintf(archivo,"EMPRESA %d\n",i);
fprintf(archivo,"Anio: %d\n",empresa[i].anio);
fprintf(archivo,"Venta: %.2f\n",empresa[i].venta);
}
fclose(archivo);
}
int BuscarAnio(EMPRESA empresa[],int n,int anio){
int i=0;
int pos;
bool existe=false;
while((existe==false)&&(i<n)){
    if(empresa[i].anio==anio){
        pos=i;
        existe=true;
    }
    i++;
}
if(existe==false){
    return -1;
}
return pos;
}
float PromedioAnio(EMPRESA empresa[],int pos){
float promedio;
promedio=empresa[pos].venta/12;
return promedio;
}
int main()
{
    int n,anio,pos;
    float promedio;
    n=CantEmpresa();
    EMPRESA empresa[n];
    Leertxt(empresa);
    CargarATxt(empresa,n);
    printf("Ingrese el anio para calcular el promedio de venta\n");
    scanf("%d",&anio);
    pos=BuscarAnio(empresa,n,anio);
    if(pos==-1){
        printf("No existe ese anio\n");
    }
    else{
       promedio=PromedioAnio(empresa,pos);
       printf("El promedio del anio %d es de %.2f\n",anio,promedio);
    }

    return 0;
}
