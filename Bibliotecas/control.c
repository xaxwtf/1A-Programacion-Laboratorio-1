#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paser.h"
#include "S_Ariel.h"
#include "Partidas.h"
int cargarDatosdeArchivoTexto(LinkedList* lista)
{
    FILE* pFile;
    int r=0;
    char aux[50];
    pedir_cadena(aux,"Indique el Nombre del Archivo: ");
    pFile=fopen(aux,"r");
    if(pFile!=NULL)
    {
        r=parser_EmployeeFromText(pFile,lista);

    }
    fclose(pFile);
    return r;
}
int listar(ePartida* lista)
{
    int r=0;
    int i;
    ePartida* aux;
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(ePartida*)ll_get(lista,i);
        printf("\n%d     %s      %d    %d   %d    %5.2f  \n",aux->id,aux->fecha,aux->tipoJuego,aux->cantJugadores,aux->durPartida,aux->costo);
        r=i;
    }
    return r;
}
void calcularPromedioxtipo(LinkedList* lista)
{

    float promedio,total,subtotal;
    int i,opcion,cont;
    ePartida* actual;
    do{

        get_String_soloNum(&opcion,"\n 1 Ping pong \n 2 Pool \n 3 Metegol \n 4 Dardos\n 0 atras\n ","error,indique solo Numeros",3);
        switch(opcion)
        {
        case 1:
            total=0;
            cont=0;
            for(i=1;i<ll_len(lista);i++)
            {
                actual=(ePartida*)ll_get(lista,i);
                if(actual->tipoJuego==0)
                {
                    subtotal=actual->cantJugadores;
                    total=total+subtotal;
                    cont++;
                }
            }
            promedio=total/cont;
            printf("\nel promedio de de Jugadores es: %0.2f\n",promedio);
            system("pause");
            break;
        case 2:
            total=0;
            cont=0;
            for(i=0;i<ll_len(lista);i++)
            {
                actual=(ePartida*)ll_get(lista,i);
                if(actual->tipoJuego==1)
                {
                    subtotal=actual->cantJugadores;
                    total=total+subtotal;
                    cont++;
                }
            }
            promedio=(float)total/cont;
            printf("\nel promedio de de Jugadores es: %d\n",promedio);
            system("pause");
            break;
        case 3:
            total=0;
            cont=0;
            for(i=0;i<ll_len(lista);i++)
            {
                actual=(ePartida*)ll_get(lista,i);
                if(actual->tipoJuego==2)
                {
                    subtotal=actual->cantJugadores;
                    total=total+subtotal;
                    cont++;
                }
            }
            promedio=total/cont;
            printf("\nel promedio de de Jugadores es: %d\n",promedio);
            system("pause");
            break;
        case 4:
            total=0;
            cont=0;
            for(i=0;i<ll_len(lista);i++)
            {
                actual=(ePartida*)ll_get(lista,i);
                if(actual->tipoJuego==3)
                {
                    subtotal=actual->cantJugadores;
                    total=total+subtotal;
                    cont++;
                }
            }
            promedio=total/cont;
            printf("\nel promedio de de Jugadores es: %d\n",promedio);
            system("pause");
            break;
        }
    }while(opcion!=0);
}
