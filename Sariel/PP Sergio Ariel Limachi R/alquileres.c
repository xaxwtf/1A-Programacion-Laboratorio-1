#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S_Ariel.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
void initAlquiler(eAlquiler *lista, int len,int dato)
{
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].codAlquiler=dato;

    }
}
int buscarPrimerLibreAlquiler(eAlquiler* lista,int len,int dato)
{
    int i;
    int r=-1;
    for(i=0;i<len;i++)
    {
        if(lista[i].codAlquiler==dato)
        {
            r=i;
            break;
        }
    }
    return r;
}
int alquilarJuego(eAlquiler *lista,int tam,eJuego *juegos,int tamj,eCliente *clientes, int tamCte,eFecha x, int codAlq)
{
    int ok=1;
    eAlquiler aux;
    int index;
    int r=buscarPrimerLibreAlquiler(lista,tam,-1);
    if(r!=-1)
    {
        imprimirJuegos(juegos,tamj);
        aux.codJuego=pedir_entero("\n Indique el codigo del Juego: ");
            index=buscarPrimerLibre(juegos,tamj,aux.codJuego);
            if(index==-1)
            {
                printf("\n el codigo indicado no existe\n");
                ok=0;
            }
        aux.codCliente=pedir_entero("\n Indique su codigo de cliente");
        index=buscarPrimerLibreCliente(clientes,tamCte,aux.codCliente);
        if(index==-1)
        {
            printf("\n el codigo indicado no existe\n");
            ok=0;
        }
        else{
            aux.codAlquiler=codAlq;
            aux.fecha=x;
            lista[r]=aux;

        }
    }
    else{
        ok=0;
    }
    return ok;
}


