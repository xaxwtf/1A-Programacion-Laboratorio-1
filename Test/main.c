#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
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
void ord_char (char array[],int tam);
int getString(char *input, char mensaje[],char Emensaje[],int Linf,int Lsup);

int main()
{
    char palabra[TAM];
    char palabra2[TAM];
    int rels;
    rels=getString(palabra2,"Indique un Nombre de 3 caracteres","el Nombre exede el Numero de caracteres permitidos",0,3);
    if(rels==0)
    {
        printf("\n el Nombre es %s",palabra2);
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
        *dir=c;
    }
    else
    {
        printf(Emsg);
        i=-1;
    }
    return i;
}
void ord_char (char array[],int tam)
{
    int i,j;
    char aux;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;i++)
        {
            if(array[i]>array[j])
            {
                aux=array[i];
                array[i]=array[j];
                array[j]=aux;
            }
        }
    }

}
int mi_strig_cpy(char destino[],char origen[])
{
    int i;
    int flag=1;
    while(flag==1)
    {
        if(origen[i]!='\0')
        {
            destino[i]=origen[i];
            i++;
        }
        else
        {
            flag=0;
        }

    }
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

