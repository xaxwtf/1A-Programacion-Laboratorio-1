#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "S_Ariel.h"
#include "control.h"


int main()
{
    LinkedList* listaEmpleados;
    int opcion;
    char nameFile[30];
    listaEmpleados=ll_newLinkedList();
    do{
        system("cls");
        get_String_soloNum(&opcion,"--Menu TP4--\n 1-Cargar datos desde Archivo de texto\n 2-Alta Empleado\n 3-Imprimir empleados\n 4-Baja Empleado\n 6-Calcular Sueldos \n 7-Guardar en archivo\n 0-Salir\n","Error,ingrese solo Numeros",1);
        switch(opcion)
        {
            case 1:
                ll_clear(listaEmpleados);
                if(cargarDatosdesdeArchivoTexto(listaEmpleados)==0)
                {
                    printf("\nArchivo no econtrado, no se pudo abrir\n");
                }
                else{
                    printf("\nDatos cargados correctamente\n");
                }
                system("pause");
                break;
            case 2:
                if(altaEmpleado(listaEmpleados))
                {
                    printf("\nEmpleado cargado Correctamente\n");
                }
                else{
                    printf("\nError, no se pudo cargar el empleado\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if(ll_isEmpty(listaEmpleados)!=1)
                {
                    imprimirEmpleados(listaEmpleados);
                }
                else
                {
                    printf("\nno hay datos\n ");
                }
                system("pause");
                break;
            case 4:
                if(ll_isEmpty(listaEmpleados)!=1)
                {
                    if(bajaEmpleado(listaEmpleados))
                    {
                        printf("\nSe ha dado de baja con exito\n");
                    }
                    else{
                        printf("\nNo se ha podido dar de baja el dato\n");
                    }

                }
                else{
                    printf("\nno Hay datos cargados\n");
                }
                system("pause");
                break;
            case 6:
                if(ll_isEmpty(listaEmpleados)!=1)
                {
                    if(calularsueldos(listaEmpleados)!=0)
                    {
                        printf("\nSueldos calculados\n");
                    }
                }
                else{
                    printf("\nno hay datos\n");
                }
                system("pause");
                break;
            case 7:
                if(guardarDatosArchivoTexto("info.csv",listaEmpleados))
                {
                    printf("Datos Guardados correctamente\n");
                }
                break;
        }
    }while(opcion!=0);
    return 0;
}
