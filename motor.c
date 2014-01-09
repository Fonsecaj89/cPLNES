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

    printf("Abriendo datos\n");
    abrir_archivo("datos.txt");
    obtener_texto();
    tokenizar();
    
    limpiar_pStr();
    printf("Total de palabras: %d\n",total_palabras());
    printf("Total de lineas: %d\n",total_lineas());
    printf("Total de caracteres: %d\n",total_caracteres());
    cerrar_archivo();

    printf("\nAbriendo 1816_La-guardia-blanca_Arthur-Conan-Doyle\n");
    
    abrir_archivo("1816_La-guardia-blanca_Arthur-Conan-Doyle.txt");
    obtener_texto();
    limpiar_pStr();
    printf("Total de palabras: %d\n",total_palabras());
    printf("Total de lineas: %d\n",total_lineas());
    printf("Total de caracteres: %d\n",total_caracteres());
    cerrar_archivo();
    
    return 0;

}
