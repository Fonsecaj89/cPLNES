typedef struct Lista_str Lista_str;
struct Lista_str
{
    int val;
    char * item_str;
    Lista_str *next;
};

extern char * cadena;

void agregar_a_cadena(char* cadena, char letra);
void final_cadena(char * cadena);
void limpiar_cadena(char * cadena);
Lista_str * crear_lista_str(char *val);
Lista_str * agregar_a_lista(char * ln);
Lista_str * buscar_en_lista(char * ln, Lista_str **prev);
int borrar_de_lista(char * ln);
void imprimir_lista();
