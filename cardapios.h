
struct  cardapio {
    char nome[100];
    char cod_cardapio[11];
    int objetivo;
    float cal_cardapio;
    int estatos;
    char dieta_cardapio[2000];
};

typedef struct cardapio cardapio;

char menu_cardapios();
void tela_adicionar_cardapio(cardapio *Cardapio);
void tela_lista_cardapio();
void tela_editar_cardapio(cardapio *Cardapio);
void tela_excluir_cardapio(cardapio *Cardapio);
void modulo_cardapios();
void substituir_caractere(char* str, char procurar, char substituir);
char* gerar_codigo_unico();
void imprimir_cardapio_tab(cardapio u);
void tela_buscar_cardapio ();