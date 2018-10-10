#ifndef clientes_H_INCLUDED
#define clientes_H_INCLUDED
typedef struct{
    int codCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
}eCliente;

/** \brief inicializa todos los codClientes en en el dato indicado
 *
 * \param es el array de clientes
 * \param es el tamaño del array
 * \param es el valor que tendra codClientes en todas las pociones del array
 * \return
 *
 */
void initClientes(eCliente *lista, int len,int dato);

/** \brief busca la primera ocurrencia y retorna el indice donde fue hallada
 *
 * \param  es el array de clientes
 * \param es el tamaño del array de clientes
 * \param es el dato buscado;
 * \return retorna el indice donde encontro el dato o -1 si no lo encontro
 *
 */
int buscarPrimerLibreCliente(eCliente* lista,int len,int dato);

/** \brief permite dar de alta un cliente
 *
 * \param es el array de clientes
 * \param es el tamaño del array
 * \param ese el codigo que diferenciara al cliente
 * \return 1 si logro cargar el cliente y 0 si no
 *
 */
int altaCliente(eCliente *lista,int tam,int codigo);

/** \brief permite cargar un sexo que solo puede ser m o f
 *
 * \param es la direcion de memoria donde se guardara el dato obtenido
 * \param es el mensaje  a ser motrado al momento de cargar el dato
 * \param es el mensaje mostrado en caso de error
 * \return
 *
 */
void cargarSexo(char *dato,char mensaje[],char emsj[]);

/** \brief imprime todos los datos de un cliente
 *
 * \param es el cliente del cual se mostraran los datos
 * \return
 *
 */
void imprimirCliente(eCliente cliente);

/** \brief permite dar  de baja un cliente de manera logica
 *
 * \param es el array de clientes
 * \param es el tamaño del array de clientes
 * \return 1 si logro dar de baja al cliente o 0 si no
 *
 */
int bajaCliente(eCliente *lista,int tam);

/** \brief permite modificar los datos del cliente
 *
 * \param es el array de clientes
 * \param es el tamaño del array
 * \return
 *
 */
void modificarCliente(eCliente *lista,int tam);

/** \brief imprime todos los clientes cargados
 *
 * \param es el array de clientes
 * \param es el tamaño del array de clientes
 * \return
 *
 */
void imprimirClientes(eCliente *lista,int tam);

/** \brief ordena el array de clientes
 *
 * \param es el array de clientes
 * \param es el tamaño del array
 * \return
 *
 */
void ordenarClientes(eCliente *lista,int tam);

/** \brief permite saber si el array de clientes tiene datos o no
 *
 * \param es el array de clientes
 * \param es el tamaño del array
 * \param es el dato que se usara de referencia
 * \return -1 si no hay datos cargados o el indice donde encontro el 1er dato
 *
 */

int hayClientes(eCliente *lista,int tam,int dato);
#endif // clientes_H_INCLUDED
