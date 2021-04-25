#ifndef SUCURSAL_H_INCLUDED
#define SUCURSAL_H_INCLUDED
#include "sucursal.h"
//VAn funciones con muchas cosas
struct StructSucursal{
int id;
char direccion[40];
char zona[30];
float factura;
int opcion;
};
typedef struct StructSucursal *SUCURSAL;
SUCURSAL CrearSucursal(int id,char direccion[40],char zona[20],float factura,int opcion);
SUCURSAL CrearSucursalPorTeclado();
void MostrarSucursal(SUCURSAL sucursal);
void SetIdSucursal(SUCURSAL sucursal, int id);
void SetDirrecion(SUCURSAL sucursal,char direccion[]);
void SetZonaSucursal(SUCURSAL sucursal,char zona[]);
void SetFacuraSucursal(SUCURSAL sucursal, float factura);
int GetIdSucursal(SUCURSAL sucursal);
char *GetDireccionSucursal(SUCURSAL sucursal);
char *GetZonaSucursal(SUCURSAL sucursal);
float GetFacturaSucursal(SUCURSAL sucursal);
void DestruirSucursal(SUCURSAL sucursal);

int GetIdSucursal(SUCURSAL sucursal);

#endif // SUCURSAL_H_INCLUDED
