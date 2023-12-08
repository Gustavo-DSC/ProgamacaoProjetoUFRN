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
    char opc;
    do {
        opc = menu_inf_usuario();
        switch(opc) {
            case '1': 	tela_novo_usuario(&Usuario); 
                        break;
            case '2': 	tela_buscar_paciente(&Usuario);
                        break;
            case '3':   tela_lista_pacientes();
                        break;
            case '4':   tela_atualizar_paciente(&Usuario);
                        break;
            case '5':   tela_excluir_paciente(&Usuario);
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
    printf("||                               1 [Novo Paciente]                                                         ||\n");
    printf("||                               2 [Buscar Paciente]                                                       ||\n");    
    printf("||                               3 [Lista de Pacientes]                                                    ||\n");
    printf("||                               4 [Atualizar Informações de Paciente]                                     ||\n");
    printf("||                               5 [Excluir Paciente]                                                      ||\n");
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
    scanf(" %c", &opc);
    getchar();
    return opc;
}

void tela_buscar_paciente(usuario *Usuario){
    FILE *arquivo = fopen("usuarios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

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

    // Lê os usuários do arquivo um por um
    while (fread(Usuario, sizeof(usuario), 1, arquivo)) {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(Usuario->cpf, buscar_cpf) == 0) {
            imprimir_usuario(*Usuario);
            break;
        }
    }
    fclose(arquivo);
    printf("||\n");
    printf("||\n");
    printf("||                   0 [Voltar]\n");    
    printf("||\n");
    printf("||\n");
    printf("||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    getchar();
}


char tela_novo_usuario (usuario *Usuario){
      FILE *arquivo = fopen("usuarios.data", "ab+");
      // Verifica se o arquivo está aberto
      if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo!\n");
          return 0;
      }
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
      printf("   CPF: ");    /// CPF do paciente
      fgets(Usuario->cpf, sizeof(Usuario->cpf), stdin);
      remover_nova_linha(Usuario->cpf);
    
      cpf_existe = cpf_existe_no_arquivo(Usuario->cpf);
    
      if (cpf_existe) {
          printf("\033[31m CPF JA EXISTE! \033[0m\n");
      }
      else if (valida_cpf(Usuario->cpf) != 0){
          printf("\033[32m CPF VALIDO \033[0m\n");
      }
      else {
          printf("\033[31m CPF INVALIDO! \033[0m\n");
      }
      } while (valida_cpf(Usuario->cpf) == 0 || cpf_existe == 1);

      if (cpf_existe == 0) {
        do {
          printf("   NOME: ");    /// Nome do usuário
          fgets(Usuario->nome, sizeof(Usuario->nome), stdin);
          remover_nova_linha(Usuario->nome);
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
          remover_nova_linha(Usuario->sexo);
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
          remover_nova_linha(Usuario->email);
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
          printf("   (1)sedentário (2)leve (3)moderado (4)intenso (5)muito intenso  \n");
          fgets(Usuario->ativ_fisica, sizeof(Usuario->ativ_fisica), stdin);
          if (valida_atividade_fisica(Usuario->ativ_fisica) != 0){
            printf("\033[32m ATIVIDADE FÍSICA VALIDA \033[0m\n");
          }
          else {
            printf("\033[31m ATIVIDADE FÍSICA INVALIDA! \033[0m\n");
          }
        } while (valida_atividade_fisica(Usuario->ativ_fisica) == 0);
        Usuario->imc = imc_usuario(*Usuario);
        // Grava o paciente no arquivo
        fwrite(Usuario, sizeof(usuario), 1, arquivo);
        // Fecha o arquivo
        fclose(arquivo);
        }
        printf("||\n");
        printf("||                   0 [Voltar]\n");    
        printf("||\n");
        printf("||\n");
        printf("||\n");    
        printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
        return opc;
}




char tela_lista_pacientes (){
  // Verifica se o arquivo está aberto
  FILE *arquivo = fopen("usuarios.data", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 0;
  }

  char opc, slc;
  usuario Usuario;
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
      imprimir_cab_tab();
      // Filtro para todos os pacientes
      while (fread(&Usuario, sizeof(usuario), 1, arquivo)) {    
        imprimir_usuario_tab(Usuario);
      }
      break;
    case '2':
      imprimir_cab_tab();
      // Filtro para pacientes com alto nível de obesidade
      while (fread(&Usuario, sizeof(usuario), 1, arquivo)) {
        if (Usuario.imc >= 30) { // IMC >= 30 é considerado obesidade    
          imprimir_usuario_tab(Usuario);
        }
      }
      break;
    case '3':
      imprimir_cab_tab();
      // Filtro para pacientes com alto nível de magreza
      while (fread(&Usuario, sizeof(usuario), 1, arquivo)) {
        if (Usuario.imc < 18.5) { // IMC < 18.5 é considerado magreza    
          imprimir_usuario_tab(Usuario);
        }
      }
      break;
    case '4':
      imprimir_cab_tab();
      // Filtro para pacientes do sexo masculino
      while (fread(&Usuario, sizeof(usuario), 1, arquivo)) {
        if (strcmp(Usuario.sexo, "masculino") == 0) {
          imprimir_usuario_tab(Usuario);
        }
      }
      break;
    case '5':
      imprimir_cab_tab();
      // Filtro para pacientes do sexo feminino
      while (fread(&Usuario, sizeof(usuario), 1, arquivo)) {
        if (strcmp(Usuario.sexo, "feminino") == 0) {
          imprimir_usuario_tab(Usuario);
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
  fclose(arquivo);
  printf("||                                                                                                         ||\n");
  printf("||       0 [Voltar]                                                                                        ||\n");
  printf("||                                                                                                         ||\n");
  printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
  scanf(" %c", &opc);
  return opc;
}


char tela_atualizar_paciente(usuario *Usuario){
    FILE *arquivo = fopen("usuarios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
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
    remover_nova_linha(buscar_cpf);
  
    // Lê os usuários do arquivo um por um
    while (fread(Usuario, sizeof(usuario), 1, arquivo)) {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(Usuario->cpf, buscar_cpf) == 0) {
          
          // Pergunta se o usuário quer atualizar a idade
          printf("Deseja atualizar a idade? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
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
          }

          // Pergunta se o usuário quer atualizar o email
          printf("Deseja atualizar o email? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
            do {
              printf("   E-MAIL: "); /// Email
              fgets(Usuario->email, sizeof(Usuario->email), stdin);
              remover_nova_linha(Usuario->email);
              if (valida_email(Usuario->email) != 0){
                printf("\033[32m EMAIL VALIDO \033[0m\n");
              }
              else {
                printf("\033[31m EMAIL INVALIDO! \033[0m\n");
              }
            } while (valida_email(Usuario->email) == 0);
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(Usuario, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }
          
          printf("Deseja atualizar o peso? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
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
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(Usuario, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }

          printf("Deseja atualizar o altura? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
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
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(Usuario, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }
          
          printf("Deseja atualizar o atividade física? (s/n): ");
          scanf(" %c", &opc); getchar();
          if (opc == 's' || opc == 'S') {
            do {
              printf("   FREQUÊNCIA DE ATIVIDADE FÍSICA\n");  // nivel de atividade física
              printf("   (1)sedentário (2)leve (3)moderado (4)intenso (5)muito intenso  \n");
              fgets(Usuario->ativ_fisica, sizeof(Usuario->ativ_fisica), stdin);
              if (valida_atividade_fisica(Usuario->ativ_fisica) != 0){
                printf("\033[32m ATIVIDADE FÍSICA VALIDA \033[0m\n");
              }
              else {
                printf("\033[31m ATIVIDADE FÍSICA INVALIDA! \033[0m\n");
              }
            } while (valida_atividade_fisica(Usuario->ativ_fisica) == 0);
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(Usuario, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          }
          break;
        }
    }
    // Fecha o arquivo
    fclose(arquivo);
  
    printf("||\n");
    printf("||                   0 [Voltar]\n");    
    printf("||\n");
    printf("||\n");
    printf("||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    return opc;
}

char tela_excluir_paciente(usuario *Usuario){
    FILE *arquivo = fopen("usuarios.data", "rb");
    FILE *temp = fopen("temp.data", "wb"); // Arquivo temporário
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      return 0;
    }
  
    char opc;
    char buscar_cpf[14];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||    =====================================    EXCLUIR PACIENTE    ====================================    ||\n");
    printf("||\n");
    printf("||          PESQUISAR POR CPF: "); 
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;
  
    // Lê os usuários do arquivo um por um
    while (fread(Usuario, sizeof(usuario), 1, arquivo)) {
      // Compara o CPF do usuário com o CPF buscado
      if (strcmp(Usuario->cpf, buscar_cpf) == 0) {
        // Pergunta se o usuário quer excluir o usuário
        printf("Deseja realmente excluir este usuario? S/N \n");
        do{
          scanf( "%c", &opc);getchar();
          if (opc == 'S' || opc == 's') {
            // Não copia o usuário para o novo arquivo
          }
          else if (opc == 'N' || opc == 'n') {
            printf("Exclusão cancelada!\n");
            // Copia o usuário para o novo arquivo
            fwrite(Usuario, sizeof(usuario), 1, temp);
          }
        }while (opc != 'S' && opc != 's' && opc != 'N' && opc != 'n');
      }  
      else {
        // Copia o usuário para o novo arquivo
        fwrite(Usuario, sizeof(usuario), 1, temp);
      }
    }
  
    // Fecha os arquivos
    fclose(arquivo);
    fclose(temp);
  
    // Exclui o arquivo antigo
    remove("usuarios.data");
  
    // Renomeia o novo arquivo para o nome do arquivo antigo
    rename("temp.data", "usuarios.data");

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



void imprimir_usuario(usuario u) {
    printf("\n");
    printf("    +--------------------------------------------------------------+\n");
    printf("    |  \033[32m NOME:\033[0m %-53s|\n", u.nome);
    printf("    +--------------------------------------------------------------+\n");
    printf("    |   E-MAIL: %-51s|\n", u.email);
    printf("    +--------------------------------------------------------------+\n");
    printf("    |   IDADE: %-52d|\n", u.idade);
    printf("    +--------------------------------------------------------------+\n");
    printf("    |   SEXO: %-53s|\n", u.sexo);    
    printf("    +--------------------------------------------------------------+\n");
    printf("    |   PESO: %-53.1f|\n", u.peso);
    printf("    +--------------------------------------------------------------+\n");
    printf("    |   ALTURA: %-51.2f|\n", u.altura);
    printf("    +--------------------------------------------------------------+\n");
    printf("    |   IMC: %-54.2f|\n", u.imc);
    printf("    +--------------------------------------------------------------+\n");
    printf("    |   NECESSIDADE CALORICA: %-37.2f|\n", u.nec_cal);
    printf("    +--------------------------------------------------------------+\n");
}


void imprimir_cab_tab() {
  printf("    +----------------------+---------------------------------------+--------------------------------------+\n");
  printf("    | CPF:                 | Nome:                                 | E-mail:                              |\n");
  printf("    +----------------------+---------------------------------------+--------------------------------------+\n");
}

void imprimir_usuario_tab(usuario u) {
    
    printf("    | \033[32m%-18s\033[0m   | %-36s  | %-37s| \n", u.cpf, u.nome, u.email);
    printf("    +----------------------+---------------------------------------+--------------------------------------+\n");
}

float imc_usuario(usuario u) {
  u.imc = u.peso / (u.altura * u.altura);
  return u.imc;
}


int cpf_existe_no_arquivo(char *cpf) {
    FILE *arquivo = fopen("usuarios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    usuario Usuario;

    // Volta para o início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    // Lê os usuários do arquivo um por um
    while (fread(&Usuario, sizeof(usuario), 1, arquivo)) {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(Usuario.cpf, cpf) == 0) {
            fclose(arquivo);
            return 1;  // Retorna verdadeiro se o CPF existir
        }
    }
    fclose(arquivo);
    return 0;  // Retorna falso se o CPF não existir
}

void remover_nova_linha(char *str) {
    str[strcspn(str, "\n")] = 0;
}