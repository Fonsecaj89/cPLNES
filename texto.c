#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // for isspace()
#include <stdbool.h> // for bool, true, false
#include "texto.h"
#include "auxiliar.h"


FILE * fp;
char * pStr;
char caracteres;
int n_palabras = 0;
int n_lineas = 0;
int n_caracteres = 0;

void abrir_archivo(char * filename)
{
 
    fp = fopen(filename, "r"); // open file for reading
    
    if (fp == NULL)
    // attempt failed
    {
        printf("Failed to open file. Bye\n");
        exit(1);
        // quit program
    }
   
}

void cerrar_archivo()
{
    fclose(fp);
}

void obtener_texto()
{
    unsigned int len_max = 128;
    unsigned int current_size = 0;
    char *pStr = malloc(len_max);
    char caracteres;
    current_size = len_max;

    if(pStr != NULL)
    {

    unsigned int i =0;
        //accept user input until hit enter or end of file
    while ((caracteres = getc(fp)) != EOF)
    {
        pStr[i++]=(char)caracteres;

        //if i reached maximize size then realloc size
        if(i == current_size)
        {
                        current_size = i+len_max;
            pStr = realloc(pStr, current_size);
        }
        obtener_total_palabras(caracteres);
        obtener_total_lineas(caracteres);
        obtener_total_caracteres(caracteres);
       
    }

    pStr[i] = '\0';

    printf("\nLong String value: \n\n %s \n\n",pStr);
    size_t tamanio;
    tamanio = strlen(pStr);
    
    printf("Tamaño del string %d\n",tamanio);
    
    }
}

void limpiar_pStr()
{
    free(pStr);
    pStr = NULL;
    printf("Listo, memory limpiada\n");
    
}

void obtener_total_palabras(char ctp)
{
    bool estado;
    
    if(ctp == ' ' || ctp == '\n' || ctp == '\t')
    {
        estado = false;
    }
    else
    {
        estado = true;
        ++n_palabras;
    }
//    return n_palabras;
}

void obtener_total_lineas(char ctl)
{
    //Conteo de lineas
    if(ctl == '\n')
        ++n_lineas;
        //return n_lineas;
}

void obtener_total_caracteres(char ctc)
{
    //Conteo de caracteres
    ++n_caracteres;
        //   return n_caracteres;
}


int total_palabras()
{
    return n_palabras;
}
int total_lineas()
{
    return n_lineas;
}
int total_caracteres()
{
    return n_caracteres;
}

void tokenizar()
{

}
