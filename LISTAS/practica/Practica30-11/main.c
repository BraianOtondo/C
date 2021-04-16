#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEnC.h"
#include "persona.h"
#include "Pila.h"
#include "Cola.h"


int main() {
    Persona p1 = crearPersona();
    Persona p2 = crearPersona();
    Persona p3 = crearPersona();

    Pila* pila;
    pila = crearLista();
    push(pila, p1);
    push(pila, p2);
    push(pila, p3);

    Persona aux;
    while(!estaVacia(pila)){ // deberian mostrarse los elementos en el orden opuesto al que se cargaron
        printf("---------------------------------------------------------\n");
        printf("Top:\n\t");
        mostrarPersona(top(pila));
        printf("Pila:"); // aca la pila deberia seguir completa ya que use el top y este no saca al elemento
        imprimir(pila);

        printf("Pop:\n\t");
        pop(pila, &aux);
        mostrarPersona(aux);
        printf("Pila:"); // aca la pila deberia estar sin el elemento mostrado antes ya que el pop lo saca de la pila
        imprimir(pila);
    }

    Cola* cola = crearLista();
    encolar(cola, p1);
    encolar(cola, p2);
    encolar(cola, p3);

    while(!estaVacia(cola)){ // deberian mostrarse los elementos en el mismo orden que se cargaron
        printf("---------------------------------------------------------\n");
        printf("Peek:\n\t");
        peek(cola, &aux);
        mostrarPersona(aux);
        printf("Cola:");
        imprimir(cola); // la cola deberia contener al elemento mostrado antes

        printf("Desencolar:\n\t");
        desencolar(cola, &aux);
        mostrarPersona(aux);
        printf("Cola:");
        imprimir(cola); // la cola no deberia contener al elemento mostrado antes
    }

    /*
    PARA PRACTICAR:
        1- hacer una funcion en el main que cargue las personas desde un archivo. (agregar al menos 5 personas).
            Hay que agregar una funcion al TDA de persona para poder crearla sin usar el teclado y que reciba los parametros

        2- cargar esos elementos en una pila

        3- hacer una funcion en el main que saque de la pila a la persona con el DNI mas grande (el del numero mas alto - el maximo)
            pero dejando los demas elementos en el mismo orden que estaban. Es decir, si estan 1, 7, 2, 6, 4
            deberia devolver la persona con dni 7 y la pila deberia quedar 1, 2, 6, 4 (usar la funcion imprimir(pila)
            para verificar que quedo con el mismo orden. (tip: se debe usar una pila auxiliar)

        4- Replicar el punto 3 cargando los elementos en una cola

        5- Cargar las personas en una lista y ordenarla por el atributo que prefieran (nombre, apellido o DNI)
    */
return 0;
}
