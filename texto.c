#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // for isspace()
#include <stdbool.h> // for bool, true, false
#include "texto.h"


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

void tokenizar()
{
    
    char caracteres;
    char *con;
    long n_chars = 0L;
    
            /*char prev;
    
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    int 
    bool inword = false;
    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';
        */
    while ((caracteres = getc(fp)) != EOF)
    {
        *con = *con + caracteres;
        printf("%d\n",con[n_chars++]);
        
            /*
        n_chars++;

        if (caracteres == '\n')
            n_lines++;

        if (!isspace(caracteres) && !inword)
        {
            inword = true; // starting a new word
            n_words++;
        }
        
        if (isspace(caracteres) && inword)
            inword = false; // reached end of word
        prev = caracteres;*/
        

    }
        /*if (prev != '\n')
        p_lines = 1;
    printf("characters = %ld, words = %d, lines = %d, ",n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);*/

}
