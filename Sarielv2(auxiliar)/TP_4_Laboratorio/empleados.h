#ifndef empleados_H_INCLUDED
#define empleados_H_INCLUDED
typedef struct{
    int id;
    char nombre[31];
    int horasTrabajadas;
    float sueldo;
}eEmpleado;
eEmpleado* new_Empleado(char* idStr, char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int setId(eEmpleado* emp, int id);
int setNombre(eEmpleado* emp, char*nombre);
int setApellido(eEmpleado* emp, char*apellido);
int setSexo(eEmpleado* emp, char sexo);
int setSalario(eEmpleado* emp, float Salario);
#endif // empleados_H_INCLUDED
