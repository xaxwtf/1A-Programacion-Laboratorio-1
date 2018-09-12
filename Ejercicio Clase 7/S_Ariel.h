/** \brief inicializa un array en el valor que indique el programador
 *
 * \param vector: es el array al cual se le asiganara el dato
 * \param tam es el tamaño del array al cual se le asignara el dato
 * \param es el dato que se le asiganara a cada pocicion del array
 * \param desde el Indice a partir del cual le Asignara el valor indicado
 * \return
 *
 */
void inizArray(int vector[],int tam,int valor,int desde);

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
int busPrimeraOcurrencia(int vector[],int tam, int valor);
int getString(char *input, char mensaje[],char Emensaje[],int Linf,int Lsup);

