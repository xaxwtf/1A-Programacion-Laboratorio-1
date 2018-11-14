#include <stdio.h>
#include <stdlib.h>

#include "S_Ariel.h"

#include "juegos.h"

#include "clientes.h"

#include "alquileres.h"
#define LEN 1 //cant de clientes
#define LON 50 //cant de alquileres
#define TAM 10 //cant de juegos

int main()
{

    int opcion=23;
    int subOpcion=23;
    int codjuego=0;
    int codCliente=0;
    int codAlquiler=0;
    int r;
    eJuego juegos[TAM];
    eCliente clientes[LEN];
    eAlquiler alquileres[LON];
    initJuegos(juegos,TAM,-1);
    initClientes(clientes,LEN,-1);
    initAlquiler(alquileres,LON,-1);
    do{
        system("cls");
        if(!get_String_soloNum(&opcion,"----ALQUILERES DE JUEGOS----\n 1-JUEGOS \n 2-CLIENTES \n 3-ALQUILERES \n 4-INFORMES \n 0-SALIR \n ","Error,Indique solo numeros\n",1))
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
                            r=altaJuego(juegos,TAM,&codjuego);
                            if(r==1)
                            {
                                codjuego++;
                                printf("el juego se cargo corretamente\n");

                            }
                            else if(r==0){
                                printf("\n El dato no se ah guardado\n");
                            }
                            system("pause");
                            break;
                        case 2:
                            if(hayJuegos(juegos,TAM,-1)!=-1)
                            {
                                modificarJuego(juegos,TAM);
                            }
                            else{
                                printf("\n No hay datos Cargados\n");
                                system("pause");
                            }

                            break;
                        case 3:
                            if(hayJuegos(juegos,TAM,-1)!=-1)
                            {
                                if(bajaJuego(juegos,TAM)==1)
                                {
                                    printf("\n Se ha dado de Baja con exito el Juego\n");
                                    system("pause");
                                }
                            }
                            else{
                                printf("\n No hay datos Cargados\n");
                                system("pause");
                            }


                            break;
                        case 4:
                            if(hayJuegos(juegos,TAM,-1)!=-1)

                            {
                                ordenarJuegos(juegos,TAM);
                                imprimirJuegos(juegos,TAM);
                                system("pause");
                            }
                            else{
                                printf("\nNo hay Datos Cargados\n");
                                system("pause");
                            }
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
                            r=altaCliente(clientes,LEN,&codCliente);
                            if(r==1)
                            {
                                codCliente++;
                                printf("\nEl cliente se ha cargado correctamente \n");

                            }
                            else if(r==-1)
                            {
                                printf("\n Se ha alcanzado el limite de clientes a cargar\n");

                            }
                            system("pause");
                            break;
                        case 2:
                            if(hayClientes(clientes,LEN,-1)!=-1)
                            {
                                modificarCliente(clientes,LEN);
                            }
                            else{
                                printf("\n No hay datos cargados\n");
                                system("pause");
                            }

                            break;
                        case 3:
                            if(hayClientes(clientes,LEN,-1)!=-1)
                            {
                                if(bajaCliente(clientes,LEN)==1)
                                {
                                    printf("\n EL Cliente, Se ha dado de Baja con exito \n");
                                    system("pause");
                                }
                            }
                            else{
                                printf("\n No hay datos cargados\n");
                                system("pause");
                            }

                            break;
                        case 4:
                            if(hayClientes(clientes,LEN,-1)!=-1)
                            {
                                ordenarClientes(clientes,LEN);
                                imprimirClientes(clientes,LEN);
                                system("pause");
                            }
                            else{
                                printf("\n No hay datos cargados\n");
                                system("pause");
                            }

                            break;
                        }
                    }while(subOpcion!=0);

                break;
            case 3:
                r=alquilarJuego(alquileres,LON,juegos,TAM,clientes,LEN,&codAlquiler);
                if(r==1)
                {
                    codAlquiler++;
                    printf("\n Registro Creado, con exito\n");
                }
                else if(r==-1){
                    printf("\n no hay espacio para mas registros de alquiler\n");
                }
                system("pause");
                break;
            case 4:
                informes(juegos,TAM,clientes,LEN,alquileres,LON);
                break;
        }
    }while(opcion!=0);

    return 0;
}
