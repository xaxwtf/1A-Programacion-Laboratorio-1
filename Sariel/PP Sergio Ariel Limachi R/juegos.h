#ifndef juegos_H_INCLUDED
#define juegos_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[51];
    float importe;
}eJuego;
/** \brief inicializa todos los codigo de cada una de las estructuras del array en en valor pasado como dato
 *
 * \param lista es el puntero al array de estructuras
 * \param len es el tamaño del array
 * \return
 *
 */
void initJuegos(eJuego *lista, int len,int dato);
/** \brief realiza una busqueda del la primera coincidencia
 *
 * \param es el array donde relizara la busqueda
 * \param es el tamaño del array
 * \param es el dato que se buscara
 * \return el indice donde encontro la 1ra concidencia y -1 si no encontro ninguna
 *
 */
int buscarPrimerLibre(eJuego* lista, int len,int dato);

/** \brief permite modificar datos del usuario
 *
 * \param el array de juegos
 * \param el tamaño del array
 * \return
 *
 */
void modificarJuego(eJuego *lista,int tam);

/** \brief imprime todos los campos de un juego
 *
 * \param  es el juego del cual se mostraran los datos
 * \return
 *
 */
void imprimirJuego(eJuego juego);

/** \brief permite dar de baja un juego de manera logica
 *
 * \param es el array de juegos
 * \param es el tamaño del array
 * \return 1 si logro dar de baja el juego y 0 si no
 *
 */
int bajaJuego(eJuego *lista,int tam);

/** \brief imprime todos los juegos de una array
 *
 * \param es el array de juegos a ser mostrado
 * \param es el tamaño del array
 * \return
 *
 */
void imprimirJuegos(eJuego *lista,int tam);

/** \brief ordena el array de juegos
 *
 * \param es el array de juegos
 * \param es el tamañod el array
 * \return
 *
 */
void ordenarJuegos(eJuego *lista,int tam);

/** \brief permite dar de alta un juego
 *
 * \param es el array de juegos
 * \param  es el tamaño del array
 * \param es el codigo unico por el cual se diferenciara el juego
 * \return 1 si logro cargar el juego y 0 si no
 *
 */
int altaJuego(eJuego *lista,int tam,int* codigo);

/** \brief permite saber si hay por lo menos un juego cargado
 *
 * \param es el array de juegos
 * \param  es el tamaño del array
 * \return -1 si no hay datos cargados 0 el indice  donde encontro el 1er dato cargado
 *
 */
int hayJuegos(eJuego *lista,int tam,int dato);
#endif // juegos_H_INCLUDED
