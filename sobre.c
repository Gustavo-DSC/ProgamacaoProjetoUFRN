#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sobre.h"



void modulo_sobre(void) {
    char opc;
    do {
        opc = menu_sobre();
    } while (opc != '0');
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

