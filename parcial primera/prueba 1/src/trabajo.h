/*
 * trabajo.h
 *
 *
 *
 */
#include "validaciones.h"

typedef struct
{
   int id;
   char marcaBicicleta[30];
   int rodadoBicicleta;
   int idServicio;
   int dia;
   int mes;
   int anio;
   int isEmpty;

}eTrabajo;

//inicializa en 0
void inicializarTrabajos(eTrabajo lista[], int tam);

//busca si esta ocupado un trabajo
int buscarLibreTrabajo(eTrabajo lista[], int tamTrabajo);

//da de baja un trabajo
void bajaTrabajo(eTrabajo lista[], int tam);

//ordena los trabajos por año
void ordenarTrabajosPorAnio(eTrabajo lista[], int tam);

#ifndef TRABAJO_H_
#define TRABAJO_H_



#endif /* TRABAJO_H_ */
