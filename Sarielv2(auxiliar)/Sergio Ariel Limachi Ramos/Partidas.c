#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Partidas.h"
int partida_set_id(ePartida* x,int id)
{
    int r=0;
    if(id>0)
    {
        x->id=id;
        r=1;
    }
    return r;
}
int partida_set_cantJugadores(ePartida* x,int cantJ)
{
    int r=0;
    if(cantJ>0)
    {
        x->cantJugadores=cantJ;
        r=1;
    }
    return r;
}
int partida_set_duracionPart(ePartida* x,int dur)
{
    int r=0;
    if(dur>0)
    {
        x->durPartida=dur;
        r=1;
    }
    return r;
}
int partida_set_fecha(ePartida* x,char fecha[])
{
    int r=1;

    strcpy(x->fecha,fecha);
    return r;
}
int partida_set_tipo(ePartida* x,int tipe)
{
    int r=0;
    if(tipe>=0)
    {
        x->tipoJuego=tipe;
        r=1;
    }
    return r;
}
ePartida* new_partida(int id, char fecha[],int cantj,int tipo, int duracion)
{
    ePartida* nuevo;
    int ok=1;
    nuevo=(ePartida*)malloc(sizeof(ePartida));
    if(nuevo!=NULL)
    {
        partida_set_id(nuevo,id);
        partida_set_fecha(nuevo,fecha);
        partida_set_cantJugadores(nuevo,cantj);
        partida_set_tipo(nuevo,tipo);
        partida_set_duracionPart(nuevo,duracion);
    }
    return nuevo;
}
