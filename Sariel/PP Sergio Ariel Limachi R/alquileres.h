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

int alquilarJuego(eAlquiler *lista,int tam,eJuego *juegos,int tamj,eCliente *clientes, int tamCte,int* codAlq);
void informes(eJuego *juegos, int tamjs,eCliente *clientes,int tamCte, eAlquiler *alquileres, int tamAlq);
float cargarImportejuego(eJuego *lista, int tam,int codAlq);
float obtenerTotalJuegosAlquilados(eAlquiler *lista,int tamAlq, eJuego *juegos,int tamj);
float obtenerPromedioJuegosAlquilados(eAlquiler *lista,int tam,float Total);
void mostrarPromYtotal(eAlquiler *alquileres, int tamAlq,eJuego *juegos, int tamJs);
int contJuegosDeImpMenorAlprom(eAlquiler *alquileres, int tamAlq, eJuego *juegos, int tam);
void imprimirCtesSegunJuego(eJuego *juegos,int tamJs,eCliente *clientes,int tamCte,eAlquiler *lista, int tamLis);
void imprimirJuegosSegunCliente(eJuego *juegos,int tamJs,eCliente *clientes,int tamCte,eAlquiler *lista, int tamLis);
void ordenarBurbugeo(eJuego *a, int len);
void ImprimirJuegosOrdxImporte(eJuego *lista, int tam);
void ordenacion_insercion (eCliente * A, int N);
void impimirClientesOrdxApellido(eCliente* lista,int tam);
int ocurrenciasdeJuego(eAlquiler* lista,int tam,int idJuego);
int ocurrenciasdeCliente(eAlquiler* lista,int tam,int idCliente);
int imprimirjuegoMenosAlq(eAlquiler* alquileres,int tamAlq,eJuego* lista,int tam);
int imprimirClienteconMasalq(eAlquiler* alquileres,int tamAlq,eCliente* lista,int tam);
int cargarFecha(eFecha* hoy,int intentos);
int imprimirjuegosxFecha(eAlquiler* alquileres,int tamAlq,eJuego* juegos,int tamJs);
int listarClientesxfecha(eAlquiler* alquileres,int tamAlq,eCliente* clientes,int tamCte);
#endif // alquileres_H_INCLUDED
