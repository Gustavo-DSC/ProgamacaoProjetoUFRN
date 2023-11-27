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
    char buscar_cpf[14];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||\n");    
    printf("||\n");
    printf("||\n");
    printf("||     =====================================    BUSCAR PACIENTE    ====================================\n");
    printf("||\n");
    printf("||\n");
    printf("||\n");
    printf("||          PESQUISAR POR CPF: "); 
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;
    int i;
    for (i = 0; i < Lista->qtd_usuarios; i++) {
      if (strcmp(Lista->usuarios[i].cpf, buscar_cpf) == 0) {
          imprimir_usuario(Lista->usuarios[i]);
          break;
      }
    }
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
  int cpf_existe;
      system("clear||cls");
      printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
      printf("||\n");    
      printf("||\n");
      printf("||\n");
      printf("||    ====================================    CADASTRAR PACIENTE    ====================================\n");
      printf("||\n");
      do {
          cpf_existe = 0;
          printf("   CPF: ");    /// CPF do usuário
          fgets(Usuario->cpf, sizeof(Usuario->cpf), stdin);
          Usuario->cpf[strcspn(Usuario->cpf, "\n")] = 0;
          for (int i = 0; i < Lista->qtd_usuarios; i++) {
            if (strcmp(Lista->usuarios[i].cpf, Usuario->cpf) == 0) {
              cpf_existe = 1;
              printf("\033[31m CPF JA EXISTE! \033[0m\n");
              break;
            }
          }
          if (!cpf_existe && valida_cpf(Usuario->cpf) != 0){
            printf("\033[32m CPF VALIDO \033[0m\n");
          }
          else if (!cpf_existe) {
            printf("\033[31m CPF INVALIDO! \033[0m\n");
          }
      } while (valida_cpf(Usuario->cpf) == 0 || cpf_existe == 1);

      if (cpf_existe == 0) {
        do {
          printf("   NOME: ");    /// Nome do usuário
          fgets(Usuario->nome, sizeof(Usuario->nome), stdin);
          if (valida_nome(Usuario->nome) != 0){
            printf("\033[32m NOME VALIDO \033[0m\n");
          }
          else {
            printf("\033[31m NOME INVALIDO! \033[0m\n");
          }
        } while (valida_nome(Usuario->nome) == 0);
  
        do {
          printf("   IDADE: ");   /// Idade do usuário
          scanf("%d", &Usuario->idade); getchar();
          if (valida_idade(Usuario->idade) != 0){
            printf("\033[32m IDADE VALIDO \033[0m\n");
          }
          else {
            printf("\033[31m IDADE INVALIDO! \033[0m\n");
          }
        } while (valida_idade(Usuario->idade) == 0);
  
  
        do {
          printf("   SEXO: ");  /// Sexo 
          fgets(Usuario->sexo, sizeof(Usuario->sexo), stdin);
          if (valida_sexo(Usuario->sexo) != 0){
            printf("\033[32m SEXO VALIDO \033[0m\n");
          }
          else {
            printf("\033[31m SEXO INVALIDO! \033[0m\n");
          }
        } while (valida_sexo(Usuario->sexo) == 0);
  
  
        do {
          printf("   E-MAIL: "); /// Email
          fgets(Usuario->email, sizeof(Usuario->email), stdin);
          if (valida_email(Usuario->email) != 0){
            printf("\033[32m EMAIL VALIDO \033[0m\n");
          }
          else {
            printf("\033[31m EMAIL INVALIDO! \033[0m\n");
          }
        } while (valida_email(Usuario->email) == 0);
  
  
        do {
          printf("   PESO: ");   /// Peso do usuário
          scanf("%f", &Usuario->peso); getchar();
          if (valida_peso(Usuario->peso) != 0){
            printf("\033[32m PESO VALIDO \033[0m\n");
          }
          else {
            printf("\033[31m PESO INVALIDO! \033[0m\n");
          }
        } while (valida_peso(Usuario->peso) == 0);
  
  
        do {
          printf("   ALTURA: "); /// Altura do usuário
          scanf("%f", &Usuario->altura); getchar();
          if (valida_altura(Usuario->altura) != 0){
            printf("\033[32m ALTURA VALIDO \033[0m\n");
          }
          else {
            printf("\033[31m ALTURA INVALIDO! \033[0m\n");
          }
        } while (valida_altura(Usuario->altura) == 0);
  
  
        do {
          printf("   FREQUÊNCIA DE ATIVIDADE FÍSICA\n");  // nivel de atividade física
          printf("   sedentário | leve | moderado | intenso | muito intenso  \n");
          fgets(Usuario->ativ_fisica, sizeof(Usuario->ativ_fisica), stdin);
          if (valida_atividade_fisica(Usuario->ativ_fisica) != 0){
            printf("\033[32m ATIVIDADE FÍSICA VALIDA \033[0m\n");
          }
          else {
            printf("\033[31m ATIVIDADE FÍSICA INVALIDA! \033[0m\n");
          }
        } while (valida_atividade_fisica(Usuario->ativ_fisica) == 0);
        Usuario->imc = imc_usuario(*Usuario);
        printf("||\n");
        printf("||                   0 [Voltar]\n");    
        printf("||\n");
        printf("||\n");
        printf("||\n");    
        printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
  
        // Adiciona o contato à lista
        Lista->usuarios[Lista->qtd_usuarios++] = *Usuario;
        return opc;
      }
  }
}


char tela_mudar_usuario (lista_usuarios *Lista){
    char opc, slc;
    carregar_usuarios(Lista);
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||   ====================================   LISTA DE PACIENTES  =======================================    ||\n");
    printf("||   1 [Todos os pacientes ]                                                                               ||\n");
    printf("||   2 [Pacientes com alto nível de obesidade]                                                             ||\n");
    printf("||   3 [Pacientes com alto nível de magreza]                                                               ||\n");
    printf("||   4 [Pacientes do sexo masculino]                                                                       ||\n");
    printf("||   5 [Pacientes do sexo feminino]                                                                        ||\n");
    printf("\n");
    printf("    ESCOLHA A OPÇÃO DE LISTAGEM: ");scanf("%c", &slc);
    switch(slc) {
        case '1':
        // Filtro para pacientes com alto nível de obesidade
        for (int i = 0; i < Lista->qtd_usuarios; i++) {
            imprimir_usuario(Lista->usuarios[i]);
        }
        break;
        case '2':
            // Filtro para pacientes com alto nível de obesidade
            for (int i = 0; i < Lista->qtd_usuarios; i++) {
                if (Lista->usuarios[i].imc >= 30) { // IMC >= 30 é considerado obesidade
                    imprimir_usuario(Lista->usuarios[i]);
                }
            }
            break;
        case '3':
            // Filtro para pacientes com alto nível de magreza
            for (int i = 0; i < Lista->qtd_usuarios; i++) {
                if (Lista->usuarios[i].imc < 18.5) { // IMC < 18.5 é considerado magreza
                    imprimir_usuario(Lista->usuarios[i]);
                }
            }
            break;
        case '4':
            // Filtro para pacientes do sexo masculino
            for (int i = 0; i < Lista->qtd_usuarios; i++) {
                if (strcmp(Lista->usuarios[i].sexo, "masculino") == 0) {
                    imprimir_usuario(Lista->usuarios[i]);
                }
            }
            break;
        case '5':
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
    printf("||                                                                                                         ||\n");
    printf("||       0 [Voltar]                                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_atualizar_usuario(lista_usuarios *Lista, usuario *Usuario){
    char opc;
    char buscar_cpf[14];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||    ==============================    ATUALIZAR INFORMAÇÔES PACIENTE    =============================    ||\n");
    printf("||\n");
    printf("||          PESQUISAR POR CPF: "); 
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;
    for (int i = 0; i < Lista->qtd_usuarios; i++) {
      if (strcmp(Lista->usuarios[i].cpf, buscar_cpf) == 0) {

        do {
          printf("   IDADE: ");   /// Idade do usuário
          scanf("%d", &Usuario->idade); getchar();
          if (valida_idade(Usuario->idade) != 0){
            printf("\033[32m IDADE VALIDO \033[0m\n");
            Lista->usuarios[i].idade = Usuario->idade;
          }
          else {
            printf("\033[31m IDADE INVALIDO! \033[0m\n");
          }
        } while (valida_idade(Usuario->idade) == 0);

        do {
          printf("   E-MAIL: "); /// Email
          fgets(Usuario->email, sizeof(Usuario->email), stdin);
          if (valida_email(Usuario->email) != 0){
            printf("\033[32m EMAIL VALIDO \033[0m\n");
            strcpy(Lista->usuarios[i].email, Usuario->email);
          }
          else {
            printf("\033[31m EMAIL INVALIDO! \033[0m\n");
          }
        } while (valida_email(Usuario->email) == 0);


        do {
          printf("   PESO: ");   /// Peso do usuário
          scanf("%f", &Usuario->peso); getchar();
          if (valida_peso(Usuario->peso) != 0){
            printf("\033[32m PESO VALIDO \033[0m\n");
            Lista->usuarios[i].peso = Usuario->peso;
          }
          else {
            printf("\033[31m PESO INVALIDO! \033[0m\n");
          }
        } while (valida_peso(Usuario->peso) == 0);


        do {
          printf("   ALTURA: "); /// Altura do usuário
          scanf("%f", &Usuario->altura); getchar();
          if (valida_altura(Usuario->altura) != 0){
            printf("\033[32m ALTURA VALIDO \033[0m\n");
            Lista->usuarios[i].altura = Usuario->altura;
          }
          else {
            printf("\033[31m ALTURA INVALIDO! \033[0m\n");
          }
        } while (valida_altura(Usuario->altura) == 0);


        do {
          printf("   FREQUÊNCIA DE ATIVIDADE FÍSICA\n");  // nivel de atividade física
          printf("   sedentário | leve | moderado | intenso | muito intenso\n");
          fgets(Usuario->ativ_fisica, sizeof(Usuario->ativ_fisica), stdin);
          if (valida_atividade_fisica(Usuario->ativ_fisica) != 0){
            printf("\033[32m ATIVIDADE FÍSICA VALIDA \033[0m\n");
            strcpy(Lista->usuarios[i].ativ_fisica, Usuario->ativ_fisica);
          }
          else {
            printf("\033[31m ATIVIDADE FÍSICA INVALIDA! \033[0m\n");
          }
        } while (valida_atividade_fisica(Usuario->ativ_fisica) == 0);
      }
    }
    printf("||\n");
    printf("||                   0 [Voltar]\n");    
    printf("||\n");
    printf("||\n");
    printf("||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    return opc;
}

char tela_excluir_usuario (lista_usuarios *Lista) {
    char opc;
    char buscar_cpf[14];
    int i;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===================================   EXCLUIR PACIENTE   ======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("       Nome do usuario a ser excluído: ");
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;
    // Procura o usuario na lista
    for (i = 0; i < Lista->qtd_usuarios; i++) {
      if (strcmp(Lista->usuarios[i].cpf, buscar_cpf) == 0) {
        printf("\033[32m   NOME:\033[0m %s\n", Lista->usuarios[i].nome);
        printf("   IDADE: %d\n", Lista->usuarios[i].idade);
        printf("   SEXO: %s\n", Lista->usuarios[i].sexo);    
        printf("   E-MAIL: %s\n", Lista->usuarios[i].email);
        // Marca o usuario como excluído
        printf("Deseja realmente excluir este usuario? S/N \n");
        do{
          scanf( "%c", &opc);getchar();
          if (opc == 'S' || opc == 's') {
            Lista->usuarios[i].estatos = 1;
      
            // salvar usuarios
            salvar_usuarios(Lista);
            carregar_usuarios(Lista);
            // Diminui a quantidade de usuarios
            Lista->qtd_usuarios--;
            break;
          }
          else if (opc == 'N' || opc == 'n') {
            printf("Exclusão cancelada!\n");
            break;
          }
        }while (opc != 'S' && opc != 's' && opc != 'N' && opc != 'n');
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
    printf("\n");
    printf("\033[32m   NOME:\033[0m %s", u.nome);
    printf("   IDADE: %d\n", u.idade);
    printf("   SEXO: %s\n", u.sexo);    
    printf("   E-MAIL: %s\n", u.email);
    printf("   PESO: %.1f\n", u.peso);
    printf("   ALTURA: %.2f\n", u.altura);
    printf("   IMC: %.2f\n", u.imc);
}


float imc_usuario(usuario u) {
  u.imc = u.peso / (u.altura * u.altura);
  return u.imc;
}
