#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*Programa para escribir todo lo que hay en un txt caracter por caracter
LECTURA
*/
int main()
{

    FILE *fichero;
    fichero=fopen("archivo.txt","r");// r porque voy a leer y el nombre del archivo
    if(fichero==NULL){ // SI ESTÁ VACIO NO EXISTE
        printf("El txt no existe\n");
    }
    else{
        char caracter;
        while(feof(fichero)==0){ // feof significa fin del archivo si es 1 terminó
            caracter=fgetc(fichero);// EN LA VARIABLE CARACTER GUARDO LO QUE LEO
            printf("%c",caracter);// ES UN CARACTER
        }
    }
    fclose(fichero); // CIERRO EL ARCHIVO

    return 0;
}
