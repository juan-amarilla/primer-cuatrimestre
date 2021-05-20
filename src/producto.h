typedef struct
{

    int idProducto;
    char descripcion[30];
    float precioDecimal;
    int idTipo;
    int idNacionalidad;
    int isEmpty;

}eProducto;

int BuscarLibreProducto(eProducto lista[], int tam);
void InicializarProductos(eProducto lista[], int tam);
void bajaProducto(eProducto lista[], int tam);
void ordenarProductosPorPrecio(eProducto lista[], int tam);
void ordenarProductosPorDescripcion(eProducto lista[], int tam);
void borrarEnCascadaTipo(int id, eProducto lista[], int tam);
void borrarEnCascadaNacionalidad(int id, eProducto lista[], int tam);
