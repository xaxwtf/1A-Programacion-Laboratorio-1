#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fecha_ingreso;
}eEmpleado;
void mostrar_empleado(eEmpleado emp);

void mostrar_empleados(eEmpleado lista[],int tam);

int main()
{
    int i;
    eFecha fecha_hoy={17,9,2018};
    eEmpleado empleados[TAM];
    for(i=0;i<TAM;i++)
    {
        printf("\n indique el nro de legajo: ");
        scanf("%d",&empleados[i].legajo);
        printf("\n indique el nombre del empleado:");
        fflush(stdin);
        gets(empleados[i].nombre);
        printf("\n indique el sexo:");
        fflush(stdin);
        scanf("%c",&empleados[i].sexo);
        printf("\n indique el sueldo del Empleado: ");
        scanf("%f",&empleados[i].sueldo);
        empleados[i].fecha_ingreso=fecha_hoy;

    }
    mostrar_empleados(empleados,TAM);

    return 0;
}
void mostrar_empleado(eEmpleado emp)
{
    printf("\n %4d    %10s    %c   %2.2f  %d/%d/%d \n",emp.legajo,emp.nombre,emp.sexo,emp.sueldo,emp.fecha_ingreso.dia,emp.fecha_ingreso.mes,emp.fecha_ingreso.anio);
}
void mostrar_empleados(eEmpleado lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        mostrar_empleado(lista[i]);
    }
}
void ordenar_empleados(eEmpleado lista[],int tam)
{
    int i,j;
    eEmpleado auxEmpleado;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if( lista[i].sexo > lista[j].sexo)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
            else if( lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }
}
