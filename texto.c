#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char** tokenizar(char *string)
{

    char ** res;
    char *  p    = strtok (string, " ,.\r\n");
    int n_spaces = 0,i;

    /* split string and append tokens to 'res' */
    while (p) {
        res = realloc (res, sizeof (char*) * ++n_spaces);

        if (res == NULL)
            exit (-1); /* memory allocation failed */

        res[n_spaces-1] = p;
        p = strtok (NULL, " ,.\r\n");
        printf("%s\n",p);
        
    }
       
    return res;
}

/*
char** parrafo(char *stringp) {
   
    char ** res;
    char *  p    = strtok (stringp, " ,.\r\n");
    int n_spaces = 0, i;

  
    while (p) {
        res = realloc (res, sizeof (char*) * ++n_spaces);

        if (res == NULL)
            exit (-1); 

        res[n_spaces-1] = p;
        p = strtok (NULL, " ,.\r\n");
    }
       
    return res;
    
}
*/
/*int frecuencia(char *t)
{

    
    char *a;
    a = tokenizar(t);
    printf("Todo bien");
    return 0;
    
}


*/
