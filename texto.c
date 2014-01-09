#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // for isspace()
#include <stdbool.h> // for bool, true, false
#include "texto.h"
#include "auxiliar.h"


FILE * fp;
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
    current_size = len_max;

    printf("\nEnter a very very very long String value:");

    if(pStr != NULL)
    {
    int c = EOF;
    unsigned int i =0;
        //accept user input until hit enter or end of file
    while ((caracteres = getc(fp)) != EOF)
    {
        pStr[i++]=(char)c;

        //if i reached maximize size then realloc size
        if(i == current_size)
        {
                        current_size = i+len_max;
            pStr = realloc(pStr, current_size);
        }
    }

    pStr[i] = '\0';

        printf("\nLong String value:%s \n\n",pStr);
        //free it 
    free(pStr);
    pStr = NULL;


    }
    
}

void tokenizar()
{
    char caracteres;
    int n_caracteres = 0;
    int n_lineas = 0;
    int n_palabras = 0;
    int n_retornoc = 0;
    char * str;
    
    bool estado;
    
    str = obtener_texto();
    printf("%s\n",str);
    
    while ((caracteres = getc(fp)) != EOF)
    {
        agregar_a_cadena(cadena,caracteres);
        
        
        //Conteo de caracteres
        ++n_caracteres;
        //Conteo de lineas
        if(caracteres == '\n')
            ++n_lineas;
        //Conteo de retorno de carro
        if(caracteres == '\r')
            ++n_retornoc;
        
        //conteo de palabras
        if(caracteres == ' ' || caracteres == '\n' || caracteres == '\t')
        {
            estado = false;
        }
        else
        {
            estado = true;
            ++n_palabras;
            
        }
    }
    printf("Nº de caracteres %d, Nº lineas %d, Nº retorno %d, Nº palabras %d\n",n_caracteres,n_lineas,n_retornoc,n_palabras);
}
