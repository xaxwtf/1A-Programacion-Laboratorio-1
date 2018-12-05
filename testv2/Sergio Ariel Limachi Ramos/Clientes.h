#ifndef Clientes_H_INCLUDED
#define Clientes_H_INCLUDED
typedef struct{
    int id;
    char nombre[51];
    char sexo;
    char telefono[21];
    float importe;
}eCliente;
eCliente* nuevoCte();
int set_nombre(eCliente* x,char* nombre);
int set_sexo(eCliente* x,char sexo);
int set_telefono(eCliente* x, char* tel);
int set_importe(eCliente* x,float importe);
int cliente_get_Id(eCliente* x);
#endif // Clientes_H_INCLUDED
