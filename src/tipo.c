#include "tipo.h"
#include <stdio.h>
//#include <stdio_ext.h>
#define VACIO 0
#define OCUPADO 1

int validarTipo(int id, eTipoProducto lista[], int tam)
{
    int i;
    int validar;

    validar=0;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idTipo)
        {
            validar=1;
            break;
        }
    }

    return validar;
}

eTipoProducto buscarTipPorId(int id, eTipoProducto lista[], int tam)
{
    int i;
    eTipoProducto unTipo;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idTipo)
        {
            unTipo=lista[i];
            break;
        }

    }

    return unTipo;
}

void listarTipos(eTipoProducto lista[], int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        if (lista[i].isEmpty==OCUPADO)
        {
           printf("si ingresas %d sera %s \n", lista[i].idTipo, lista[i].descripcionTipo);
        }

    }
}

int menuTipo()
{
    int opcion;

    printf("1.ALTA tipo\n");
    printf("2.BAJA tipo \n");
    printf("3.MODIFICAR tipo \n");
    printf("Elija una opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarTipos(eTipoProducto lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = VACIO;
    }
}

int altaTipo(eTipoProducto lista[], int tam)
{
    int i;
    i = buscarLibreTipo(lista, tam);
    if(i!=-1)
    {
        lista[i] = pedirDatosTipo();

    }

    return i;
}

int buscarLibreTipo(eTipoProducto lista[], int tam)
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

eTipoProducto pedirDatosTipo()
{
    eTipoProducto miTipo;

    printf("Ingrese id tipo: ");
    scanf("%d", &miTipo.idTipo);

    printf("Ingrese descripcion de tipo: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%[^\n]", miTipo.descripcionTipo);

    miTipo.isEmpty = OCUPADO;

    return miTipo;
}

int verificarTiposDeAlta(eTipoProducto lista[], int tam)
{
    int i;
    int validarTipo;

    validarTipo=0;

    for (i=0;i<tam;i++)
    {
        if (lista[i].isEmpty==OCUPADO)
        {
            validarTipo=1;
            break;
        }

    }

    return validarTipo;
}

int bajaTipo(eTipoProducto lista[], int tam)
{
    int i;
    int id;
    int flag;
    int confirmacion;

    flag=0;

    printf("¿Esta seguro de dar de baja? escriba 1 para SI / 0 para NO \n");
    scanf("%d", &confirmacion);

    if(confirmacion==1) {

        printf("Ingrese el id del tipo para la baja: \n");
        scanf("%d", &id);

        for (i=0;i<tam;i++)
        {
          if (lista[i].idTipo==id && lista[i].isEmpty==OCUPADO)
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

void modificarTipo(eTipoProducto lista[], int tam)
{
    int i;
    int id;
    int flag;

    flag=0;

    printf("Ingrese el id del tipo para la modificacion: \n");
    scanf("%d", &id);

    for (i=0;i<tam;i++)
    {
       if(lista[i].idTipo==id)
       {
           flag=1;
           printf("ingrese la nueva descripcion del tipo: \n");
           scanf("%s", lista[i].descripcionTipo);
           break;
       }

    }

    if (flag==0)
    {
        printf("La modificacion no fue exitosa\n");
    }
}
