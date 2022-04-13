#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/** \brief Esta funcion calcula el precio de los vuelos con un descuento del 10%
 *
 * \param float* precioDebitoAero recibe como puntero al precio con el valor descontado
 * \param float precioAero recibe el valor del vuelo sin modificaciones
 * \param float* precioDebitoLatam recibe como puntero al precio con el valor descontado
 * \param float precioLatam recibe el valor del vuelo sin modificaciones
 * \return int Devuelve 0 si el valor de ambos vuelos es 0, o 1 si ambos tienen un valor mayor a 0.
 *
 */

float costoDebito(float* precioDebitoAero, float precioAero, float* precioDebitoLatam, float precioLatam);

/** \brief Esta funcion calcula el precio de los vuelos con un sobrecargo del 25%
 *
 * \param float* precioCreditoAero recibe como puntero al precio con el valor agregado
 * \param float precioAero recibe el valor del vuelo sin modificaciones
 * \param float* precioCreditoLatam recibe como puntero al precio con el valor agregado
 * \param float precioLatam recibe el valor del vuelo sin modificaciones
 * \return int Devuelve 0 si el valor de ambos vuelos es 0, o 1 si ambos tienen un valor mayor a 0.
 *
 */

float costoCredito(float* precioCreditoAero, float precioAero, float* precioCreditoLatam, float precioLatam);

/** \brief Esta funcion calcula el precio de los vuelos en bitcoins
 *
 * \param float* precioAerolineasBitcoin recibe como puntero al precio en bitcoins
 * \param float precioAero recibe el valor del vuelo sin modificaciones
 * \param float* precioAerolineasLatam recibe como puntero al precio en bitcoins
 * \param float precioLatam recibe el valor del vuelo sin modificaciones
 * \return int Devuelve 0 si el valor de ambos vuelos es 0, o 1 si ambos tienen un valor mayor a 0.
 *
 */

float costoBitcoin(float* precioAerolineasBitcoin, float precioAero, float* precioLatamBitcoin, float precioLatam);

/** \brief Esta funcion calcula el precio unitario por kilómetro
 *
 * \param float* precioKmAero recibe como puntero al precio unitario
 * \param float precioAero recibe el valor del vuelo sin modificaciones
 * \param float* precioKmLatam recibe como puntero al precio unitario
 * \param float precioLatam recibe el valor del vuelo sin modificaciones
 * \param float kmTotales recibe la cantidad total de kilometros
 * \return int Devuelve 0 si el valor de ambos vuelos es 0, o 1 si ambos tienen un valor mayor a 0.
 *
 */

float precioPorKm(float* precioKmAero, float precioAero, float* precioKmLatam, float precioLatam, float kmTotales);

/** \brief Esta funcion calcula la diferencia entre el precio de ambos vuelos sin modificaciones
 *
 * \param float* diferencia recibe como puntero a la diferencia entre los precios
 * \param float precioAero recibe el valor del vuelo sin modificaciones
 * \param float precioLatam recibe el valor del vuelo sin modificaciones
 *
 */

float diferenciaPrecio(float* diferencia,float precioAero,float precioLatam);

/** \brief Esta funcion informa por pantalla todos los datos ingresados y calculados
 *
 * \param float km recibe el valor de los kilometros ingresados
 * \param float precioAerolineas recibe el valor del vuelo sin modificaciones
 * \param float precioAerolineasDebito recibe el valor del vuelo con un 10% de descuento
 * \param float precioAerolineasCredito recibe el valor del vuelo con recargo del 25%
 * \param float precioAerolineasBitcoin recibe el valor del vuelo en BTC
 * \param float precioKmAerolineas recibe el valor unitario de los kilometros
 * \param float precioLatam recibe el valor del vuelo sin modificaciones
 * \param float precioLatamDebito recibe el valor del vuelo con un 10% de descuento
 * \param float precioLatamCredito recibe el valor del vuelo con recargo del 25%
 * \param float precioLatamBitcoin recibe el valor del vuelo en BTC
 * \param float precioKmLatam recibe el valor unitario de los kilometros
 *
 */

void informarResultados(float km, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin,
float precioKmAerolineas, float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioKmLatam, float diferencia);
#endif /* FUNCIONES_H_ */
