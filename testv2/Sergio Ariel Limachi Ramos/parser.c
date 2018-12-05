#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
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
    char aux1[51];
    char aux2[51];
    char aux3[51];
    char aux4[51];
    char aux5[51];
    eCliente* nuevo;
    int r=0;
    r=fscanf(pFile,"%[^\n]",aux1);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",aux1,aux2,aux3,aux4);
        if(r==5)
        {
            nuevo=nuevoCte();
            nuevo->id=atoi(aux1);
            set_nombre(nuevo,aux2);
            set_sexo(nuevo,aux3[0]);
            set_telefono(nuevo,aux3);
            set_importe(nuevo,atof(aux5));
            if(nuevo!=NULL)
            {
                ll_add(pArrayListEmployee,nuevo);
            }
        }

    }while(!feof(pFile));
    return r;
}
