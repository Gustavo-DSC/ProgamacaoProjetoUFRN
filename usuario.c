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
            case '5':   tela_atualizar_usuario(&Lista,&Usuario);
                        salvar_usuarios(&Lista);
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
    printf("||     ==========================================   PACIENTE   =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Buscar Paciente]                                                       ||\n");
    printf("||                               2 [Restrições Alimentares]                                                ||\n");    
    printf("||                               3 [Novo Paciente]                                                         ||\n");
    printf("||                               4 [Lista de Pacientes]                                                    ||\n");
    printf("||                               5 [Atualizar Informações de Paciente]                                     ||\n");
    printf("||                               6 [Excluir Paciente]                                                      ||\n");
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
    printf("||     =====================================    BUSCAR PACIENTE    ====================================\n");
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
          printf("\n||          FREQUÊNCIA DE ATIVIDADE FÍSICA: %s", Lista->usuarios[i].ativ_fisica);
      }
    }
    printf("\n||");
    printf("\n||");
    printf("\n||                   0 [Voltar]");    
    printf("\n||");
    printf("\n||");
    printf("\n||");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
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
      printf("\n||    ====================================    CADASTRAR PACIENTE    ====================================");
      printf("\n||");
      printf("\n||");
      printf("\n||");
      do {
        printf("\n||                   NOME: ");    /// Nome do usuário
        fgets(Usuario->nome, sizeof(Usuario->nome), stdin);
        if (valida_nome(Usuario->nome) != 0){
          printf("\033[32m NOME VALIDO \033[0m");
        }
        else {
          printf("\033[31m NOME INVALIDO! \033[0m");
        }
      } while (valida_nome(Usuario->nome) == 0);

      do {
        printf("\n||                   IDADE: ");   /// Idade do usuário
        scanf("%d", &Usuario->idade); getchar();
        if (valida_idade(Usuario->idade) != 0){
          printf("\033[32m IDADE VALIDO \033[0m");
        }
        else {
          printf("\033[31m IDADE INVALIDO! \033[0m");
        }
      } while (valida_idade(Usuario->idade) == 0);


      do {
        printf("\n||                   SEXO: ");  /// Sexo 
        fgets(Usuario->sexo, sizeof(Usuario->sexo), stdin);
        if (valida_sexo(Usuario->sexo) != 0){
          printf("\033[32m SEXO VALIDO \033[0m");
        }
        else {
          printf("\033[31m SEXO INVALIDO! \033[0m");
        }
      } while (valida_sexo(Usuario->sexo) == 0);


      do {
        printf("\n||                   E-MAIL: "); /// Email
        fgets(Usuario->email, sizeof(Usuario->email), stdin);
        if (valida_email(Usuario->email) != 0){
          printf("\033[32m EMAIL VALIDO \033[0m");
        }
        else {
          printf("\033[31m EMAIL INVALIDO! \033[0m");
        }
      } while (valida_email(Usuario->email) == 0);


      do {
        printf("\n||                   PESO: ");   /// Peso do usuário
        scanf("%f", &Usuario->peso); getchar();
        if (valida_peso(Usuario->peso) != 0){
          printf("\033[32m PESO VALIDO \033[0m");
        }
        else {
          printf("\033[31m PESO INVALIDO! \033[0m");
        }
      } while (valida_peso(Usuario->peso) == 0);


      do {
        printf("\n||                   ALTURA: "); /// Altura do usuário
        scanf("%f", &Usuario->altura); getchar();
        if (valida_altura(Usuario->altura) != 0){
          printf("\033[32m ALTURA VALIDO \033[0m");
        }
        else {
          printf("\033[31m ALTURA INVALIDO! \033[0m");
        }
      } while (valida_altura(Usuario->altura) == 0);


      do {
        printf("\n||                   FREQUÊNCIA DE ATIVIDADE FÍSICA");  // nivel de atividade física
        printf("\n||                   sedentário | leve | moderado | intenso | muito intenso  ");
        fgets(Usuario->ativ_fisica, sizeof(Usuario->ativ_fisica), stdin);
        if (valida_atividade_fisica(Usuario->ativ_fisica) != 0){
          printf("\033[32m ATIVIDADE FÍSICA VALIDA \033[0m");
        }
        else {
          printf("\033[31m ATIVIDADE FÍSICA INVALIDA! \033[0m");
        }
      } while (valida_atividade_fisica(Usuario->ativ_fisica) == 0);
      Usuario->imc = imc_usuario(*Usuario);
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
}


char tela_mudar_usuario (lista_usuarios *Lista){
    char opc, slc;
    carregar_usuarios(Lista);
    system("clear||cls");
    printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
    printf("\n||                                                                                                         ||");    
    printf("\n||                                                                                                         ||");
    printf("\n||                                                                                                         ||");
    printf("\n||   ====================================   LISTA DE PACIENTES  =======================================    ||");
    printf("\n||   1 [Pacientes com alto nível de obesidade]                                                             ||");
    printf("\n||   2 [Pacientes com alto nível de magreza]                                                               ||");
    printf("\n||   3 [Pacientes do sexo masculino]                                                                       ||");
    printf("\n||   4 [Pacientes do sexo feminino]                                                                        ||");
    scanf(" %c", &slc);
    switch(slc) {
        case '1':
            // Filtro para pacientes com alto nível de obesidade
            for (int i = 0; i < Lista->qtd_usuarios; i++) {
                if (Lista->usuarios[i].imc >= 30) { // IMC >= 30 é considerado obesidade
                    imprimir_usuario(Lista->usuarios[i]);
                }
            }
            break;
        case '2':
            // Filtro para pacientes com alto nível de magreza
            for (int i = 0; i < Lista->qtd_usuarios; i++) {
                if (Lista->usuarios[i].imc < 18.5) { // IMC < 18.5 é considerado magreza
                    imprimir_usuario(Lista->usuarios[i]);
                }
            }
            break;
        case '3':
            // Filtro para pacientes do sexo masculino
            for (int i = 0; i < Lista->qtd_usuarios; i++) {
                if (strcmp(Lista->usuarios[i].sexo, "masculino") == 0) {
                    imprimir_usuario(Lista->usuarios[i]);
                }
            }
            break;
        case '4':
            // Filtro para pacientes do sexo feminino
            for (int i = 0; i < Lista->qtd_usuarios; i++) {
                if (strcmp(Lista->usuarios[i].sexo, "feminino") == 0) {
                    imprimir_usuario(Lista->usuarios[i]);
                }
            }
            break;
        case '0':
            // Voltar
            break;
        default:
            printf("\nOpção inválida. Tente novamente.\n");
            break;
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

char tela_atualizar_usuario(lista_usuarios *Lista, usuario *Usuario){
    char opc;
    char buscar_nome[100];
    system("clear||cls");
    printf("\nMWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM");
    printf("\n||                                                                                                         ||");    
    printf("\n||                                                                                                         ||");
    printf("\n||                                                                                                         ||");
    printf("\n||    ==============================    ATUALIZAR INFORMAÇÔES PACIENTE    =============================    ||");
    printf("\n||");
    printf("\n||          PESQUISAR POR NOME: "); fgets(buscar_nome, sizeof(buscar_nome), stdin);
    int i;
    for (i = 0; i < Lista->qtd_usuarios; i++) {
      if (strcmp(Lista->usuarios[i].nome, buscar_nome) == 0) {

        do {
          printf("\n||                   IDADE: ");   /// Idade do usuário
          scanf("%d", &Usuario->idade); getchar();
          if (valida_idade(Usuario->idade) != 0){
            printf("\033[32m IDADE VALIDO \033[0m");
            Lista->usuarios[i].idade = Usuario->idade;
          }
          else {
            printf("\033[31m IDADE INVALIDO! \033[0m");
          }
        } while (valida_idade(Usuario->idade) == 0);

        do {
          printf("\n||                   E-MAIL: "); /// Email
          fgets(Usuario->email, sizeof(Usuario->email), stdin);
          if (valida_email(Usuario->email) != 0){
            printf("\033[32m EMAIL VALIDO \033[0m");
            strcpy(Lista->usuarios[i].email, Usuario->email);
          }
          else {
            printf("\033[31m EMAIL INVALIDO! \033[0m");
          }
        } while (valida_email(Usuario->email) == 0);


        do {
          printf("\n||                   PESO: ");   /// Peso do usuário
          scanf("%f", &Usuario->peso); getchar();
          if (valida_peso(Usuario->peso) != 0){
            printf("\033[32m PESO VALIDO \033[0m");
            Lista->usuarios[i].peso = Usuario->peso;
          }
          else {
            printf("\033[31m PESO INVALIDO! \033[0m");
          }
        } while (valida_peso(Usuario->peso) == 0);


        do {
          printf("\n||                   ALTURA: "); /// Altura do usuário
          scanf("%f", &Usuario->altura); getchar();
          if (valida_altura(Usuario->altura) != 0){
            printf("\033[32m ALTURA VALIDO \033[0m");
            Lista->usuarios[i].altura = Usuario->altura;
          }
          else {
            printf("\033[31m ALTURA INVALIDO! \033[0m");
          }
        } while (valida_altura(Usuario->altura) == 0);


        do {
          printf("\n||                   FREQUÊNCIA DE ATIVIDADE FÍSICA");  // nivel de atividade física
          printf("\n||                   sedentário | leve | moderado | intenso | muito intenso");
          fgets(Usuario->ativ_fisica, sizeof(Usuario->ativ_fisica), stdin);
          if (valida_atividade_fisica(Usuario->ativ_fisica) != 0){
            printf("\033[32m ATIVIDADE FÍSICA VALIDA \033[0m");
            strcpy(Lista->usuarios[i].ativ_fisica, Usuario->ativ_fisica);
          }
          else {
            printf("\033[31m ATIVIDADE FÍSICA INVALIDA! \033[0m");
          }
        } while (valida_atividade_fisica(Usuario->ativ_fisica) == 0);
      }
    }
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
    printf("||     ===================================   EXCLUIR PACIENTE   ======================================     ||\n");
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
  FILE *arquivo = fopen("usuarios.data", "wb");

  // Verifica se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  // Grava as informações no arquivo
  for (int i = 0; i < Lista->qtd_usuarios; i++) {
    if (Lista->usuarios[i].estatos == 0) {
      fwrite(&Lista->usuarios[i], sizeof(usuario), 1, arquivo);
    }
  }
  // Fecha o arquivo
  fclose(arquivo);
}

// Função para ler as informações do arquivo binário
void carregar_usuarios(lista_usuarios *Lista) {
  // Abre o arquivo binário
  FILE *arquivo = fopen("usuarios.data", "rb");

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


void imprimir_usuario(usuario u) {
    printf("\n||");
    printf("\n||\033[32m                   NOME:\033[0m %s", u.nome);
    printf("||                   IDADE: %d", u.idade);
    printf("\n||                   SEXO: %s", u.sexo);    
    printf("\n||                   E-MAIL: %s", u.email);
    printf("\n||                   PESO: %.1f", u.peso);
    printf("\n||                   ALTURA: %.2f", u.altura);
    printf("\n||                   IMC: %.2f", u.imc);
}


float imc_usuario(usuario u) {
  u.imc = u.peso / (u.altura * u.altura);
  return u.imc;
}
