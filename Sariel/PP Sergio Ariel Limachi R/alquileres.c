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
void informes(eJuego *juegos, int tamjs,eCliente *clientes,int tamCte, eAlquiler *alquileres, int tamAlq)
{
    char opcion='z';
    int aux;
    do{
        system("cls");
        getChar(&opcion,"\nINFORMES \n a)Promedio y Total de los Importes de los Juegos alquilados \n b)la cantida de los juegos cuyo importe NO superan el promedio del item anterior \n c)Listar todos los clientes que alquilaron un juego determinado  \n d)Listar todos los juegos que fueron alquilados por un cliente determinado\n e)Listar el/losjuegos menos alquilados\n f)listar el/los clientes que realizo mas alquileres \n g)listar todos los juegos alquilados en una fecha determinada \n h)listar los clientes que realizaron al menos un alquiler en una fecha determinada \n i)Listar todos los juegos ordenados por Improte\n j)listar todos los clientes ordenados por Apellido \n s)Atras\n"," ",'a','z');
        switch(opcion)
        {
            case 'a':
                mostrarPromYtotal(alquileres,tamAlq,juegos,tamjs);
                system("pause");
                break;
            case 'b':
                aux=contJuegosDeImpMenorAlprom(alquileres,tamAlq,juegos,tamjs);
                printf("\nExisten %d Juegos cuyo Importe no supera el Promedio\n",aux);
                system("pause");
                break;
            case 'c':
                imprimirCtesSegunJuego(juegos,tamjs,clientes,tamCte,alquileres,tamAlq);
                system("pause");
                break;
            case 'd':
                imprimirJuegosSegunCliente(juegos,tamjs,clientes,tamCte,alquileres,tamAlq);
                system("pause");
                break;
            case 'e':

                break;
            case 'f':
                break;
            case 'g':
                break;
            case 'h':
                break;
            case 'i':
                listarJuegos(juegos,tamjs);
                system("pause");
                break;
            case 'j':
                break;


        }
    }while(opcion!='s');
}
float obtenerTotalJuegosAlquilados(eAlquiler *lista,int tamAlq, eJuego *juegos,int tamj)
{
    int i;
    float total=0;
    for(i=0;i<tamAlq;i++)
    {
        if(lista[i].codAlquiler!=-1)
        {
            total=total+cargarImportejuego(juegos,tamj,lista[i].codJuego);
        }
    }
    return total;
}
float cargarImportejuego(eJuego *lista, int tam,int codAlq)
{
    int i;
    float r;
    for(i=0;i<tam;i++)
    {
        if(codAlq==lista[i].codigo)
        {
            r=lista[i].importe;
            break;
        }

    }
    return r;
}
float obtenerPromedioJuegosAlquilados(eAlquiler *lista,int tam,float Total)
{
    int i;
    int k=0;
    float prom;
    for(i=0;i<tam;i++)
    {
        if(lista[i].codAlquiler!=-1)
        {
          k++;
        }
    }
    prom=Total/(float)k;
    return prom;
}
void mostrarPromYtotal(eAlquiler *alquileres, int tamAlq,eJuego *juegos, int tamJs)
{
    float total=obtenerTotalJuegosAlquilados(alquileres,tamAlq,juegos,tamJs);
    float prom=obtenerPromedioJuegosAlquilados(alquileres,tamAlq,total);
    printf("\n El total importes es %2.f \n Con un Promedio de: %2.f\n",total,prom);
}
int contJuegosDeImpMenorAlprom(eAlquiler *alquileres, int tamAlq, eJuego *juegos, int tam)
{
    int i;
    int k=0;
    float total=obtenerTotalJuegosAlquilados(alquileres,tamAlq,juegos,tam);
    float promedio=obtenerPromedioJuegosAlquilados(alquileres,tamAlq,total);
    for(i=0;i<tam;i++)
    {
        if(juegos[i].importe<=promedio&&juegos[i].codigo!=-1)
        {
          k++;
        }
    }
    return k;
}
void imprimirCtesSegunJuego(eJuego *juegos,int tamJs,eCliente *clientes,int tamCte,eAlquiler *lista, int tamLis)
{
    int dato;
    int i,j;
    int r;
        printf("\nJuegos\n ");
        imprimirJuegos(juegos,tamJs);
        dato=pedir_entero("\nIndique un codigo de Juego: ");
        r=buscarPrimerLibre(juegos,tamJs,dato);
        if(r!=-1)
        {
            for(i=0;i<tamLis;i++)
            {
                if(dato==lista[i].codJuego)
                {
                    for(j=0;j<tamCte;j++)
                    {
                        if(lista[i].codCliente==clientes[j].codCliente)
                        {
                            imprimirCliente(clientes[j]);
                        }
                    }
                }
            }

        }
        else{
            printf("\n el codigo indicado no existe\n");
        }



}
void imprimirJuegosSegunCliente(eJuego *juegos,int tamJs,eCliente *clientes,int tamCte,eAlquiler *lista, int tamLis)
{
    int dato;
    int i,j;
    int r;
        printf("\nClientes: \n ");
        dato=pedir_entero("\nIndique un codigo de Cliente: ");
        r=buscarPrimerLibreCliente(clientes,tamCte,dato);
        if(r!=-1)
        {
            for(i=0;i<tamLis;i++)
            {
                if(dato==lista[i].codCliente)
                {
                    for(j=0;j<tamJs;j++)
                    {
                        if(lista[i].codJuego==juegos[j].codigo)
                        {
                            imprimirJuego(juegos[j]);
                        }
                    }
                }
            }

        }
        else{
            printf("\n el codigo indicado no existe\n");
        }
}
void listarJuegos(eJuego *lista, int tam)
{
    ordenarBurbugeo(lista,tam);
    imprimirJuegos(lista,tam);
}
void ordenarBurbugeo(eJuego *lista, int tam)
{
    int i,j;
    eJuego aux;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].importe<lista[j].importe)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}
