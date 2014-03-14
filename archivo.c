#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "archivo.h"
#include "texto.h"
#include "auxiliar.h"

DIR *dp;
struct dirent *entry;
int contador_archivo = 0;
char * nombre_archivo;

void contar_archivos()
{
	++contador_archivo;
}

int total_archivos()
{
	return contador_archivo;
}

/* Enlista los archivos dentro de una carpeta*/
int listdir(const char *path)
{

	dp = opendir(path);
	if (dp == NULL) {
		perror("opendir");
		return -1;
	}

	while((entry = readdir(dp)))
	{
		contar_archivos();
		nombre_archivo = entry->d_name;
		lista_agregar(&node_head,nombre_archivo);
	}
}
/*
void ver_lista()
{
	printf("La lista tiene %i items\n",longitud_lista(&node_head));
	print_lista(&node_head);
}
*/

void cerrar_directorio()
{
	closedir(dp);
}

void procesarArchivos()
{
	char * aux;
	aux = NULL;
	
	while(node_head)
    {
		nombre_archivo = node_head->data;

		if(aux == NULL)
		{
			aux =  nombre_archivo;
			
			if(!strcmp(nombre_archivo, ".."))
				printf("");
			else if(!strcmp(nombre_archivo, "."))
				printf("");
			else
			{
				abrir_archivo(nombre_archivo);
				obtener_texto();
				preprocesar_texto();
				tokenizar();
				limpiar_pStr();
				printf("Total de palabras: %d\n",total_palabras());
				printf("Total de lineas: %d\n",total_lineas());
				printf("Total de caracteres: %d\n",total_caracteres());
				cerrar_archivo();
			    printf("\n\n");
			}
		}
		else
		{
			printf("Ya está guardado");
		}

		aux = NULL;
		node_head = node_head -> next;
	}
}
