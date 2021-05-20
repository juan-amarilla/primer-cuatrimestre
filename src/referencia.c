/******************************************************************************

amarilla juan sebastian 1B

*******************************************************************************/
#include <stdio.h>
#include "Apple.h"
#define T 4
#define VACIO 0
#define OCUPADO 1


int main()
{

    eNacionalidad tiposNacionalidad[3] = {{1,"EEUU",1},{2,"CHINA",1},{3,"OTRO",1}};
    eTipoProducto tipos[4] = {{1000,"iphone",1,2},{1001,"ipad",1,3},{1002,"mac",1,1},{1003,"accesorios",1,3}};
    eFabricante fabricantes[3] = {{1,"Foxconn"},{2,"Sharp"},{3,"Japan Display Inc"}};
    eProducto listaDeProductos[T] = {
        {1,"Sony",100,1000,1,1},
        {2,"Abra",400,1000,1,1},
        {3,"Rayo",400,1003,2,1},
        {4,"Caballo",300,1000,3,1}

    };

    //eProducto listaDeProductos[T];
    //eTipoProducto tipos[4];
    //eNacionalidad tiposNacionalidad[3];
    int opcion;
    int retorno;
    int retornoIdTipo;
    int retornoIdNacionalidad;
    int retornoIdFabricante;

    //InicializarProductos(listaDeProductos, T);
    //inicializarTipos(tipos, 4);
    //inicializarNacionalidades(tiposNacionalidad, 3);

    setbuf(stdout, NULL);

    do
    {
      opcion=menu();

      switch(opcion)
      {
          case 1:
            retorno = verificarTiposDeAlta(tipos, 4);
            if(retorno == 1)
            {
               retorno = verificarNacionalidadesDeAlta(tiposNacionalidad, 3);
               if(retorno == 1)
               {
                  retorno =  AltaProducto(listaDeProductos, T , tiposNacionalidad, tipos);
                  if(retorno !=-1)
                  {
                    printf("producto ingresado con exito!!!\n");
                  }
                  else
                  {
                    printf("No hay mas lugar en la lista!!\n");
                  }

               }
               else
               {
                    printf("Por favor haga un alta de nacionalidad!!\n");
               }

            }
            else
            {
                printf("Por favor haga un alta de tipo!!\n");
            }
          break;

          case 2:
            bajaProducto(listaDeProductos, T);
          break;

          case 3:
            modificarProducto(listaDeProductos, T, tipos);
          break;

          case 4:
            MostrarListadoDeProductos(listaDeProductos, T, tiposNacionalidad, tipos);
          break;

          case 5:
            ordenarProductosPorPrecio(listaDeProductos, T);
            MostrarListadoDeProductos(listaDeProductos, T, tiposNacionalidad, tipos);
          break;

          case 6:
            ordenarProductosPorDescripcion(listaDeProductos, T);
            MostrarListadoDeProductos(listaDeProductos, T, tiposNacionalidad, tipos);
          break;

          case 7:
            productosMasCaro(listaDeProductos, T, tiposNacionalidad, tipos);
          break;

          case 8:
            promedioPorTipoDeProducto(listaDeProductos, T, tipos, 4);
          break;

          case 9:
            MostrarListadoDeProductos(listaDeProductos, T, tiposNacionalidad, tipos);
          break;

          case 10:
            listarPorCadaTipoLosProductos(listaDeProductos, T, tipos, 4, tiposNacionalidad);
          break;

          case 11:
            tiposDeProductosMasElaborados(listaDeProductos, T, tipos, 4);
          break;

          case 12:
            nacionalidadFabricanteDeIphone(listaDeProductos, T, tipos, tiposNacionalidad, 3);
          break;

          case 13:
            ordenarProductosAlfabeticamentePorNacionalidad(listaDeProductos, T, tiposNacionalidad, 3);
            MostrarListadoDeProductos(listaDeProductos, T, tiposNacionalidad, tipos);
          break;

          case 14:
            nacQueFabricaMasTip(listaDeProductos, T, tiposNacionalidad, 3);
          break;

          case 15:
            promedioPorNac(listaDeProductos, T, tiposNacionalidad, 3);
          break;

          case 16:
            opcion=menuTipo();
            switch(opcion)
            {
                case 1:
                   retorno =  altaTipo(tipos, 4);
                   if(retorno !=-1)
                   {
                        printf("tipo ingresado con exito!!!\n");
                   }
                   else
                   {
                        printf("No hay mas lugar en la lista!!\n");
                   }
                break;

                case 2:
                   retornoIdTipo=bajaTipo(tipos, 4);
                   borrarEnCascadaTipo(retornoIdTipo, listaDeProductos, T);
                break;

                case 3:
                   modificarTipo(tipos , 4);
                break;

            }
          break;

          case 17:
            opcion=menuNacionalidad();
            switch(opcion)
            {
                case 1:
                   retorno =  altaNacionalidad(tiposNacionalidad, 3);
                   if(retorno !=-1)
                   {
                        printf("nacionalidad ingresado con exito!!!\n");
                   }
                   else
                   {
                        printf("No hay mas lugar en la lista!!\n");
                   }
                break;

                case 2:
                   retornoIdNacionalidad=bajaNacionalidad(tiposNacionalidad, 3);
                   borrarEnCascadaNacionalidad(retornoIdNacionalidad, listaDeProductos, T);
                break;

                case 3:
                   modificarNacionalidad(tiposNacionalidad , 3);
                break;

            }
          break;

          case 18:
            retornoIdFabricante=ingresarIdFabricante(fabricantes, 3);
            MostrarListConFabr(retornoIdFabricante, listaDeProductos, T, tiposNacionalidad, tipos, fabricantes);
          break;
      }

    } while(opcion!=19);


    return 0;
}
