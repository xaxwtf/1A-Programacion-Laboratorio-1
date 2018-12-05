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
            get_String_soloNum(&opcion,"1-ALTAS\n2-CREAR Y COMPLETAR\n3-LISTAR\n4-GENERAr\n0-Salir\n","\nError, indique solo numeros\n",1);
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

                    break;
                case 3:
                    break;
                case 4:
                    break;
            }


    }while(opcion!=0);

    return 0;
}
