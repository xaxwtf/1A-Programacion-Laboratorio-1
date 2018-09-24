#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
void initEmployees(eEmployee *lista,int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].isEmpy=1;
    }
}
int busPrimeraOcurrencia(eEmployee *lista,int tam, int valor)
{
    int i;
    int index=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpy==valor)
        {
           return i;
        }
    }
    return index;
}
int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup)
{
    int i=0;
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
int getString(char *input, char mensaje[],char Emensaje[],int Linf,int Lsup)
{
    char aux[300];
    int rels;
    int i=0;
    printf(mensaje);
    fflush(stdin);
    gets(aux);
    rels=strlen(aux);
    if(rels>=Linf&&rels<=Lsup)
    {
        strcpy(input,aux);
    }
    else
    {
        printf(Emensaje);
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
int addEmployee(eEmployee *lista, int len,int id, char name[],char lastName[], float salary, int sector)
{
    int index=-1;
    eEmployee aux;
    int dir;
    dir=busPrimeraOcurrencia(lista,len,1);
    aux.id=id;
    return index;
}
