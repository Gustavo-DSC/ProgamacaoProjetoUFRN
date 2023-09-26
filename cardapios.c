#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cardapios.h"



void modulo_cardapios(void) {
    char opc;
    do {
        opc = menu_cardapios();
        switch(opc) {
            case '1': 	tela_adicionar_cardapio();
                        break;
            case '2': 	tela_lista_cardapio();
                        break;
            case '3':   tela_editar_cardapio();
                        break;
            case '4':   tela_excluir_cardapio();
                        break;
        } 		
    } while (opc != '0');
}



char menu_cardapios (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =======================================    CARDÁPIOS   ========================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Adicionar Cardápio]                                                    ||\n");
    printf("||                               2 [Lista de Cardapios]                                                    ||\n");
    printf("||                               3 [Editar Cardápio]                                                       ||\n");
    printf("||                               4 [Excluir Cardápio]                                                      ||\n");    
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
    return opc;
}


char tela_adicionar_cardapio (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================   ADICIONAR CARDÁPIO   ===================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     	Objetivo do cardápio: 1(Ganhar peso) 2(Perde peso) 3(Manter peso) 4(Ganha massa muscular)          ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||      Café da manhã:                                                                                     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      Lanche da Manhã:                                                                             	   ||\n");
    printf("||                                                                                		                   ||\n");
    printf("||      Almoço:                                                                                     	   ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||      Lanche da Tarde:                                                                                   ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||      Jantar:                                                                                            ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      Ceia:                                                                                              ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}
                    
char tela_lista_cardapio (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================   LISTA DE CARDÁPIOS   ===================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                		                   ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}                                                

char tela_editar_cardapio (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ======================================   EDITAR CARDÁPIO   ====================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     	Objetivo do cardápio: 1(Ganhar peso) 2(Perde peso) 3(Manter peso) 4(Ganha massa muscular)          ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||      Café da manhã:                                                                                     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      Lanche da Manhã:                                                                                   ||\n");
    printf("||                                                                                		                   ||\n");
    printf("||      Almoço:                                                                                     	   ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||      Lanche da Tarde:                                                                                   ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||      Jantar:                                                                                            ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      Ceia:                                                                                              ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_excluir_cardapio (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================   EXCLUIR CARDÁPIO   ====================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                		                   ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                            			                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("||      0 [Voltar]                                                                                         ||\n");
    printf("||                                                                            			                   ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}