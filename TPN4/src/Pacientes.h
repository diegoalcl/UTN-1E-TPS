#ifndef PACIENTES_H_
#define PACIENTES_H_

typedef struct{
	int id;
	char nombre[51];
	char sexo[51];
	char especie[51];
	char esquemaVacunacion[51];
	int edad;

}ePaciente;

int compareById(void* pElementOne, void* pElementTwo);

int compareByEspecie(void* pElementOne, void* pElementTwo);

int compareBySexo(void* pElementOne, void* pElementTwo);

int compareByNombre(void* pElementOne, void* pElementTwo);

int compareByEstadoEsquemaDeVacunacion(void* pElementOne, void* pElementTwo);

int compareByEdad(void* pElementOne, void* pElementTwo);
#endif /* PACIENTES_H_ */
