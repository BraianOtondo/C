#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *fp;
char cadena[]="Hola a todos";//31 caracteres
char leida[50]=" ";
fp=fopen("ejemplo5.txt","w");
fputs(cadena,fp);
fclose(fp);
fp=fopen("ejemplo5.txt","r");
fgets(leida,sizeof(leida)/sizeof(char),fp);
fclose(fp);
printf("\nCadena leida: %s\n",leida);
printf("long: %d\n",strlen(leida));
system("PAUSE");
return 0;
}
