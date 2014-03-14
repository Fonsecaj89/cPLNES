typedef char * stack_data; //Puede ser cambiada
typedef struct Lista Node; //short name for the stack type
struct Lista //stack structure format
{
    stack_data data;
    Node *next;
};

extern char * cadena;
extern Node *node_head;

void agregar_a_cadena(char* cadena, char letra);
void final_cadena(char * cadena);
void limpiar_cadena(char * cadena);
char *reemplazar_lista(char *str, char *orig, char *rep);

void lista_agregar_inicio(Node **node_head, stack_data d); //pushes a value d onto the stack
stack_data lista_eliminar_item(Node **node_head); //removes the head from the stack & returns its value
void print_lista(Node **node_head); //prints all the stack data
void eliminar_lista(Node **node_head); //clears the stack of all elements
void lista_agregar(Node **node_head, stack_data d); //appends a node
int lista_buscar(Node **node_head, stack_data d); //checks for an element
