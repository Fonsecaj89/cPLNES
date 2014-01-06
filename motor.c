/*
 * Motor de Procesamiento de Lenguaje Natural del Español.
 * Clase principal del sistema.
 */


#include <stdio.h>
#include "texto.h"


int main()
{
    int ch;
    abrir_archivo("datos.txt");
    printf("Puntero del archivo %p\n",fp);

    tokenizar();
    
    cerrar_archivo();
    printf("Puntero del archivo %p\n",fp);


    return 0;

}
