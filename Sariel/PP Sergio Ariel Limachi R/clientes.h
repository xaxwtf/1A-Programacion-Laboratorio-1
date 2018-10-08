#ifndef clientes_H_INCLUDED
#define clientes_H_INCLUDED
typedef struct{
    int codCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
}eCliente;

void initClientes(eCliente *lista, int len,int dato);
int buscarPrimerLibreCliente(eCliente* lista,int len,int dato);
#endif // clientes_H_INCLUDED
