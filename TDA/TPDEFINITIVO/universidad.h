#ifndef UNIVERSIDAD_H_INCLUDED
#define UNIVERSIDAD_H_INCLUDED
#include "integrante.h"
#include "materia.h"
#include "carrera.h"
#include "departamento.h"
struct EstructuraUniversidad{
char nombre[50];//Nombre de la universidad
char direccion[40];
char contacto[11];
DEPARTAMENTO departamento[4];
int CantDepartamentos;
};
typedef struct EstructuraUniversidad *UNIVERSIDAD;
UNIVERSIDAD CrearUniversidad();
void MostrarUniversidad(UNIVERSIDAD universidad);
void SetNombreUniversidad(UNIVERSIDAD universidad,char nombre[]);
void SetDireccionUniversidad(UNIVERSIDAD universidad,char direccion[]);
void SetContactoUniversidad(UNIVERSIDAD universidad,char contacto[]);
char *GetNombreUniversidad(UNIVERSIDAD universidad);
char *GetDireccionUniversidad(UNIVERSIDAD universidad);
char *GetContactoUniversidad(UNIVERSIDAD universidad);
void AgregarDepartamentoAUniversidad(UNIVERSIDAD universidad,DEPARTAMENTO departamento);
int BuscarDepartamentoEnUniversidad(UNIVERSIDAD universidad);
void QuitarDepartamentoAUniversidad(UNIVERSIDAD universidad,int pos);
void Modificar(UNIVERSIDAD universidad);
#endif // UNIVERSIDAD_H_INCLUDED
