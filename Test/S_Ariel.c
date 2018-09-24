#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S_Ariel.h"

float pedir_flotante(char mensaje[])
{
    float num;
    printf(mensaje);
    scanf("%f",&num);
    return num;
}
int pedir_entero(char mensaje[])
{
    int num;
    printf(mensaje);
    scanf("%d",&num);
    return num;
}
int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup)
{
    int i=-1;
    int num;
    num=pedir_entero(msg);
    if(num>=Linf&&num<=Lsup)
    {
        *dir=num;
    }
    else{
        printf(Emsg);
        i=0;
    }
    return i;
}
int getFloat(float *dir,char msg[],char Emsg [], float Linf,float Lsup)
{
    int i=-1;
    float num;
    num=pedir_flotante(msg);
    if(num>=Linf&&num<=Lsup)
    {
        *dir=num;
        i=0;
    }
    else{
        printf(Emsg);
    }
    return i;
}
int getChar(char *dir,char msg[],char Emsg[],char linf,char lsup)
{
    int i=-1;
    char c;
    printf(msg);
    fflush(stdin);
    scanf("%c",&c);
    if(c>=linf&&c<=lsup)
    {
        *dir=c;
    }
    else
    {
        printf(Emsg);
        i=0;
    }
    return i;
}
int getString(char *input, char mensaje[],char Emensaje[],int Linf,int Lsup)
{
    char aux[300];
    int rels;
    int i=-1;
    printf(mensaje);
    gets(aux);
    rels=strlen(aux);
    if(rels>=Linf&&rels<=Lsup)
    {
        strcpy(input,aux);
        i=0;
    }
    else
    {
        printf(Emensaje);
    }
    return i;
}
void string_save(char *date)
{
    int i;
    int largo=strlen(date);
    strlwr(date);
    for(i=0;i<largo;i++)
    {
        if(date[i]==' ')
        {
            date[i+1]=toupper(date[i+1]);
        }
    }
    date[0]=toupper(date[0]);

}
void ordenar(char *lista,int tam)
{
    char aux;
    int i,j;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i]>lista[j])
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}
void mi_swap(int* dato,int* dato2)
{
    int aux;
    aux=*dato;
    *dato=*dato2;
    *dato2=aux;
}

