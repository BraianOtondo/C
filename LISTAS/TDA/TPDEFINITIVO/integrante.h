#ifndef INTEGRANTE_H_INCLUDED
#define INTEGRANTE_H_INCLUDED
struct EstructuraIntegrante{
char nombre[20];
char apellido[20];
int dni;
char DocOAlum;
};
typedef struct EstructuraIntegrante *INTEGRANTE; // TIPO DE DATO
INTEGRANTE CrearIntegrantePorTeclado();// CONSTRUCTOR
INTEGRANTE CrearIntegrante(char DocOAlum,char nombre[20],char apellido[20],int dni);
void MostrarIntegrante(INTEGRANTE integrante);//MOSTRAR
void DestruirIntegrante(INTEGRANTE integrante);//DESTRUCTOR
void SetNombreIntegrante(INTEGRANTE integrante,char nombre[]);
void SetApellidoIntegrante(INTEGRANTE integrante,char apellido[]);
void SetDniIntegrante(INTEGRANTE integrante, int dni);
void SetAlumODoc(INTEGRANTE integrante,char AlumODoc);
char *GetNombreIntegrante(INTEGRANTE integrante);
char *GetApellidoIntegrante(INTEGRANTE integrante);
char GetDocOAlumIntegrante(INTEGRANTE integrante);
int GetDniIntegrante(INTEGRANTE integrante);

#endif // INTEGRANTE_H_INCLUDED
