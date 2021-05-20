#include "fabricante.h"
#include <stdio.h>
//#include <stdio_ext.h>
#define VACIO 0
#define OCUPADO 1

int ingresarIdFabricante(eFabricante listaFabricante[], int tam)
{
    int validarFabr;
    eFabricante miFabricante;

    printf("Ingrese id fabricante: \n");
    scanf("%d", &miFabricante.idFabricante);
    validarFabr=validarFabricante(miFabricante.idFabricante, listaFabricante, 3);
    while(validarFabr==0)
    {
        printf("Error: Ingrese id fabricante de nuevo\n");
        scanf("%d", &miFabricante.idFabricante);
        validarFabr=validarFabricante(miFabricante.idFabricante, listaFabricante, 3);
    }

    return miFabricante.idFabricante;
}

int validarFabricante(int id, eFabricante lista[], int tam)
{
    int i;
    int validar;

    validar=0;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idFabricante)
        {
            validar=1;
            break;
        }
    }

    return validar;
}

eFabricante buscarFabrPorId(int id, eFabricante lista[], int tam)
{
    int i;
    eFabricante unFabricante;

    for (i=0;i<tam;i++)
    {
        if (id==lista[i].idFabricante)
        {
            unFabricante=lista[i];
            break;
        }

    }

    return unFabricante;
}
