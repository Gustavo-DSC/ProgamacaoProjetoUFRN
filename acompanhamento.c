#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "acompanhamento.h"



void modulo_acompanhamento(void) {
    char opc;
    do {
        opc = menu_acompanhamento();
        switch(opc) {
            case '1': 	tela_registro_medidas();
                        break;
            case '2': 	tela_adesao_plan_alimentar();
                        break;
        } 		
    } while (opc != '0');
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