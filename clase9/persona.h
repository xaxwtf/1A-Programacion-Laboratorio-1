#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}EFecha;

typedef struct {
    char apellido[31];
    char nombre[31];
    long int dni;
    EFecha feNac;
    int isEmpty;
}EPersona;
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
void string_save(char *date);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int len);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], long int dni);

void alta(EPersona[], int len);
#endif // PERSONA_H_INCLUDED
