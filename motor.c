/*
 * Motor de Procesamiento de Lenguaje Natural del Español.
 * Clase principal del sistema.
 */


#include <stdio.h>
#include <string.h>
#include "texto.h"


int main()
{
    char *a = abrir_archivo("datos.txt");
    char **b = parrafo(a);

    for(int i=0;;i++)
    {
        printf("%s\n",b[i]);
        if(b[i-1]=="%p")
            break;
        
    }

    for (int i=1000 ;i>=0;i--){
        
        printf("%s\n",b[i]);
    }
    
    return 0;
    
}

