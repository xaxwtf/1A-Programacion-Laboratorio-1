#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S_Ariel.h"
#include "juegos.h"
#include "clientes.h"
void initClientes(eCliente *lista, int len,int dato)
{
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].codCliente=dato;

    }
}
int buscarPrimerLibreCliente(eCliente* lista,int len,int dato)
{
    int i;
    int r=-1;
    for(i=0;i<len;i++)
    {
        if(lista[i].codCliente==dato)
        {
            r=i;
            break;
        }
    }
    return r;
}
int altaCliente(eCliente *lista,int tam,int* codigo)
{
    eCliente aux;
    int ok=1;
    int r;
    r=buscarPrimerLibreCliente(lista,tam,-1);
    if(r==-1)
    {
        printf("\n Ha alcanzado el Limite de cliente a cargar\n");
        ok=-1;
    }
    else
    {
        if(getString(aux.nombre,"\n Indique su nombre : ","\n Error, el Nombre no debe tener mas de 50 caracteres\n",0,50,3)==-1)
            {
                ok=0;
            }
        if(ok==1&&(getString(aux.apellido,"\n Indique el Apellido: ","\n Error, el Apellido no debe tener mas de 50 caracteres\n",0,50,3)==-1))
            {
                ok=0;
            }

        cargarSexo(&aux.sexo,"\n indique el sexo(f/m): ","\nError, solo se aceptan f o m\n");
        if(ok==1&&(getString(aux.domicilio,"\n Indique su Domicilio: ","\nError, el Domicilio no debe ter mas de 50 caracteres\n",1,50,3)==0))
        {
            aux.codCliente=100+*codigo;
            lista[r]=aux;
        }
        else
        {
            ok=0;
            printf("Error");
            system("pause");
        }
    }
    return ok;
}
void cargarSexo(char *dato,char mensaje[],char emsj[])
{
    char aux;
    int flag=0;
    do{
        printf(mensaje);
        fflush(stdin);
        scanf("%c",&aux);
        if(aux=='m'||aux=='f')
        {
            *dato=aux;
            flag=1;
        }
        else
        {
            printf(emsj);
        }

    }while(flag!=1);
}
void modificarCliente(eCliente *lista,int tam)
{
    int opcion;
    int dato=pedir_entero("\n Indique el codigo de Cliente: ");
    int r;
    r=buscarPrimerLibreCliente(lista,tam,dato);
    if(r!=-1)
    {

        do{
            system("cls");
            printf("\nCliente: \n  Cod.Cliente      Nombre      Apellido      Sexo      Domicilio");
            imprimirCliente(lista[r]);
            dato=get_String_soloNum(&opcion,"\n 1-Modificar Nombre\n 2-Modificar Apellido \n 3-Modificar Sexo \n 4-Modificar Domicilio\n 0-Atras\n","\n Error, Solo indique numeros\n",1);
            switch(opcion)
            {
                case 1:
                    if(getString(lista[r].nombre,"\n Indique el Nuevo Nombre: ","\n Error,el nombre no debe tener mas de 50 caracteres",1,50,3)==0)
                    {
                        printf("\n Se ha Modificado el dato con exito\n");
                        system("pause");
                    }
                    break;
                case 2:
                    if(getString(lista[r].apellido,"\n Indique el Nuevo Apellido: ","\n Error, el Apellido no debe tener mas de 50 caracteres",1,50,3)==0)
                    {
                        printf("\n Se ha Modificado el dato con exito");
                        system("pause");
                    }
                    break;
                case 3:
                    cargarSexo(&lista[r].sexo,"\nIndique el Sexo: ","\nError,Indique solo (m/f):\n");
                    break;
                case 4:
                    if(getString(lista[r].domicilio,"\n Indique el nuevo Domicilio : ","\n Error, el Domicilio no debe tener mas de 50 caracteres",1,50,3)==0)
                    {
                        printf("\n Se ha Modificado el dato con exito");
                        system("pause");
                    }
                    break;

            }

        }while(opcion!=0);

    }
    else{
        printf("\nEl Codigo Indicado No existe\n");
        system("pause");
    }


}
void imprimirCliente(eCliente cliente)
{
     printf("\n      %d          %5s       %5s        %c         %5s\n",cliente.codCliente,cliente.nombre,cliente.apellido,cliente.sexo,cliente.domicilio);
}
int bajaCliente(eCliente *lista,int tam)
{
    int ok=0;
    int flag=0;
    char c;
    int dato=pedir_entero("\n Indique el codigo de Cliente: ");
    int r;
    r=buscarPrimerLibreCliente(lista,tam,dato);
    if(r!=-1)
    {
        do{
            printf("\nCliente encontrado: ");
            imprimirCliente(lista[r]);
            getChar(&c,"\n Seguro que desea dar de Baja este Cliente(s/n):  ","\n \n",'a','z');
            switch(c)
            {
                case 's':
                    lista[r].codCliente=-1;
                    ok=1;
                    flag=1;
                    break;
                case 'n':
                    flag=1;
                    break;
            }


        }while(flag!=1);


    }
    else{
        printf("\n El Codigo Indicado No existe\n");
        system("pause");
    }
    return ok;
}
void imprimirClientes(eCliente *lista,int tam)
{

    int i;
    printf("\nClientes: \n  Cod.Cliente      Nombre      Apellido      Sexo      Domicilio");
    for(i=0;i<tam;i++)
    {
        if(lista[i].codCliente!=-1)
        {
            imprimirCliente(lista[i]);
        }

    }
}
void ordenarClientes(eCliente *lista,int tam)
{
    int i,j;
    eCliente aux;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
            {
                if(strcmp(lista[i].apellido,lista[j].apellido)>0)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
                else if(strcmp(lista[i].apellido,lista[j].apellido)==0 && strcmp(lista[i].nombre,lista[j].nombre)<0)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }

    }

}
int hayClientes(eCliente *lista,int tam,int dato)
{
    int r=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].codCliente!=dato)
        {
            r=i;
            break;
        }
    }
    return r;
}

