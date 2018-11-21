#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "empleados.h"
#include "eFecha.h"
eEmpleado* new_Empleado(char* idStr, char* nombreStr,char* apellidoStr,char* sexoStr,char* salarioStr,char* dia,char*mes,char* anio)
{
    eEmpleado* nuevo;
    nuevo=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(nuevo!=NULL)
    {
        nuevo->id=atoi(idStr);
        strcpy(nuevo->nombre,nombreStr);
        strcpy(nuevo->apellido,apellidoStr);
        nuevo->sexo=sexoStr[0];
        nuevo->salario=atof(salarioStr);
        nuevo->FechadeContratacion.dia=atoi(dia);
        nuevo->FechadeContratacion.mes=atoi(mes);
        nuevo->FechadeContratacion.anio=atoi(anio);
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
int setApellido(eEmpleado* emp, char*apellido)
{
    int r=0;
    if(strlen(apellido)<31)
    {
        strcpy(emp->apellido,apellido);
        r=1;
    }
    return r;
}
int setSexo(eEmpleado* emp, char sexo)
{
    int r=0;
    if(sexo=='m'||sexo=='f')
    {
        emp->sexo=sexo;
        r=1;
    }
    return r;
}
int setSalario(eEmpleado* emp, float Salario)
{
    int r=0;
    if(Salario>0)
    {
        emp->salario=Salario;
        r=1;
    }
    return r;
}

