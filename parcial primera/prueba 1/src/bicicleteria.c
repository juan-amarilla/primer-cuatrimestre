/*
 * bicicleteria.c
 *
 *
 *
 */

#include "bicicleteria.h"
#define VACIO 0
#define OCUPADO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
	int opcion;

	printf("1.ALTA trabajo\n");
	printf("2.MODIFICAR trabajo \n");
    printf("3.BAJA trabajo \n");
	printf("4.LISTAR trabajos \n");
	printf("5.LISTAR servicios \n");
	printf("6.MOSTRAR total en pesos por los servicios prestados \n");
	printf("7.SALIR \n");
	printf("Elija una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int altaTrabajo(eTrabajo lista[], int tamTrabajo, eServicio listaServicio[])
{
	 int i;
	 i = buscarLibreTrabajo(lista, tamTrabajo);
	 if(i!=-1)
	 {
	        lista[i] = pedirDatosTrabajo(listaServicio);

	 }


     return i;
}

eTrabajo pedirDatosTrabajo(eServicio listaServicio[])
{
	char idStr[15];
	char marcaStr[15];
	char rodadoStr[15];
	char idServicioStr[15];
	char diaStr[15];
	char mesStr[15];
	char anioStr[15];

	int validar;

	eTrabajo miTrabajo;

	printf("Ingrese id de trabajo: ");
	scanf("%s", idStr);
	validar=validarEntero(idStr);
	while(validar==0)
	{
		printf("Error: Ingrese id de trabajo: ");
		scanf("%s", idStr);
	    validar=validarEntero(idStr);

	}
	miTrabajo.id=atoi(idStr);

	printf("Ingrese marca de bicicleta: ");
	fflush(stdin);
	scanf("%s", marcaStr);
	validar=validarLetras(marcaStr);
	while(validar==0)
	{
			printf("Error: Ingrese marca de bicicleta: ");
			scanf("%s", marcaStr);
		    validar=validarLetras(marcaStr);

	}
	strcpy(miTrabajo.marcaBicicleta, marcaStr);

	printf("Ingrese rodado de bicicleta en numero entero: ");
	scanf("%s", rodadoStr);
	validar=validarEntero(rodadoStr);
	while(validar==0)
	{
			printf("Error: Ingrese rodado de bicicleta en numero entero: ");
			scanf("%s", rodadoStr);
		    validar=validarEntero(rodadoStr);

	}
	miTrabajo.rodadoBicicleta=atoi(idStr);

    printf("Ingrese id de servicio: ");
    scanf("%s", idServicioStr);
    validar=validarEntero(idServicioStr);
    while( validar==0 || atoi(idServicioStr)<20000 || atoi(idServicioStr)>20003)
    {
    	printf("Error: Ingrese id de servicio entre 20000 y 20003 inclusive: ");
    	scanf("%s", idServicioStr);
    	validar=validarEntero(idServicioStr);
    }
    miTrabajo.idServicio=atoi(idServicioStr);

    printf("Ingrese dia en numero entero: ");
    scanf("%s", diaStr);
    validar=validarEntero(diaStr);
    while( validar==0 || atoi(diaStr)<1 || atoi(diaStr)>31)
    {
        	printf("Error: Ingrese dia entre 1 y 31 inclusive: ");
        	scanf("%s", diaStr);
        	validar=validarEntero(diaStr);
    }
    miTrabajo.dia=atoi(diaStr);

    printf("Ingrese mes en numero entero: ");
    scanf("%s", mesStr);
    validar=validarEntero(mesStr);
    while( validar==0 || atoi(mesStr)<1 || atoi(mesStr)>12)
    {
            	printf("Error: Ingrese mes entre 1 y 12 inclusive: ");
            	scanf("%s", mesStr);
            	validar=validarEntero(mesStr);
    }
    miTrabajo.mes=atoi(mesStr);

    printf("Ingrese a?o en numero entero: ");
    scanf("%s", anioStr);
    validar=validarEntero(anioStr);
    while( validar==0 || atoi(anioStr)<2000 || atoi(anioStr)>2021)
    {
            	printf("Error: Ingrese a?o entre 2000 y 2021 inclusive: ");
            	scanf("%s", anioStr);
            	validar=validarEntero(anioStr);
    }
    miTrabajo.anio=atoi(anioStr);

	miTrabajo.isEmpty = OCUPADO;

	return miTrabajo;
}

void modificarTrabajo(eTrabajo lista[], int tamTrabajo, eServicio listaServicio[])
{
	    int i;
	    int id;
	    int flag;
	    int opcion;
	    int validar;
	    char idStr[15];
	    char marcaStr[15];
	    char idServicioStr[15];

	    flag=0;

	    printf("Ingrese el id del trabajo para la modificacion: \n");
	    scanf("%s", idStr);
	    validar=validarEntero(idStr);
	    while(validar==0)
	    {
	    	     printf("Error: Ingrese id de trabajo para la modificacion: ");
	    	     scanf("%s", idStr);
	    	     validar=validarEntero(idStr);

	    }
	    id=atoi(idStr);

	    printf("Ingrese 1 para modificar la marca de bicicleta \n");
	    printf("Ingrese 0 para modificar la id del servicio \n");
	    scanf("%d", &opcion);

	    for (i=0;i<tamTrabajo;i++)
	    {

	       if (lista[i].id==id && opcion==1)
	       {
	            flag=1;

	            printf("Ingrese una marca nueva: ");
	            fflush(stdin);
	            scanf("%s", marcaStr);
	            validar=validarLetras(marcaStr);
	            while(validar==0)
	            {
	            			printf("Error: Ingrese una marca nueva: ");
	            			scanf("%s", marcaStr);
	            		    validar=validarLetras(marcaStr);

	            }
	            strcpy(lista[i].marcaBicicleta, marcaStr);

	            printf("La modificacion fue exitosa\n");

	            break;
	       }

	       else if (lista[i].id==id && opcion==0)
	       {
	            flag=1;

	            printf("Ingrese una id de servicio nuevo: ");
	            scanf("%s", idServicioStr);
	            validar=validarEntero(idServicioStr);
	            while( validar==0 || atoi(idServicioStr)<20000 || atoi(idServicioStr)>20003)
	            {
	                	printf("Error: Ingrese id de servicio entre 20000 y 20003 inclusive: ");
	                	scanf("%s", idServicioStr);
	                	validar=validarEntero(idServicioStr);
	            }
	            lista[i].idServicio=atoi(idServicioStr);

	            printf("La modificacion fue exitosa\n");

	            break;
	       }

	    }

	    if (flag==0)
	    {
	        printf("La modificacion no fue exitosa\n");
	    }
}

void mostrarListadoDeTrabajos(eTrabajo lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
	    if(lista[i].isEmpty == OCUPADO)
	    {
	        mostrarUnTrabajo(lista[i]);
	    }

	}
}

void mostrarUnTrabajo(eTrabajo unTrabajo)
{
	printf("la id %d, la marca %s, el rodado %d, la id servicio %d, el dia %d, el mes %d, el a?o %d \n",
			unTrabajo.id,
			unTrabajo.marcaBicicleta,
			unTrabajo.rodadoBicicleta,
			unTrabajo.idServicio,
			unTrabajo.dia,
			unTrabajo.mes,
			unTrabajo.anio
	                            );
}

void totalPesosDeServicio(eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicio[], int tamServicio)
{
	    int i;
	    int acumulador;
	    eServicio servicio;

	    acumulador=0;

	    for (i=0;i<tamTrabajo;i++)
	    {

	         if (listaTrabajo[i].isEmpty==OCUPADO)
	         {
	        	 servicio=buscarServicioPorId(listaTrabajo[i].idServicio, listaServicio, tamServicio);
                 acumulador+=servicio.precio;

	         }

	    }

        printf("el precio total por los servicios prestados es: %d \n", acumulador);

}
