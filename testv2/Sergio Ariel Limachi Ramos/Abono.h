#ifndef Abono_H_INCLUDED
#define Abono_H_INCLUDED
typedef struct{
    int id;
    int tipo;
    int idCliente;
    float importeFinal;
}eAbono;
eAbono* nuevo_Abono();
int abono_set_id(eAbono* x, int id);
int abono_set_tipo(eAbono* x,int tipo);
int abono_set_idCliente(eAbono* x,int idCte);
int abono_get_tipo(eAbono* x);
int abono_set_importeFinal(eAbono* x, float total);
int ordenarXImporte(void* x,void* y);
int comparar(void* x, void* tipo);
#endif // Abono_H_INCLUDED
