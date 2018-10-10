#ifndef alquileres_H_INCLUDED
#define alquileres_H_INCLUDED
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct{
    int codAlquiler;
    int codJuego;
    int codCliente;
    eFecha fecha;
}eAlquiler;

/** \brief inicializa el array de alquileres
 *
 * \param es el array de alquileres
 * \param  es el tamaño del array
 * \param es el valor con el cual se inicializara
 * \return
 *
 */
void initAlquiler(eAlquiler *lista, int len,int dato);

/** \brief busca un dato y devuelve la pocicion donde lo encontro
 *
 * \param  es el array de alquileres
 * \param es el tamaño del array
 * \param es el dato a buscaer
 * \return el indice donde encontro el dato o -1 si no lo encontro
 *
 */
int buscarPrimerLibreAlquiler(eAlquiler* lista,int len,int dato);

/** \brief permite crear un registro del un alquiler
 *
 * \param es el array de alquileres
 * \param es el tamaño del array de alquileres
 * \param es el array de juegos
 * \param es el tamaño del array de juegos
 * \param es el array de clientes
 * \param es el tamaño del array de clientes
 * \param es una estructura de fecha
 * \param es el codigo por el cual se diferenciara el alquiler
 * \return
 *
 */

int alquilarJuego(eAlquiler *lista,int tam,eJuego *juegos,int tamj,eCliente *clientes, int tamCte,eFecha x, int codAlq);
#endif // alquileres_H_INCLUDED
