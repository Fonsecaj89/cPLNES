/*
 * Motor de Procesamiento de Lenguaje Natural del Español.
 * Clase principal del sistema.
 */


#include <stdio.h>
#include <string.h>
#include "texto.h"

int main()
{
    int contestants[] = {1, 2, 3};
    int *choice = contestants;
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    printf("I'm going to pick contestant number %i\n", contestants[2]);

    int drinks[] = {4, 2, 3};
    printf("1st order: %i drinks\n", drinks[1]);
    printf("1st order: %i drinks\n", *drinks);
    printf("3rd order: %i drinks\n", *(drinks + 2));

    char cards[] = "JQK";
    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);

    char s0[] = "dysfunctional";
    char s1[] = "fun";
    if (strstr(s0, s1))
        puts("I found the fun in dysfunctional!");

    char *string = abrir_archivo("datos.txt");
    /* if (string) {
        puts(string);
        free(string);
        }*/
  
//    tokenizar(string);
char** a = parrafo(string);

for(int i = 0; i < sizeof(a); i++) {
  for(int j = 0; j < sizeof(a[i]); j++)
    printf("%d ", a[i][j]);
  printf("\n");
}
    return 0;
}


