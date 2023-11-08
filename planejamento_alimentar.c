#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "planejamento_alimentar.h"
#include "usuario.h"



void modulo_plan_alimentar(void) {
    usuario Usuario;
    lista_usuarios Lista;
    Lista.qtd_usuarios = 0;
    carregar_usuarios(&Lista);
    char opc;
    do {
        opc = menu_plan_alimentar();
        switch(opc) {
            case '1': 	tela_imc_cal(&Lista);
                        salvar_usuarios(&Lista);
                        break;
            case '2': 	tela_cardapio_peso();
                        break;
            case '3': 	tela_cardapio_nutricional();
                        break;

        } 		
    } while (opc != '0');
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
    printf("||                               1 [Cálculo do IMC e  necessidades calóricas]                              ||\n");
    printf("||                               2 [Sugestão de Cardápios Personalizados para Objetivos de Peso]           ||\n");
    printf("||                               3 [Sugestão de Cardápios Baseados em Necessidades Nutricionais]           ||\n");
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


char tela_imc_cal (lista_usuarios *Lista) {
    char opc;
    char buscar_nome[100];
    getchar();
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ======================================   IMC DO PACIENTE  =====================================     ||\n");
    printf("||     NOME DO PACIENTE: "); fgets(buscar_nome, sizeof(buscar_nome), stdin);
    int i;
    for (i = 0; i < Lista->qtd_usuarios; i++) {
      if (strcmp(Lista->usuarios[i].nome, buscar_nome) == 0) {
        Lista->usuarios[i].imc = Lista->usuarios[i].peso / (Lista->usuarios[i].altura * Lista->usuarios[i].altura);

        if (strcmp(Lista->usuarios[i].sexo, "masculino") == 0){
          Lista->usuarios[i].nec_cal = 10 * Lista->usuarios[i].peso + 6.25 * (Lista->usuarios[i].altura * 100) - 5 * Lista->usuarios[i].idade + 5;
        }
        else if (strcmp(Lista->usuarios[i].sexo, "feminino") == 0){
          Lista->usuarios[i].nec_cal = 10 * Lista->usuarios[i].peso + 6.25 * (Lista->usuarios[i].altura * 100) - 5 * Lista->usuarios[i].idade - 161;
        }
        if (strcmp(Lista->usuarios[i].ativ_fisica, "sedentário") == 0){
          Lista->usuarios[i].nec_cal = Lista->usuarios[i].nec_cal * 1.2;
        }
        else if (strcmp(Lista->usuarios[i].ativ_fisica, "leve") == 0){
          Lista->usuarios[i].nec_cal = Lista->usuarios[i].nec_cal * 1.375;
        }
        else if (strcmp(Lista->usuarios[i].ativ_fisica, "moderado") == 0){
          Lista->usuarios[i].nec_cal = Lista->usuarios[i].nec_cal * 1.55;
        }
        else if (strcmp(Lista->usuarios[i].ativ_fisica, "intenso" ) == 0){
          Lista->usuarios[i].nec_cal = Lista->usuarios[i].nec_cal * 1.725;
        }
        else if (strcmp(Lista->usuarios[i].ativ_fisica, "muito intenso" ) == 0){
          Lista->usuarios[i].nec_cal = Lista->usuarios[i].nec_cal * 1.9;
        }



        printf("||                                                                                                         \n");
        printf("||         tabela de valores de IMC          |   PACIENTE: \033[32m %s \033[0m \n", Lista->usuarios[i].nome);
        printf("||     IMC               CLASSIFICAÇÃO       |\n");
        printf("||     < 16,00           Magreza grau III    |   IMC: \033[32m %.2f \033[0m \n", Lista->usuarios[i].imc);
        printf("||     16,00 - 16,99     Magreza grau II     |\n");
        printf("||     17,00 - 18,49     Magreza grau I      |   ESTIMATIVA DAS NECESSIDADES CALÓRICAS COM BASE  \n");
        printf("||     18,50 - 24,99     Peso normal         |   NO NÍVEL DE ATIVIDADE FÍSICA:\033[32m %.2f \033[0m \n", Lista->usuarios[i].nec_cal);
        printf("||     25,00 - 29,99     Sobrepeso           |\n");    
        printf("||     30,00 - 34,99     Obesidade grau I    |\n");
        printf("||     35,00 - 39,99     Obesidade grau II   |\n");
        printf("||     40,00 >           Obesidade grau III  |\n");    
        printf("||\n");
        printf("||\n");    
        printf("||     0 -[voltar]\n");
        printf("||\n");
        printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
        printf("||Selecione a opção:\n");
        scanf(" %c", &opc);
      }
    }
    return opc;
}



char tela_cardapio_peso(){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ==========================     CARDÁPIOS PARA OBJETIVOS DE PESO    ============================     ||\n");
    printf("||                                                                                                         ||\n");
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
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
    
}



char tela_cardapio_nutricional(){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ========================   CARDÁPIOS PARA NECESSIDADES NUTRICIONAIS   =========================     ||\n");
    printf("||                                                                                                         ||\n");
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
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    return opc;
}