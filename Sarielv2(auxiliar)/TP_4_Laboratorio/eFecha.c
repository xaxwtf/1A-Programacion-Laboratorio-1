#include "S_Ariel.h"
#include "eFecha.h"
#include <stdio.h>
int cargarFecha(eFecha* hoy,int intentos,char* mjs)
{
    int r=0;
    eFecha fecha;
    int num;
    int i;
    for(i=0;i<intentos;i++)
    {
        printf(mjs);
        if(get_String_soloNum(&num,"\nIndique el dia(de manera numerica(1-31): ","\nError,Indique solo Numeros\n",intentos))
        {
            if(num>0 && num<32)
            {
                r=1;
                fecha.dia=num;
            }
            else{
                printf("\nError,el dia indicado no existe\n");
            }
        }
        if(r==1&&get_String_soloNum(&num,"\nIndique el Mes(de manera numerica 1-12): ","\nError indique solo numeros",intentos))
        {
            if(num>0 && num<13)
            {
                fecha.mes=num;
            }
            else{
                printf("\nError,el mes indicado no existe\n");
                r=0;
            }
        }
        else{
            r=0;
        }
        if(r==1&&get_String_soloNum(&num,"\nIndique el Anio: ","\nError indique solo numeros",intentos))
        {
            if(num>0)
            {
                fecha.anio=num;
            }
            else{
                printf("\nError,el anio debe ser mayor a 0\n");
                r=0;
            }
        }
        else{
            r=0;
        }
        if(r==1)
        {
            *hoy=fecha;
            break;
        }
    }
    return r;
}
