#include <stdio.h>
#include <stdlib.h>

#include "S_Ariel.h"

#include "juegos.h"

#include "clientes.h"

#include "alquileres.h"
#define LEN 50

#define TAM 10

int main()
{

    int opcion=23;
    int subOpcion=23;
    int codjuego=0;
    eJuego juegos[TAM];
    eCliente clientes[LEN];
    initJuegos(juegos,TAM,-1);
    initClientes(clientes,LEN,-1);
    do{
        system("cls");
        if(!get_String_soloNum(&opcion,"----ALQUILERES DE JUEGOS----\n 1-JUEGOS \n 2-CLIENTES \n 3-ALQUILERES \n 0-SALIR \n ","Error,Indique solo numeros",1))
        {
            system("pause");
        }
        switch(opcion)
        {
            case 1:
                do{
                    system("cls");
                    if(!get_String_soloNum(&subOpcion,"\n---JUEGOS---\n 1-Alta\n 2-Modificar \n 3-Baja \n 4-Listar \n 0-Atras\n","\n Error, indique solo numeros\n",1))
                    {
                        system("pause");
                    }
                    switch(subOpcion)
                    {
                        case 1:
                            if(altaJuego(juegos,TAM,1000+codjuego))
                            {
                                printf("el juego se cargo corretamente");
                                system("pause");
                            }
                            break;
                        case 2:
                            modificarJuego(juegos,TAM);
                            break;
                        case 3:
                            if(bajaJuego(juegos,TAM)==1)
                            {
                                printf("\n Se ha dado de Baja con exito el Juego\n");
                                system("pause");
                            }

                            break;
                        case 4:
                            ordenarJuegos(juegos,TAM);
                            imprimirJuegos(juegos,TAM);
                            break;

                    }


                }while(subOpcion!=0);
                break;
            case 2:
                   do{
                    system("cls");
                    if(!get_String_soloNum(&subOpcion,"\n---CLIENTES---\n 1-Alta\n 2-Modificar \n 3-Baja \n 4-Listar \n 0-Atras\n","\n Error, indique solo numeros\n",1))
                    {
                        system("pause");
                    }
                    switch(subOpcion)
                    {
                        case 1:
                            if(altaCliente(clientes,LEN,100+codjuego))
                            {
                                printf("El cliente se ha cargado correctamente");
                                system("pause");
                            }
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                    }
                    }while(subOpcion!=0);

                break;
            case 3:
                break;
        }
    }while(opcion!=0);

    return 0;
}
