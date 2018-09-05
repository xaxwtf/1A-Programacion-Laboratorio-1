#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** \brief Solicita un Numero Entero, lo verifica y guarda
 *
 * \param es La direcion de Memoria Donde se guardara el dato
 * \param es el Mensaje Mostrado al Solicitar el dato
 * \param es el Mensaje mostrado en caso que indique un dato Incorrecto
 * \param es el limite Inferior para verificar el dato
 * \param es el limite superior para verificar el dato
 * \return 1 si se logro cargar el dato -1 si no
 *
 */

int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup);
int getFloat(float *dir,char msg[],char Emsg [], float Linf,float Lsup);
int getChar(char *dir,char msg[],char Emsg[],char linf,char lsup);

int main()
{
    char letra={'A'};
    char letra2;
    int resl;
    /*resl=getChar(&letra,"Indique una Letra de A - C","Error, el Caracter Indicado no es Valido",'A','C');
    if(resl!=-1)
    {
        printf("\n EL caracter Indicado es %c",letra);
    }
    else
    {
        printf("\n No se Logro cargar el Caracter");
    }*/
    fflush(stdin);
    scanf("%c",&letra2);
    if(strcmp(letra2,letra)==0)
    {
        printf("Letra Correcta es %c",letra2);
    }
    else{
        printf("Error;");
    }



    return 0;
}
int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup)
{
    int i=1;
    int num;
    printf(msg);
    scanf("%d",&num);
    if(num>=Linf&&num<=Lsup)
    {
        *dir=num;
    }
    else{
        printf(Emsg);
        i=-1;
    }
    return i;
}
int getFloat(float *dir,char msg[],char Emsg [], float Linf,float Lsup)
{
    int i=-1;
    float num;
    printf(msg);
    scanf("%f",&num);
    if(num>=Linf&&num<=Lsup)
    {
        *dir=num;
        i=1;
    }
    else{
        printf(Emsg);
    }
    return i;
}
int getChar(char *dir,char msg[],char Emsg[],char linf,char lsup)
{
    int i=1;
    char c;
    printf(msg);
    fflush(stdin);
    scanf("%c",&c);
    if(c>=linf&&c<=lsup)
    {
        strcpy(*dir,c);
    }
    else
    {
        printf(Emsg);
        i=-1;
    }
    return i;
}

