#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S_Ariel.h"
#define TAM 50


int main()
{
    char letras[5];
    int aux;
    printf("indique un numero:");
    gets(letras);
    aux=soloNumeros(letras);
    if(aux)
    {
        printf("es numerico");
    }
    else
    {
        printf("no es numerico");
    }

    return 0;
}



