#ifndef juegos_H_INCLUDED
#define juegos_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[51];
    float importe;
}eJuego;
/** \brief inicializa todos las banderas(isEMpy) de cada una de las estructuras del array en 1
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
void modificarJuego(eJuego *lista,int tam);
void imprimirJuego(eJuego juego);
int bajaJuego(eJuego *lista,int tam);
void imprimirJuegos(eJuego *lista,int tam);
void ordenarJuegos(eJuego *lista,int tam);
#endif // juegos_H_INCLUDED
