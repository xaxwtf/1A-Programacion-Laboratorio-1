#include "control.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "S_Ariel.h"
#include "empleados.h"
int cargarDatosdesdeArchivoTexto(LinkedList* lista)
{
    char nameFile[30];
    FILE* pFile;
    int r=0;
    getString(nameFile,"\nindique el Nombre del archivo a abrir: ","\nError,\n",1,30,3);
    pFile=fopen(nameFile,"r");
    if(pFile!=NULL)
    {
        r=parser_EmployeeFromText(pFile,lista);
    }
    fclose(pFile);

    return r;
}
int cargarDatosdesdeArchivoBinario(char* patch,LinkedList* lista)
{
    FILE* pFile;
    int r=0;
    pFile=fopen(patch,"rb");
    if(pFile!=NULL)
    {
        r=parser_EmployeeFromText(pFile,lista);
    }
    fclose(pFile);

    return r;
}
int altaEmpleado(LinkedList* lista)
{
    int ok=0;
    eEmpleado* emp;
    emp=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(emp!=NULL)
    {
        if(!getInt(&emp->id,"\nIndique el Numero de ID: \n","Error,el ID indicado No es Valido\n",1,9999999,3))
        {
            ok=0;
        }
        if(ok==1 && getString(emp->nombre,"\nIndique el Nombre: ","Error,el Nombre debe tener mas de 2 caracteres",3,227,3)!=1)
            {
                ok=0;
            }
        if(ok==1 && getInt(&emp->horasTrabajadas,"\nIndique las Horas trabajadas: \n","Error,El Numero Minimo de horas es 8",8,1000,3)!=1)
        {
            ok=0;
        }
        if(ok==1 && (getFloat(&emp->sueldo,"\n Indique El Salario: \n","Error, EL salario no puede ser menor a 1",1,99999999,3)!=1))
        {
            ok=0;
        }
        if(ok==1)
        {
            ll_add(lista,emp);
        }
        else{
            free(emp);
        }
        return ok;
    }
    return ok;
}
int bajaEmpleado(LinkedList* lista)
{
    int flag=0;
    int r=0;
    char c;
    int i,index;
    eEmpleado* empleado;
    index=pedir_entero("Indique el Numero de ID: ");
    for(i=0;i<ll_len(lista);i++)
        {
            empleado=(eEmpleado*)ll_get(lista,i);
            if(empleado->id==index)
            {
                do{
                    system("cls");
                    printf("Empleado ID: %d",empleado->id);
                    printf("%5d %15s %3d %6f\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                    getChar(&c,"\nEsta seguro que desea elimiar este empleado?(s/n)","",'A','z');
                    switch(c)
                    {
                        case 's':
                            ll_remove(lista,i);
                            r=1;
                            flag=1;
                            break;
                        case 'n':
                            flag=1;
                            break;
                    }

                }while(flag!=1);

             break;
            }
        }

    return r;
}
int imprimirEmpleados(LinkedList* lista)
{
    int i;
    eEmpleado* emp;
    int len=ll_len(lista);
    if(len>0)
    {
        system("cls");
        printf("  ID       Nombre   Hs.Trab. Sueldo\n");
        for(i=0;i<len;i++)
        {
            emp=(eEmpleado*)ll_get(lista,i);
            printf("%5d %15s %3d %6.2f\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
        }

    }

    return len;
}
int guardarDatosArchivoTexto(char* path,LinkedList* lista)
{
    FILE* pfile;
    int ok=0;
    int len,i;
    char encabezado[]={"Id,Nombre,Apellido,HsTrabajadas,Sueldo"};
    eEmpleado* aux;
    pfile=fopen(path,"w");
    if(pfile!=NULL)
    {
        len=ll_len(lista);
        fprintf(pfile,"%s\n",encabezado);
        for(i=0;i<len;i++)
        {
            aux=(eEmpleado*)ll_get(lista,i);
            fprintf(pfile,"%d,%s,%d,%0.2f\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
        ok=1;
    }
    fclose(pfile);
    return ok;
}
int CalcularSueldoXhorasTrabj(void* emp)
{
    int r;
    eEmpleado* aux;
    float sueldoParcialmenteCalculado;
    float sueldoCalculado;
    float auxhoras;
    float HorasRestantes;
    if(emp!=NULL)
    {
        aux=(eEmpleado*)emp;
        auxhoras=(float)aux->horasTrabajadas;

        if(auxhoras<177)
        {
            sueldoCalculado=auxhoras*180;
            aux->sueldo=sueldoCalculado;
            r=1;
        }
        if(auxhoras>176 && auxhoras<209)
        {
            sueldoParcialmenteCalculado=176*180;
            HorasRestantes=auxhoras-176;
            sueldoCalculado=HorasRestantes * 270 + sueldoParcialmenteCalculado;
            aux->sueldo=sueldoCalculado;
            r=1;
        }
        if(auxhoras>208 && auxhoras<241)
        {
            sueldoCalculado=176*180;
            HorasRestantes=auxhoras-176;
            sueldoParcialmenteCalculado=sueldoParcialmenteCalculado+(32*270);
            HorasRestantes=HorasRestantes-32;
            sueldoCalculado=sueldoParcialmenteCalculado+(HorasRestantes*360);
            aux->sueldo=sueldoCalculado;
            r=1;
        }
    }
    return r;
}
int calularsueldos(LinkedList* lista)
{
    int r=0;
    if(lista!=NULL)
    {
        r=maps(lista,CalcularSueldoXhorasTrabj);
    }
    return r;
}
