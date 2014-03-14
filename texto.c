#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <iconv.h>
#include <errno.h>
#include <stdbool.h> // for bool, true, false
#include "texto.h"
#include "auxiliar.h"


FILE * fp;
char * pStr;
char * texto_convertido;
char * ubicacion;
char caracteres;
char caracteresp;
int n_palabras = 0;
int n_lineas = 0;
int n_caracteres = 0;
int n_caracteresp = 0;
unsigned char * txt_ppro;

/* The names of the input and output encodings. */
const char * LATINSET = "ISO-8859-1";
const char * OUTSET = "UTF-8";


void abrir_archivo(char * filename)
{

	char * directorio = "recursos/";

	char * ubicacion = ubicacion_archivo(directorio,filename);
	
	fp = fopen(ubicacion, "r"); // open file for reading
    
    if (fp == NULL)
    // attempt failed
    {
        printf("Failed to open file. Bye\n");
        exit(EXIT_FAILURE);
        // quit program
    }
	printf("Archivo Abierto\n");
	limpiar_ubicacion();
}

char * ubicacion_archivo(char * directorio, char * archivo)
{
	char * ubicacion = malloc(snprintf(NULL, 0, "%s%s", directorio, archivo) + 1);
	sprintf(ubicacion, "%s%s", directorio, archivo);

	printf("Abriendo Archivo -> %s\n", ubicacion);

	return ubicacion;
}

void limpiar_ubicacion()
{
	free(ubicacion);
	ubicacion = NULL;
}

void cerrar_archivo()
{
    fclose(fp);
}

void obtener_texto()
{
	printf("Obteniendo Texto\n");
    unsigned int len_max = 250;
    unsigned int current_size = 0;
    char caracteres;
    pStr = malloc(len_max);
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

    //printf("\nLong String value: \n\n %s \n\n",pStr);
    }
	printf("Texto Obtenido\n");
}

void limpiar_pStr()
{
    free(pStr);
    pStr = NULL;
    
}

void limpiar_texto_procesado()
{
    free(txt_ppro);
    txt_ppro = NULL;
    
}

void obtener_total_palabras(char ctp)
{
    bool estado;
    
    if(ctp == ' ' || ctp == '\n' || ctp == '\t' || ctp == '\r')
    {
        estado = false;
    }
    else
    {
        estado = true;
        ++n_palabras;
    }
}

void obtener_total_lineas(char ctl)
{
    //Conteo de lineas
    if(ctl == '\n')
        ++n_lineas;
}

void obtener_total_caracteres(char ctc)
{
    //Conteo de caracteres
    ++n_caracteres;
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

int total_caracteres_procesados()
{
	n_caracteresp = strlen(txt_ppro);
    return n_caracteresp;
}

char * texto_a_procesar()
{
    return pStr;
}

unsigned char * texto_procesado()
{
    return txt_ppro;
}


char * codificar_texto()
{
	int v;
	char * utf8;
    unsigned int len;
    unsigned int utf8len;
	size_t icodificacion;
	iconv_t codificaciones;
	/* The variables with "start" in their name are solely for display of what the function is doing. As iconv runs, it alters the values of the variables, so these are for keeping track of the start points and start lengths. */
	int len_start;
    int utf8len_start;
    const char * euc_start;
    

	/*Inicio de la conexion con la libreria iconv*/
	char * a_procesar = texto_a_procesar();

    codificaciones = iconv_open(OUTSET, LATINSET);

    if ((int) codificaciones == -1)
	{
		/* Initialization failure. */
		if (errno == EINVAL) {
			fprintf (stderr,"La conversion de '%s' a '%s' no esta soportada.\n", LATINSET, OUTSET);
		}
		else
		{
			fprintf (stderr, "Initialization failure: %s\n",strerror (errno));
		}
		exit (1);
    }

    /* Codificacion del texto*/
    len = strlen(a_procesar);
    if (!len)
	{
		fprintf (stderr, "Input string is empty.\n");
		return (0);
    }

    /* Assign enough space to put the UTF-8. */
    utf8len = 2*len;
    utf8 = calloc (utf8len, 1);
    /* Keep track of the variables. */
    len_start = len;
    utf8len_start = utf8len;
    texto_convertido = utf8;
    euc_start = a_procesar;

	icodificacion = iconv(codificaciones, &a_procesar, & len, & utf8, & utf8len);

    /* Handle failures. */
    if (icodificacion == (size_t) -1)
	{
		fprintf (stderr, "iconv failed: in string '%s', length %d, out string '%s', length %d\n", a_procesar, len, texto_convertido, utf8len);
		switch (errno)
		{
			/* See "man 3 iconv" for an explanation. */
	        case EILSEQ:
				fprintf (stderr, "Invalid multibyte sequence.\n");
				break;
	        case EINVAL:
				fprintf (stderr, "Incomplete multibyte sequence.\n");
				break;
  	        case E2BIG:
				fprintf (stderr, "No more room.\n");
				break;
	        default:
				fprintf (stderr, "Error: %s.\n", strerror (errno));
		}
		exit (1);
    }

   /*Finalizacion de la conexion con la libreria de conversion */
    v = iconv_close (codificaciones);
    if (v != 0)
	{
		fprintf (stderr, "iconv_close failed: %s\n", strerror (errno));
		exit (1);
	}

	/*Mostrar El texto codificado*/
	if (texto_convertido) {
		printf ("Final iconv output: \n%s\n", texto_convertido);
    }
	
	return texto_convertido;
}

void preprocesar_texto()
{
	printf("Preprocesando Texto\n");
    bool bb;
    unsigned int ii = 0, jj = 0, ln = 0, sl = 0,m=0;
    unsigned int t_len_max = 250;
    unsigned int t_current_size = 0;
    char * ppstr = codificar_texto();
    txt_ppro = malloc(t_len_max);
    t_current_size = t_len_max;
    
    for (ii = 0;ii<total_caracteres();ii++)
    {
        
        if(ppstr[ii] == '\r' && ppstr[ii+1] == '\n')
            bb = true;
        else if(ppstr[ii] == '\n')
        {
            
            if(bb == true)
            {
                jj = jj - 1;
                txt_ppro[jj++] = ' ';
                continue;
            }
            else
            {
                txt_ppro[jj++] = ' ';
            }

        }
        else
        {
            bb = false;
        }
        txt_ppro[jj++] = ppstr[ii];

        if(jj == t_current_size)
        {
            t_current_size = jj+t_len_max;
            txt_ppro = realloc(txt_ppro, t_current_size);
            
        }
    }
    txt_ppro[jj] = '\0';
    printf("\nArchivo procesado\n%s\nTamaño: %d\n",txt_ppro,strlen(txt_ppro));
}

void tokenizar()
{
	printf("Tokenizando\n");
    bool bp;
    
    unsigned char * token;
    unsigned int iii = 0, jjj = 0;
    unsigned int t_len_maxt = 256;
    unsigned int t_current_sizet = 0;
    unsigned char * pstrr = texto_procesado();
    token = malloc(t_len_maxt);
    t_current_sizet = t_len_maxt;
    
    for (iii = 0;iii<total_caracteres_procesados();iii++)
    {
		if(pstrr[iii] == EOF)
        {
			break;
		}

        if(pstrr[iii] == '\t' || pstrr[iii] == '\r' || pstrr[iii] == '\n')
        {
            continue;
        }
        
        if(pstrr[iii] == ' ' || pstrr[iii] == '\n')
        {
            token[jjj] = '\0';
            //printf("Tamaño: %d, Palabra: %s\n",strlen(token),token);
            jjj = 0;
            bp = false;
            free(token);
            token = NULL;
            token = malloc(t_len_maxt);
            
        }
        else
        {
            bp = true;
        }

        if(bp == true)
        {
            token[jjj++] = pstrr[iii];
            if(jjj == t_current_sizet)
            {
                t_current_sizet = jjj+t_len_maxt;
                token = realloc(token, t_current_sizet);
            }
        }
        else
        {
            continue;
        }
    } 

}
