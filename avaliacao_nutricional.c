#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "avaliacao_nutricional.h"



void modulo_avaliacao_nutri(void) {
    char opc;
    do {
        opc = menu_avaliacao_nutri();
        switch(opc) {
            case '1': 	tela_imc();
                        break;
            case '2': 	tela_ingestao_alimentar();
                        break;
        } 		
    } while (opc != '0');
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