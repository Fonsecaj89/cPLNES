#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "auxiliar.h"

/*Variables globales*/

char * cadena;
Node *node_head = NULL;

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

char *reemplazar_string(char *str, char *orig, char *rep)
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
 * Manejo de Listas
 * *********************************************** */
int longitud_lista(Node **node_head)
{
    Node *node_curr = *node_head;
    int len = 0;
     
	if(!node_curr)
    {
	    return len;
	}
    else
    {
	    while(node_curr)
        {
            ++len;
            node_curr = node_curr -> next;
        }
        return len;
	}

}
 
void lista_agregar_inicio(Node **node_head, stack_data d)
{
    Node *node_new = malloc(sizeof(Node));
     
    node_new -> data = d;
    node_new -> next = *node_head;
    *node_head = node_new;
}
 
stack_data lista_eliminar_item(Node **node_head)
{
    Node *node_togo = *node_head;
    stack_data d;
     
    if(node_head)
    {
        d = node_togo -> data;
        *node_head = node_togo -> next;
        free(node_togo);
    }
    return d;
}
 
void print_lista(Node **node_head)
{
    Node *node_curr = *node_head;
     
    if(!node_curr)
        puts("the stack is empty");
    else
    {
        while(node_curr)
        {
            printf("%s ", node_curr -> data); //set for integers, modifiable
            node_curr = node_curr -> next;
        }
        putchar('\n');
    }
}
 
void eliminar_lista(Node **node_head)
{
    while(*node_head)
        lista_eliminar_item(node_head);
}
 
void lista_agregar(Node **node_head, stack_data d)
{
    Node *node_curr = *node_head;
     
    if(!node_curr)
        lista_agregar_inicio(node_head, d);
    else
    {
        //find the last node
        while(node_curr -> next)
            node_curr = node_curr -> next;
        //build the node after it
        lista_agregar_inicio(&(node_curr -> next), d);
    }
}
 
int lista_buscar(Node **node_head, stack_data d)
{
    Node *node_curr = *node_head;
     
    while(node_curr)
    {
        if(node_curr -> data == d) //set for numbers, modifiable
            return 1;
        else
            node_curr = node_curr -> next;
    }
    return 0;
}
