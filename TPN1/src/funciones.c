#include <stdio.h>
#include <stdlib.h>

float costoDebito(float* precioDebitoAero, float precioAero, float* precioDebitoLatam, float precioLatam)
{
	int retorno =0;

	if(precioAero>0 && precioLatam>0)
	{
		retorno=1;
		*precioDebitoAero=precioAero*0.90;
		*precioDebitoLatam=precioLatam*0.90;
	}

	return retorno;
}

float costoCredito(float* precioCreditoAero, float precioAero, float* precioCreditoLatam, float precioLatam)
{
	int retorno=0;

	if(precioAero>0 && precioLatam>0)
	{
		retorno=1;
		*precioCreditoAero=precioAero*1.25;
		*precioCreditoLatam=precioLatam*1.25;
	}

	return retorno;
}

float costoBitcoin(float* precioAerolineasBitcoin, float precioAero, float* precioLatamBitcoin, float precioLatam)
{
	int retorno=0;
	float valorBitcoin=4606954.55;

	if(precioAero>0 && precioLatam>0)
	{
		retorno=1;
		*precioAerolineasBitcoin=precioAero/valorBitcoin;
		*precioLatamBitcoin=precioLatam/valorBitcoin;
	}
	return retorno;
}

float precioPorKm(float* precioKmAero, float precioAero, float* precioKmLatam, float precioLatam, float kmTotales)
{
	int retorno=0;

	if(precioAero>0 && precioLatam>0)
	{
		retorno=1;
		*precioKmAero=precioAero/kmTotales;
		*precioKmLatam=precioLatam/kmTotales;

	}
	return retorno;
}

float diferenciaPrecio(float* diferencia,float precioAero,float precioLatam)
{
	int retorno=0;

	if(precioAero>0 && precioLatam>0)
	{
		retorno=1;
		if(precioAero>=precioLatam)
		{
			*diferencia=precioAero-precioLatam;
		}else{
			*diferencia=precioLatam-precioAero;
		}
	}
	return retorno;
}

void informarResultados(float km, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin, float precioKmAerolineas,
float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioKmLatam, float diferencia)
{
	printf("\nKMs ingresados: %.2f km\n\nPrecio Aerolineas: $%.2f.\na)Precio con tarjeta de débito: $%.2f\n", km, precioAerolineas, precioAerolineasDebito);
	printf("b)Precio con tarjeta de crédito: $%.2f.\nc)Precio pagando con bitcoin: %f BTC.\n", precioAerolineasCredito, precioAerolineasBitcoin);
	printf("d)Mostrar precio unitario: $%.2f\n", precioKmAerolineas);
	printf("\nPrecio Latam: $%.2f.\na)Precio con tarjeta de débito: $%.2f\n", precioLatam, precioLatamDebito);
	printf("b)Precio con tarjeta de crédito: $%.2f.\nc)Precio pagando con bitcoin: %f BTC.\n", precioLatamCredito, precioLatamBitcoin);
	printf("d)Mostrar precio unitario: $%.2f\n\nLa diferencia de precio es $%.2f.", precioKmLatam, diferencia);
}
