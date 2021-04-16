int suma(int numero1, int numero2)
{
	int suma;

	suma=numero1+numero2;

	return suma;
}

int resta(int numero1, int numero2)
{
	int resta;

	resta=numero1-numero2;

	return resta;
}

float division(float numero1, float numero2)
{
	float division;

	division=(float)numero1/numero2;

	return division;
}

int multiplicacion(int numero1, int numero2)
{
	int multiplicacion;

	multiplicacion=numero1*numero2;

	return multiplicacion;
}

int factorial(int numero1)
{
	int respuesta;

	if(numero1==1)
	{
		return 1;
	}

	respuesta=numero1*factorial(numero1-1);

	return respuesta;
}
