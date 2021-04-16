#include <stdio.h>
#include <stdlib.h>
#include "integrante.h"
#include "materia.h"
#include "carrera.h"
#include "universidad.h"

int Menu(){
int opcion;
printf("Integrantes del Grupo:\n");
printf("\nBraian Condori Otondo\n");
printf("\nJulieta Luana Coronel\n");
printf("\nSantiago Gauto\n");

printf("\n--------------------------------------------------------------------");
printf("\n\t Que desea hacer?\n");
printf("\n 1: Agregar\n 2:Modificar\n 3: Eliminar\n 4: Mostrar\n 0: Salir\n\t\t Su opcion: ");
scanf("%d",&opcion);
return opcion;
}
void Agregar(UNIVERSIDAD universidad){
system("pause");
system("cls");
int opc,i,CantDep,CantCarr,CantMate,CantInte;
while(opc!=0){
        printf("\n--------------------------------------------------------------------------------");
        printf("\nQue va a agregar?:\n");
        printf(" 1: Departamento\n 2: Carrera\n 3: Materia\n 4: Integrante\n 0: Salir\n\t\t Su opcion ");
        scanf("%d",&opc);

    switch(opc){
    case 1:// AGREGA DEPARTAMENTO
        if((universidad->CantDepartamentos)==4){
            printf("No se pueden ingresar mas departamentos\n");
        }
        else{
        universidad->departamento[universidad->CantDepartamentos]=CrearDepartamentoPorTeclado();
    AgregarDepartamentoAUniversidad(universidad,universidad->departamento[universidad->CantDepartamentos]);
        }
       system("pause");
    system("cls"); break;
    case 2: //AGREGA CARRERA
        if((universidad->CantDepartamentos)==0){ // SI NO HAY DEPARTAMENTOS
            printf("No existen departamentos\n\n");
        }
        else{
        printf("Los departamentos que existen son:\n\n");

        for(i=0;i<universidad->CantDepartamentos;i++){
            printf("%d-",i+1);
            printf("%s\n",GetNombreDepartamento(universidad->departamento[i]));

        }
        //MUESTRA LOS DEPARTAMENTOS
        int pos;
        printf("A que departamento lo quiere ingresar?\n");
        pos=BuscarDepartamentoEnUniversidad(universidad);//Escribe el nombre de
                                                        // Departamento para agregar la materia
        if(pos==-1){
            printf("No existe el departamento\n");
        }
        else{ // SI EXISTE EL DEPARTAMENTO SI AGREGA CARRERA A ESE DEPARTAMENTO
    int aux=universidad->departamento[pos]->CantCarreras;// Auxiliar que guarda la cant
                                                        // de carreras
    // LLAMAMOS AL Procedimiento para Crearcarrera
    universidad->departamento[pos]->carrera[aux]=CrearCarreraPorTeclado();
    // AGREGAMOS ESA CARRERA POR TECLADOA ESE DEPARTAMENTO
    AgregarCarreraADepartamento(universidad->departamento[pos],universidad->departamento[pos]->carrera[aux]);

   }
}  system("pause");
    system("cls");break;
    case 3: // AGREGA MATERIA

        CantDep=universidad->CantDepartamentos;
        if((CantDep)==0){
            printf("\nNo existen departamentos\n\n");
        }
        else{
        printf("\nLos departamentos que existen son:\n\n");
        for(i=0;i<universidad->CantDepartamentos;i++){
            printf("%d-",i+1);
            printf("%s\n",GetNombreDepartamento(universidad->departamento[i]));

        }

        int posdep,poscarrera;
        printf("\nA que departamento lo quiere ingresar?\n\n");
        posdep=BuscarDepartamentoEnUniversidad(universidad);
        if(posdep==-1){
            printf("\nNo existe el departamento\n\n");
        }
        else{
                printf("\nLas carreras que existen son:\n\n");
            CantCarr=universidad->departamento[posdep]->CantCarreras;
                  for(i=0;i<CantCarr;i++){
            printf("%d-",i+1);
            printf("%s\n",GetNombreCarrera(universidad->departamento[posdep]->carrera[i]));

        }
                printf("\nA que carrera lo quiere ingresar?\n\n");
            poscarrera=BuscarCarreraEnElDepartamento(universidad->departamento[posdep]);
            if(poscarrera==-1){
                printf("\nNo existe esa carrera\n\n");
            }
            else{
            CantMate=universidad->departamento[posdep]->carrera[poscarrera]->CantMaterias;
        universidad->departamento[posdep]->carrera[poscarrera]->materia[CantMate]=CrearMateriaPorTeclado();
        AgregarMateriaACarrera(universidad->departamento[posdep]->carrera[poscarrera],universidad->departamento[posdep]->carrera[poscarrera]->materia[CantMate]);
            }

        }
        system("pause");
        system("cls");
        break;
    case 4:
        CantDep=universidad->CantDepartamentos;
        if((CantDep)==0){
            printf("\nNo existen departamentos\n\n");
        }
        else{
        printf("\nLos departamentos que existen son:\n\n");
        for(i=0;i<universidad->CantDepartamentos;i++){
            printf("%d-",i+1);
            printf("%s\n",GetNombreDepartamento(universidad->departamento[i]));

        }
        int posdep,poscarrera,posmater;
        printf("\nA que departamento lo quiere ingresar?\n");
        posdep=BuscarDepartamentoEnUniversidad(universidad);
        if(posdep==-1){
            printf("No existe el departamento\n");
        }
        else{
            CantCarr=universidad->departamento[posdep]->CantCarreras;
            printf("\nLas carreras que exiten son:\n");
                  for(i=0;i<CantCarr;i++){
            printf("%d-",i+1);
            printf("%s\n",GetNombreCarrera(universidad->departamento[posdep]->carrera[i]));
            printf("\n");
        }
                printf("\nA que carrera lo quiere ingresar?\n");
            poscarrera=BuscarCarreraEnElDepartamento(universidad->departamento[posdep]);
            if(poscarrera==-1){
                printf("No existe esa carrera\n");
            }
            else{
                CantMate=universidad->departamento[posdep]->carrera[poscarrera]->CantMaterias;
                printf("A que materia lo quiere ingresar?\n");
            for(i=0;i<CantMate;i++){
               printf("(%d)-",GetCodigoMateria(universidad->departamento[posdep]->carrera[poscarrera]->materia[i]));
            printf("%s\n",GetNombreMateria(universidad->departamento[posdep]->carrera[poscarrera]->materia[i]));
            printf("\n");
            }
            posmater=BuscarMateriaEnCarrera(universidad->departamento[posdep]->carrera[poscarrera]);
            if(posmater==-1){
                printf("\nNo existe esa materia\n");
            }
            else{
            CantInte=universidad->departamento[posdep]->carrera[poscarrera]->materia[posmater]->CantidadIngrantes;
        universidad->departamento[posdep]->carrera[poscarrera]->materia[posmater]->integrante[CantInte]=CrearIntegrantePorTeclado();
        AgregarIntegranteAMateria(universidad->departamento[posdep]->carrera[poscarrera]->materia[posmater],universidad->departamento[posdep]->carrera[poscarrera]->materia[posmater]->integrante[CantInte]);
            }
            }
      system("pause");
    system("cls");  break;
case 0:
break;
default:printf("Ingrese bien las opciones...\n");system("pause");
    system("cls");
            }

}
}
}
}}
void Eliminar(UNIVERSIDAD universidad){
int opc,pos,opcdepa,opccarrera,opcmateria,i;

while(opc){
        printf("Ingrese lo que quiere eliminar:\n1.Integrante\n");
    scanf("%d",&opc);
    switch(opc){
    case 1://BUSCAMOS EL INTEGRANTE POR DEPARTAMENTO
        printf("Seleccione el departamento:\n\n");//modificarmateria case3
    for(i=0;i<universidad->CantDepartamentos;i++){
        printf("\n%d-%s\n",i+1,GetNombreDepartamento(universidad->departamento[i]));
    }
    scanf("%d",&opcdepa);
    //BUSCAMOS EL INTEGRANTE CARRERA
    printf("De que carrera es eliminar?\n\n");
    for(i=0;i<universidad->departamento[opcdepa-1]->CantCarreras;i++){
       printf("\n%d-%s\n",i+1,GetNombreCarrera(universidad->departamento[opcdepa-1]->carrera[i]));
    }
    scanf("%d",&opccarrera);
    //BUSCAMOS EL INTEGRANTE POR MATERIA
   printf("De  que Materia es?\n");
   for(i=0;i<universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->CantMaterias;i++){
    printf("\n %d-%s\n",i+1,GetNombreMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[i]));
   }
   scanf("%d",&opcmateria);
    int cantintegrante;
    //UNA VEZ ENCONTRADO DECIMOS CUAL INTEGRANTE ELIMINAR
   printf("Que integrante quiere Eliminar?");
   cantintegrante=universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->CantidadIngrantes;
    for(i=0;i<cantintegrante;i++){
         printf("\n %d-%s\n",i+1,GetNombreIntegrante(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[i]));
    }
    printf("\n");
    // LO BUSCAMOS POR DNI
    printf("DNI PARA ELIMINAR:\n");
   pos=BuscarIntegranteMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]);
    if(pos==-1){
        printf("No existe el integrante\n");
    }
    else{
    DestruirIntegrante(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[pos]);
    QuitarIntegranteAMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1],pos);
    }
    break;
    default:printf("Ingrese bien la opcion..\n");break;
    }
}

}
void Mostrar(UNIVERSIDAD universidad){
int opc,opcdepa,opccarrera,opcmateria,i;

while(opc!=0){
        printf("Ingrese lo que quiere mostrar:\n1.Integrante\n");
    scanf("%d",&opc);
    switch(opc){
        // MUESTRA SOLO INTEGRANTE
    case 1:
        printf("Seleccione el departamento:\n\n");//DE QUE DEPA ES EL INTEGRANTE
    for(i=0;i<universidad->CantDepartamentos;i++){
        printf("\n%d-%s\n",i+1,GetNombreDepartamento(universidad->departamento[i]));
    }//MUESTRA LOS DEPARTAMENTOS QUE EXISTEN
    scanf("%d",&opcdepa);
    printf("De que carrera es?\n\n");
    for(i=0;i<universidad->departamento[opcdepa-1]->CantCarreras;i++){
       printf("\n%d-%s\n",i+1,GetNombreCarrera(universidad->departamento[opcdepa-1]->carrera[i]));
    }//MUESTRA LAS CARRERAS QUE EXISTEN
    scanf("%d",&opccarrera);
    printf("\n");
   printf("De  que Materia ?\n");
   for(i=0;i<universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->CantMaterias;i++){
    printf("\n %d-%s\n",i+1,GetNombreMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[i]));
   }
   //LLAMA AL PROCEDIMIENTO MostrarIntegrante
   scanf("%d",&opcmateria);
   for(i=0;i<universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->CantidadIngrantes;i++){
   // OrdenarIntegrantesEnMateria(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1],universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[i]);
    MostrarIntegrante(universidad->departamento[opcdepa-1]->carrera[opccarrera-1]->materia[opcmateria-1]->integrante[i]);

   }break;
    case 0: // EN CASO DE 0 Vuelve al menu principal
        while(opc!=0){
opc=Menu();
switch(opc){
case 1:Agregar(universidad);system("pause");system("cls");break;
case 2:Modificar(universidad);system("pause");system("cls");break;
case 3:Eliminar(universidad);;system("pause");system("cls");break;
case 4:Mostrar(universidad);system("pause");system("cls");break;
case 0: printf("Gracias por usar el programa\n");break;
default:printf("Ingrese bien las opciones...\n");break;
}
}}}}
int main(){
int i;
UNIVERSIDAD universidad;

//Creo los departamentos y carreras y le agrego integrantes a Sistemas por parametro
universidad=CrearUniversidad();
universidad->departamento[0]=CrearDepartamento("Desarrollo Productivo y Tecnologico","Dr. Pablo Narvaja");
universidad->departamento[1]=CrearDepartamento("Humanidades y Artes","Mtro. Daniel Bozzani");
universidad->departamento[2]=CrearDepartamento("Planificacion y Politicas Publicas","Dr. Francisco Pestanha");
universidad->departamento[3]=CrearDepartamento("Salud Comunitaria","Lic. Ramon Alvarez");
for(i=0;i<4;i++){
 AgregarDepartamentoAUniversidad(universidad,universidad->departamento[i]);
}
universidad->departamento[0]->carrera[0]=CrearCarrera("Sistemas","Lic.en Sistemas");
universidad->departamento[1]->carrera[0]=CrearCarrera("Audiovision","Lic.en Audiovision");
universidad->departamento[2]->carrera[0]=CrearCarrera("Educacion","Lic. en Educacion ");
universidad->departamento[3]->carrera[0]=CrearCarrera("Enfermeria","Lic. en Enfermeria");
for(i=0;i<4;i++){
AgregarCarreraADepartamento(universidad->departamento[i],universidad->departamento[i]->carrera[0]);
}
//CREO MATERIA
universidad->departamento[0]->carrera[0]->materia[0]=CrearMateria(1234,"Programacion de computadoras");
AgregarMateriaACarrera(universidad->departamento[0]->carrera[0],universidad->departamento[0]->carrera[0]->materia[0]);
// CREO INTEGRANTES
universidad->departamento[0]->carrera[0]->materia[0]->integrante[0]=CrearIntegrante('A',"Braian","Otondo",42091994);
universidad->departamento[0]->carrera[0]->materia[0]->integrante[1]=CrearIntegrante('A',"Martin","Malfoi",42091995);
universidad->departamento[0]->carrera[0]->materia[0]->integrante[2]=CrearIntegrante('A',"Maria","Lopez",42091984);
universidad->departamento[0]->carrera[0]->materia[0]->integrante[3]=CrearIntegrante('A',"Victor","Hugo",42091945);
universidad->departamento[0]->carrera[0]->materia[0]->integrante[4]=CrearIntegrante('A',"Alan","Hugo",42094945);
for(i=0;i<5;i++){
AgregarIntegranteAMateria(universidad->departamento[0]->carrera[0]->materia[0],universidad->departamento[0]->carrera[0]->materia[0]->integrante[i]);
}
int opcion;
while(opcion!=0){

opcion=Menu();


switch(opcion){
case 1:Agregar(universidad);system("pause");system("cls");break;//Tiene un void en el main
case 2:Modificar(universidad);system("pause");system("cls");break;
case 3:Eliminar(universidad);;system("pause");system("cls");break;
case 4:Mostrar(universidad);system("pause");system("cls");break;
case 0: printf("Gracias por usar el programa\n");break;
default:printf("Ingrese bien las opciones...\n");break;
}
}

return 0;
}
