#include <stdio.h>
#include <stdlib.h>
#include<string.h>
enum EnumNumeros{
uno=1,dos=2,tres=3,cuatro=4,cinco=5
};
typedef enum EnumNumeros NUMEROS;
int main()
{
    NUMEROS opciones;
    FILE *fichero;
    int numero;
    char cadena[10];
    fichero=fopen("archivo.txt","r");
    if(fichero==NULL){
        printf("No existe el txt\n");
    }
    else{

       while(feof(fichero)==0){
        fscanf(fichero,"%d %s",&numero,cadena);// EL ORDEN IMPORTA
        opciones=numero;
        switch(opciones){
        case uno:strcpy(cadena,"ONE");
        break;
        case dos:strcpy(cadena,"TWO");
        break;
        case tres:strcpy(cadena,"THREE");
        break;
        case cuatro:strcpy(cadena,"FOUR");
        break;
        case cinco:strcpy(cadena,"FIVE");
        break;
        default:printf("Error\n");
        break;
        }
        printf("%d %s\n",numero,cadena);
       }
    fclose(fichero);
    }
    return 0;
}
