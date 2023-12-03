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

char menu_cardapios();
char tela_adicionar_cardapio(cardapio *Cardapio);
char tela_lista_cardapio(cardapio *Cardapio);
char tela_editar_cardapio(cardapio *Cardapio);
char tela_excluir_cardapio(cardapio *Cardapio);
void modulo_cardapios();
void substituir_caractere(char* str, char procurar, char substituir);

#endif