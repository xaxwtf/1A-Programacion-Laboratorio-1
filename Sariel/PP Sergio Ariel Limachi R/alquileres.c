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
int alquilarJuego(eAlquiler *lista,int tam,eJuego *juegos,int tamj,eCliente *clientes, int tamCte,int* codAlq)
{
    int ok=0;
    eAlquiler aux;
    int index;
    int r=buscarPrimerLibreAlquiler(lista,tam,-1);
    if(r!=-1)
    {
        imprimirJuegos(juegos,tamj);
        if(get_String_soloNum(&aux.codJuego,"Indique el codigo del Juego: ","Error, indique solo Numeros",3))
        {
            ok=1;
            index=buscarPrimerLibre(juegos,tamj,aux.codJuego);
            if(index==-1)
            {
                printf("\n el codigo indicado no existe\n");
                ok=0;
            }
        }
        if((ok==1) && get_String_soloNum(&aux.codCliente,"Indique su codigo de cliente: ","Error, el Codigo de Cliente debe ser Numerico",3))
        {
            index=buscarPrimerLibreCliente(clientes,tamCte,aux.codCliente);
            if(index==-1)
            {
                printf("\n el codigo indicado no existe\n");
                ok=0;
            }
        }
        if((ok==1)&&cargarFecha(&aux.fecha,3))
        {
                aux.codAlquiler=*codAlq;
                lista[r]=aux;
        }
        else{
            printf("Error, reintente mas tarde");
            ok=0;
        }
    }
    else{
        ok=-1;
    }
    return ok;
}
void informes(eJuego *juegos, int tamjs,eCliente *clientes,int tamCte, eAlquiler *alquileres, int tamAlq)
{
    char opcion='z';
    int aux;
    do{
        system("cls");
        getChar(&opcion,"\nINFORMES \n a)Promedio y Total de los Importes de los Juegos alquilados \n b)la cantida de los juegos cuyo importe NO superan el promedio del item anterior \n c)Listar todos los clientes que alquilaron un juego determinado  \n d)Listar todos los juegos que fueron alquilados por un cliente determinado\n e)Listar el/los juegos menos alquilados\n f)listar el/los clientes que realizo mas alquileres \n g)listar todos los juegos alquilados en una fecha determinada \n h)listar los clientes que realizaron al menos un alquiler en una fecha determinada \n i)Listar todos los juegos ordenados por Improte\n j)listar todos los clientes ordenados por Apellido \n s)Atras\n"," ",'a','z');
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
                if(0==imprimirjuegoMenosAlq(alquileres,tamAlq,juegos,tamjs))
                {
                    printf("\nno hay datos \n");
                }
                system("pause");
                break;
            case 'f':
                if(0==imprimirClienteconMasalq(alquileres,tamAlq,clientes,tamCte))
                {
                    printf("\nNo hay datos\n");
                }
                system("pause");
                break;
            case 'g':
                if(0==imprimirjuegosxFecha(alquileres,tamAlq,juegos,tamjs))
                {
                    printf("\nno hay datos");
                }
                system("pause");
                break;
            case 'h':
                if(0==listarClientesxfecha(alquileres,tamAlq,clientes,tamCte))
                {
                    printf("\nNo hay datos\n");
                }
                system("pause");
                break;
            case 'i':
                ImprimirJuegosOrdxImporte(juegos,tamjs);
                system("pause");
                break;
            case 'j':
                impimirClientesOrdxApellido(clientes,tamCte);
                system("pause");
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
void ImprimirJuegosOrdxImporte(eJuego *lista, int tam)
{
    ordenarBurbugeo(lista,tam);
    imprimirJuegos(lista,tam);
}
void impimirClientesOrdxApellido(eCliente* lista,int tam)
{
    ordenacion_insercion(lista,tam);
    imprimirClientes(lista,tam);
}
void ordenarBurbugeo(eJuego *a, int len)
{
    int j;
    eJuego aux;
    int flagNoEstaOrdenado = 1;
    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < len; j++)
        {
            if (a[j].importe < a[j - 1].importe)
            {
                aux = a[j];
                a[j] = a[j - 1];
                a[j - 1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }

}
void ordenacion_insercion (eCliente * A, int N)
{
    int p, j;
    eCliente tmp;
    for (p = 1; p < N; p++)
    {
        tmp = A[p];
        j = p - 1;
        while ((j >= 0) && (strcmp(tmp.apellido , A[j].apellido)<0 ))
        {
            A[j + 1] = A[j];
            j--;
        }
    A[j + 1] = tmp;
    }
}
int ocurrenciasdeJuego(eAlquiler* lista,int tam,int idJuego)
{
    int r=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].codJuego==idJuego)
        {
            r++;
        }
    }
    return r;
}
int ocurrenciasdeCliente(eAlquiler* lista,int tam,int idCliente)
{
    int r=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].codCliente==idCliente)
        {
            r++;
        }
    }
    return r;
}
int imprimirjuegoMenosAlq(eAlquiler* alquileres,int tamAlq,eJuego* lista,int tam)
{
    int r=0;
    int jsMenosAlq;
    int dato;
    int i;
    jsMenosAlq=ocurrenciasdeJuego(alquileres,tamAlq,lista[0].codigo);
    for(i=1;i<tam;i++)
    {
        if(lista[i].codigo!=-1)
        {
            dato=ocurrenciasdeJuego(alquileres,tamAlq,lista[i].codigo);
            if(jsMenosAlq>dato)
            {
                jsMenosAlq=dato;
            }
        }
    }
    for(i=0;i<tam;i++)
    {
        if(lista[i].codigo!=-1)
        {
            dato=ocurrenciasdeJuego(alquileres,tamAlq,lista[i].codigo);
            if(jsMenosAlq==dato)
            {
                imprimirJuego(lista[i]);
                r++;
            }
        }
    }
    return r;
}
int imprimirClienteconMasalq(eAlquiler* alquileres,int tamAlq,eCliente* lista,int tam)
{
    int r=0;
    int ctemasAlq;
    int dato;
    int i;
    ctemasAlq=ocurrenciasdeCliente(alquileres,tamAlq,lista[0].codCliente);
    for(i=1;i<tam;i++)
    {
        if(lista[i].codCliente!=-1)
        {
            dato=ocurrenciasdeCliente(alquileres,tamAlq,lista[i].codCliente);
            if(ctemasAlq<dato)
            {
                ctemasAlq=dato;
            }
        }
    }
    for(i=0;i<tam;i++)
    {
        if(lista[i].codCliente!=-1)
        {
            dato=ocurrenciasdeCliente(alquileres,tamAlq,lista[i].codCliente);
            if(ctemasAlq==dato)
            {
                imprimirCliente(lista[i]);
                r++;
            }
        }
    }
    return r;
}
int cargarFecha(eFecha* hoy,int intentos)
{
    int r=0;
    eFecha fecha;
    int num;
    int i;
    for(i=0;i<intentos;i++)
    {
        if(get_String_soloNum(&num,"\nIndique el dia(de manera numerica(1-31): ","\nError,Indique solo Numeros\n",3))
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
        if(r==1&&get_String_soloNum(&num,"\nIndique el Mes(de manera numerica 1-12): ","\nError indique solo numeros",3))
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
        if(r==1&&get_String_soloNum(&num,"\nIndique el Anio: ","\nError indique solo numeros",3))
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
int imprimirjuegosxFecha(eAlquiler* alquileres,int tamAlq,eJuego* juegos,int tamJs)
{
    int r=0;
    int i;
    eFecha dato;
    int index;
    eFecha aux;

    if(cargarFecha(&dato,3))
    {
        printf("\nJuegos Alquilados ---fecha: %2d/%2d/%5d\n",dato.dia,dato.mes,dato.anio);
        for(i=0;i<tamAlq;i++)
        {
            aux=alquileres[i].fecha;
            if((aux.dia==dato.dia&&aux.mes==dato.mes)&&(aux.anio==dato.anio))
            {
                index=buscarPrimerLibre(juegos,tamJs,alquileres[i].codJuego);
                r++;
                imprimirJuego(juegos[index]);
            }
        }
    }
    return r;
}
int listarClientesxfecha(eAlquiler* alquileres,int tamAlq,eCliente* clientes,int tamCte)
{
    int r=0;
    eFecha hoy;
    cargarFecha(&hoy,3);
    int i;
    int index;
    printf("fecha:%2d/%2d/%d",hoy.dia,hoy.mes,hoy.anio);
    for(i=0;i<tamAlq;i++)
    {
        if(alquileres[i].fecha.dia==hoy.dia&&alquileres[i].fecha.mes==hoy.mes&&alquileres[i].fecha.anio==hoy.anio)
        {
            index=buscarPrimerLibreCliente(clientes,tamCte,alquileres[i].codCliente);
            imprimirCliente(clientes[index]);
            r++;
        }

    }
    return r;
}
