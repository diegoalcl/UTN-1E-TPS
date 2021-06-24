#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int id;
	char descripcion[4][25];
	float precio[4];
}Servicio;

int altaServicios(char servicio, int idServicio);

/*int bajaServicios

int modificarServicios
*/
void listarServicios(int serviciosLimpieza, int serviciosParche, int serviciosCentrado, int serviciosCadena);

#endif /* SERVICIOS_H_ */
