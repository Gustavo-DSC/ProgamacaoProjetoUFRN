#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "usuario.h"
#include "utilidades.h"



char nome[100];
int idade;
char sexo[100];
char email[100];
float peso;
float altura;
char ativ_fisica[100];


// funções modulo usuario

void modulo_usuario(void) {
    char opc;
    do {
        opc = menu_inf_usuario();
        switch(opc) {
            case '1': 	tela_dados_pessoais();
                        break;
            case '2': 	tela_restricao_alimentar();
                        break;
            case '3':   tela_novo_usuario();
                        break;
            case '4':   tela_mudar_usuario();
                        break;
            case '5':   tela_atualizar_usuario();
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
    return opc;
}

char tela_dados_pessoais (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================    DADOS PESSOAIS    ====================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                   NOME:                                                                                 ||\n");
    printf("||                   IDADE:                                                                                ||\n");
    printf("||                   SEXO:                                                                                 ||\n");    
    printf("||                   E-MAIL:                                                                               ||\n");
    printf("||                   PESO:                                                                                 ||\n");
    printf("||                   ALTURA:                                                                               ||\n");
    printf("||                   FREQUÊNCIA DE ATIVIDADE FÍSICA:                                                       ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                   0 [Voltar]                                                                            ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||\n");
    scanf(" %c", &opc);
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
    printf("||\n");
    scanf(" %c", &opc);
    return opc;
}



char tela_novo_usuario (){
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
      fgets(nome, sizeof(nome), stdin);
      if (valida_nome(nome) != 0){
        printf("\033[32m NOME VALIDO \033[0m");
      }
      else {
        printf("\033[31m NOME INVALIDO! \033[0m");
      }
  
      printf("\n||                   IDADE: ");   /// Idade do usuário
      scanf("%d", &idade); getchar();
      if (valida_idade(idade) != 0){
        printf("\033[32m IDADE VALIDO \033[0m");
      }
      else {
        printf("\033[31m IDADE INVALIDO! \033[0m");
      }
      
      printf("\n||                   SEXO: ");  /// Sexo 
      fgets(sexo, sizeof(sexo), stdin);
      if (valida_sexo(sexo) != 0){
        printf("\033[32m SEXO VALIDO \033[0m");
      }
      else {
        printf("\033[31m SEXO INVALIDO! \033[0m");
      }
  
      printf("\n||                   E-MAIL: "); /// Email
      fgets(email, sizeof(email), stdin);
      if (valida_email(email) != 0){
        printf("\033[32m EMAIL VALIDO \033[0m");
      }
      else {
        printf("\033[31m EMAIL INVALIDO! \033[0m");
      }
  
      printf("\n||                   PESO: ");   /// Peso do usuário
      scanf("%f", &peso); getchar();
      if (valida_peso(peso) != 0){
        printf("\033[32m PESO VALIDO \033[0m");
      }
      else {
        printf("\033[31m PESO INVALIDO! \033[0m");
      }
  
      printf("\n||                   ALTURA: "); /// Altura do usuário
      scanf("%f", &altura); getchar();
      if (valida_altura(altura) != 0){
        printf("\033[32m ALTURA VALIDO \033[0m");
      }
      else {
        printf("\033[31m ALTURA INVALIDO! \033[0m");
      }
  
      printf("\n||                   FREQUÊNCIA DE ATIVIDADE FÍSICA:");
      printf("\n||                   > NUNCA | RARAMENTE | FREQUENTEMENTE | TODO DIA");scanf("%s", ativ_fisica); getchar();
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



char tela_atualizar_usuario (){
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
    fgets(nome, sizeof(nome), stdin);
    if (valida_nome(nome) != 0){
      printf("\033[32m NOME VALIDO \033[0m");
    }
    else {
      printf("\033[31m NOME INVALIDO! \033[0m");
    }
 
    printf("\n||                   IDADE: ");   /// Idade do usuário
    scanf("%d", &idade); getchar();
    if (valida_idade(idade) != 0){
      printf("\033[32m IDADE VALIDO \033[0m");
    }
    else {
      printf("\033[31m IDADE INVALIDO! \033[0m");
    }
      
    printf("\n||                   SEXO: ");  /// Sexo 
    fgets(sexo, sizeof(sexo), stdin);
    if (valida_sexo(sexo) != 0){
      printf("\033[32m SEXO VALIDO \033[0m");
    }
    else {
      printf("\033[31m SEXO INVALIDO! \033[0m");
    }
  
    printf("\n||                   E-MAIL: "); /// Email
    fgets(email, sizeof(email), stdin);
    if (valida_email(email) != 0){
      printf("\033[32m EMAIL VALIDO \033[0m");
    }
    else {
      printf("\033[31m EMAIL INVALIDO! \033[0m");
    }
  
    printf("\n||                   PESO: ");   /// Peso do usuário
    scanf("%f", &peso); getchar();
    if (valida_peso(peso) != 0){
      printf("\033[32m PESO VALIDO \033[0m");
    }
    else {
      printf("\033[31m PESO INVALIDO! \033[0m");
    }
  
    printf("\n||                   ALTURA: ");
    scanf("%f", &altura); getchar();
    if (valida_altura(altura) != 0){
      printf("\033[32m ALTURA VALIDO \033[0m");
    }
    else {
      printf("\033[31m ALTURA INVALIDO! \033[0m");
    }
  
    printf("\n||                   FREQUÊNCIA DE ATIVIDADE FÍSICA:");
    printf("\n||                   > NUNCA | RARAMENTE | FREQUENTEMENTE | TODO DIA");scanf("%s", ativ_fisica); getchar();
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



int valida_nome(char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i]) && !isspace(str[i])) {
            return 0;
        }
    }
    return 1;
}


int valida_idade(int idade) {
    int idade_min = 8;  
    int idade_max = 120;  

    if (idade >= idade_min && idade <= idade_max){
      return 1;
    }
  return 0;
}


int valida_sexo(char *str) {
    char *espaco = strchr(str, '\n');  // procura por '\n' na string
      if (espaco){                        // se '\n' foi encontrado
        *espaco = 0;                     // substitui '\n' por '\0'
      }
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }

    if (strcmp(str, "masculino") == 0 || strcmp(str, "feminino") == 0){
      return 1;
    }
  return 0;
}



int valida_email(char *email) {
    char *arroba = strchr(email, '@');
    char *ponto = strrchr(email, '.');
    char *espaco = strchr(email, '\n');  
    if (espaco){                        
      *espaco = 0;                     
    }
    if (arroba != NULL && ponto != NULL && arroba < ponto) {
        // Verifica se há apenas um '@' no email 
        if (strchr(arroba + 1, '@') == NULL) {
            // Verifica se tem pelo menos um caractere antes do '@'
            if (arroba != email) {
                // Verifica se tem pelo menos um caractere entre '@' e '.'
                if (arroba + 1 < ponto) {
                    // Verifica se tem pelo menos dois caracteres após o '.'
                    if (strlen(ponto) > 2) {
                        // Verifica se o email contém caracteres especiais
                        for (char *c = email; *c; c++) {
                            if ((*c < 'a' || *c > 'z') && (*c < 'A' || *c > 'Z') && (*c < '0' || *c > '9') && *c != '@' && *c != '.' && *c != '-' && *c != '_') {
                                return 0;
                            }
                        }
                        // Verifica o comprimento da parte local e do domínio
                        if ((arroba - email <= 64) && (strlen(arroba) - strlen(ponto) <= 255)) {
                            return 1;
                            printf("legal\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}



int valida_peso(float peso) {
    float peso_min = 20.0;  
    float peso_max = 650.0;  

    if (peso >= peso_min && peso <= peso_max){
        return 1;
    }
    return 0;
}


int valida_altura(float altura) {
    float altura_min = 0.40; 
    float altura_max = 2.5; 

    if (altura >= altura_min && altura <= altura_max){
        return 1;
    }
    return 0;
}