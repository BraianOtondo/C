#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"
Nodo *CrearNodo(LIBRO libro){
Nodo *nodo= malloc(sizeof(Nodo));//im

nodo->libro=libro;
nodo->siguiente=NULL;
return nodo;
}
Lista* crearLista() {
    Lista* lista = malloc(sizeof(*lista));
    if (lista == NULL){
      return NULL;
    }
    lista->cabeza= NULL;
    lista->tam= 0;
    return lista;
}

int Insertar(Lista* lista,LIBRO libro,int pos){
int i;
if(lista==NULL){
    return ESTRUCTURA_NO_INICIALIZADA;
}
if(pos<0||pos>lista->tam){
return INDICE_INVALIDO;
}
Nodo* nuevonodo;
if(pos==0){
    return InsertarPrincipio(lista,libro);
}
else{
    Nodo *aux;
    aux=lista->cabeza;
    for(i=0;i<pos-1;i++){
    aux=aux->siguiente;//
    }
    nuevonodo=CrearNodo(libro);//
    nuevonodo->siguiente=aux->siguiente;
    if(nuevonodo==NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }
    aux->siguiente=nuevonodo;//
}
lista->tam++;
return OK;
}
int InsertarPrincipio(Lista* lista,LIBRO libro){
Nodo* nodo=CrearNodo(libro);
nodo->siguiente=lista->cabeza;
lista->cabeza=nodo;
lista->tam++;
return OK;
}
int InsertarFin(Lista* lista, LIBRO libro) {
    return Insertar(lista, libro, lista->tam);
}

int ObtenerTamanio(Lista* lista){
int tam;
tam=lista->tam;
return tam;
}
int obtenerElemento(Lista* lista, LIBRO *libro, int pos){
int i;
if (lista == NULL){
  return ESTRUCTURA_NO_INICIALIZADA;
}

    if (EstaVacia(lista)){
       return ESTRUCTURA_VACIA;
    }

    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    if (libro== NULL)
        return PARAMETRO_INVALIDO;


    Nodo *aux;
    aux =lista->cabeza;
    for(i=0; i < pos; i++) {
        aux = aux->siguiente;
    }
    *libro = aux->libro;

    return OK;
}
int EstaVacia(Lista* lista) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (lista->cabeza== NULL)
        return TRUE;
    return FALSE;
}
void ImprimirLista(Lista* lista){
int tam,i;
if(lista!=NULL){
tam=ObtenerTamanio(lista);
   for(i=0;i<tam;i++){
        LIBRO libro;
        obtenerElemento(lista,&libro,i);
  MostrarLibro(libro);

   } //Mientras cabeza no sea NULL


}
else{
    printf("No existe la lista\n");
}

}
int removerInicio(Lista* lista,LIBRO *libro) {
    if (lista == NULL){
          return ESTRUCTURA_NO_INICIALIZADA;
    }
    if (EstaVacia(lista)){
     return ESTRUCTURA_VACIA;
    }
    ;
    Nodo *aux = lista->cabeza;
    if (libro != NULL){
     *libro = aux->libro;
    }
    lista->cabeza = aux->siguiente;
    free(aux);
    aux = NULL;
    lista->tam--;
    return OK;

}
int remover(Lista* lista, LIBRO *libro, int pos) {
    if (lista == NULL){
      return ESTRUCTURA_NO_INICIALIZADA;
    }
    if (EstaVacia(lista)){
          return ESTRUCTURA_VACIA;
    }
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    Nodo *ant, *atual;
    if (pos == 0) {
        return removerInicio(lista, libro);
    } else {
        // prepara para remover
        ant = NULL;
        atual = lista->cabeza;
        for(int i= 0; i < pos; i++) {
            ant = atual;
            atual = atual->siguiente;
        }

        // remove o nó atual
        ant->siguiente = atual->siguiente;
        if (libro != NULL)
            *libro = atual->libro;
        free(atual);
        atual = NULL;
    }
    lista->tam--;
    return OK;
}
int removerFin(Lista* lista,LIBRO *libro) {
    return remover(lista, libro, lista->tam-1);
}

