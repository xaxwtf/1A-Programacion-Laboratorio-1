#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#include "juegos.h"
#include "clientes.h"
void initJuegos(eJuego *lista, int len,int dato)
{
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].codigo=dato;

    }
}
int buscarPrimerLibre(eJuego* lista,int len,int dato)
{
    int i;
    int r=-1;
    for(i=0;i<len;i++)
    {
        if(lista[i].codigo==dato)
        {
            r=i;
            break;
        }
    }
    return r;
}
int altaJuego(eJuego *lista,int tam,int codigo)
{
    eJuego aux;
    int ok=1;
    int r;
    r=buscarPrimerLibre(lista,tam,-1);
    if(r==-1)
    {
        printf("\n Ha alcanzado el Limite de Juegos a cargar");
    }
    else
    {
        if(getString(aux.descripcion,"\n Indique el nombre del juego: ","Error, el Nombre del juego no debe tener mas de 50 caracteres",0,50,3)==-1)
            {
                ok=0;
            }
        if(ok==1&&(getFloat(&aux.importe,"indique el Precio de Alquieres del Producto: ","Error,el importe debe ser mayor a 0",1,999999999999,3)==0))
        {
            aux.codigo=codigo;
            lista[r]=aux;
        }
        else
        {
            ok=0;
        }
    }
    return ok;
}
void modificarJuego(eJuego *lista,int tam)
{
    int opcion;
    int dato=pedir_entero("\n Indique el codigo de Juego");
    int r;
    r=buscarPrimerLibre(lista,tam,dato);
    if(r!=-1)
    {

        do{
            system("cls");
            printf("\njuego: \n Codigo    Nombre       Importe ");
            imprimirJuego(lista[r]);
            dato=get_String_soloNum(&opcion,"\n 1-Modificar Nombre\n 2-Modificar Importe \n 0-atras","\n Error, Solo indique numeros",1);
            switch(opcion)
            {
                case 1:
                    if(getString(lista[r].descripcion,"\n Indique el Nuevo Nombre: ","\n Error,el nombre no debe tener mas de 50 caracteres",1,50,3)==0)
                    {
                        printf("\n Se ha Modificado el dato con exito\n");
                        system("pause");
                    }
                    break;
                case 2:
                    if(getFloat(&lista[r].importe,"\n Indique el Nuevo Importe: ","\n Error,el Importe debe ser mayo a 0",1,9999999999999,3)==0)
                    {
                        printf("\n Se ha Modificado el dato con exito");
                        system("pause");
                    }
                    break;
            }

        }while(opcion!=0);

    }
    else{
        printf("\nEl Codigo Indicado No existe\n");
        system("pause");
    }


}
void imprimirJuego(eJuego juego)
{
     printf("\n %d      %5s    %2.f",juego.codigo,juego.descripcion,juego.importe);
}
int bajaJuego(eJuego *lista,int tam)
{
    int ok=0;
    int flag=0;
    char c;
    int dato=pedir_entero("\n Indique el codigo de juego: ");
    int r;
    r=buscarPrimerLibre(lista,tam,dato);
    if(r!=-1)
    {
        do{
            printf("\nJuego encontrado: ");
            imprimirJuego(lista[r]);
            getChar(&c,"\n Seguro que desea dar de Baja este juego(s/n) "," ",'a','z');
            switch(c)
            {
                case 's':
                    lista[r].codigo=-1;
                    ok=1;
                    flag=1;
                    break;
                case 'n':
                    flag=1;
                    break;
            }


        }while(flag!=1);


    }
    else{
        printf("\n El Codigo Indicado No existe\n");
        system("pause");
    }
    return ok;
}
void imprimirJuegos(eJuego *lista,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].codigo!=-1)
        {
            imprimirJuego(lista[i]);
        }

    }
}
void ordenarJuegos(eJuego *lista,int tam)
{
    int i,j;
    eJuego aux;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
            {
                if(lista[i].importe > lista[j].importe)
                {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                }
                    else if(lista[i].importe==lista[j].importe && strcmp(lista[i].descripcion,lista[j].descripcion)>0)
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
            }

    }

}
