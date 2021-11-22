#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char aux[]="Roberto;Perez";// Creo aux con una cadena
    char aux2[]="PEPE;";
    //printf("%s\n",aux);
    char *token;//Puntero a un tipo de dato char llamado token
    token=strtok(aux,";");
     printf("1--> %s\n",token);
      token=strtok(aux2,";");
     printf("--> %s\n",token);
    token=strtok(NULL,";");//deja almacenado el vector original si le paso aux2 pepe
    printf("2-->%s\n",token);


    return 0;
}
