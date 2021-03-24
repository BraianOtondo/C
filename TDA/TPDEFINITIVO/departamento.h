#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED
#include "integrante.h"
#include "materia.h"
#include "carrera.h"

struct EstructuraDepartamento{
char nombre[40];
char director[40];
CARRERA carrera[10];
int CantCarreras;
};
typedef struct EstructuraDepartamento *DEPARTAMENTO;//TIPO DE DATO
DEPARTAMENTO CrearDepartamento(char nombre[40],char director[40]);
DEPARTAMENTO CrearDepartamentoPorTeclado();
void DestruirDepartamento(DEPARTAMENTO departamento);
void MostrarDepartamento(DEPARTAMENTO departamento);
void SetNombreDepartamento(DEPARTAMENTO departamento,char nombre[]);
void SetDirectorDepartamento(DEPARTAMENTO departamento,char director[]);
char *GetNombreDepartamento(DEPARTAMENTO departamento);
char *GetDirectorDepartamento(DEPARTAMENTO departamento);
void AgregarCarreraADepartamento(DEPARTAMENTO departamento,CARRERA carrera);
void QuitarCarreraADepartamento(DEPARTAMENTO departamento,int pos);
int BuscarCarreraEnElDepartamento(DEPARTAMENTO departamento);
#endif // DEPARTAMENTO_H_INCLUDED
