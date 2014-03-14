/*
    Simple singly linked lists example usage; it is only one of
    many possible implementations - try your own enchancements.
*/
 
#include <stdio.h>
#include <stdlib.h>
 

 

 
int main(void)
{
    Node *node_head = NULL; //pointer to stack head
 
    //example usage:
    lista_agregar(&node_head, 7); //push value 7 onto stack
    printf("%d\n", node_head -> data); //show stack head value
    lista_agregar(&node_head, 21); //push value 21 onto stack
	lista_agregar(&node_head, 4); //push value 21 onto stack
	lista_agregar(&node_head, 325346521); //push value 21 onto stack
	lista_agregar(&node_head, 212234234); //push value 21 onto stack
	printf("La lista tiene %i items\n",longitud_lista(&node_head));
    print_lista(&node_head); //print the stack
    if(lista_buscar(&node_head, 7)) puts("found 7"); //does 7 belong to the stack?
    lista_agregar_inicio(&node_head, 0); //append 0 to the end of the stack
    print_lista(&node_head); //print the stack
    printf("%d\n", lista_eliminar_item(&node_head)); //pop the stack's head
    print_lista(&node_head); //print the stack
    eliminar_lista(&node_head); //clear the stack
    print_lista(&node_head); //print the stack
     
    getchar();
    return 0;
}
 
