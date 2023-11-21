#ifndef CARDAPIOS_H
#define CARDAPIOS_H 

struct  cardapio {
    char nome[100];
    int objetivo;
    float cal_cardapio;
    int estatos;
    char dieta_cardapio[2000];
};

typedef struct cardapio cardapio;

struct  lista_cardapios {
    cardapio cardapios[100];
    int qtd_cardapios;
};

typedef struct lista_cardapios lista_cardapios;


char menu_cardapios();
char tela_adicionar_cardapio(lista_cardapios *Lista, cardapio *Cardapio);
char tela_lista_cardapio(lista_cardapios *Lista);
char tela_editar_cardapio(lista_cardapios *Lista);
char tela_excluir_cardapio(lista_cardapios *Lista);
void modulo_cardapios();
void carregar_cardapios(lista_cardapios *Lista);
void salvar_cardapios(lista_cardapios *Lista);
void substituir_caractere(char* str, char procurar, char substituir);

#endif