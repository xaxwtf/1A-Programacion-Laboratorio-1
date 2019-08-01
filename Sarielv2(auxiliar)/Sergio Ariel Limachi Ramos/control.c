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
        printf("\%d     %s      %d    %d  %d    %5.2f  n",aux->id,aux->fecha,aux->tipoJuego,aux->cantJugadores,aux->durPartida,aux->costo);
        r=i;
    }
    return r;
}
