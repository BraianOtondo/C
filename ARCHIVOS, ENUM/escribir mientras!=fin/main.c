#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
FILE* fichero;
char fin[]="fin";
char frase[60];
int estado;
fichero=fopen("archivo.txt", "w");
do{
puts("Escriba una FRASE o 'fin':\n");
fflush(stdin);
gets(frase);
estado=strcmp(frase,fin);
if (estado==0){
break;
}
fprintf(fichero, "%s\n", frase);
}while (estado!= 0);
fclose(fichero);
    return 0;
}
