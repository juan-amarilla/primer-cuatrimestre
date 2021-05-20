#include "producto.h"
#include "nacionalidad.h"
#include "tipo.h"
#include "fabricante.h"

typedef struct{
    int id;
    int contador;
    float acumulador;

}eAuxiliar;

int menu();

eProducto PedirDatosProducto(eNacionalidad listaNacionalidad[], eTipoProducto listaTipo[]);
int AltaProducto(eProducto lista[], int tam, eNacionalidad listaNacionalidad[], eTipoProducto listaTipo[]);
void MostrarListadoDeProductos(eProducto lista[], int tam, eNacionalidad listaNac[], eTipoProducto listaTip[]);
void MostrarUnProducto(eProducto unProducto, eNacionalidad listaNac[], eTipoProducto listaTip[]);
void modificarProducto(eProducto listaPro[], int tam, eTipoProducto listaTip[]);
void productosMasCaro(eProducto lista[], int tam, eNacionalidad listaNac[], eTipoProducto listaTip[]);
void promedioPorTipoDeProducto(eProducto lista[], int tam, eTipoProducto listaTip[], int tamTip);
void listarPorCadaTipoLosProductos(eProducto lista[], int tam, eTipoProducto listaTip[], int tamTip, eNacionalidad listaNac[]);
void tiposDeProductosMasElaborados(eProducto lista[], int tam, eTipoProducto listaTip[], int tamTip);
void nacionalidadFabricanteDeIphone(eProducto lista[], int tam, eTipoProducto listaTip[], eNacionalidad listaNac[], int tamNac);
void ordenarProductosAlfabeticamentePorNacionalidad(eProducto lista[], int tam, eNacionalidad listaNac[], int tamNac);
void nacQueFabricaMasTip(eProducto lista[], int tam, eNacionalidad listaNac[], int tamNac);
void promedioPorNac(eProducto lista[], int tam, eNacionalidad listaNac[], int tamNac);
void MostrarListConFabr(int id,eProducto lista[], int tam, eNacionalidad listaNac[], eTipoProducto listaTip[], eFabricante listaFabr[]);
void MostrarUnProductoConFabr(eProducto unProducto, eNacionalidad listaNac[], eTipoProducto listaTip[], eFabricante listaFabr[]);
