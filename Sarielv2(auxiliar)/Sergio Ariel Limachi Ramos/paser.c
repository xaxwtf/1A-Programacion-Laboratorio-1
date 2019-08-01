#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paser.h"
#include "Partidas.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayList)
{
    char aux1[51];
    char aux2[51];
    char aux3[51];
    char aux4[51];
    char aux5[51];
    int num1,num2,num3,num4;
    ePartida* nuevo;
    int r=0;
    r=fscanf(pFile,"%[^\n]",aux1);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",aux1,aux2,aux3,aux4,aux5);
        if(r==5)
        {
            num1=atoi(aux1);
            num2=atoi(aux3);
            num3=atoi(aux4);
            num4=atoi(aux5);
            nuevo=new_partida(num1,aux2,num3,num4);
            if(nuevo!=NULL)
            {
                ll_add(pArrayList,nuevo);
            }
        }
    }while(!feof(pFile));
    return r;
}
