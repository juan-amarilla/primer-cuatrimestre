typedef struct
{
    int idFabricante;
    char descripcionFabricante[30];

}eFabricante;

int ingresarIdFabricante(eFabricante listaFabricante[], int tam);
int validarFabricante(int id, eFabricante lista[], int tam);
eFabricante buscarFabrPorId(int id, eFabricante lista[], int tam);
