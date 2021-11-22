#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct StrucVentas{
int anio;
int total;
};

void CargarVentas(struct StrucVentas ventas[],int contador,char aux[100]){
   int pos=0;
char anio[100]=" ";
char total[100]=" ";
int i,j;
for (i=0;i<100; i++){
    if(aux[i]==';'){
    pos=i;
    break;

    }
}

for(i=0;i<pos;i++){

anio[i] = aux[i];
}

j=0;
for (i=pos+1; i<100; i++){
if(aux[i]=='\0'){
break;
}
total[j] = aux[i];
j++;
}
ventas[contador].anio=atoi(anio);
ventas[contador].total=atoi(total);
}
void LeerVentas(struct StrucVentas  ventas[]){
 int contador=0;
FILE *archivo;
    archivo = fopen("ventas.txt", "r");

    while(!feof(archivo)){

         if(!feof(archivo)){

        char aux[100]="";
        fgets(aux, 100, archivo);
        if(strcmp(aux," ")==1){
        CargarVentas(ventas,contador,aux);
        contador = contador+1;
        }

         }
    }
}

int main()
{
    struct StrucVentas  ventas[3];// 5 de maximo
    LeerVentas(ventas);
    int i;

    //ojo, ese 3, hay que contarlo del archivo o verificar hasta donde estan cargadas las ventas
    for (i=0;i<3;i++){

        printf("%d ---- %d\n", ventas[i].anio, ventas[i].total);
    }


    return 0;
}
