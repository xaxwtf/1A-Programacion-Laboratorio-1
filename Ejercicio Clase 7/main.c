#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S_Ariel.h"
#define  TAM 200

int main()
{
    char nombres [TAM][30];
    char apellido [TAM][30];
    int legajo [TAM];
    int edad[TAM];
    int opcion=23;
    int rels;
    int valor;
    int aux;
    int i;
    inizArray(legajo,TAM,-1,0);

    do{
         for( i=0;i<TAM;i++)
        {
            if(legajo[i]!=-1)
            {
                printf("%s        %10s    %5d     %5d \n",nombres[i],apellido[i],legajo[i],edad[i]);

            }
        }
        rels=getInt(&opcion,"----Clase 7 ABM---- \n 1-ALTA. \n 2-BAJA \n 3-MODIFICAR. \n 0-Salir \n \n","\n El Numero Indicado no es Valido\n",0,3);

        switch(opcion)
        {
            case 1:
                rels=busPrimeraOcurrencia(legajo,TAM,-1);
                if(rels!=-1)
                {
                    if(getString(nombres[rels],"\n Indique Un Nombre: \n ","\n Error, el Nombre Ingresado exede el Nro de caracteres Permitidos \n ",0,29)==-1)
                    {
                        break;
                    }
                    if(getString(apellido[rels],"\n Indique EL Apellido: \n","\n Error, el Apellido Ingresado exede el nro Max de caracteres permitidos",0,29)==-1)
                    {
                        break;
                    }
                    if(getInt(&legajo[rels],"\n indique el Numero de legajo: \n ","\n el legajo Indicado no es Valido\n",0,200)==-1)
                    {
                        break;
                    }
                    if(getInt(&edad[rels],"\n indique la Edad: \n ","la edad Indicada no es valida",1,100)==-1)
                    {
                        break;
                    }
                }
                else{
                    printf("\n Se Ha alcanzado el Maximo de Datos a Cargar");
                }

                break;
            case 2:
                aux=getInt(&valor,"\n indique un nro de legajo: \n","\n el Legajo indicado no es Valido\n",1,TAM);
                rels=busPrimeraOcurrencia(legajo,TAM,valor);
                if(rels==-1)
                {
                    printf("\n el Legajo Indicado No existe\n ");
                }
                else{
                    strcpy(nombres[rels]," ");
                    strcpy(apellido[rels]," ");
                    legajo[rels]=-1;
                    edad[rels]=0;
                }

                break;
            case 3:
                aux=getInt(&valor,"\n-MODIFICAR \n indique el Numero de legajo: \n","el Legajo Indicano No es Valido\n ",1,TAM);
                rels=busPrimeraOcurrencia(legajo,TAM,valor);
                if(rels!=-1)
                {
                    do{
                        printf("Datos Obetenidos del legajo Nro:%d \n Nombre: %s\n Apellido: %s \n Edad: %d",legajo[rels],nombres[rels],apellido[rels],edad[rels]);
                        aux=getInt(&valor,"\n -MODIFICAR- \n 1-Nombre \n 2-apellido \n 3-Edad \n 0-salir"," ",0,3);
                        switch(valor)
                        {
                            case 1:getString(&nombres[rels],"Indique un Nombre","Error, el Nombre debe tener al menos 2 caracteres",2,29);
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                        }

                    }while(valor!=0);
                }
                break;
        }



    }while(opcion!=0);

    return 0;
}
