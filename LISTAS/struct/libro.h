#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
struct EstructuraLibro{
char nombre[50];
int telefono;
};
typedef struct EstructuraLibro *LIBRO;
LIBRO CrearLibro();
LIBRO CrearLibroPorParametro(char nombre[],int telefono);
char *GetNombre(LIBRO libro);
int GetDni(LIBRO libro);
void SetNombre(LIBRO libro,char nombre[]);
void SetTelefono(LIBRO libro,int telefono);
void MostrarLibro(LIBRO libro);

#endif // LIBRO_H_INCLUDED
