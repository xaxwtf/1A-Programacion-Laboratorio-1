#include "persona.h"
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

void init(EPersona lista[], int len){
    int i;
    for(i=0; i<len; i++){
        lista[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len){
    int i;
    int retorno = -1;

    for(i=0; i<len; i++){
        if(lista[i].isEmpty == 1){
            retorno = i;
            break;
        }
    }
    return retorno;
}


void alta(EPersona lista[], int len){
    int index;
    int aux;
    EPersona eAux;
    if(obtenerEspacioLibre(lista, len)==-1)
    {
        brea.
    }


    if(index != -1){
        //hay espacio libre
        aux=getInt(&)
    }
    else{
        //no hay espacio libre
    }

    return;
}

