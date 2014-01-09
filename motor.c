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
    limpiar_pStr();
    printf("Total de palabras: %d\n",total_palabras());
    printf("Total de lineas: %d\n",total_lineas());
    printf("Total de caracteres: %d\n",total_caracteres());
    
    return 0;

}
