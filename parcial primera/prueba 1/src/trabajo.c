/*
 * trabajo.c
 *
 *
 *
 */

#include "trabajo.h"
#define VACIO 0
#define OCUPADO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarTrabajos(eTrabajo lista[], int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
	   lista[i].isEmpty = VACIO;
	}
}

int buscarLibreTrabajo(eTrabajo lista[], int tamTrabajo)
{
    int i;
    int index = -1;
    for(i=0; i<tamTrabajo; i++)
    {
        if(lista[i].isEmpty==VACIO)
        {
            index = i;
            break;
        }
    }

    return index;
}

void bajaTrabajo(eTrabajo lista[], int tam)
{
	    int i;
	    int id;
	    int flag;
	    int confirmacion;
	    int validar;
		char idStr[15];

	    flag=0;

	    printf("?Esta seguro de dar de baja? escriba 1 para SI \n");
	    scanf("%d", &confirmacion);

	    if(confirmacion==1)
	    {

	        printf("Ingrese el id del trabajo para la baja: \n");
	        scanf("%s", idStr);
	        validar=validarEntero(idStr);
	        while(validar==0)
	        {
	        		printf("Error: Ingrese id de trabajo para la baja: ");
	        		scanf("%s", idStr);
	        	    validar=validarEntero(idStr);

	        }
	        id=atoi(idStr);

	        for (i=0;i<tam;i++)
	        {
	          if (lista[i].id==id)
	          {
	            flag=1;
	            lista[i].isEmpty=VACIO;
	            printf("La baja fue dado con exito!!\n");
	            break;
	          }
	        }

	        if (flag==0)
	        {
	          printf("La baja no fue exitosa\n");

	        }
	    }

	    else if (confirmacion!=1)
	    {
	        printf("Baja cancelada\n");

	    }
}

void ordenarTrabajosPorAnio(eTrabajo lista[], int tam)
{
	int i;
	int j;

    eTrabajo auxiliarTrabajo;

	for(i=0; i<tam-1; i++)
	{
	     for(j=i+1; j<tam; j++)
	     {
	            if(lista[i].anio>lista[j].anio)
	            {
	            	auxiliarTrabajo = lista[i];
	                lista[i] = lista[j];
	                lista[j] = auxiliarTrabajo;
	            }
	            else if(lista[i].anio==lista[j].anio && strcmp(lista[i].marcaBicicleta , lista[j].marcaBicicleta)>0)
	            {
	            	auxiliarTrabajo = lista[i];
	                lista[i] = lista[j];
	                lista[j] = auxiliarTrabajo;
	            }
	     }
	}
}
