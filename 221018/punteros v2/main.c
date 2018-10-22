#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S_Ariel.h"

typedef struct{
    int indice;
    char marca[25];
    int capacidad;
    float precio;
}ePendrive;

int cargar_Pendrive(ePendrive *pen);
int cargar_Pendrive_Param(ePendrive *pen, int codigo, char marca[],int capacidad,float precio);
void mostrar_Pendrive(ePendrive *pen);
int main()
{
    ePendrive pendrive;
    if(cargar_Pendrive(&pendrive))
    {
        printf("\nSe Cargo con exito el Producto\n");
        mostrar_Pendrive(&pendrive);

    }
    else{
        printf("\n Error, No se cargo el Producto");
    }
    return 0;
}
int cargar_Pendrive(ePendrive *pen)
{
    ePendrive aux;
    int r=0;
    if(pen!=NULL)
    {
        r=1;
        if(getInt(&aux.indice,"indique la codigo: ","Error el Codigo debe ser mayo a 0",1,9999999,3)==0)
        {
            r=0;
        }
        if(r!=0 && getString(aux.marca," \n Indique la marca del Pendrive: ","\nError,El Nombre debe tener al menos 2 caracteres\n",2,999999,3)==-1)
        {
            r=0;
        }
        if(r!=0 && getInt(&aux.capacidad,"indique la capacidad: ","Error,La capacidad Minima es 2 GB",2,9999999,3)==0)
        {
            r=0;
        }
        if(r!=0 && getFloat(&aux.precio,"indique el Precio del Producto: ","Error, el precio no puede ser menor a 1",1,9999999999999,3)==-1)
        {
            r=0;
        }
        if(r==1)
        {
            *pen=aux;
        }
    }
    return r;
}
void mostrar_Pendrive(ePendrive *pen)
{
    printf("%d %s  %d  %0.2f \n",pen->indice,pen->marca,pen->capacidad,pen->precio);
}
int cargar_Pendrive_Param(ePendrive *pen, int codigo, char marca[],int capacidad,float precio)
{
    int ok=0;
    if(pen != NULL)
    {
        pen->indice=codigo;
        strcpy(pen->marca,marca);
        pen->capacidad=capacidad;
        pen->precio=precio;
        ok=1;
    }
    return ok;
}
