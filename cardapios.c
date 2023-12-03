#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cardapios.h"




void modulo_cardapios(void) {
    cardapio Cardapio;
    char opc;
    do {
        opc = menu_cardapios();
        switch(opc) {
            case '1':   tela_adicionar_cardapio(&Cardapio);
                        break;
            case '2':   tela_lista_cardapio(&Cardapio);
                        break;
            case '3':   tela_editar_cardapio(&Cardapio);
                        break;
            case '4':   tela_excluir_cardapio(&Cardapio);
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


char tela_adicionar_cardapio (cardapio *Cardapio){
    FILE *arquivo = fopen("cardapios.data", "ab+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
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
    fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
    fclose(arquivo);
  
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
                    
char tela_lista_cardapio (cardapio *CardapioParam){
    FILE *arquivo = fopen("cardapios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================   LISTA DE CARDÁPIOS   ===================================     ||\n");
    printf("||                                                                                                         ||\n");
    cardapio CardapioLocal;
    while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo)){
      printf("\n");
      printf("\n\033[32m NOME:\033[0m %s", CardapioLocal.nome);
      printf("\n OBJETIVO: %d", CardapioLocal.objetivo);
      printf("\n CALORIAS: %.2f", CardapioLocal.cal_cardapio);
      printf("\n DIETA: "); 
      printf("\n%s", CardapioLocal.dieta_cardapio); 
    }
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                       ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("||                                                                            			                       ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    fclose(arquivo);
    return opc;
}
                                               

char tela_editar_cardapio (cardapio *Cardapio){
    FILE *arquivo = fopen("cardapios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
      char opc;
      char buscar_nome[100];
      system("clear||cls");
      printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
      printf("||                                                                                                         ||\n");    
      printf("||                                                                                                         ||\n");
      printf("||                                                                                                         ||\n");
      printf("||     ======================================   EDITAR CARDÁPIO   ====================================     ||\n");
      printf("||                                                                                                         ||\n");
      printf("||     	PESQUISAR POR NOME: "); 
      fgets(buscar_nome, sizeof(buscar_nome), stdin);
      buscar_nome[strcspn(buscar_nome, "\n")] = '\0';
      printf("||\n");
      printf("||\n");

      while (fread(Cardapio, sizeof(cardapio), 1, arquivo)) {
      // Compara o CPF do usuário com o CPF buscado
        if (strcmp(Cardapio->nome, buscar_nome) == 0) {
          
          printf("Deseja atualizar a idade? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
            printf("    NOME DO CARDÁPIO: ");
            fgets(Cardapio->nome, sizeof(Cardapio->nome), stdin);
            fseek(arquivo, -sizeof(cardapio), SEEK_CUR);
            fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }
          
          printf("Deseja atualizar a idade? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
            printf("    Objetivo do cardápio: 1(Ganhar peso) 2(Perde peso) 3(Manter peso) 4(Ganha massa muscular):"); 
            scanf("%d", &Cardapio->objetivo); getchar();
            fseek(arquivo, -sizeof(cardapio), SEEK_CUR);
            fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }

          printf("Deseja atualizar a idade? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
            printf("\n||  DIETA DO CARDÁPIO (use ; para nova linha): ");
            char dieta[2000];
            fgets(dieta, sizeof(dieta), stdin);
            substituir_caractere(dieta, ';', '\n');
            strcpy(Cardapio->dieta_cardapio, dieta);
            fseek(arquivo, -sizeof(cardapio), SEEK_CUR);
            fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }

          printf("Deseja atualizar a idade? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
            printf("    CALORIAS DO CARDÁPIO: ");
            scanf("%f", &Cardapio->cal_cardapio); getchar();
            fseek(arquivo, -sizeof(cardapio), SEEK_CUR);
            fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }
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


char tela_excluir_cardapio (cardapio *Cardapio){
    FILE *arquivo = fopen("cardapios.data", "rb");
    FILE *temp = fopen("temp.data", "wb"); // Arquivo temporário
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      return 0;
    }
    char opc;
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
    buscar_nome[strcspn(buscar_nome, "\n")] = '\0';
  
    // Lê os cardapios do arquivo um por um
    while (fread(Cardapio, sizeof(cardapio), 1, arquivo)) {
      // Compara o CPF do cardapio com o CPF buscado
      if (strcmp(Cardapio->nome, buscar_nome) == 0) {
        // Pergunta se o cardapio quer excluir o cardapio
        printf("Deseja realmente excluir este cardapio? S/N \n");
        do{
          scanf( "%c", &opc);getchar();
          if (opc == 'S' || opc == 's') {
            // Não copia o cardapio para o novo arquivo
          }
          else if (opc == 'N' || opc == 'n') {
            printf("Exclusão cancelada!\n");
            // Copia o cardapio para o novo arquivo
            fwrite(Cardapio, sizeof(cardapio), 1, temp);
          }
        }while (opc != 'S' && opc != 's' && opc != 'N' && opc != 'n');
      }  
      else {
        // Copia o cardapio para o novo arquivo
        fwrite(Cardapio, sizeof(cardapio), 1, temp);
      }
    }
  
    // Fecha os arquivos
    fclose(arquivo);
    fclose(temp);
  
    // Exclui o arquivo antigo
    remove("cardapios.data");
  
    // Renomeia o novo arquivo para o nome do arquivo antigo
    rename("temp.data", "cardapios.data");
  
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


void substituir_caractere(char* str, char procurar, char substituir){
    char *posicao_atual = strchr(str,procurar);
    while (posicao_atual){
        *posicao_atual = substituir;
        posicao_atual = strchr(posicao_atual,procurar);
    }
}
