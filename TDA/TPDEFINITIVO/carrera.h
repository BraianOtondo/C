#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED
#include "integrante.h"
#include "materia.h"
#include "carrera.h"
struct EstructuraCarrera{
char nombre [40];// NOMBRE DE LA CARRERA Sistemas
char titulo[40];// Lincenciatura en Sistemas
MATERIA materia [40]; // 40 Materias en una carrera como max
int CantMaterias;
};
typedef struct EstructuraCarrera *CARRERA; // TIPO DE DATO
CARRERA CrearCarreraPorTeclado();
CARRERA CrearCarrera(char nombre[40],char titulo[40]);
void DestruirCarrera(CARRERA carrera);
void MostrarCarrera(CARRERA carrera);
void SetNombreCarrera(CARRERA carrera,char nombre[]);
void SetTituloCarrera(CARRERA carrera, char titulo[]);
char *GetNombreCarrera(CARRERA carrera);
char *GetTituloCarrera(CARRERA carrera);
void AgregarMateriaACarrera(CARRERA carrera,MATERIA materia);
void QuitarMateriaACarrera(CARRERA carrera,int pos);
int BuscarMateriaEnCarrera(CARRERA carrera);

#endif // CARRERA_H_INCLUDED
