#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // for bool, true, false
#include "texto.h"
#include "auxiliar.h"


FILE * fp;
char * pStr;
char caracteres;
char caracteresp;
int n_palabras = 0;
int n_lineas = 0;
int n_caracteres = 0;
int n_caracteresp = 0;
unsigned char * txt_ppro;

void abrir_archivo(char * filename)
{

	errno = 0;
    fp = fopen(filename, "rb"); // open file for reading
    
    if (fp == NULL)
    // attempt failed
    {
        printf("Failed to open file. Bye\n");
		printf("Error %d \n", errno);
        exit(EXIT_FAILURE);
        // quit program
    }
   
}

void cerrar_archivo()
{
    fclose(fp);
}

void obtener_texto()
{
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

void preprocesar_texto()
{
    bool bb;
    unsigned int ii = 0, jj = 0, ln = 0, sl = 0,m=0;
    unsigned int t_len_max = 250;
    unsigned int t_current_size = 0;
    char * ppstr = texto_a_procesar();
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
//    printf("\nArchivo procesado\n%s\nTamaño: %d\n",txt_ppro,strlen(txt_ppro));
}

void tokenizar()
{
  
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
