#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#include "juegos.h"
#include "clientes.h"
void initClientes(eCliente *lista, int len,int dato)
{
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].codCliente=dato;

    }
}
int buscarPrimerLibreCliente(eCliente* lista,int len,int dato)
{
    int i;
    int r=-1;
    for(i=0;i<len;i++)
    {
        if(lista[i].codCliente==dato)
        {
            r=i;
            break;
        }
    }
    return r;
}
int altaCliente(eCliente *lista,int tam,int codigo)
{
    eCliente aux;
    int ok=1;
    int r;
    r=buscarPrimerLibre(lista,tam,-1);
    if(r==-1)
    {
        printf("\n Ha alcanzado el Limite de cliente a cargar");
    }
    else
    {
        if(getString(aux.nombre,"\n Indique su nombre : ","Error, el Nombre no debe tener mas de 50 caracteres",0,50,3)==-1)
            {
                ok=0;
            }
        if(ok==1&&(getString(aux.apellido,"\n Indique el Apellido: ","Error, el Apellido no debe tener mas de 50 caracteres",0,50,3)==-1))
            {
                ok=0;
            }

        cargarSexo(&aux.sexo,"\n indique el sexo","Error, solo se aceptan f o m");
        if(ok==1&&(getString(aux.domicilio,"\n Indique su Domicilio","\nError, el Domicilio no debe ter mas de 50 caracteres\n",1,50,3)))
        {
            aux.codCliente=codigo;
            lista[r]=aux;
        }
        else
        {
            ok=0;
        }
    }
    return ok;
}
void cargarSexo(char *dato,char mensaje[],char emsj[])
{
    char aux;
    int flag=0;
    do{
        printf(mensaje);
        fflush(stdin);
        scanf("%c",&aux);
        if(aux=='m'||aux=='f')
        {
            *dato=aux;
            flag=1;
        }

    }while(flag!=1);
}
