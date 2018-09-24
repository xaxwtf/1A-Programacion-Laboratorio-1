#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#define TAM 5

int main()
{
    int opcion = 25;
    int resl;
    eEmployee empleado[TAM];
    initEmployees(empleado,TAM);
    do{
            //system("cls");
            resl=getInt(&opcion,"----TP Nro 2----\n 1-ALTAS \n 2-MODIFICAR \n 3-BAJA \n 4-INFORMAR \n 0-SALIR \n\n"," ",0,4);
            switch(opcion)
            {
                case 1:

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
