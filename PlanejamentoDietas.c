//+-------------------------------------------------------+//
//| Universidade Federal do Rio Grande do Norte           |//
//| CERES - Caicó                                         |//
//| Período da faculdade: 2023.2                          |//
//| Disciplina: DCT1206 - Programação                     |//
//| Professor: Flavius Gorgonio                           |//
//| Discente: Gustavo Douglas Silva Cruz                  |//
//| Projeto: Sistema de Planejamento de Dietas versão 0.8 |//
//+-------------------------------------------------------+//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "usuario.h"
#include "avaliacao_nutricional.h"
#include "planejamento_alimentar.h"
#include "acompanhamento.h"
#include "sobre.h"
#include "cardapios.h"

char menu_inicial();

int main(void){
  char opc;

  do {
    opc = menu_inicial();
    switch(opc){
      case '1': modulo_usuario();
        break;
      case '2': modulo_avaliacao_nutri(); 
        break;
      case '3': modulo_plan_alimentar();
        break;
      case '4': modulo_acompanhamento();
        break;
      case '5': modulo_cardapios();
        break;
      case '6': modulo_sobre();
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
    printf("||                               1 [Usuário]                                                               ||\n");
    printf("||                               2 [Avaliação Nutricional]                                                 ||\n");
    printf("||                               3 [Planejamento Alimentar]                                                ||\n");
    printf("||                               4 [Acompanhamento do Usuário]                                             ||\n");
    printf("||                               5 [Cardápios]                                                             ||\n");
    printf("||                               6 [Sobre]                                                                 ||\n");
    printf("||                               0 [Sair]                                                                  ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}




