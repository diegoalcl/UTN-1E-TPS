#ifndef TRABAJO_H_
#define TRABAJO_H_

struct
{
	int id;
	char marcaBicicleta[50];
	int rodadoBicicleta;
	int idServicio;
	int fecha[3];
	int isEmpty;
}typedef Trabajo;

int altaTrabajo(Trabajo* arrayTrabajos, int tamanio, int* idServicio, int* idTrabajo, Servicio* arrayServicios);

void pedirDatosTrabajo(char marcaBicicleta[], int *rodadoBicicleta, char* descripcion, int *dia, int *mes, int *anio);

int getNewId(Trabajo* arrayTrabajos, int tamanio);

void mostrarTrabajo(char marcaBicicleta[], int rodadoBicicleta, int dia, int mes, int anio, int servicio);

int agregarTrabajo(Trabajo* arrayTrabajos, int tamanio, int id, int idServicio, char marcaBicicleta[], int rodadoBicicleta, int dia, int mes, int anio);

int agregarId(Trabajo* arrayTrabajos, int len);

int listarTrabajos(Trabajo* arrayTrabajos, int tamanio, Servicio* arrayServicios);

void mostrarUnTrabajo(Trabajo arrayTrabajos, char* descripcion);

int modificarTrabajo(Trabajo* arrayTrabajos, int tamanio, Servicio* arrayServicios);

int bajaTrabajo(Trabajo* arrayTrabajos, int tamanio, Servicio* arrayServicios);


#endif /* TRABAJO_H_ */
