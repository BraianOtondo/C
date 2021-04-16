#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include"libro.h"
void OrdenarLista(Lista* lista){
Nodo *aux=NULL;
Nodo *p= lista->cabeza;
LIBRO *libro;
while(p->siguiente!=NULL){
aux=p->siguiente;
while(aux!=NULL){
    if((p->libro->telefono)>(aux->libro->telefono)){
    libro=aux->libro;
    aux->libro=p->libro;
    p->libro=libro;
    }
    aux=aux->siguiente;
}
p=p->siguiente;
}
}

int main()
{

    Lista* lista=crearLista();
   LIBRO libro,libro1;
    libro=CrearLibro();
    InsertarFin(lista,libro);
    libro1=CrearLibro();
    InsertarFin(lista,libro1);
    remover(lista,NULL,1);
//printf("ELim\n");
//obtenerElemento(lista,&libro,lista->tam-1);
//remover(lista,&libro,lista->tam-1);
//OrdenarLista(lista);

 ImprimirLista(lista);

    return 0;
}
