#ifndef S_Ariel_H_INCLUDED
#define S_Ariel_H_INCLUDED
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpy;
}eEmployee;
/** \brief inicializa un array en el valor que indique el programador
 *
 * \param es la direcion donde se encuentra el array de estructuras
 * \param es el tamaño del array
 * \return
 *
 */
void initEmployees(eEmployee *lista,int len);

/** \brief Solicita un Numero Entero, lo verifica y guarda
 *
 * \param es La direcion de Memoria Donde se guardara el dato
 * \param es el Mensaje Mostrado al Solicitar el dato
 * \param es el Mensaje mostrado en caso que indique un dato Incorrecto
 * \param es el limite Inferior para verificar el dato
 * \param es el limite superior para verificar el dato
 * \return 0 si se logro cargar el dato -1 si no
 *
 */
int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup);

/** \brief busca el valor indicado dentro del array
 *
 * \param vector es el array en el cual se reliza la busqueda
 * \param tam es el tamaño del array
 * \param valor es el dato a ser buscando dentro del arrays
 * \return devuelve -1 si no se encuentra el dato o devuelve el indice en el cual se encontro el dato indicado
 *
 */
//int busPrimeraOcurrencia(eEmployee vector[],int tam, int valor);
int getString(char *input, char mensaje[],char Emensaje[],int Linf,int Lsup);
int getFloat(float *dir,char msg[],char Emsg [], float Linf,float Lsup);
#endif // S_Ariel_H_INCLUDED
