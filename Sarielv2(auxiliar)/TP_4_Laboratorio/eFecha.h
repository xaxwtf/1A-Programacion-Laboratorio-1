#ifndef eFecha_H_INCLUDED
#define eFecha_H_INCLUDED
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
/** \brief Carga los datos de una estructura fecha
 *
 * \param es el estructura a cargar,
 * \param es la cantidad de veces que volvera a pedir el dato
 * \return 1 si logra cargar la estructura y 0 si no
 *
 */

int cargarFecha(eFecha* hoy,int intentos,char* mjs);
#endif // eFecha_H_INCLUDED
