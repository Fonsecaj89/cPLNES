/*
 * Motor de Procesamiento de Lenguaje Natural del Español.
 * Clase principal del sistema.
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "archivo.h"


int main()
{

	listdir("recursos/");
	int ta = total_archivos();
	printf("Total Archivos guardados: %i\n",ta);
	procesarArchivos();
return 0;


}
