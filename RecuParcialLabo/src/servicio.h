#ifndef SERVICIO_H_
#define SERVICIO_H_

struct
{
	int id;
	char descripcion[25];
	int precio;
	int isEmpty;
	int servicios[3];
}typedef Servicio;

void listarServicios(Servicio* arrayServicios, int tamanio);

int inicializarIdServicios(Servicio* arrayServicios, int tamanio);

int inicializarServicios(Servicio* arrayServicios, int tamanio);

int conseguirIdServicio(Servicio* arrayServicios, int tamanio);


#endif /* SERVICIO_H_ */
