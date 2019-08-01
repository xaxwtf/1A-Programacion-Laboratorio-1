#include "eFecha.h"
int fecha_set_dia(eFecha* x,int dia)
{
    int r=0;
    if(dia>0&& dia<32)
    {
        x->dia=dia;
        r=1;
    }
    return r;
}
int fecha_set_mes(eFecha* x,int mes)
{
    int r=0;
    if(mes>0&& mes<13)
    {
        x->mes=mes;
        r=1;
    }
    return r;
}
int fecha_set_anio(eFecha* x,int anio)
{
    int r=0;
    if(anio>0)
    {
        x->anio=anio;
        r=1;
    }
    return r;
}
