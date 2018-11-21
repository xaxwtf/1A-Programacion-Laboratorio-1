#ifndef control_H_INCLUDED
#define control_H_INCLUDED
#include "LinkedList.h"
int cargarDatosdesdeArchivoTexto(LinkedList* lista);
int cargarDatosdesdeArchivoBinario(char* patch,LinkedList* lista);
int altaEmpleado(LinkedList* lista);
int imprimirEmpleados(LinkedList* lista);
int bajaEmpleado(LinkedList* lista);
int guardarDatosArchivoTexto(char* path,LinkedList* lista);
int calularsueldos(LinkedList* lista);
#endif // control_H_INCLUDED
