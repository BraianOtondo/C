#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "sucursal.h"

int Menu(){
int opcion;
printf("\n--------------------------------------------------------------------");
printf("\n\t Que accion desea hacer?\n");
printf("\n 1: Agregar\n 2: Total de zona\n 3: Maximo y Minimo de sucursal\n 0: Salir\n\t\t Su opcion: ");
scanf("%d",&opcion);

return opcion;
}
void Listado(SUCURSAL sucursal[],int cant){
int i;
float arreglo[5]={0,0,0,0,0};
i=0;
do{
    switch(GetIdSucursal(sucursal[i])){
    case 1: arreglo[0]=arreglo[0]+sucursal[i]->factura;
    i++;
    break;
    case 2:arreglo[1]=arreglo[1]+sucursal[i]->factura;
    i++;
    case 3:arreglo[2]=arreglo[2]+sucursal[i]->factura;
    i++;
    break;
    case 4:arreglo[3]=arreglo[3]+sucursal[i]->factura;
    i++;
    break;
    case 5:arreglo[4]=arreglo[4]+sucursal[i]->factura;
    i++;
    break;
    }
}while(i<cant);
    for(i=0;i<5;i++){
printf("La zona %d tuvo un total de = %.2f\n",i,arreglo[i]);

        }

}
int main(){
SUCURSAL sucursal[25];
int j=0;
int opcion;
    do{
    opcion=Menu();
        switch(opcion){
        case 1:
        sucursal[j]=CrearSucursalPorTeclado();
        j=j+1;
        break;//Tiene un void en el main
        case 2:Listado(sucursal,j);

        break;
//case 3:Eliminar(universidad);;system("pause");system("cls");break;
//case 4:Mostrar(universidad);system("pause");system("cls");break;
        case 0: printf("Gracias por usar el programa\n");break;
        default:printf("Ingrese bien las opciones...\n");break;
        }
    }while(opcion!=0);
    return 0;
}
