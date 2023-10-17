#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "usuario.h"
#include "utilidades.h"
#include "validacoes.h"


// funções modulo usuario

void modulo_usuario(void) {
    struct usuario Usuario;
    char opc;
    do {
        opc = menu_inf_usuario();
        switch(opc) {
            case '1': 	tela_dados_pessoais(&Usuario);
                        break;
            case '2': 	tela_restricao_alimentar();
                        break;
            case '3':   tela_novo_usuario(&Usuario);
                        break;
            case '4':   tela_mudar_usuario();
                        break;
            case '5':   tela_atualizar_usuario(&Usuario);
                        break;
            case '6':   tela_excluir_usuario();
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
    printf("||                               4 [Mudar Usuário]                                                         ||\n");
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

char tela_dados_pessoais (struct usuario *Usuario){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||\n");    
    printf("||\n");
    printf("||\n");
    printf("||     =====================================    DADOS PESSOAIS    ====================================\n");
    printf("||\n");
    printf("||\n");
    printf("||\n");
    printf("||                   NOME: %s\n", Usuario->nome);
    printf("||                   IDADE: %d\n", Usuario->idade);
    printf("||                   SEXO: %s\n", Usuario->sexo);    
    printf("||                   E-MAIL: %s\n", Usuario->email);
    printf("||                   PESO: %.1f\n", Usuario->peso);
    printf("||                   ALTURA: %.2f\n", Usuario->altura);
    printf("||                   FREQUÊNCIA DE ATIVIDADE FÍSICA:\n");
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



char tela_novo_usuario (struct usuario *Usuario){
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
    return opc;
}



char tela_mudar_usuario (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================    MUDAR USUÁRIO   =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||       LISTA DE USUÁRIOS                                                                                 ||\n");
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



char tela_atualizar_usuario (struct usuario *Usuario){
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



char tela_excluir_usuario (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===================================   EXCLUIR USUÁRIO   =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||       LISTA DE USUÁRIOS                                                                                 ||\n");
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
