#include "control.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "S_Ariel.h"
#include "eFecha.h"
#include "empleados.h"
int cargarDatosdesdeArchivoTexto(char* patch,LinkedList* lista)
{
    FILE* pFile;
    int r=0;
    pFile=fopen(patch,"r");
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
        if(getString(emp->nombre,"\nIndique el nombre: ","\nError, el Nombre no debe tener mas de 30 caracteres \n",0,30,3))
        {
            ok=1;
        }
        if(ok==1 && getString(emp->apellido,"\nIndique el Apellido: ","\nError, el Apellido no debe tener mas de 30 caracteres \n",0,30,3)==0)
        {
            ok=0;
        }
        if(ok==1 && cargarSexo(&emp->sexo,"\nIndique el sexo(m/f): ","\nError, indique m(masculino)o f(femenino)\n",3)==0)
        {
            ok=0;
        }
        if(ok==1 && getFloat(&emp->salario,"\n Indique el salario: ","\nError,el salario debe ser mayo a 0\n",1,999999,3)==0)
        {
            ok=0;
        }

        if(ok==1 &&cargarFecha(&emp->FechadeContratacion,3,"\nIndique la fecha de contratacion: ")==0)
        {
            ok=0;
        }
        if(ok==1)
        {
            emp->id=lista->size+1;
            ll_add(lista,emp);
        }
        else{
            free(emp);
        }
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
                    printf("\n%5d %15s %15s %2c  %5.2f %2d/%2d/%d\n",empleado->id,empleado->nombre,empleado->apellido,empleado->sexo,empleado->salario,empleado->FechadeContratacion.dia,empleado->FechadeContratacion.mes,empleado->FechadeContratacion.anio);
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
int modificarEmpleado(LinkedList* lista)
{
    int r=0;
    int i,index,opcion=33;
    int len;
    eEmpleado* empleado,*aux;
    len=ll_len(lista);
    index=pedir_entero("\nIndique el Numero de ID: \n");
    for(i=0;i<len;i++)
    {
        empleado=(eEmpleado*)ll_get(lista,i);
        if(empleado->id==index)
        {
            aux=(eEmpleado*)malloc(sizeof(eEmpleado));
            *aux=*empleado;
            do{
                printf("Empleado ID: %d",aux->id);
                printf("\n%5d %15s %15s %2c  %5.2f %2d/%2d/%d\n",empleado->id,empleado->nombre,empleado->apellido,empleado->sexo,empleado->salario,empleado->FechadeContratacion.dia,empleado->FechadeContratacion.mes,empleado->FechadeContratacion.anio);
                get_String_soloNum(&opcion,"\n---Modificar--- \n 1-Nombre.\n 2-Apellido \n 3-Sexo \n 4-Salario \n 5-Fecha de Contratacion\n 6-Salir y Guardar Cambios efectuados\n 0-Atras\n","\n Error Indique solo Numeros\n",1);
                switch(opcion)
                {
                case 1:
                    if(getString(aux->nombre,"\nIndique el Nombre Nuevo: \n","Error el Nombre debe tener al menos 3 caracteres\n",3,227,3))
                    {
                        printf("\nDato Modificado con exito\n");
                        system("pause");

                    }
                    break;
                case 2:
                    if(getString(aux->apellido,"\nIndique el Apellido: ","\nError, el Apellido no debe tener mas de 30 caracteres \n",0,30,3))
                    {
                        printf("\nDato Modificado con exito\n");
                        system("pause");


                    }
                    break;
                case 3:
                    if(cargarSexo(&aux->sexo,"\nIndique el sexo(m/f): ","\nError, indique m(masculino)o f(femenino)\n",3))
                    {
                        printf("\nDato Modificado con exito\n");
                        system("pause");
                    }
                    break;
                case 4:
                    if(getFloat(&aux->salario,"\n Indique el salario: ","\nError,el salario debe ser mayo a 0\n",1,999999,3))
                    {
                        printf("\nDato Modificado con exito\n");
                        system("pause");
                    }
                    break;
                case 5:
                     if(cargarFecha(&aux->FechadeContratacion,3,"\nIndique la fecha de contratacion: "))
                     {
                        printf("\nDato Modificado con exito\n");
                        system("pause");
                     }
                    break;
                case 6:
                    *empleado=*aux;
                    free(aux);
                    opcion=0;
                }


            }while(opcion!=0);
        r=1;
        break;
        }
     }
    return r;
}
int guardarDatosArchivoTexto(char* path,LinkedList* lista)
{
    FILE* pfile;
    int ok=0;
    int len,i;
    char encabezado[]={"Id,Nombre,Apellido,Sexo,Salario,fecha de contratacion"};
    eEmpleado* aux;
    pfile=fopen(path,"w");
    if(pfile!=NULL)
    {
        len=ll_len(lista);
        fprintf(pfile,"%s\n",encabezado);
        for(i=0;i<len;i++)
        {
            aux=(eEmpleado*)ll_get(lista,i);
            fprintf(pfile,"%d,%s,%s,%c,%f,%d/%d/%d\n",aux->id,aux->nombre,aux->apellido,aux->sexo,aux->salario,aux->FechadeContratacion.dia,aux->FechadeContratacion.mes,aux->FechadeContratacion.anio);
        }
        ok=1;
    }
    fclose(pfile);
    return ok;
}
int guardarDatosArchivoBinario(char* path,LinkedList* lista)
{
    FILE* pfile;
    int ok=0;
    int len,i;
    char encabezado[]={"Id,Nombre,Apellido,Sexo,Salario,fecha de contratacion"};
    eEmpleado* aux;
    pfile=fopen(path,"wb");
    if(pfile!=NULL)
    {
        len=ll_len(lista);
        fprintf(pfile,"%s\n",encabezado);
        for(i=0;i<len;i++)
        {
            aux=(eEmpleado*)ll_get(lista,i);
            fprintf(pfile,"%d,%s,%s,%c,%f,%d/%d/%d\n",aux->id,aux->nombre,aux->apellido,aux->sexo,aux->salario,aux->FechadeContratacion.dia,aux->FechadeContratacion.mes,aux->FechadeContratacion.anio);
        }
        ok=1;
    }
    fclose(pfile);
    return ok;
}

