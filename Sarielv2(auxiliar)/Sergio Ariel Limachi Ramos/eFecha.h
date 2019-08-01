#ifndef eFecha_H_INCLUDED
#define eFecha_H_INCLUDED
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
int fecha_set_dia(eFecha* x,int dia);
int fecha_set_mes(eFecha* x,int mes);
int fecha_set_anio(eFecha* x,int anio);
#endif // eFecha_H_INCLUDED
