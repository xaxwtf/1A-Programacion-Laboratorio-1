#ifndef empleados_H_INCLUDED
#define empleados_H_INCLUDED
#include "eFecha.h"
typedef struct{
    int id;
    char nombre[31];
    char apellido[31];
    char sexo;
    float salario;
    eFecha FechadeContratacion;
}eEmpleado;
eEmpleado* new_Empleado(char* idStr, char* nombreStr,char* apellidoStr,char* sexoStr,char* salarioStr,char* dia,char*mes,char* anio);
int setId(eEmpleado* emp, int id);
int setNombre(eEmpleado* emp, char*nombre);
int setApellido(eEmpleado* emp, char*apellido);
int setSexo(eEmpleado* emp, char sexo);
int setSalario(eEmpleado* emp, float Salario);
#endif // empleados_H_INCLUDED
