#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;
typedef struct{
    int id;
    char descripcion[20];
}eComida;

typedef struct{
int idAlmuerzo;
int idComida;
int idEmpleado;
}eAlmuerzo;

void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);;
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listar_empleadosxSector(eEmpleado x[],int tam,eSector sectores[],int tamSector);
void ordenarXsectorYnombre(eEmpleado x[],int tam, eSector sectores[],int tamSector);
int menu();

int main()
{

    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] = {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
        };
    eComida comidas []={
    {1,"Milanesa"},
    {2,"Fideos"},
    {3,"Pizza"},
    {4,"Sopa"},
    {5,"Pescado"},
    };
    eAlmuerzo almuerzos[]={
    {100,1111,4},
    {101,5555,1},
    {102,4545,3},
    {103,3232,4},
    {104,1111,1},
    {105,5555,5},
    {106,4545,2},
    {107,3232,5},
    {108,1111,2},
    {109,4545,1},
    {110,3232,1},
    {111,1111,4},
    {112,5555,3},
    {113,4545,5},
    {114,3232,2},
    {115,5555,5},
    {116,4545,2},
    {117,3232,3},
    {118,1111,2},
    {119,5555,1},
    {200,4545,3},
    };


    inicializarEmpleados(lista, 10);
    harcodearEmpleados(lista);


    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, 10, sectores, 5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, 10, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, 10, sectores, 5);
            system("pause");
            break;
        case 5:
            listar_empleadosxSector(lista,10,sectores,5);
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i;
    for( i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;
    int i;
    for( i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    int i;
    for( i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- ordenar por sector y nombre\n");
    printf("7- mostrar datatos de el o los que mas ganan de cada sector\n");
    printf("8- listar Almuerzos\n");
    printf("9- Almuerzos x Empleado\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta], sectores, tamSector);
        }
        else{
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d %s %c %.2f %s \n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    int i;
    for( i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector){

int legajo;
int indice;
char borrar;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);

    printf("\nConfirma borrado?: ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's'){
        printf("Borrado cancelado\n\n");
    }
    else{
        empleados[indice].isEmpty = 0;
        printf("Se ha eliminado el empleado\n\n");
    }
    system("pause");
}

}

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector){

int legajo;
int indice;
char modificar;
float nuevoSueldo;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);

    printf("\nModifica sueldo?: ");
    fflush(stdin);
    scanf("%c", &modificar);
    if(modificar != 's'){
        printf("Modificacion cancelada\n\n");
    }
    else{
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

        empleados[indice].sueldo = nuevoSueldo;
        printf("Se ha modificado el sueldo con exito\n\n");
    }

    system("pause");
}



}


int elegirSector(eSector sectores[], int tam){
    int idSector;
    printf("\nSectores\n\n");
    int i;
    for( i=0; i < tam; i++){
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]){

    int i;
    for(i=0; i < tamSector; i++){
        if( sectores[i].id == idSector){

            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }


}
void listar_empleadosxSector(eEmpleado x[],int tam,eSector sectores[],int tamSector)
{
    int i;
    int dato;
    dato=elegirSector(sectores,tamSector);
    for(i=0;i<tam;i++)
    {
        if(x[i].idSector==dato&&x[i].isEmpty==1)
        {
            mostrarEmpleado(x[i],sectores,tamSector);
        }
        else{
            printf("\n No hay Empleados para Mostrar\n\n");
        }
    }
    system("pause");

}
void ordenarXsectorYnombre(eEmpleado x[],int tam, eSector sectores[],int tamSector)
{
    int i,j;
    for(i=0;i<tamSector;i++)
    {
        for(j=0;j<tam;j++)
        {
            if(sectores[i].id>x[j].idSector&&x[j].isEmpty==1)
            {
                if(x[j].nombre);
            }
        }
    }
}
void cargarDescripcionComidas(eComida comidas[], int tamComida, int idComida, char cadena[]){

    int i;
    for(i=0; i < tamComida; i++){
        if( comidas[i].id == idComida){

            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }


}
void harcodearEmpleados(eEmpleado x[])
{
    int i;
    eEmpleado y[]={
    {1111,"ana",'f',15000,5,1},
    {3333,"luis",'m',25000,4,1},
    {4444,"albertod",'m',10000,5,1},
    {5555,"julia",'f',30000,1,1},
    {1313,"julieta",'f',23000,2,1},
    {4545,"andrea",'f',31000,5,1},
    {3232,"mauro",'m',27000,5,1},
    };
    for(i=0;i<7;i++)
    {
        y[i]=x[i];
    }
}
void listarAlmuerzos(eAlmuerzo listaAlmuerzo[],int tamAlmuezo,eEmpleado lista[],int tamEmp,eComida comidas[],int tamcomidas)
{
    int i,j,k;
    char comida_descripcion[20];
    char empleado_nombre[20];


}

