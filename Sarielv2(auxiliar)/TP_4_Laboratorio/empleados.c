#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "empleados.h"
eEmpleado* new_Empleado(char* idStr, char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    eEmpleado* nuevo;
    nuevo=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(nuevo!=NULL)
    {
        nuevo->id=atoi(idStr);
        strcpy(nuevo->nombre,nombreStr);
        nuevo->horasTrabajadas=atoi(horasTrabajadasStr);
        nuevo->sueldo=atof(sueldoStr);
    }
    return nuevo;
}
int setId(eEmpleado* emp, int id)
{
    int r=0;
    if(id>0)
    {
        emp->id=id;
        r=1;
    }
    return r;
}
int setNombre(eEmpleado* emp, char*nombre)
{
    int r=0;
    if(strlen(nombre)<31)
    {
        strcpy(emp->nombre,nombre);
        r=1;
    }
    return r;
}

