#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "S_Ariel.h"
#include "eFecha.h"
#include "control.h"


int main()
{
    LinkedList* listaEmpleados;
    int opcion;
    listaEmpleados=ll_newLinkedList();
    do{
        get_String_soloNum(&opcion,"--Menu TP4--\n 1-Cargar datos desde Archivo de texto(text)\n 2-Cargar datos desde Archivo binario(bin)\n 3-Alta Empleado\n 4-Modificar Empleado\n 5-Baja Empleado\n 8-Guardar Datos en el Archivo de text(txt).\n 9-Guardar datos en Archivo Binario(bin)\n 0-Salir\n","Error,ingrese solo Numeros",1);
        switch(opcion)
        {
            case 1:
                ll_clear(listaEmpleados);
                if(cargarDatosdesdeArchivoTexto("data.csv",listaEmpleados)==0)
                {
                    printf("\nArchivo no econtrado, no se pudo abrir\n");
                }
                else{
                    printf("\nDatos cargados correctamente\n");
                }
                system("pause");
                break;
            case 2:
                ll_clear(listaEmpleados);
                if(cargarDatosdesdeArchivoBinario("data.bin",listaEmpleados)==0)
                {
                    printf("\nArchivo no econtrado, no se pudo abrir\n");
                }
                else{
                    printf("\nDatos cargados correctamente\n");
                }
                system("pause");
                break;
            case 3:
                if(altaEmpleado(listaEmpleados))
                {
                    printf("\nEmpleado cargado Correctamente\n");
                }
                else{
                    printf("\nError, no se pudo cargar el empleado\n");
                }
                system("pause");
                break;
            case 4:
                if(ll_isEmpty(listaEmpleados)!=1)
                {
                    if(modificarEmpleado(listaEmpleados))
                    {
                        printf("\nEmpleado Modificado Con exito\n");
                    }
                    else{
                        printf("\nError, no se ha modificado\n");
                    }
                }
                else{
                    printf("\nno Hay datos cargados\n");
                }
                system("pause");
                break;
            case 5:
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
            case 8:
                system("cls");
                if(guardarDatosArchivoTexto("data.csv",listaEmpleados))
                {
                    printf("\nDatos Guardados Correctamente\n");
                }
                else{
                    printf("\nError al cargar los datos\n");
                }
                system("pause");
                break;
            case 9:
                system("cls");
                if(guardarDatosArchivoBinario("data.bin",listaEmpleados))
                {
                    printf("\nDatos Guardados Correctamente\n");
                }
                else{
                    printf("\nError al cargar los datos\n");
                }
                system("pause");
                break;
        }
    }while(opcion!=0);
    return 0;
}
