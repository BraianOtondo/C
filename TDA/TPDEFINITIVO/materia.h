#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include "integrante.h"
struct EstructuraMateria{
int codigo;
char nombre[50];
INTEGRANTE integrante[50]; // SOLO 50 Integrantes
int CantidadIngrantes;
};
typedef struct EstructuraMateria *MATERIA; // TIPO DE DATO
MATERIA CrearMateriaPorTeclado();
MATERIA CrearMateria(int codigo,char nombre[50]);
void DestruirMateria(MATERIA materia);
void MostrarMateria(MATERIA materia);
void SetNombreMateria(MATERIA materia,char nombre[]);
void SetCodigoMateria(MATERIA materia, int codigo);
char *GetNombreMateria(MATERIA materia);
int GetCodigoMateria(MATERIA materia);
void OrdenarMateria(MATERIA materia);// FALTA ESTO
int BuscarIntegranteMateria(MATERIA materia);// FALTA ESTO
void AgregarIntegranteAMateria(MATERIA materia,INTEGRANTE integrante);
void QuitarIntegranteAMateria(MATERIA materia,int pos);
void OrdenarIntegrantesEnMateria(MATERIA materia,INTEGRANTE aux_integrante);
#endif // MATERIA_H_INCLUDED
