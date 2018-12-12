#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#include "Abono.h"
#include "Clientes.h"
#include "LinkedList.h"
#include "parser.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2
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
    int i,k;
    int cont;
    float importeParcial;
    float importeTotal;
    eCliente* aux;
    eCliente* actual;
    eAbono* nuevo;
    for(i=0;i<ll_len(listaCte);i++)
    {
        cont=0;
        importeParcial=0;
        importeTotal=0;
        actual=(eCliente*)ll_get(listaCte,i);
        if(buscarTodaslasOcurrencias(listaAb,actual->id)==0)
        {
            nuevo=nuevo_Abono();
            if(nuevo!=NULL)
            {
                abono_set_id(nuevo,(1+ll_len(listaAb)));
                abono_set_idCliente(nuevo,cliente_get_Id(actual));
                for(k=0;k<ll_len(listaCte);k++)
                {
                    aux=(eCliente*)ll_get(listaCte,k);
                    if(actual->id==aux->id)
                    {
                        cont++;
                        importeParcial=cliente_get_importe(aux);
                        importeTotal=importeTotal+importeParcial;
                    }

                }
                if(cont==1)
                {
                    abono_set_tipo(nuevo,PERSONAL);
                    abono_set_importeFinal(nuevo,importeTotal);
                }
                else if(cont>1&&cont<5)
                {
                    abono_set_tipo(nuevo,FAMILIAR);
                    importeParcial=importeTotal;
                    importeTotal=importeTotal-(importeParcial*0.10);
                    abono_set_importeFinal(nuevo,importeTotal);
                }
                else if(cont>4)
                {
                    abono_set_tipo(nuevo,CORPORATIVO);
                    importeParcial=importeTotal;
                    importeTotal=importeTotal-(importeParcial*0.20);
                    abono_set_importeFinal(nuevo,importeTotal);
                }
                ll_add(listaAb,nuevo);
                r=1;
            }

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
int listar(eCliente* listaCte, eAbono* listaAb)
{
    int r=0;
    int i,k;
    eCliente* aux;
    eAbono* abono;
    ll_sort(listaAb,ordenarXImporte,1);
        for(i=0;i<ll_len(listaAb);i++)
        {
            abono=(eAbono*)ll_get(listaAb,i);
            printf("\nID ABONO: %d  IMPORTE FINAL:%4.2f TIPO: %d \n",abono->id,abono->importeFinal,abono->tipo);
            for(k=0;k<ll_len(listaCte);k++)
            {
                aux=(eCliente*)ll_get(listaCte,k);
                if(aux->id==abono->idCliente)
                {
                    printf("%d  %20s %c  %10s %5.2f \n",aux->id,aux->nombre,aux->sexo,aux->telefono,aux->importe);
                }
            }
            r=i;
        }
        return r;
}
int generar(LinkedList* listaAb)
{

    FILE* pfile;
    int ok=0;
    int len,i;
    char encabezado[]={"Id,Tipo,idCliente,ImporteFinal"};
    eAbono* aux;
    pfile=fopen("abonos.csv","w");
    if(pfile!=NULL)
    {
        len=ll_len(listaAb);
        fprintf(pfile,"%s\n",encabezado);
        for(i=0;i<len;i++)
        {
            aux=(eAbono*)ll_get(listaAb,i);
            fprintf(pfile,"%d,%d,%d,%0.2f\n",aux->id,aux->tipo,aux->idCliente,aux->importeFinal);
        }
        ok=1;
    }
    fclose(pfile);

    pfile=fopen("abonos.bin","wb");
    if(pfile!=NULL)
    {
        len=ll_len(listaAb);
        fprintf(pfile,"%s\n",encabezado);
        for(i=0;i<len;i++)
        {
            aux=(eAbono*)ll_get(listaAb,i);
            fprintf(pfile,"%d,%d,%d,%0.2f\n",aux->id,aux->tipo,aux->idCliente,aux->importeFinal);
        }
        ok=1;
    }
    fclose(pfile);
    return ok;
}
void imprimirListaFiltrada(LinkedList* listaCte,LinkedList*listaAb)
{
    int r;
    LinkedList* listaFiltrada;
    get_String_soloNum(&r,"indique el Tipo: ","indique solo Numeros",3);
    listaFiltrada=ll_Filter(listaAb,comparar,r);
    listar(listaCte,listaFiltrada);
}
