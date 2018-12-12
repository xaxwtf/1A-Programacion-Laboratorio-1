#ifndef Control_H_INCLUDED
#define Control_H_INCLUDED
int Alta(LinkedList* lista);
int crearYcompletar(LinkedList* listaCte,LinkedList* listaAb);
int buscarTodaslasOcurrencias(LinkedList* lista, int id);
int listar(eCliente* listaCte, eAbono* listaAb);
int generar(LinkedList* listaAb);
void imprimirListaFiltrada(LinkedList* listaCte,LinkedList*listaAb);
#endif // Control_H_INCLUDED
