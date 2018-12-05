#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#include "Clientes.h"
#include <string.h>
eCliente* nuevoCte()
{
    eCliente* aux;
    aux=(eCliente*)malloc(sizeof(eCliente));
    if(aux!=NULL)
    {
        aux->id=-1;
        aux->importe=0;
        strcpy(aux->nombre,"");
        strcpy(aux->telefono,"");
        aux->sexo='\0';
    }
    return aux;
}
int set_nombre(eCliente* x,char* nombre)
{
    int r=0;
    if(strlen(nombre)<21)
    {
        strcpy(x->nombre,nombre);
        r=1;
    }
    return r;
}
int set_sexo(eCliente* x, char sexo)
{
    int r=0;
    if(sexo=='M'||sexo=='F')
    {
        x->sexo=sexo;
        r=1;
    }
    return r;
}
int set_telefono(eCliente* x, char* tel)
{
    int r=0;
    if(strlen(tel)<22)
    {
        strcpy(x->telefono,tel);
        r=1;
    }
    return r;
}
int set_importe(eCliente* x,float importe)
{
    int r=0;
    if(importe>0)
    {
        x->importe=importe;
        r=1;
    }
    return r;
}
int cliente_get_Id(eCliente* x)
{
    int r=-1;
    if(x!=NULL)
    {
        r=x->id;
    }
    return r;
}
float cliente_get_importe(eCliente* x)
{
    float aux;
    if(x!=NULL)
    {
        aux=x->importe;
    }
    return aux;
}
