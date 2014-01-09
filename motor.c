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
    abrir_archivo("1816_La-guardia-blanca_Arthur-Conan-Doyle.txt");
    tokenizar();

    return 0;

}
