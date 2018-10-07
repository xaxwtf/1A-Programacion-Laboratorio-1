#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S_Ariel.h"
#define TAM 50

int main()
{
    int aux;
    if(get_String_soloNum(&aux,"Indique un numero: ","\n Error,solo se admiten Numeros",3))
    {
        printf("\n el numero se cargo correctamente");
    }

    return 0;
}



