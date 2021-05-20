typedef struct
{
    int idNacionalidad;
    char descripcionNacionalidad[30];
    int isEmpty;

}eNacionalidad;

int validarNacionalidad(int id, eNacionalidad lista[], int tam);
eNacionalidad buscarNacPorId(int id, eNacionalidad lista[], int tam);
int menuNacionalidad();
int altaNacionalidad(eNacionalidad lista[], int tam);
int buscarLibreNacionalidad(eNacionalidad lista[], int tam);
eNacionalidad pedirDatosNacionalidad();
void inicializarNacionalidades(eNacionalidad lista[], int tam);
int bajaNacionalidad(eNacionalidad lista[], int tam);
void modificarNacionalidad(eNacionalidad lista[], int tam);
int verificarNacionalidadesDeAlta(eNacionalidad lista[], int tam);
