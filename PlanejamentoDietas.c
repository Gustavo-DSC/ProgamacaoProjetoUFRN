//+-------------------------------------------------------+//
//| Universidade Federal do Rio Grande do Norte           |//
//| CERES - Caicó                                         |//
//| Período da faculdade: 2023.2                          |//
//| Disciplina: DCT1206 - Programação                     |//
//| Professor: Flavius Gorgonio                           |//
//| Discente: Gustavo Douglas Silva Cruz                  |//
//| Projeto: Sistema de Planejamento de Dietas vers�o 0.3 |//
//+-------------------------------------------------------+//


#include <stdio.h>
#include <stdlib.h>

char menu_inicial();
char menu_inf_usuario();
char tela_dados_pessoais();
char tela_restricao_alimentar ();
char menu_avaliacao_nutri();
char tela_imc ();
char tela_ingestao_alimentar ();
char menu_plan_alimentar();
char tela_cria_cardapio();
char tela_suges_substituicao();
char menu_acompanhamento();
char tela_registro_medidas ();
char tela_adesao_plan_alimentar ();
char menu_sobre();

int main(void){
  char opc;
  do {
    opc = menu_inicial();
    switch(opc){
      char opc_2;
      case '1':
        do {
          opc_2 = menu_inf_usuario();
          switch(opc_2){
            case '1':
              tela_dados_pessoais();
              break;
            case '2':
              tela_restricao_alimentar();
              break;
            case '0':
              break;
            
              break;
          }
        } while (opc_2 != '0');
        break;
      case '2':
        do {
          opc_2 = menu_avaliacao_nutri();
          switch(opc_2){
            case '1':
              tela_imc ();
              break;
            case '2':
              tela_ingestao_alimentar ();
              break;
            case '0':
              break;
          }
        } while (opc_2 != '0');
        break;
      case '3':
        do {
          opc_2 = menu_plan_alimentar(); 
          switch(opc_2){
            case '1':
              tela_cria_cardapio();
              break;
            case '2':
              tela_suges_substituicao();
              break;
            case '0':
              break;
          }
        } while (opc_2 != '0');
        break;
      case '4':
        do {
          opc_2 = menu_acompanhamento();
          switch(opc_2){
            case '1':
              tela_registro_medidas ();
              break;
            case '2':
              tela_adesao_plan_alimentar ();
              break;
            case '0':
              break;           
          }
        } while (opc_2 != '0');
        break;
      case '5':
        do {
          opc_2 = menu_sobre();
          switch(opc_2){
            case '0':
              break;
          }
        } while (opc_2 != '0');
        break;
    }
  } while (opc != '0');
  
  return 0;
}


char menu_inicial (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                       _   _           _            _   _____   _                                        ||\n");
    printf("||                      | | | |  _   _  | |_   _ __  (_) |  _  | | |   __ _   _ __                         ||\n");
    printf("||                      |  || | | | | | | __| | '__| | | | |_) | | |  / _` | | '_  |                       ||\n");
    printf("||                      | ||  | | |_| | | |_  | |    | | |  __/  | | | (_| | | | | |                       ||\n");
    printf("||                      |_| |_| |_____| |___| |_|    |_| |_|     |_| |_| |_| |_| |_|                       ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================    MENU INICIAL   =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Informações do Usuário]                                                ||\n");
    printf("||                               2 [Avaliação Nutricional]                                                 ||\n");
    printf("||                               3 [Planejamento Alimentar]                                                ||\n");
    printf("||                               4 [Acompanhamento do Usuário]                                             ||\n");
    printf("||                               5 [Sobre]                                                                 ||\n");
    printf("||                               0 [Sair]                                                                  ||\n");
    printf("||                                                                                                         ||\n");  
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}


char menu_inf_usuario (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ================================    INFORMA��ES DO USU�RIO   ==================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Dados Pessoais]                                                        ||\n");
    printf("||                               2 [Restrições Alimentares]                                                ||\n");    
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
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
    printf("||                   E-MAIL                                                                                ||\n");
    printf("||                   PESO:                                                                                 ||\n");
    printf("||                   ALTURA                                                                                ||\n");
    printf("||                   FREQUÊNCIA DE ATIVIDADE FÍSICA - NUNCA | RARAMENTE | FREQUENTEMENTE | TODO DIA        ||\n");
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

char menu_avaliacao_nutri (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ================================    AVALIAÇÃO  NUTRICIONAL   ==================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Cálculo do IMC]                                                        ||\n");
    printf("||                               2 [Avaliação da Ingestão Alimentar]                                       ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
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
    return opc;
}
char tela_imc (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ========================================   IMC USÚARIO  =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||         tabela de valores de IMC          | INFORMAÇÕES                                                 ||\n");
    printf("||     IMC               CLASSIFICAÇÃO       | O IMC (índice de Massa Corporal). É uma técnica utilizada   ||\n");
    printf("||     < 16,00           Magreza grau III    | para verificar o estado nutricional e observar se a pessoa  ||\n");
    printf("||     16,00 - 16,99     Magreza grau II     | está dentro dos padrões de normalidade com relação ao seu   ||\n");
    printf("||     17,00 - 18,49     Magreza grau I      | peso e estatura                                             ||\n");
    printf("||     18,50 - 24,99     Peso normal         |                                                             ||\n");
    printf("||     25,00 - 29,99     Sobrepeso           | SEU IMC :                                                   ||\n");    
    printf("||     30,00 - 34,99     Obesidade grau I    |                                                             ||\n");
    printf("||     35,00 - 39,99     Obesidade grau II   |                                                             ||\n");
    printf("||     ? 40,00           Obesidade grau III  |                                                             ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||     0 -[voltar]                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}
char tela_ingestao_alimentar (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =============================   AVALIAÇÃO DA INGESTÃO ALIMENTAR   =============================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      INFORME SE DEIXOU DE FAZER UMA REFEIÇÃO DA DIETA                                                   ||\n");
    printf("||          1 - café da manhã                                                                              ||\n");
    printf("||          2 - almoço                                                                                     ||\n");
    printf("||          3 - jantar                                                                                     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      INFORME COMO VOCÊ ESTÁ SE SENTINDO COM A ALIMENTAÇÃO                                               ||\n");
    printf("||          1 - bem                                                                                        |\n");    
    printf("||          2 - normal                                                                                     ||\n");
    printf("||          3 - ruim                                                                                       ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||      INFOEME SE ALGUM ALIMENTO ESTÁ FAZENDO MAL                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||          0 [Voltar]                                                                                     ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}

char menu_plan_alimentar(){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ================================    PLANEJAMENTO ALIMENTAR   ==================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Criação de Cardápios]                                                  ||\n");
    printf("||                               2 [Sugestões de substituições]                                            ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
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
    return opc;
}

char tela_cria_cardapio(){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ================================     CRIAÇÃO DE CARDÁPIOS    ==================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Este cardápio foi crido, utilizando informações sobre sua altura, peso, idade e nível de atividade  ||\n");
    printf("||     física para calcular suas necessidades calóricas diárias e criar um cardápio personalizado que      ||\n");
    printf("||     atenda às suas necessidades nutricionais.                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Café da manhã:                                                                                      ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Almoço:                                                                                             ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Jantar :                                                                                            ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
    
}

char tela_suges_substituicao(){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===============================   SUSGESTÕES DE SUBSTITUIÇÕES   ===============================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     A substituição de alimentos com valor nutricional igual permite variar as refeições, mantendo       ||\n");
    printf("||     o equilíbrio nutricional. Isso é feito substituindo um alimento por outro de valor nutricional      ||\n");
    printf("||     semelhante. Essa estratégia é útil para evitar a monotonia alimentar e permitir que o paciente      ||\n");
    printf("||     tenha mais autonomia na hora de fazer suas escolhas alimentares.                                    ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Café da manhã:                                                                                      ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Almoço:                                                                                             ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Jantar :                                                                                            ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}

char menu_acompanhamento (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===================================    ACOMPANHAMENTO    ======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Registro de Peso e Medidas Corporais]                                  ||\n");
    printf("||                               2 [Avaliação da Adesão ao Plano Alimentar]                                ||\n");
    printf("||                               3 [Ajuste do Plano Alimentar]                                             ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");    
    printf("||                                                                                                         ||\n");
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
    return opc;
}

char tela_registro_medidas (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =========================    REGISTRO DE PESO E MEDIDAS CORPORAIS    ==========================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     O registro de peso e medidas corporais é uma ferramenta útil para acompanhar o progresso de um      ||\n");
    printf("||     plano de dieta. Ele permite que vocé monitore as mudanças em seu peso, altura, índice de massa      ||\n");
    printf("||     corporal e outras medidas importantes ao longo do tempo. Isso pode ajudá-lo a avaliar a eficêcia    ||\n");
    printf("||     de sua dieta e fazer ajustes conforme necessário.                                                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     INFORME SUAS NOVAS MEDIDAS                                                                          ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||     PESO:                                                                                               ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ALTURA:                                                                                             ||\n");  
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_adesao_plan_alimentar (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===========================  AVALIAÇÃO DA ADESÃO AO PLANO ALIMENTAR  ==========================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Com que frequência você segue o plano alimentar recomendado?                                        ||\n");
    printf("||     1- Sempre                                                                                           ||\n");
    printf("||     2- às vezes                                                                                         ||\n");
    printf("||     3- Nunca                                                                                            ||\n");
    printf("||     Você costuma pular refeições ou substituí-las por lanches não saudúveis?                            ||\n");
    printf("||     1- Sim                                                                                              ||\n");
    printf("||     2- às vezes                                                                                         ||\n");    
    printf("||     3- Não                                                                                              ||\n");
    printf("||     Você costuma comer alimentos não recomendados pelo plano alimentar?                                 ||\n");
    printf("||     1- Sim                                                                                              ||\n");  
    printf("||     2- às vezes                                                                                         ||\n");
    printf("||     3- Não                                                                                              ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}


char menu_sobre (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =========================================    SOBRE    =========================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Bem-vindo ao Sistema de Planejamento de Dietas, um projeto desenvolvido por Gustavo Douglas         ||\n");
    printf("||     Silva Cruz como parte da disciplina DCT1206 - Programação, ministrada pelo Professor Flavius        ||\n");
    printf("||     Gorgonio na Universidade Federal do Rio Grande do Norte, CERES - Caicó, no período 2023.2.          ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Este programa foi criado com o objetivo de auxiliar no planejamento de dietas e é destinado         ||\n");
    printf("||     apenas para fins de aprendizagem, não sendo comercializado. O autor não se responsabiliza por       ||\n"); 
    printf("||     quaisquer problemas que possam ocorrer durante o uso do programa.                                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}
