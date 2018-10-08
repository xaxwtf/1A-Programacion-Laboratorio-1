#ifndef alquileres_H_INCLUDED
#define alquileres_H_INCLUDED
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct{
    int codAlquiler;
    int codJuego;
    int codCliente;
    eFecha fecha;
}eAlquiler;
#endif // alquileres_H_INCLUDED
