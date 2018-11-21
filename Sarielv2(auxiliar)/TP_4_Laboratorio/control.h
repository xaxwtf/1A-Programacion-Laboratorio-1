#ifndef control_H_INCLUDED
#define control_H_INCLUDED
#include "LinkedList.h"
int cargarDatosdesdeArchivoTexto(char* patch,LinkedList* lista);
int cargarDatosdesdeArchivoBinario(char* patch,LinkedList* lista);
int altaEmpleado(LinkedList* lista);
int bajaEmpleado(LinkedList* lista);
int modificarEmpleado(LinkedList* lista);
int guardarDatosArchivoTexto(char* path,LinkedList* lista);
int guardarDatosArchivoBinario(char* path,LinkedList* lista);
#endif // control_H_INCLUDED
