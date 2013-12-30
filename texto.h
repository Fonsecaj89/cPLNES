#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


/*void palabra(const char *string) {
    // Make a local copy of the string that we can manipulate.
    char * const copy = strdup(string);
    char *space = copy;
    // Find the next space in the string, and replace it with a newline.
    while (space = strchr(space,' ')) *space = '\n';
    // There are no more spaces in the string; print out our modified copy.
    printf("%s\n", copy);
    // Free our local copy
    free(copy);
    }*/

char* tokenizar(char *string) {
    char * pch;
    pch = strtok(string," ,.-");
    while (pch != NULL)
    {
        printf("%s\n",pch);
        pch = strtok(NULL, " ,.-");
    }
    return pch;
}

char** parrafo(char *string) {
   
    char ** res  = NULL;
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
