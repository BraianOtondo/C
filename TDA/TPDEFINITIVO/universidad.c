#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "integrante.h"
#include "materia.h"
#include "carrera.h"
#include "departamento.h"
#include "universidad.h"
UNIVERSIDAD CrearUniversidad(){

UNIVERSIDAD U=malloc(sizeof(struct EstructuraUniversidad));//defino que u va a ser una estructura "UNIVERSIDAD"
//Ahora voy a llenar los datos de U:
strcpy(U->nombre,"Universidad de Lanus\n");
strcpy(U->direccion,"29 de Septiembre 3901\n");
strcpy(U->contacto,"1155335600\n");
U->CantDepartamentos=0;

return U;//devuelvo la estructura U
}

void MostrarUniversidad(UNIVERSIDAD universidad){
    //Muesro los datos de "universidad" utilizando los GETTERS:
printf("%s\n",GetNombreUniversidad(universidad));
printf("Direccion: %s\n",GetDireccionUniversidad(universidad));
printf("Contacto: %s\n",GetContactoUniversidad(universidad));

}

//-----------------   SETTERS   --------------------------------

void SetNombreUniversidad(UNIVERSIDAD universidad,char nombre[]){
    //Modifico el nombre que está en la estructura "universisdad" y lo reemplazo por el contenido del char "nombre[]" que figura en el parametro
strcpy(universidad->nombre,nombre);
}

void SetDireccionUniversidad(UNIVERSIDAD universidad,char direccion[]){
    //Modifico la direccion que está en la estructura "universisdad" y lo reemplazo por el contenido del char "direccion[]" que figura en el parametro
strcpy(universidad->direccion,direccion);
}

void SetContactoUniversidad(UNIVERSIDAD universidad,char contacto[]){
    //Modifico el contacto que está en la estructura "universisdad" y lo reemplazo por el contenido del char "contacto[]" que figura en el parametro
strcpy(universidad->contacto,contacto);
}

//---------------   GETTERS   ----------------------------

char *GetNombreUniversidad(UNIVERSIDAD universidad){

return universidad->nombre;//devuelve el contenido de "nombre" (char) que esta dentro de la estructura "universidad"

}
char *GetDireccionUniversidad(UNIVERSIDAD universidad){

return universidad->direccion;//devuelve el contenido de "direccion" (char) que esta dentro de la estructura "universidad"

}
char *GetContactoUniversidad(UNIVERSIDAD universidad){

return universidad->contacto;//devuelve el contenido de "contacto" (char) que esta dentro de la estructura "universidad"

}


void AgregarDepartamentoAUniversidad(UNIVERSIDAD universidad,DEPARTAMENTO departamento){

if((universidad->CantDepartamentos)>3){//si ya hay 4 deptos cargados:
printf("No se puede agregar mas departamentos\n");
}//cierro if

else{//si hay menos de 4:
universidad->departamento[universidad->CantDepartamentos]=departamento;//La ultima posicion sin cargar del array de la estructura "departamentos" se iguala a "departamento" que entra desde el parametro
universidad->CantDepartamentos=(universidad->CantDepartamentos)+1;//Se le suma 1 al entero "CantDepartamentos"
}//cierro else

}//cierro AgregarDepartamentoAUniversidad

//--------------   BUSCADOR   ------------------------------------
int BuscarDepartamentoEnUniversidad(UNIVERSIDAD universidad){

int i,pos;//declaro el auxiliar "i" para el bucle while y "pos" que contendrá la posicion del departamento en su array
char nombrebuscar [40];//declaro un char que contenga el nombre del depto que quiero encontrar

printf("Ingrese el nombre del departamento a buscar:\n");
fflush(stdin);
gets(nombrebuscar);//defino que nombrebuscar contendra el nombre del depto que se quiere encontrar
bool band=false;//declaro un booleano que detenga el bucle while en caso que se vuelva "true"
i=0;
while((band==false)&&(i<(universidad->CantDepartamentos))){//=mientras que el booleano sea "false" e "i" sea menor a la cantidad total de departamentos:

    if(strcmp(nombrebuscar,universidad->departamento[i]->nombre)==0){//si el contenido de "nombrebuscar" es igual al contenido de "universidad->departamento[i]->nombre"
    band=true;
    pos=i;
    }
    i++;

}//cierro WHILE
if(band==false){//si sigue sindo falso el booleano despues del primer if:
    return -1;
}
else{
    return pos;//se devuelve la posicion del array que contiene el departamento que busccamos
}

}//cierro BuscarDepartamentoEnUniversidad


void QuitarDepartamentoAUniversidad(UNIVERSIDAD universidad,int pos){

int i; //declaro "i" para auxiliarme en el bucle FOR
if(pos==(universidad->CantDepartamentos)-1){//si el entero "pos" que entró desde el parametro es igual al ultimo departamento del array de deptos
    universidad->CantDepartamentos=(universidad->CantDepartamentos)-1;
}
else{
        //genero un bucle FOR desde la posicion del depto que eliminé hasta la ultima, reemplazando las posiciones de cada una por las que estaban un array arriba
    for(i=pos;i<(universidad->CantDepartamentos)-1;i++){
        universidad->departamento[i]=universidad->departamento[i+1];
    }
    universidad->CantDepartamentos=(universidad->CantDepartamentos)-1;//le resto 1 a la cant de deptos existente
}//cierro ELSE

}//cierro QuitarDepartamentoAUniversidad

//--------------- v OPCIONES DEL MENU v --------------------------------

//---------------    OPCION MODIFICAR   --------------------------------
void Modificar(UNIVERSIDAD universidad){

//declaro los auxiliares necesarios para contener las pociones de los array de estructuras concatenadas
int opc,i,opcdepa,opccarrera,opcmateria,opcintegrante;
int opcidatomod;
//declaro los auxiliares contenedores de datos a modificar
char nombre_departamento[40];
char nombre_director[40];
char nombre_carrera[40];
char nombre_titulo[40];
char nombre_materia[50];
int codigo_materia;
char nombre_integrante[20];
char apellido_integrante[20];
int dni_integrante;
char DocOAlum_integrante;

//Genero menu de opciones
while(opc!=0){
        system("cls");//borro lo anterior en pantalla
        printf("\n---------------------------  MARCO OPCION 2: Modificar  -----------------------------------------------------");
        printf("\nQue va a modificar?:\n");
        printf(" 1: Departamento\n 2: Carrera\n 3: Materia\n 4: Integrante\n 0: Salir\n\t\t Su opcion ");
        scanf("%d",&opc);//obtengo la opcion que deseo modificar

switch(opc){//inicio switch de opciones

case 1://MODIFICAR DEPTOS
        system("cls");//borro lo anterior en pantalla
        printf("\n--------------Seleciono DEPARTAMENTO---------------\n\nEstos son los departamentos existentes:\n");
        //genero bucle for que imprime los departamentos exitentes
        for(i=0;i<universidad->CantDepartamentos;i++){
       printf("\n%d-%s\n",i+1,GetNombreDepartamento(universidad->departamento[i]));
        }
        printf("\n\nQue Departamento quiere modificar?\n");
        scanf("%d",&opcdepa);//obtengo la posicion(+1) de depto que quiero modificar. cada vez que quiera referenciar la posicion, se debera ingresar "opcdepa-1".

        system("cls");//borro lo anterior en pantalla
        //genero otro sub-menu con los datos del depto que puedo modificar
        printf("Que quiere modificar?\n 1.Nombre del departamento\n 2.Nombre del director de departamento)\n");
        scanf("%d",&opcidatomod);//obtengo la opcion de depto que quiero modificar.
        while(opcidatomod!=0){
        //genero switch que modifique x dato en cada caso
        switch(opcidatomod){

        case 1://caso NOMBRE DEPTO
            system("cls");
            printf("Ingrese nuevo nombre de departamento:\n");
            fflush(stdin);
            gets(nombre_departamento);
            SetNombreDepartamento(universidad->departamento[opcdepa-1],nombre_departamento);
            opcidatomod=0;
            break;
        case 2://caso NOMBRE DIRECTOR
            system("cls");
            printf("Ingrese nuevo nombre del director de departamento:\n");
            fflush(stdin);
            gets(nombre_director);
            SetDirectorDepartamento(universidad->departamento[opcdepa],nombre_director);
            opcidatomod=0;
            break;
        default:printf("Ingrese bien la opcion..\n");break;
            }
        }
break;
case 2://MODIFICAR CARRERA
    printf("Seleccione el departamento:\n\n");
    for(i=0;i<universidad->CantDepartamentos;i++){
        printf("\n%d-%s\n",i+1,GetNombreDepartamento(universidad->departamento[i]));
    }
    scanf("%d",&opcdepa);
    printf("Que Carrera quiere modificar?\n\n");
    for(i=0;i<universidad->departamento[opcdepa-1]->CantCarreras;i++){
       printf("\n%d-%s\n",i+1,GetNombreCarrera(universidad->departamento[opcdepa-1]->carrera[i]));
    }
    scanf("%d",&opccarrera);
    printf("Que quiere modificar?\n\n");
    printf("(1.Nombre de carrera)\n\n(2.Nombre de Titulo de carrera)\n\n");
    scanf("%d",&opcidatomod);
     while(opcidatomod!=0){
        switch(opcidatomod){
        case 1:printf("Ingrese nuevo nombre de la carrera:\n");
            fflush(stdin);
            gets(nombre_carrera);
            SetNombreCarrera(universidad->departamento[opcdepa-1]->carrera[opccarrera-1],nombre_carrera);
            opcidatomod=0;
            break;
        case 2:printf("Ingrese nuevo nombre de titulo de carrera:\n");
            fflush(stdin);
            gets(nombre_titulo);
            SetTituloCarrera(universidad->departamento[opcdepa-1]->carrera[opccarrera-1],nombre_titulo);

            opcidatomod=0;
            break;
            default:printf("Ingrese bien la opcion..\n");break;
            }

        }
        break;//case2
case 3: printf("Seleccione el departamento:\n\n");//modificarmateria case3
    for(i=0;i<universidad->CantDepartamentos;i++){
        printf("\n%d-%s\n",i+1,GetNombreDepartamento(universidad->departamento[i]));
    }
    scanf("%d",&opcdepa);
    printf("Que Carrera quiere modificar?\n\n");
    for(i=0;i<universidad->departamento[opcdepa-1]->CantCarreras;i++){
       printf("\n%d-%s\n",i+1,GetNombreCarrera(universidad->departamento[opcdepa-1]->carrera[i]));
    }
    scanf("%d",&opccarrera);
   printf("Que Materia quiere modificar?\n");
   for(i=0;i<universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->CantMaterias;i++){
    printf("\n %d-%s\n",i+1,GetNombreMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[i]));
   }
   scanf("%d",&opcmateria);
   printf("Que desea modificar?\n");
   printf("\n(1.Codigo de materia)\n(2.Nombre de materia)\n\n");
   scanf("%d",&opcidatomod);
     while(opcidatomod!=0){
        switch(opcidatomod){
        case 1:printf("Ingrese nuevo nombre de la materia:\n");
            fflush(stdin);
            gets(nombre_materia);
            SetNombreMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1],nombre_materia);
            opcidatomod=0;
            break;
        case 2:printf("Ingrese nuevo nombre de codigo de materia:\n");
            scanf("%d",&codigo_materia);
            SetCodigoMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1],codigo_materia);
            opcidatomod=0;
            break;
            default:printf("Ingrese bien la opcion..\n");break;
            }

        }// WHILEE

            break;
case 4:
printf("Seleccione el departamento:\n\n");//modificarmateria case3
    for(i=0;i<universidad->CantDepartamentos;i++){
        printf("\n%d-%s\n",i+1,GetNombreDepartamento(universidad->departamento[i]));
    }
    scanf("%d",&opcdepa);
    printf("Que Carrera quiere modificar?\n\n");
    for(i=0;i<universidad->departamento[opcdepa-1]->CantCarreras;i++){
       printf("\n%d-%s\n",i+1,GetNombreCarrera(universidad->departamento[opcdepa-1]->carrera[i]));
    }
    scanf("%d",&opccarrera);
   printf("Que Materia quiere modificar?\n");
   for(i=0;i<universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->CantMaterias;i++){
    printf("\n %d-%s\n",i+1,GetNombreMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[i]));
   }
   scanf("%d",&opcmateria);
   printf("Que integrante quiere modificar?");
   for(i=0;i<universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->CantidadIngrantes;i++){
    printf("\n%d-%s\n",i+1,GetNombreIntegrante(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[i]));
   }
   scanf("%d",&opcintegrante);
   printf("Que quiere modificar?\n\n");
   printf("(1.Nombre integrante)\n(2.Apellido Integrante)\n(3.Dni Integrante)\n\n(4.Doc O Alum)\n\n");
   scanf("%d",&opcidatomod);
   while(opcidatomod!=0){
        switch(opcidatomod){
        case 1:printf("Ingrese nuevo nombre del integrante:\n");
            fflush(stdin);
            gets(nombre_integrante);
            SetNombreIntegrante(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[opcintegrante-1],nombre_integrante);
            opcidatomod=0;
            break;
        case 2:printf("Ingrese nuevo apellido de integrante:\n");
            fflush(stdin);
            gets(apellido_integrante);
            SetApellidoIntegrante(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[opcintegrante-1],apellido_integrante);
            opcidatomod=0;
            break;
            case 3:printf("Ingrese nuevo dni:\n");
            scanf("%d",&dni_integrante);
            SetDniIntegrante(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[opcintegrante-1],dni_integrante);
            opcidatomod=0;
            break;
            case 4:printf("Ingrese Nuevo Doc o ALum:\n");
                    scanf("%c",&DocOAlum_integrante);
                    SetAlumODoc(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[opcintegrante-1],DocOAlum_integrante);
             opcidatomod=0;
             break;
            default:printf("Ingrese bien la opcion..\n");break;
            }
            break;
            case 0:
            break;
default:printf("Ingrese bien la opcion..\n");
        }// CIERRA switch modificador de integrantes


            }// Switch modificador de estructura

        }//Cierra while principal
}//Cierra Void











