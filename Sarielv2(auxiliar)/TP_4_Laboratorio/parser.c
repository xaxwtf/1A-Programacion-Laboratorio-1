#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "LinkedList.h"
#include "S_Ariel.h"

#include <string.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char aux1[31];
    char aux2[31];
    char aux3[31];
    char aux4[31]={"0"};
    eEmpleado* nuevo;
    int r=0;
    r=fscanf(pFile,"%[^\n]",aux1);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^\n]",aux1,aux2,aux3);
        if(r==3)
        {
            nuevo=new_Empleado(aux1,aux2,aux3,aux4);
            if(nuevo!=NULL)
            {
                ll_add(pArrayListEmployee,nuevo);
            }
        }

    }while(!feof(pFile));
    return r;
}
