#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "libro.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ESTRUCTURA_NO_INICIALIZADA -1
#define ESTRUCTURA_VACIA -2
#define INDICE_INVALIDO -3
#define PARAMETRO_INVALIDO -4
typedef struct {
LIBRO libro;
struct Nodo* siguiente;
}Nodo;

typedef struct {
Nodo* cabeza;
int tam;
}Lista;
Nodo* CrearNodo(LIBRO libro);
Lista* crearLista();
int Insertar(Lista* lista,LIBRO libro,int pos);
int InsertarPrincipio(Lista* lista,LIBRO libro);
int InsertarFin(Lista* lista, LIBRO libro);

int removerInicio(Lista* lista, LIBRO *libro);
int remover(Lista* lista, LIBRO *libro, int pos);
int removerFin(Lista* lista,LIBRO *libro);

int ObtenerTamanio(Lista* lista);
int EstaVacia(Lista* lista);
int obtenerElemento(Lista* lista, LIBRO *libro, int pos);
void ImprimirLista(Lista* lista);
#endif // LISTA_H_INCLUDED
