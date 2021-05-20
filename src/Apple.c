#include "Apple.h"
#include <stdio.h>
//#include <stdio_ext.h>
#include <string.h>

#define VACIO 0
#define OCUPADO 1

int menu()
{
    int opcion;

    printf("1.ALTA producto\n");
    printf("2.BAJA producto \n");
    printf("3.MODIFICAR producto \n");
    printf("4.MOSTRAR productos \n");
    printf("5.MOSTRAR productos ordenados en precio \n");
    printf("6.MOSTRAR productos ordenados en descripcion \n");
    printf("7.MOSTRAR productos mas caros \n");
    printf("8.MOSTRAR precio promedio por tipo de producto \n");
    printf("9.MOSTRAR productos con tipos \n");
    printf("10.MOSTRAR tipos con sus listados de productos \n");
    printf("11.MOSTRAR tipos de productos con mas productos elaborados \n");
    printf("12.MOSTRAR nacionalidades que fabrican iphone \n");
    printf("13.MOSTRAR productos por nacionalidad alfabeticamente \n");
    printf("14.MOSTRAR la nacionalidad que fabrica mas productos \n");
    printf("15.MOSTRAR el precio promedio de productos por nacionalidad \n");
    printf("16.alta, baja y modificacion de TIPO \n");
    printf("17.alta, baja y modificacion de NACIONALIDAD \n");
    printf("18.MOSTRAR productos con sus fabricantes de pantallas \n");
    printf("19.SALIR \n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

eProducto PedirDatosProducto(eNacionalidad listaNacionalidad[], eTipoProducto listaTipo[])
{
    int validarNac;
    int validarTip;
    eProducto miProducto;

    printf("Ingrese id de producto: ");
    scanf("%d", &miProducto.idProducto);

    printf("Ingrese precio: ");
    scanf("%f", &miProducto.precioDecimal);

    printf("Ingrese descripcion: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%[^\n]", miProducto.descripcion);

    printf("Ingrese id nacionalidad: ");
    scanf("%d", &miProducto.idNacionalidad);
    validarNac=validarNacionalidad(miProducto.idNacionalidad, listaNacionalidad, 3);
    while(validarNac==0)
    {
        printf("Error: Ingrese id nacionalidad de nuevo\n");
        scanf("%d", &miProducto.idNacionalidad);
        validarNac=validarNacionalidad(miProducto.idNacionalidad, listaNacionalidad, 3);
    }

    listarTipos(listaTipo, 4);
    printf("Ingrese id tipo: ");
    scanf("%d", &miProducto.idTipo);
    validarTip=validarTipo(miProducto.idTipo, listaTipo, 4);
    while(validarTip==0)
    {
        listarTipos(listaTipo, 4);
        printf("Error: Ingrese id tipo de nuevo\n");
        scanf("%d", &miProducto.idTipo);
        validarTip=validarTipo(miProducto.idTipo, listaTipo, 4);
    }

    miProducto.isEmpty = OCUPADO;

    return miProducto;
}

int AltaProducto(eProducto lista[], int tam, eNacionalidad listaNacionalidad[], eTipoProducto listaTipo[])
{
    int i;
    i = BuscarLibreProducto(lista, tam);
    if(i!=-1)
    {
        lista[i] = PedirDatosProducto(listaNacionalidad, listaTipo);

    }

    return i;


}

void MostrarUnProducto(eProducto unProducto, eNacionalidad listaNac[], eTipoProducto listaTip[])
{
    eNacionalidad nac;
    eTipoProducto tip;

    nac=buscarNacPorId(unProducto.idNacionalidad, listaNac, 3);
    tip=buscarTipPorId(unProducto.idTipo, listaTip, 4);

    printf("la id %d, la descripcion %s, el precio %.2f, la nacionalidad %s, el tipo %s \n",
                                   unProducto.idProducto,
                                   unProducto.descripcion,
                                   unProducto.precioDecimal,
                                   nac.descripcionNacionalidad,
                                   tip.descripcionTipo
                                   );

}

void MostrarListadoDeProductos(eProducto lista[], int tam, eNacionalidad listaNac[], eTipoProducto listaTip[])
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            MostrarUnProducto(lista[i], listaNac, listaTip);
        }

    }
}

void modificarProducto(eProducto listaPro[], int tam, eTipoProducto listaTip[])
{
    int i;
    int id;
    int flag;
    int opcion;
    int validarTip;

    flag=0;

    printf("Ingrese el id del producto para la modificacion: \n");
    scanf("%d", &id);

    printf("Ingrese 1 para modificar precio / 0 para modificar tipo \n");
    scanf("%d", &opcion);

    for (i=0;i<tam;i++)
    {

       if (listaPro[i].idProducto==id && opcion==1)
       {
            flag=1;

            printf("Ingrese un precio nuevo: ");
            scanf("%f", &listaPro[i].precioDecimal);

            printf("La modificacion fue exitosa\n");

            break;
       }

       else if (listaPro[i].idProducto==id && opcion==0)
       {
            flag=1;

            listarTipos(listaTip, 4);
            printf("Ingrese un tipo nuevo: ");
            scanf("%d", &listaPro[i].idTipo);
            validarTip=validarTipo(listaPro[i].idTipo, listaTip, 4);

            while(validarTip==0)
            {
                listarTipos(listaTip, 4);
                printf("Error: Ingrese id tipo de nuevo\n");
                scanf("%d", &listaPro[i].idTipo);
                validarTip=validarTipo(listaPro[i].idTipo, listaTip, 4);
            }


            printf("La modificacion fue exitosa\n");

            break;
       }

    }

    if (flag==0)
    {
        printf("La modificacion no fue exitosa\n");
    }
}

void productosMasCaro(eProducto lista[], int tam, eNacionalidad listaNac[], eTipoProducto listaTip[])
{
    int i;
    int maximo;

    for(i=0;i<tam;i++)
    {
        if(i==0 || lista[i].precioDecimal>maximo)
        {
            maximo=lista[i].precioDecimal;
        }


    }

   for (i=0;i<tam;i++)
   {
       if(maximo==lista[i].precioDecimal)
       {
           MostrarUnProducto(lista[i], listaNac, listaTip);
       }
   }

}

void promedioPorTipoDeProducto(eProducto lista[], int tam, eTipoProducto listaTip[], int tamTip)
{
    int i;
    int j;
    float promedio;
    eAuxiliar auxiliar[tamTip];

    for (i=0;i<tamTip;i++)
    {
        auxiliar[i].id=listaTip[i].idTipo;
        auxiliar[i].contador=0;
        auxiliar[i].acumulador=0;
    }

    for (i=0;i<tamTip;i++)
    {
        for (j=0;j<tam;j++)
        {
            if (auxiliar[i].id==lista[j].idTipo)
            {
                auxiliar[i].contador++;
                auxiliar[i].acumulador+=lista[j].precioDecimal;
            }
        }

    }


    for (i=0;i<tamTip;i++)
    {
        if (listaTip[i].isEmpty==OCUPADO)
        {
            if (auxiliar[i].acumulador>0)
            {
                promedio=auxiliar[i].acumulador/auxiliar[i].contador;
                printf("el promedio de %s es %.2f\n", listaTip[i].descripcionTipo, promedio);
            }
            else
            {
                printf("el promedio de %s es 0\n", listaTip[i].descripcionTipo);
            }
        }

    }
}

void listarPorCadaTipoLosProductos(eProducto lista[], int tam, eTipoProducto listaTip[], int tamTip, eNacionalidad listaNac[])
{
    int i;
    int j;

    for (i=0;i<tamTip;i++)
    {
        if (listaTip[i].isEmpty==OCUPADO)
        {

         printf("Listado de productos de %s: \n", listaTip[i].descripcionTipo);
         for (j=0;j<tam;j++)
         {
           if (listaTip[i].idTipo==lista[j].idTipo && lista[j].isEmpty==OCUPADO)
           {
               MostrarUnProducto(lista[j], listaNac, listaTip);
           }

         }

        }



    }
}

void tiposDeProductosMasElaborados(eProducto lista[], int tam, eTipoProducto listaTip[], int tamTip)
{
    int i;
    int j;
    int maximo;
    eAuxiliar auxiliar[tamTip];

    for (i=0;i<tamTip;i++)
    {
        auxiliar[i].id=listaTip[i].idTipo;
        auxiliar[i].contador=0;
    }

    for (i=0;i<tamTip;i++)
    {
        for (j=0;j<tam;j++)
        {
            if (auxiliar[i].id==lista[j].idTipo)
            {
                auxiliar[i].contador++;
            }
        }

    }

    for(i=0;i<tamTip;i++)
    {
        if(i==0 || auxiliar[i].contador>maximo)
        {
            maximo=auxiliar[i].contador;
        }

    }

    for (i=0;i<tamTip;i++)
    {
       if(maximo==auxiliar[i].contador && listaTip[i].isEmpty==OCUPADO)
       {
          printf("El tipo mas elaborado fue %s \n", listaTip[i].descripcionTipo);
       }
    }

}

void nacionalidadFabricanteDeIphone(eProducto lista[], int tam, eTipoProducto listaTip[], eNacionalidad listaNac[], int tamNac)
{
    int i;
    int j;
    eTipoProducto tip;

    for (i=0;i<tamNac;i++)
    {
        for (j=0;j<tam;j++)
        {
            tip=buscarTipPorId(lista[j].idTipo, listaTip, 4);
            if ( strcmp(tip.descripcionTipo, "iphone") == 0 )
            {
                if (listaNac[i].idNacionalidad==lista[j].idNacionalidad)
                {
                    printf("la nacionalidad que fabrica iphone es %s \n", listaNac[i].descripcionNacionalidad);
                    break;
                }

            }
        }
    }

}

void ordenarProductosAlfabeticamentePorNacionalidad(eProducto lista[], int tam, eNacionalidad listaNac[], int tamNac)
{
    int i;
    int j;
    int k;
    char nacionalidadI[30];
    char nacionalidadJ[30];

    eProducto auxiliarProducto;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            for(k=0;k<tamNac;k++)
            {
                if(lista[i].idNacionalidad==listaNac[k].idNacionalidad)
                {
                    strcpy(nacionalidadI, listaNac[k].descripcionNacionalidad);
                    break;
                }
            }

            for(k=0;k<tamNac;k++)
            {
                if(lista[j].idNacionalidad==listaNac[k].idNacionalidad)
                {
                    strcpy(nacionalidadJ, listaNac[k].descripcionNacionalidad);
                    break;
                }
            }

            if(strcmp(nacionalidadI, nacionalidadJ)>0)
            {
                auxiliarProducto = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarProducto;
            }
        }
    }
}

void nacQueFabricaMasTip(eProducto lista[], int tam, eNacionalidad listaNac[], int tamNac)
{
    int i;
    int j;
    int maximo;
    eAuxiliar auxiliar[tamNac];

    for (i=0;i<tamNac;i++)
    {
        auxiliar[i].id=listaNac[i].idNacionalidad;
        auxiliar[i].contador=0;
    }

    for (i=0;i<tamNac;i++)
    {
        for (j=0;j<tam;j++)
        {
            if (auxiliar[i].id==lista[j].idNacionalidad && lista[j].isEmpty==OCUPADO)
            {
                auxiliar[i].contador++;
            }
        }

    }

    for(i=0;i<tamNac;i++)
    {
        if(i==0 || auxiliar[i].contador>maximo)
        {
            maximo=auxiliar[i].contador;
        }

    }

    for (i=0;i<tamNac;i++)
    {
       if(maximo==auxiliar[i].contador)
       {
          printf("La nacionalidad que fabrica mas tipos es: %s \n", listaNac[i].descripcionNacionalidad);
       }
    }
}

void promedioPorNac(eProducto lista[], int tam, eNacionalidad listaNac[], int tamNac)
{
    int i;
    int j;
    float promedio;
    eAuxiliar auxiliar[tamNac];

    for (i=0;i<tamNac;i++)
    {
        auxiliar[i].id=listaNac[i].idNacionalidad;
        auxiliar[i].contador=0;
        auxiliar[i].acumulador=0;
    }

    for (i=0;i<tamNac;i++)
    {
        for (j=0;j<tam;j++)
        {
            if (auxiliar[i].id==lista[j].idNacionalidad)
            {
                auxiliar[i].contador++;
                auxiliar[i].acumulador+=lista[j].precioDecimal;
            }
        }

    }


    for (i=0;i<tamNac;i++)
    {
        if (auxiliar[i].acumulador>0)
        {
           promedio=auxiliar[i].acumulador/auxiliar[i].contador;
           printf("el promedio de %s es %.2f\n", listaNac[i].descripcionNacionalidad, promedio);
        }
        else
        {
           printf("el promedio de %s es 0\n", listaNac[i].descripcionNacionalidad);
        }

    }
}

//case 18:
void MostrarListConFabr(int id, eProducto lista[], int tam, eNacionalidad listaNac[], eTipoProducto listaTip[], eFabricante listaFabr[])
{
    int i;
    eTipoProducto tip;
    eFabricante fabr;

    for(i=0; i<tam; i++)
    {
        tip=buscarTipPorId(lista[i].idTipo, listaTip, 4);
        fabr=buscarFabrPorId(tip.idFabricante, listaFabr, 3);

        if(lista[i].isEmpty == OCUPADO && id==fabr.idFabricante)
        {
            MostrarUnProductoConFabr(lista[i], listaNac, listaTip, listaFabr);
        }

    }
}

void MostrarUnProductoConFabr(eProducto unProducto, eNacionalidad listaNac[], eTipoProducto listaTip[], eFabricante listaFabr[])
{
    eNacionalidad nac;
    eTipoProducto tip;
    eFabricante fabr;

    nac=buscarNacPorId(unProducto.idNacionalidad, listaNac, 3);
    tip=buscarTipPorId(unProducto.idTipo, listaTip, 4);
    fabr=buscarFabrPorId(tip.idFabricante, listaFabr, 3);

    printf("la id %d, la descripcion %s, el precio %.2f, la nacionalidad %s, el tipo %s, el fabricante %s \n",
                                   unProducto.idProducto,
                                   unProducto.descripcion,
                                   unProducto.precioDecimal,
                                   nac.descripcionNacionalidad,
                                   tip.descripcionTipo,
                                   fabr.descripcionFabricante
                                   );
}
