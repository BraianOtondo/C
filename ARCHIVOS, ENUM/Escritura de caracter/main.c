#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
FILE *fichero;
char caracter;
printf("\nIntroduce caracter:\n");
fflush(stdin);
scanf("%c",&caracter);

fichero=fopen("caracter.txt","w");
fputc(caracter,fichero);
fclose(fichero);
printf("\nCaracter guardado en el fichero!!\n");
system("PAUSE");
system("cls");
printf("\nIntroduce caracter:\n");
fflush(stdin);
scanf("%c",&caracter);

fichero=fopen("caracter.txt","a");
fprintf(fichero,"\n");
fputc(caracter,fichero);
fclose(fichero);
printf("\nCaracter guardado en el fichero!!\n");
system("PAUSE");

    return 0;
}
