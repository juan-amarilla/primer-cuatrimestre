#include "nacionalidad.h"
#include <string.h>
#include <stdio.h>
//#include <stdio_ext.h>
#define VACIO 0
#define OCUPADO 1


int validarNacionalidad(int id, eNacionalidad lista[], int tam)
{
    int i;
    int validar;

    validar=0;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idNacionalidad)
        {
            validar=1;
            break;
        }
    }

    return validar;
}

eNacionalidad buscarNacPorId(int id, eNacionalidad lista[], int tam)
{
    int i;
    eNacionalidad unaNacionalidad;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idNacionalidad)
        {
            unaNacionalidad=lista[i];
            break;
        }

    }

    return unaNacionalidad;
}

int menuNacionalidad()
{
    int opcion;

    printf("1.ALTA nacionalidad\n");
    printf("2.BAJA nacionalidad \n");
    printf("3.MODIFICAR nacionalidad \n");
    printf("Elija una opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int altaNacionalidad(eNacionalidad lista[], int tam)
{
    int i;
    i = buscarLibreNacionalidad(lista, tam);
    if(i!=-1)
    {
        lista[i] = pedirDatosNacionalidad();

    }

    return i;
}

int buscarLibreNacionalidad(eNacionalidad lista[], int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==VACIO)
        {
            index = i;
            break;
        }
    }

    return index;
}

eNacionalidad pedirDatosNacionalidad()
{
    eNacionalidad miNacionalidad;

    printf("Ingrese id nacionalidad: ");
    scanf("%d", &miNacionalidad.idNacionalidad);

    printf("Ingrese descripcion de nacionalidad: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%[^\n]", miNacionalidad.descripcionNacionalidad);

    miNacionalidad.isEmpty = OCUPADO;

    return miNacionalidad;
}

void inicializarNacionalidades(eNacionalidad lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = VACIO;
    }
}

int bajaNacionalidad(eNacionalidad lista[], int tam)
{
    int i;
    int id;
    int flag;
    int confirmacion;

    flag=0;

    printf("¿Esta seguro de dar de baja? escriba 1 para SI / 0 para NO \n");
    scanf("%d", &confirmacion);

    if(confirmacion==1) {

        printf("Ingrese el id de la nacionalidad para la baja: \n");
        scanf("%d", &id);

        for (i=0;i<tam;i++)
        {
          if (lista[i].idNacionalidad==id)
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

    else if (confirmacion==0)
    {
        printf("Baja cancelada\n");

    }

    return id;
}

void modificarNacionalidad(eNacionalidad lista[], int tam)
{
    int i;
    int id;
    int flag;

    flag=0;

    printf("Ingrese el id de la nacionalidad para la modificacion: \n");
    scanf("%d", &id);

    for (i=0;i<tam;i++)
    {
       if(lista[i].idNacionalidad==id)
       {
           flag=1;
           printf("ingrese la nueva descripcion de la nacionalidad: \n");
           scanf("%s", lista[i].descripcionNacionalidad);
           break;
       }

    }

    if (flag==0)
    {
        printf("La modificacion no fue exitosa\n");
    }
}

int verificarNacionalidadesDeAlta(eNacionalidad lista[], int tam)
{
    int i;
    int validarNacionalidad;

    validarNacionalidad=0;

    for (i=0;i<tam;i++)
    {
        if (lista[i].isEmpty==OCUPADO)
        {
            validarNacionalidad=1;
            break;
        }

    }

    return validarNacionalidad;
}
