#include "producto.h"
#define VACIO 0
#define OCUPADO 1
#include <stdio.h>
#include <string.h>

void InicializarProductos(eProducto lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = VACIO;
    }
}

void bajaProducto(eProducto lista[], int tam)
{
    int i;
    int id;
    int flag;
    int confirmacion;

    flag=0;

    printf("¿Esta seguro de dar de baja? escriba 1 para SI / 0 para NO \n");
    scanf("%d", &confirmacion);

    if(confirmacion==1) {

        printf("Ingrese el id del producto para la baja: \n");
        scanf("%d", &id);

        for (i=0;i<tam;i++)
        {
          if (lista[i].idProducto==id)
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
}

int BuscarLibreProducto(eProducto lista[], int tam)
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

//ordena de menor a mayor
void ordenarProductosPorPrecio(eProducto lista[], int tam)
{
    int i;
    int j;

    eProducto auxiliarProducto;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].precioDecimal>lista[j].precioDecimal)
            {
                auxiliarProducto = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarProducto;
            }
        }
    }
}

//se ordena de manera ascendente
void ordenarProductosPorDescripcion(eProducto lista[], int tam)
{
    int i;
    int j;

    eProducto auxiliarProducto;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].descripcion, lista[j].descripcion)>0)
            {
                auxiliarProducto = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarProducto;
            }
        }
    }
}

void borrarEnCascadaTipo(int id, eProducto lista[], int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idTipo && lista[i].isEmpty==OCUPADO)
        {
            lista[i].isEmpty=VACIO;
        }
    }
}

void borrarEnCascadaNacionalidad(int id, eProducto lista[], int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idNacionalidad && lista[i].isEmpty==OCUPADO)
        {
            lista[i].isEmpty=VACIO;
        }
    }
}
