#ifndef INPUT_H_
#define INPUT_H_

/** \brief Esta funcion verifica que el string ingresado consista solo de letras
 *
 * \param cadena[] char La cadena a validar
 * \return int Devuelve 0 si hay otros caracteres ademas de letras, o 1 si es solo letras
 *
 */
int verificarPalabra(char cadena[]);

/**
 * \brief Obtiene un numero entero
 * \param Recibe un entero
 * \return Devuelve un 1 si recibio un entero entre 12 y 30 o 0 si recibio cualquier otra cosa
 *
 */
int verificarRodado(int numero);

/**
 * \brief Verifica el dia
 *\param Recibe un entero
 *\param devuelve un 1 si es menor a 31 y mayor a 0 o 0 si es menor a 0 o mayor a 31.
 */
int verificarDia(int numero);

/**
 * \brief Verifica el mes
 *\param Recibe un entero
 *\param devuelve un 1 si es menor a 12 y mayor a 0 o 0 si es menor a 0 o mayor a 12.
 */
int verificarMes(int numero);

/**
 * \brief Verifica el año
 *\param Recibe un entero
 *\param devuelve un 1 si es menor a 2030 y mayor a 1900 o 0 si es menor a 1900 o mayor a 2040.
 */
int verificarAnio(int numero);

/**
 * \brief Verifica la id de servicio
 *\param Recibe un entero
 *\param devuelve un 1 si es una id valida(mayor a 19999)o 0 si es es invalida
 */

int verificarIdServicio(int numero);

/**
 * \brief Verifica que se elija un servicio valido
 *\param Recibe un char
 *\param Devuelve el servicio elegido
 */
char verificarServicio(char* eleccionServicio);
#endif /* INPUT_H_ */
