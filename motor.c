/*
 * Motor de Procesamiento de Lenguaje Natural del Español.
 * Clase principal del sistema.
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "texto.h"
#include "auxiliar.h"


int main()
{

    int ch;
    abrir_archivo("datos.txt");
    obtener_texto();
    tokenizar();

    return 0;

}
