#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cardapios.h"




void modulo_cardapios(void) {
    cardapio Cardapio;
    lista_cardapios Lista;
    char opc;
    carregar_cardapios(&Lista);
    do {
        opc = menu_cardapios();
        switch(opc) {
            case '1':   tela_adicionar_cardapio(&Lista, &Cardapio);
                        salvar_cardapios(&Lista);
                        break;
            case '2': 	carregar_cardapios(&Lista);
                        tela_lista_cardapio(&Lista);
                        break;
            case '3':   tela_editar_cardapio(&Lista);
                        salvar_cardapios(&Lista);
                        break;
            case '4':   tela_excluir_cardapio(&Lista);
                        break;
        } 		
    } while (opc != '0');
}



char menu_cardapios (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =======================================    CARDÁPIOS   ========================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Adicionar Cardápio]                                                    ||\n");
    printf("||                               2 [Lista de Cardapios]                                                    ||\n");
    printf("||                               3 [Editar Cardápio]                                                       ||\n");
    printf("||                               4 [Excluir Cardápio]                                                      ||\n");    
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");  
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);getchar();
    return opc;
}


char tela_adicionar_cardapio (lista_cardapios *Lista, cardapio *Cardapio){
    if (Lista->qtd_cardapios == 100) {
      printf("Lista está cheia!\n");
    }
    else { 
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================   ADICIONAR CARDÁPIO   ===================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("\n||  NOME DO CARDÁPIO: ");
    fgets(Cardapio->nome, sizeof(Cardapio->nome), stdin);

    printf("\n||  Objetivo do cardápio: 1(Ganhar peso) 2(Perde peso) 3(Manter peso) 4(Ganha massa muscular): "); 
    scanf("%d", &Cardapio->objetivo); getchar();

    printf("\n||  DIETA DO CARDÁPIO (use ; para nova linha): ");
    char dieta[2000];
    fgets(dieta, sizeof(dieta), stdin);
    substituir_caractere(dieta, ';', '\n');
    strcpy(Cardapio->dieta_cardapio, dieta);

    printf("\n||  CALORIAS DO CARDÁPIO: ");
    scanf("%f", &Cardapio->cal_cardapio); getchar();

    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    Lista->cardapios[Lista->qtd_cardapios++] = *Cardapio;
    return opc;
  }
}
                    
char tela_lista_cardapio (lista_cardapios *Lista){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================   LISTA DE CARDÁPIOS   ===================================     ||\n");
    printf("||                                                                                                         ||\n");
    for (int i = 0; i < Lista->qtd_cardapios; i++) {
      printf("\n");
      printf("\n\033[32m NOME:\033[0m %s", Lista->cardapios[i].nome);
      printf("\n OBJETIVO: %d", Lista->cardapios[i].objetivo);
      printf("\n CALORIAS: %.2f", Lista->cardapios[i].cal_cardapio);
      printf("\n DIETA: "); 
      printf("\n%s", Lista->cardapios[i].dieta_cardapio); 
    }
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                       ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("||                                                                            			                       ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}                                                

char tela_editar_cardapio (lista_cardapios *Lista){
    if (Lista->qtd_cardapios == 100) {
      printf("Lista está cheia!\n");
    }
    else { 
      char opc;
      char buscar_nome[100];
      system("clear||cls");
      printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
      printf("||                                                                                                         ||\n");    
      printf("||                                                                                                         ||\n");
      printf("||                                                                                                         ||\n");
      printf("||     ======================================   EDITAR CARDÁPIO   ====================================     ||\n");
      printf("||                                                                                                         ||\n");
      printf("||     	PESQUISAR POR NOME: "); fgets(buscar_nome, sizeof(buscar_nome), stdin);
      printf("||\n");
      printf("||\n");
      int i;
      for (i = 0; i < Lista->qtd_cardapios; i++) {
        if (strcmp(Lista->cardapios[i].nome, buscar_nome) == 0) {
          printf("    NOME DO CARDÁPIO: ");
          fgets(Lista->cardapios[i].nome, sizeof(Lista->cardapios[i].nome), stdin);
    
          printf("    Objetivo do cardápio: 1(Ganhar peso) 2(Perde peso) 3(Manter peso) 4(Ganha massa muscular):"); 
          scanf("%d", &Lista->cardapios[i].objetivo); getchar();
    
          printf("\n||  DIETA DO CARDÁPIO (use ; para nova linha): ");
          char dieta[2000];
          fgets(dieta, sizeof(dieta), stdin);
          substituir_caractere(dieta, ';', '\n');
          strcpy(Lista->cardapios[i].dieta_cardapio, dieta);
    
          printf("    CALORIAS DO CARDÁPIO: ");
          scanf("%f", &Lista->cardapios[i].cal_cardapio); getchar();
        }
      }
      printf("||                                                                                                         ||\n");
      printf("||                                                                                                         ||\n");    
      printf("||                                                                                                         ||\n");
      printf("||                                                                                                         ||\n");
      printf("||                                                                                                         ||\n");    
      printf("||                                                                                                         ||\n");
      printf("||      0 [Voltar]                                                                                         ||\n");
      printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
      scanf(" %c", &opc);
      return opc;
      }
}

char tela_excluir_cardapio (lista_cardapios *Lista){
    char opc;
    int i;
    char buscar_nome[100];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================   EXCLUIR CARDÁPIO   ====================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Nome do cardápio a ser excluído: ");
    fgets(buscar_nome, sizeof(buscar_nome), stdin);
  
    // Procura o cardápio na lista
    for (i = 0; i < Lista->qtd_cardapios; i++) {
      if (strcmp(Lista->cardapios[i].nome, buscar_nome) == 0) {
  
        // Marca o cardápio como excluído
        Lista->cardapios[i].estatos = 1;
  
        // salvar cardapios
        salvar_cardapios(Lista);
        carregar_cardapios(Lista);
        // Diminui a quantidade de cardapios
        Lista->qtd_cardapios--;
      }
    }
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                       ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                            			                       ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                       ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("||                                                                            			                       ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}



// Função para salvar as informações do cardápio
void salvar_cardapios(lista_cardapios *Lista) {
  // Abre o arquivo texto
  FILE *arquivo = fopen("cardapios.txt", "wt");

  // Verifica se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  // Grava as informações no arquivo
  for (int i = 0; i < Lista->qtd_cardapios; i++) {
    if (Lista->cardapios[i].estatos == 0) {
      fwrite(&Lista->cardapios[i], sizeof(cardapio), 1, arquivo);
    }
  }
  // Fecha o arquivo
  fclose(arquivo);
}

// Função para ler as informações do arquivo 
void carregar_cardapios(lista_cardapios *Lista) {
  // Abre o arquivo texto
  FILE *arquivo = fopen("cardapios.txt", "rt");

  // Verifica se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  Lista->qtd_cardapios = fread(Lista->cardapios, sizeof(cardapio), 100, arquivo);

  // Fecha o arquivo
  fclose(arquivo);
}

void substituir_caractere(char* str, char procurar, char substituir){
    char *posicao_atual = strchr(str,procurar);
    while (posicao_atual){
        *posicao_atual = substituir;
        posicao_atual = strchr(posicao_atual,procurar);
    }
}
