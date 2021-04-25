#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "sucursal.h"
int Zona(char zona[]){
int opcion;
printf("Ingrese de que zona pertenece la sucursal:\n");
printf("1.Norte\n2.Sur\n3.Este\n4.Oeste\n5.Centro\n");
scanf("%d",&opcion);

    switch(opcion){
    case 1:strcpy(zona,"Norte");break;
    case 2:strcpy(zona,"Sur");break;
    case 3:strcpy(zona,"Este");break;
    case 4:strcpy(zona,"Oeste");break;
    case 5:strcpy(zona,"Centro");break;
    default:printf("Ingrese bien la opcion..\n");break;
    }
    return opcion;
}
SUCURSAL CrearSucursal(int id,char direccion[40],char zona[20],float factura,int opcion){
SUCURSAL S=malloc(sizeof(struct StructSucursal));
S->id=id;
strcpy(S->zona,zona);
strcpy(S->direccion,direccion);
S->factura=factura;
return S;
}
SUCURSAL CrearSucursalPorTeclado(){
int id;
char direccion[40];
char zona[20];
float factura;
int opcion;
printf("Ingrese ID de la sucursal\n");
scanf("%d",&id);
    while((id<0)||(id>99)){
    printf("Por favor ingrese bien las opciones...\n");
    printf("Ingrese ID de la sucursal\n");
    scanf("%d",&id);
    }
system("cls");
printf("Ingrese direccion de la sucursal:\n");
fflush(stdin);
gets(direccion);
system("cls");
opcion=Zona(zona);
printf("Ingrese de la factura:\n");
scanf("%f",&factura);
return CrearSucursal(id,direccion,zona,factura,opcion);
}

void MostrarSucursal(SUCURSAL sucursal){
printf("ID:%d\n",sucursal->id);
printf("Direccion: %s\n",sucursal->direccion);
printf("Zona: %s\n",sucursal->zona);
printf("Factura: %f\n",sucursal->factura);
}
void SetIdSucursal(SUCURSAL sucursal, int id){
sucursal->id=id;
}
void SetDirrecion(SUCURSAL sucursal,char direccion[]){//* O []
strcpy(sucursal->direccion,direccion);
}
void SetZonaSucursal(SUCURSAL sucursal,char zona[]){
strcpy(sucursal->zona,zona);               // CADA I ES INDEPENDIENTE
}
void SetFacuraSucursal(SUCURSAL sucursal, float factura){
sucursal->factura=factura;
}
int GetIdSucursal(SUCURSAL sucursal){
return sucursal->id;
}
char *GetDireccionSucursal(SUCURSAL sucursal){
return sucursal->direccion;
}
char *GetZonaSucursal(SUCURSAL sucursal){
return sucursal->zona;
}
float GetFacturaSucursal(SUCURSAL sucursal){
return sucursal->factura;
}
void DestruirSucursal(SUCURSAL sucursal){
printf("La sucursal %d ha sido eliminado\n",GetIdSucursal(sucursal));
free(sucursal);
}

