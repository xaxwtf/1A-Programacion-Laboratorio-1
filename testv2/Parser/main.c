#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int legajo;
    char nombre[30];
    float sueldo;
    int isEmpy;
}eEmpleado;


int main()
{
    FILE* pFile;
    char a[30];
    char b[30];
    char c[30];
    char d[30];
    int r,i;
    eEmpleado* lista=(eEmpleado*)malloc(sizeof(eEmpleado)*30);
    pFile=fopen("empleados.csv","r");
    if(pFile!=NULL){
        do{
            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",a,b,c,d);
            if(r==4)
            {
                (lista+i)->legajo=atoi(a);
                 strcpy(lista+i,b);
                (lista+i)->sueldo=atof(c);
                (lista+i)->isEmpy=atoi(d);
            }

        }while(!feof(pFile));

        for(i=0;i<30;i++)
        {
            printf("%d %s %0.2f %d \n",(lista+i)->legajo,(lista+i)->nombre,(lista+i)->sueldo,(lista+i)->isEmpy);
        }


    }

    return 0;
}
