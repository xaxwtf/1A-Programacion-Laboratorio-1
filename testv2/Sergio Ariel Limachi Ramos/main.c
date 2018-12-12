#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#include "Abono.h"
#include "Clientes.h"
#include "LinkedList.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

int main()
{
    LinkedList* listaCtes;
    LinkedList* listaAbonos;
    listaCtes=ll_newLinkedList();
    listaAbonos=ll_newLinkedList();
    int opcion;
    do{
            get_String_soloNum(&opcion,"1-ALTAS\n2-CREAR Y COMPLETAR\n3-LISTAR\n4-GENERAr\n5-Imprimir Lista filtrada x tipo\n 0-Salir\n","\nError, indique solo numeros\n",1);
            switch(opcion)
            {
                case 1:
                    if(Alta(listaCtes))
                    {
                        printf("\nDatos Cargados correctamente\n");
                    }
                    else{
                        printf("\nError,Archivo no encontrado\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(crearYcompletar(listaCtes,listaAbonos))
                    {
                        printf("Datos generados Correctamente\n");
                    }
                    else{
                        printf("no se Pudieron generar datos\n");
                    }
                    system("pause");
                    break;
                case 3:
                    if(listar(listaCtes,listaAbonos)==0)
                    {
                        printf("Error NO hay datos cargados\n");

                    }
                    system("pause");
                    break;
                case 4:
                    if(generar(listaAbonos))
                    {
                        printf("Archivos generados con exito\n");
                    }
                    system("pause");
                    break;
                case 5:
                    imprimirListaFiltrada(listaCtes,listaAbonos);
                    system("pause");
                    break;


            }


    }while(opcion!=0);

    return 0;
}
