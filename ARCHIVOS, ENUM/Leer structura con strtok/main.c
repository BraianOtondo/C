#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct StructVentas{
int anio;
int cantidad;
};
void CargarVentasPorLectura(struct StructVentas ventas[],int contador,char aux[100]){
char *token;
token=strtok(aux,";");
int contar=0;
 while(token){

        switch(contar){
    case 0:
    ventas[contador].anio=atoi(token);
    break;
    case 1:
    ventas[contador].cantidad=atoi(token);
    break;

        }
        token=strtok(NULL,";");
        contar=contar+1;
    }

}
int LeerTxt(struct StructVentas ventas[]){
int contador=0;
FILE *archivo;
     char aux[100]="";
    archivo = fopen("ventas.txt", "r");
    while(!feof(archivo)){

         if(!feof(archivo)){

        fgets(aux, 100, archivo);
        if(strcmp(aux," ")==1){
        CargarVentasPorLectura(ventas,contador,aux);
        contador = contador+1;
        }

         }
    }
return contador;
}
int main(){
    int n,i;
    struct StructVentas ventas[5];// ASUMIMOS QUE HAY 5

n=LeerTxt(ventas);
for(i=0;i<n;i++){
printf("%d----%d\n",ventas[i].anio,ventas[i].cantidad);
}

    return 0;
}
