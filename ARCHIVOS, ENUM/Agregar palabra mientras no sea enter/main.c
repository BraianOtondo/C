#include <stdio.h>
#include <string.h>
int main(){
FILE* fichero;
char frase[60];
int estado;

fichero= fopen("frases.txt", "w");
do{
puts("\nEscriba otra FRASE:\n(o pulse \"Intro\" para terminar). \n");
fflush(stdin);
gets(frase);
estado=strcmp(frase,"");
    if(estado==0){
    break;
    }
fprintf(fichero,"%s\n",frase);
}while(estado!=0);
printf("He aqui lo que escribio:\n\n");
fclose(fichero);

fichero=fopen("frases.txt", "r");
while(!feof(fichero)){
        fgets(frase, 60,fichero);
        if(!feof(fichero)){
      printf("%s\n",frase);
        }
};
fclose(fichero);
printf("...Hasta luego!");
getchar();
return 0;
}
