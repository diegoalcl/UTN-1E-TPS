#ifndef TRABAJO_H_
#define TRABAJO_H_
#define MAX_MARCA 100
typedef struct
{
	int id;
	char marcaBicicleta[MAX_MARCA];
	int rodadoBicicleta;
	int idServicio;
	int fecha[3];
}Trabajo;

/**
 * \brief Permite crear un nuevo trabajo
 * \param arrayTrabajos La lista de trabajos a la cual se agregara el nuevo
 * \param idTrabajos La id del trabajo que le sera otorgada al nuevo trabajo
 * \param idServicios La id que se otorga a los servicios que se le hagan
 * \retorna void
 */
void altaTrabajo(Trabajo* arrayTrabajos, int* idTrabajos, int* idServicio);

/**
 * \brief Permite dar de baja un trabajo
 * \param arrayTrabajos Los trabajos que podemos dar de baja
 * \param idADarDeBaja La id del trabajo que el usuario quieredar de baja
 * \param idTrabajos Para asegurarse que sea una id existente
 * \retorna void
 */
void bajaTrabajo(Trabajo* arrayTrabajos, int idADarDeBaja, int* idTrabajos);

/**
 * \brief Permite modificar la marca o el servicio de la bicicleta
 * \param arrayTrabajos Los trabajos que tenemos para modificar
 * \param idAModificar La id del trabajo que el usuario quiere que se modifique
 * \param idTrabajos Para asegurarse que sea una id existente
 * \retorna void
 */

void modificarTrabajo(Trabajo* arrayTrabajos, int idAModificar, int* idTrabajos);

/**
 * \brief Lista los trabajos en orden por año o por marca si dos o mas años coinciden
 * \param arrayTrabajos Los trabajos a ordenar
 * \param idTrabajos Toma el id mas alto como limite de comparacion
 * \retorna void
 */
int listarTrabajo(Trabajo* arrayTrabajos,int idTrabajos);

#endif /* TRABAJO_H_ */
