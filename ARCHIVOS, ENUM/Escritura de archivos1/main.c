#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void escribir();// ESCRITURA DE ARCHIVO CON VAR
int main()
{
   escribir();
    return 0;
}
void escribir(){
char nombre[20];
FILE *archivo;
archivo=fopen("archivo.txt","w");// CREAMOS EL ARCHIVO, ESTO SE HACE UNA VEZ

fprintf(archivo,"Hola CTM\n");
fprintf(archivo,"Habla pe :v\n");

printf("Tu archivo fue escrito\n");
fclose(archivo);
printf("Ingrese nombre:\n");
fflush(stdin);
gets(nombre);
archivo=fopen("archivo.txt","a");
fputs(nombre,archivo);
fclose(archivo);
}

