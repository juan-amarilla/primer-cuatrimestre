typedef struct
{
    int idTipo;
    char descripcionTipo[30];
    int isEmpty;
    int idFabricante;

}eTipoProducto;

int validarTipo(int id, eTipoProducto lista[], int tam);
eTipoProducto buscarTipPorId(int id, eTipoProducto lista[], int tam);
void listarTipos(eTipoProducto lista[], int tam);
int menuTipo();
void inicializarTipos(eTipoProducto lista[], int tam);
int altaTipo(eTipoProducto lista[], int tam);
int buscarLibreTipo(eTipoProducto lista[], int tam);
eTipoProducto pedirDatosTipo();
int verificarTiposDeAlta(eTipoProducto lista[], int tam);
int bajaTipo(eTipoProducto lista[], int tam);
void modificarTipo(eTipoProducto lista[], int tam);
