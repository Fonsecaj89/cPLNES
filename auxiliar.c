#include <stdio.h>
#include <string.h>
#include "auxiliar.h"

void agregar_a_cadena(char* cadena, char letra)
{
    int len;
    len = strlen(cadena);
    cadena[len] = letra;
}

void final_cadena(char * cadena_completa)
{
    int len;
    len = strlen(cadena_completa);
    cadena_completa[len] = '\0';
}
