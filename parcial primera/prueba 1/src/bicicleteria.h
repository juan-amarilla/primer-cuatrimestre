/*
 * bicicleteria.h
 *
 *
 *
 */

#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"

typedef struct{
    int id;
    int acumulador;

}eAuxiliar;

//un menu de opciones
int menu();

// da de alta
int altaTrabajo(eTrabajo lista[], int tamTrabajo, eServicio listaServicio[]);

// pide datos
eTrabajo pedirDatosTrabajo(eServicio listaServicio[]);

// modifica solo uno de los datos
void modificarTrabajo(eTrabajo lista[], int tamTrabajo, eServicio listaServicio[]);

// empieza a mostrar trabajos
void mostrarListadoDeTrabajos(eTrabajo lista[], int tam);

// mostrara un trabajo
void mostrarUnTrabajo(eTrabajo unTrabajo);


// total de pesos nos muestra
void totalPesosDeServicio(eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicio[], int tamServicio);

#ifndef BICICLETERIA_H_
#define BICICLETERIA_H_



#endif /* BICICLETERIA_H_ */
