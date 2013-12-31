#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

char* abrir_archivo(char *filename)
{
   char *buffer = NULL;
   int string_size,read_size;
   FILE *handler = fopen(filename,"r");

   if (handler)
   {
       //seek the last byte of the file
       fseek(handler,0,SEEK_END);
       //offset from the first to the last byte, or in other words, filesize
       string_size = ftell (handler);
       //go back to the start of the file
       rewind(handler);

       //allocate a string that can hold it all
       buffer = (char*) malloc (sizeof(char) * (string_size + 1) );
       //read it all in one operation
       read_size = fread(buffer,sizeof(char),string_size,handler);
       //fread doesnt set it so put a \0 in the last position
       //and buffer is now officialy a string
       buffer[string_size+1] = '\0';

       if (string_size != read_size) {
           //something went wrong, throw away the memory and set
           //the buffer to NULL
           free(buffer);
           buffer = NULL;
        }
    }

    return buffer;
}


char** tokenizar(char *string)
{
        /*  char *array[1000000];
    int i;
         printf("%s\n",string);
    
    array[i] = strtok(string," ,.\r\n");
    
    while(array[i])
    {
        array[++i] = strtok(NULL," ,.\r\n");
        if(array[i]=='\0')
            break;
        printf("%s\n",array[i]);
    }
    return array[800];

*/
    char ** res;
    char *  p    = strtok (string, " ,.\r\n");
    int n_spaces = 0, i;

    /* split string and append tokens to 'res' */
    while (p) {
        res = realloc (res, sizeof (char*) * ++n_spaces);

        if (res == NULL)
            exit (-1); /* memory allocation failed */

        res[n_spaces-1] = p;
        p = strtok (NULL, " ,.\r\n");
    }
       
    return res;
}


char** parrafo(char *string) {
   
    char ** res;
    char *  p    = strtok (string, "\n");
    int n_spaces = 0, i;

    /* split string and append tokens to 'res' */
    while (p) {
        res = realloc (res, sizeof (char*) * ++n_spaces);

        if (res == NULL)
            exit (-1); /* memory allocation failed */

        res[n_spaces-1] = p;
        p = strtok (NULL, "\n");
    }
       
    return res;
}

void prueba()
{
    char *a = abrir_archivo("1816_La-guardia-blanca_Arthur-Conan-Doyle.txt");

        /*char** (*ptoken)(char*);
    ptoken = tokenizar;
    char** token = ptoken(a);
    for(int i = 0; i < strlen(token); i++)
    {
        printf("%s\n",token[i]);
    }
        */

    char *array[1000000];
    int i;
    printf("%s\n",a);
    
    array[i] = strtok(a," ,.");
    
    while(array[i])
    {
        array[++i] = strtok(NULL," ,.");
        if(array[i]=='\0')
            break;
        printf("%s\n",array[i]);
       
    }
    
    
}

void concatenar()
{
        /* int espacio = 0;
    char * cadena;
    char *a = abrir_archivo("datos.txt");
    char** (*ptoken)(char*);
    ptoken = tokenizar;
    char** token = ptoken(a);
   
    
    for(int i = 0; i < strlen(token); i++)
    {
        if(token[i] == "\r")
        {
            espacio+=1;
        }
        printf("%d %s\n",espacio,token[i]);
   
    }
        */
}
