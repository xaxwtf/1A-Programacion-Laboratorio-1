#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pNumero;
    pNumero= (int*) malloc(sizeof(int));
    if(pNumero!=NULL)
    {
        *pNumero= 25;
        printf("%d",*pNumero);
        free(pNumero);
    }
    else{
        printf("No se Ha Logrado reservar espacio");
        exit(1);
    }
    return 0;
}
