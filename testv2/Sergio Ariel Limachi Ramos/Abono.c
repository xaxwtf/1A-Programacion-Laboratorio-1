#include "Clientes.h"
#include "S_Ariel.h"
#include "Abono.h"
#include <stdio.h>
#include <stdlib.h>
eAbono* nuevo_Abono()
{
    eAbono* nuevo=(eAbono*)malloc(sizeof(eAbono));
    if(nuevo!=NULL)
    {
        nuevo->id=-1;
        abono_set_tipo(nuevo,-1);
        abono_set_idCliente(nuevo,-1);
        nuevo->importeFinal=-1;
    }
    return nuevo;
}
int abono_set_tipo(eAbono* x,int tipo)
{
    int r=0;
    if(tipo>=0)
    {
        x->tipo=tipo;
        r=1;
    }
    return r;
}
int abono_set_idCliente(eAbono* x,int idCte)
{
    int r=0;
    if(idCte>=0)
    {
        x->idCliente=idCte;
        r=1;
    }
    return r;
}
int abono_set_importeFinal(eAbono* x, float total)
{
    int r=0;
    if(x!=NULL)
    {
        x->importeFinal=total;
        r=1;
    }
    return r;
}
int abono_set_id(eAbono* x, int id)
{
    int r=0;
    if(x!=NULL)
    {
        x->id=id;
        r=1;
    }
    return r;
}
int abono_get_tipo(eAbono* x)
{
    int r;
    if(x!=NULL)
    {
        r=x->tipo;
    }
    return r;
}
int ordenarXImporte(void* x,void* y)
{
    int r=0;
    eAbono* dato1=(eAbono*)x;
    eAbono* dato2=(eAbono*)y;
    if(dato1->importeFinal > dato2->importeFinal)
    {
            r=1;
    }
    if(dato1->importeFinal < dato2->importeFinal)
    {
        r=-1;
    }
    return r;
}
int comparar(void* x, void* tipo)
{
    int r=NULL;
    eAbono* lll=(eAbono*)x;
    int y=(int)tipo;
    if(lll->tipo==y)
    {
        r=0;
    }
    if(lll->tipo>y)
    {
        r=1;
    }
    if(lll->tipo<y)
    {
        r=-1;
    }
    return r;
}
