/*
 *
 *
 *
 *
 */

#include "validaciones.h"

int validarEntero(char str[])
{
	int i;
	int validar;

	i=0;
	validar=1;

	while (str[i] != '\0')
	{
		if(str[i]<'0' || str[i]>'9')
		{
			validar=0;
			break;
		}

		i++;

	}

	return validar;
}

int validarLetras(char str[])
{
   int validar;
   int i;

   i=0;
   validar=1;

   while(str[i]!='\0')
   {
        if((str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z') && (str[i]!=' '))
        {
               validar=0;
               break;
        }

        i++;
   }

   return validar;
}
