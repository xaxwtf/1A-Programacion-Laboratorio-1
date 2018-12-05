#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#include "Abono.h"
#include "Clientes.h"
#include "LinkedList.h"
#include "parser.h"
int Alta(LinkedList* lista)
{
    int r=0;
    FILE* pArchivo;
    char aux[30];
    pedir_cadena(aux,"\nIndique el Nombre del archivo: ");
    pArchivo=fopen(aux,"r");
    if(pArchivo!=NULL)
    {
        parser_EmployeeFromText(pArchivo,lista);
        r=1;
    }
    return r;
}
int crearYcompletar(LinkedList* listaCte, LinkedList* listaAb)
{
    int r=0;
    int i;
    int cont;
    float rrr;
    eCliente* aux;
    eAbono* nuevo;
    for(i=0;i<ll_len(listaCte);i++)
    {
        nuevo=nuevo_Abono();
        aux=(eCliente*)ll_get(listaCte,i);

        cont=buscarTodaslasOcurrencias(listaCte,cliente_get_Id(aux));
        abono_set_tipo(nuevo,cont);
        abono_set_idCliente(nuevo,aux->id);
        if(abono_get_tipo(nuevo)==1)
        {
            abono_set_importeFinal(nuevo,aux->importe);
        }
        else if(abono_get_tipo(nuevo)>1&& abono_get_tipo(nuevo)<5)
        {
            rrr=totalImporte(listaCte,aux->id);

        }



    }
    return r;
}
int buscarTodaslasOcurrencias(LinkedList* lista, int id)
{
    int r=0;
    int i;
    eCliente* aux;
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(eCliente*)ll_get(lista,i);
        if(cliente_get_Id(aux)==id)
        {
            r++;
        }
    }
    return r;
}
float totalImporte(LinkedList* lista, int id)
{
    float total=0;
    float mmm;
    int i;
    eCliente* aux;
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(eCliente*)ll_get(lista,i);
        if(aux->id==id)
        {
            mmm=cliente_get_importe(aux);
            total=total+mmm;
        }
    }
}
