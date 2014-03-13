#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "auxiliar.h"

/*Variables globales*/

Lista_str *head = NULL;
Lista_str *curr = NULL;
char * cadena;


/* ***********************************************
 * Manejo de String
 * *********************************************** */
void agregar_a_cadena(char* cadena, char letra)
{
    

    size_t len = strlen(cadena);
    cadena[len] = letra;
        //  printf("%s\n",cadena);
}

void final_cadena(char * cadena)
{
    int len;
    len = strlen(cadena);
    cadena[len] = '\0';
}

void limpiar_cadena(char * cadena)
{
    cadena = "";
    printf("%s\n",cadena);
    printf("Esta mierda sirvio");
    
}

char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}
/* ***********************************************
 * Ejemplo de Manejo de Listas
 * *********************************************** */
Lista_str * crear_lista_str(char * ln)
{
    Lista_str *ptr = (Lista_str*)malloc(sizeof(Lista_str));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->item_str = "";
    ptr->next = NULL;

    head = curr = ptr;

    
    return ptr;
}

Lista_str * agregar_a_lista(char * ln)
{
    if(NULL == head)
    {
        crear_lista_str(ln);
    }

    Lista_str *ptr = (Lista_str*)malloc(sizeof(Lista_str));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->item_str = ln;
    ptr->next = NULL;
    curr->next = ptr;
    curr = ptr;

    return ptr;
}

Lista_str * buscar_en_lista(char * ln, Lista_str **prev)
{
    Lista_str *ptr = head;
    Lista_str *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%s] \n",ln);

    while(ptr != NULL)
    {
        if(ptr->item_str == ln)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

int borrar_de_lista(char * ln)
{
    Lista_str *prev = NULL;
    Lista_str *del = NULL;

    printf("\n Deleting value [%s] from list\n",ln);

    del = buscar_en_lista(ln,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

void imprimir_lista()
{
    Lista_str *ptr = head;

    while(ptr != NULL)
    {
        printf("%s\n",ptr->item_str);
        ptr = ptr->next;
    }

    return;
}
