#ifndef Partidas_H_INCLUDED
#define Partidas_H_INCLUDED

typedef struct{
    int id;
    char fecha[50];
    int tipoJuego;
    int cantJugadores;
    int durPartida;
    float costo;
}ePartida;

#endif // Partidas_H_INCLUDED
