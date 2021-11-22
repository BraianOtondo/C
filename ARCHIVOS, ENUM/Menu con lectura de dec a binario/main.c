#include <stdio.h>
#include <stdlib.h>
#include<string.h>
enum EnumOpciones{
leer,ingresar,transformar,guardar,salir
};
typedef enum EnumOpciones ENUMOPCION;
int Opcion(){
int opc;
printf("Ingrese las opciones:\n");
printf("0.Leer\n1.Ingresar\n2.Transformar\n3.Guardar\n4.Salir\n");
scanf("%d",&opc);
return opc;
}
int LeerTxt(){
int numero;
FILE *fichero;
fichero=fopen("binario.txt","r");
fscanf(fichero,"%d",&numero);
fclose(fichero);
return numero;
}
int Ingresar(){
int numero;
printf("Ingrese numero:\n");
scanf("%d",&numero);
if(numero<0){
 return Ingresar();
}

return numero;
}

int Transformar(int numero){
    if(numero<2){
        return numero;
    }
    else{
    return (numero%2+(10*Transformar(numero/2)));
    }
}
void Guardar(int binario){
FILE *archivo;
    archivo = fopen("binario.txt", "w");
    fprintf(archivo, "%d",binario);
    fclose(archivo);
system("pause");
system("cls");
}
void Salir(){
printf("Gracias por usar el programa.\n");
system("pause");
system("cls");
}
int main()
{
    int numero;
    int binario;
    ENUMOPCION opcion;
    while(opcion!=salir){
    opcion=Opcion();
        switch(opcion){
        case leer://0
        numero=LeerTxt();
            if (numero<0){
            printf("El numero no es positivo");
            }
        break;
        case ingresar:numero=Ingresar();//1
        break;
        case transformar://2
            if(numero>=0){
            binario=Transformar(numero);
            }
            else{
                printf("El numero es negativo\n");
            }
        break;
        case guardar:Guardar(binario);//3
        break;
        case salir:Salir();
        break;
        default:printf("Ingrese bien las opciones..\n");
        system("pause");
        system("cls");
        break;
        }
    }
    return 0;
}
