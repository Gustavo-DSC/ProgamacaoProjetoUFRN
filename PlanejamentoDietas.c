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
#include "planejamento_alimentar.h"
#include "acompanhamento.h"
#include "sobre.h"
#include "cardapios.h"
#include "utilidades.h"


char menu_inicial();

int main(void){
  char opc;

  do {
    opc = menu_inicial();
    switch(opc){
      case '1': modulo_usuario();
        break;
      case '2': modulo_plan_alimentar();
        break;
      case '3': modulo_acompanhamento();
        break;
      case '4': modulo_cardapios();
        break;
      case '5': modulo_sobre();
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
    printf("||                               1 [Paciente]                                                              ||\n");
    printf("||                               2 [Planejamento Alimentar]                                                ||\n");
    printf("||                               3 [Acompanhamento do Paciente]                                            ||\n");
    printf("||                               4 [Cardápios]                                                             ||\n");
    printf("||                               5 [Sobre]                                                                 ||\n");
    printf("||                               0 [Sair]                                                                  ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    opc = digite_opcao();
    return opc;
}