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

#endif // SUCURSAL_H_INCLUDED
