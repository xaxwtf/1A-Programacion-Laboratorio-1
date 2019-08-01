#include <stdio.h>
#include <stdlib.h>
#include "control.h"
#include "Partidas.h"
#include "S_Ariel.h"
#include "LinkedList.h"
int main()
{
    LinkedList* partidas;
    int opcion=99;
    partidas=ll_newLinkedList();
    do{
        get_String_soloNum(&opcion,"__FINAL__\n 1- Cargar Archivo\n 2- Imprimir Pantalla \n 3-Cantidad de jugadores promedio x tipo \n 4- Generar Archivo de costos\n","\nerror,indique solo numeros\n",1);
        switch(opcion)
        {
        case 1:
            if(cargarDatosdeArchivoTexto(partidas)==0)
            {
                printf("\nerror, no se encontro el archivo\n");
                system("pause");
            }
            break;
        case 2:
            if(listar(partidas)==0)
            {
                printf("\n No hay partidas para mostrar\n");
                system("pause");
            }

            break;
        case 3:
            break;
        case 4:
            break;

        }



    }while(opcion!=0);

    return 0;
}
