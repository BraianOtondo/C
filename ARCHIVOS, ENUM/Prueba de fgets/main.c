#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct StrucVentas{
int anio;
int total;
};

void MostrarVentas(struct StrucVentas  ventas[],int contador){
int i;
for(i=0;i<contador;i++){
printf("%d\n",i);
printf("%d  %d \n",ventas[i].anio,ventas[i].total);
}
}
int main()
{
FILE *archivo;
struct StrucVentas  ventas[3];
    archivo = fopen("ventas.txt", "r");
    int contador=0;
    while(!feof(archivo)){

         if(!feof(archivo)){
        char aux[100]="";
        fgets(aux, 100, archivo);
        if(strcmp(aux," ")==1){
        int pos=0;
char anio[100]=" ";
char total[100]=" ";
int i,j,anionuevo,totalnuevo;
char *token=strtok(aux,";");
anionuevo=atoi(token);



anionuevo=atoi(anio);
totalnuevo=atoi(total);
ventas[contador].anio=anionuevo;
ventas[contador].total=totalnuevo;
        contador = contador+1;

        }

         }
    }
MostrarVentas(ventas,contador);


    return 0;
}

