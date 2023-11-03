#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "usuario.h"
#include "utilidades.h"
#include "validacoes.h"


// funções modulo usuario
void modulo_usuario(void) {
    usuario Usuario;
    lista_usuarios Lista;
    Lista.qtd_usuarios = 0;
    carregar_usuarios(&Lista);
    char opc;
    do {
        opc = menu_inf_usuario();
        switch(opc) {
            case '1': 	tela_dados_pessoais(&Lista,&Usuario);
                        break;
            case '2': 	tela_restricao_alimentar();
                        break;
            case '3':   tela_novo_usuario(&Lista,&Usuario); 
                        salvar_usuarios(&Lista);
                        break;
            case '4':   tela_mudar_usuario(&Lista);
                        break;
            case '5':   tela_atualizar_usuario(&Usuario);
                        break;
            case '6':   tela_excluir_usuario(&Lista);
                        break; 
        } 		
    } while (opc != '0');
}



char menu_inf_usuario (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===========================================   USUÁRIO   =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Dados Pessoais]                                                        ||\n");
    printf("||                               2 [Restrições Alimentares]                                                ||\n");    
    printf("||                               3 [Novo Usuário]                                                          ||\n");
    printf("||                               4 [Lista de Usuários]                                                     ||\n");
    printf("||                               5 [Atualizar Informações do Usuário]                                      ||\n");
    printf("||                               6 [Excluir Usuário]                                                       ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    getchar();
    return opc;
}

char tela_dados_pessoais (lista_usuarios *Lista, usuario *Usuario){
    char opc;
    char buscar_nome[100];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||\n");    
    printf("||\n");
    printf("||\n");
    printf("||     =====================================    DADOS PESSOAIS    ====================================\n");
    printf("||\n");
    printf("||\n");
    printf("||\n");
    printf("\n||          PESQUISAR POR NOME: "); fgets(buscar_nome, sizeof(buscar_nome), stdin);
    int i;
    for (i = 0; i < Lista->qtd_usuarios; i++) {
      if (strcmp(Lista->usuarios[i].nome, buscar_nome) == 0) {
        // Exclui o contato da lista
          printf("\n||          NOME: %s", Lista->usuarios[i].nome);
          printf("||          IDADE: %d", Lista->usuarios[i].idade);
          printf("\n||          SEXO: %s", Lista->usuarios[i].sexo);    
          printf("\n||          E-MAIL: %s", Lista->usuarios[i].email);
          printf("\n||          PESO: %.1f", Lista->usuarios[i].peso);
          printf("\n||          ALTURA: %.2f", Lista->usuarios[i].altura);
      }
    }
    printf("||          FREQUÊNCIA DE ATIVIDADE FÍSICA:\n");
    printf("||\n");
    printf("||\n");
    printf("||                   0 [Voltar]\n");    
    printf("||\n");
    printf("||\n");
    printf("||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    getchar();
    return opc;
}

char tela_restricao_alimentar (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =================================    RESTRIÇÕES ALIMENTARES    ================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                 OPÇÕES RÁPIDAS                                                                          ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                  1 - Intolerância à lactose                                                             ||\n");
    printf("||                  2 - Alergia ao glúten                                                                  ||\n");
    printf("||                  3 - Alergia a crustáceos                                                               ||\n");
    printf("||                  4 - Diabetes                                                                           ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                  INFORME SUAS RESTRIÇÕES ALIMENTARES                                                    ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                 0 [Voltar]                                                                              ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    getchar();
    return opc;
}

char tela_novo_usuario (lista_usuarios *Lista, usuario *Usuario){
  // Verifica se a lista está cheia

  if (Lista->qtd_usuarios == 100) {
    printf("Lista está cheia!\n");
  }
  else {
  char opc;
      system("clear||cls");
      printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
      printf("\n||");    
      printf("\n||");
      printf("\n||");
      printf("\n||    ====================================    CADASTRAR USUÁRIO    ====================================");
      printf("\n||");
      printf("\n||");
      printf("\n||");
      printf("\n||                   NOME: ");    /// Nome do usuário

      fgets(Usuario->nome, sizeof(Usuario->nome), stdin);

      if (valida_nome(Usuario->nome) != 0){
        printf("\033[32m NOME VALIDO \033[0m");
      }
      else {
        printf("\033[31m NOME INVALIDO! \033[0m");
      }

      printf("\n||                   IDADE: ");   /// Idade do usuário

      scanf("%d", &Usuario->idade); getchar();
      if (valida_idade(Usuario->idade) != 0){
        printf("\033[32m IDADE VALIDO \033[0m");
      }
      else {
        printf("\033[31m IDADE INVALIDO! \033[0m");
      }

      printf("\n||                   SEXO: ");  /// Sexo 

      fgets(Usuario->sexo, sizeof(Usuario->sexo), stdin);
      if (valida_sexo(Usuario->sexo) != 0){
        printf("\033[32m SEXO VALIDO \033[0m");
      }
      else {
        printf("\033[31m SEXO INVALIDO! \033[0m");
      }

      printf("\n||                   E-MAIL: "); /// Email

      fgets(Usuario->email, sizeof(Usuario->email), stdin);
      if (valida_email(Usuario->email) != 0){
        printf("\033[32m EMAIL VALIDO \033[0m");
      }
      else {
        printf("\033[31m EMAIL INVALIDO! \033[0m");
      }

      printf("\n||                   PESO: ");   /// Peso do usuário

      scanf("%f", &Usuario->peso); getchar();
      if (valida_peso(Usuario->peso) != 0){
        printf("\033[32m PESO VALIDO \033[0m");
      }
      else {
        printf("\033[31m PESO INVALIDO! \033[0m");
      }

      printf("\n||                   ALTURA: "); /// Altura do usuário

      scanf("%f", &Usuario->altura); getchar();
      if (valida_altura(Usuario->altura) != 0){
        printf("\033[32m ALTURA VALIDO \033[0m");
      }
      else {
        printf("\033[31m ALTURA INVALIDO! \033[0m");
      }

      printf("\n||                   FREQUÊNCIA DE ATIVIDADE FÍSICA:");
      printf("\n||                   > NUNCA | RARAMENTE | FREQUENTEMENTE | TODO DIA");scanf("%s", Usuario->ativ_fisica); getchar();
      printf("\n||");
      printf("\n||                   0 [Voltar]\n");    
      printf("\n||");
      printf("\n||");
      printf("\n||");    
      printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");

      // Adiciona o contato à lista
      Lista->usuarios[Lista->qtd_usuarios++] = *Usuario;
      return opc;
  }
    // salvar usuarios
  salvar_usuarios(Lista);
}

char tela_mudar_usuario (lista_usuarios *Lista){
    char opc;
    carregar_usuarios(Lista);
    system("clear||cls");
    printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
    printf("\n||                                                                                                         ||");    
    printf("\n||                                                                                                         ||");
    printf("\n||                                                                                                         ||");
    printf("\n||   ====================================   LISTA DE USUÁRIOS  ========================================    ||");
    for (int i = 0; i < Lista->qtd_usuarios; i++) {
      printf("\n||");
      printf("\n||\033[32m                   NOME:\033[0m %s", Lista->usuarios[i].nome);
      printf("||                   IDADE: %d", Lista->usuarios[i].idade);
      printf("\n||                   SEXO: %s", Lista->usuarios[i].sexo);    
      printf("\n||                   E-MAIL: %s", Lista->usuarios[i].email);
      printf("\n||                   PESO: %.1f", Lista->usuarios[i].peso);
      printf("\n||                   ALTURA: %.2f", Lista->usuarios[i].altura);
    }
    
    printf("\n||                                                                                                         ||");
    printf("\n||                                                                                                         ||");
    printf("\n||                                                                                                         ||");    
    printf("\n||                                                                                                         ||");
    printf("\n||       0 [Voltar]                                                                                        ||");
    printf("\n||                                                                                                         ||");    
    printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
    scanf(" %c", &opc);
    return opc;
}

char tela_atualizar_usuario (usuario *Usuario){
    char opc;
    system("clear||cls");
    printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
    printf("\n||                                                                                                         ||");    
    printf("\n||                                                                                                         ||");
    printf("\n||                                                                                                         ||");
    printf("\n||    ==============================    ATUALIZAR INFORMAÇÔES USUÁRIO    ==============================    ||");
    printf("\n||");
    printf("\n||");
    printf("\n||");

    printf("\n||                   NOME: ");    /// Nome do usuário
    fgets(Usuario->nome, sizeof(Usuario->nome), stdin);
    if (valida_nome(Usuario->nome) != 0){
      printf("\033[32m NOME VALIDO \033[0m");
    }
    else {
      printf("\033[31m NOME INVALIDO! \033[0m");
    }

    printf("\n||                   IDADE: ");   /// Idade do usuário
    scanf("%d", &Usuario->idade); getchar();
    if (valida_idade(Usuario->idade) != 0){
      printf("\033[32m IDADE VALIDO \033[0m");
    }
    else {
      printf("\033[31m IDADE INVALIDO! \033[0m");
    }

    printf("\n||                   SEXO: ");  /// Sexo 
    fgets(Usuario->sexo, sizeof(Usuario->sexo), stdin);
    if (valida_sexo(Usuario->sexo) != 0){
      printf("\033[32m SEXO VALIDO \033[0m");
    }
    else {
      printf("\033[31m SEXO INVALIDO! \033[0m");
    }

    printf("\n||                   E-MAIL: "); /// Email
    fgets(Usuario->email, sizeof(Usuario->email), stdin);
    if (valida_email(Usuario->email) != 0){
      printf("\033[32m EMAIL VALIDO \033[0m");
    }
    else {
      printf("\033[31m EMAIL INVALIDO! \033[0m");
    }

    printf("\n||                   PESO: ");   /// Peso do usuário
    scanf("%f", &Usuario->peso); getchar();
    if (valida_peso(Usuario->peso) != 0){
      printf("\033[32m PESO VALIDO \033[0m");
    }
    else {
      printf("\033[31m PESO INVALIDO! \033[0m");
    }

    printf("\n||                   ALTURA: ");
    scanf("%f", &Usuario->altura); getchar();
    if (valida_altura(Usuario->altura) != 0){
      printf("\033[32m ALTURA VALIDO \033[0m");
    }
    else {
      printf("\033[31m ALTURA INVALIDO! \033[0m");
    }

    printf("\n||                   FREQUÊNCIA DE ATIVIDADE FÍSICA:");
    printf("\n||                   > NUNCA | RARAMENTE | FREQUENTEMENTE | TODO DIA");scanf("%s", Usuario->ativ_fisica); getchar();
    printf("\n||");
    printf("\n||                   0 [Voltar]\n");    
    printf("\n||");
    printf("\n||");
    printf("\n||");    
    printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
    return opc;
}

char tela_excluir_usuario (lista_usuarios *Lista) {
    char opc;
    char nome[100];
    int i;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===================================   EXCLUIR USUÁRIO   =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("       Nome do usuario a ser excluído: ");
    fgets(nome, sizeof(nome), stdin);
  
    // Procura o usuario na lista
    for (i = 0; i < Lista->qtd_usuarios; i++) {
      if (strcmp(Lista->usuarios[i].nome, nome) == 0) {
  
        // Marca o usuario como excluído
        Lista->usuarios[i].estatos = 1;
  
        // salvar usuarios
        salvar_usuarios(Lista);
        carregar_usuarios(Lista);
        // Diminui a quantidade de usuarios
        Lista->qtd_usuarios--;
      }
    }
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||       0 [Voltar]                                                                                        ||\n");
    printf("||                                                                                                         ||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||\n");
    scanf(" %c", &opc);
    return opc;
}

// Função para salvar as informações do usuario
void salvar_usuarios(lista_usuarios *Lista) {
  // Abre o arquivo binário
  FILE *arquivo = fopen("usuarios.bin", "wb");

  // Verifica se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  // Grava as informações no arquivo
  for (int i = 0; i < Lista->qtd_usuarios; i++) {
    if (Lista->usuarios[i].estatos != 1) {
      fwrite(&Lista->usuarios[i], sizeof(usuario), 1, arquivo);
    }
  }
  // Fecha o arquivo
  fclose(arquivo);
}

// Função para ler as informações do arquivo binário
void carregar_usuarios(lista_usuarios *Lista) {
  // Abre o arquivo binário
  FILE *arquivo = fopen("usuarios.bin", "rb");

  // Verifica se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  // Lê as informações do arquivo para o array de contatos
  Lista->qtd_usuarios = fread(Lista->usuarios, sizeof(usuario), 100, arquivo);

  // Fecha o arquivo
  fclose(arquivo);
}