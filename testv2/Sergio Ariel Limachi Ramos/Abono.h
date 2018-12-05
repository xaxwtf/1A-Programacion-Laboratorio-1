#ifndef Abono_H_INCLUDED
#define Abono_H_INCLUDED
typedef struct{
    int id;
    int tipo;
    int idCliente;
    float importeFinal;
}eAbono;
eAbono* nuevo_Abono();
int abono_set_tipo(eAbono* x,int tipo);
int abono_set_idCliente(eAbono* x,int idCte);
int abono_get_tipo(eAbono* x);
#endif // Abono_H_INCLUDED
