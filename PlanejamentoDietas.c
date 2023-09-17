//+-------------------------------------------------------+//
//| Universidade Federal do Rio Grande do Norte           |//
//| CERES - Caicó                                         |//
//| Período da faculdade: 2023.2                          |//
//| Disciplina: DCT1206 - Programação                     |//
//| Professor: Flavius Gorgonio                           |//
//| Discente: Gustavo Douglas Silva Cruz                  |//
//| Projeto: Sistema de Planejamento de Dietas versão 0.4 |//
//+-------------------------------------------------------+//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "usuario.h"
#include "avaliacao_nutricional.h"
#include "planejamento_alimentar.h"


char menu_inicial();
char menu_acompanhamento();
char tela_registro_medidas ();
char tela_adesao_plan_alimentar ();
char menu_sobre();

int main(void){
  char opc;
  char opc_2;
  do {
    opc = menu_inicial();
    switch(opc){
      case '1': modulo_usuario();
        break;
      case '2': modulo_avaliacao_nutri(); 
        break;
      case '3': modulo_plan_alimentar();
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
    printf("||     0 [Voltar]                                                                                          ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}
