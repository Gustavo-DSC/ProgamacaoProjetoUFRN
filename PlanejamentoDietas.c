//+----------------------------------------------+//
//| Universidade Federal do Rio Grande do Norte  |//
//| CERES - Caicó                                |//
//| Período da faculdade: 2023.2                 |//
//| Disciplina: DCT1206 - Programação            |//
//| Professor: Flavius Gorgonio                  |//
//| Discente: Gustavo Douglas Silva Cruz         |//
//| Projeto: Sistema de Planejamento de Dietas   |//
//+----------------------------------------------+//


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(void){
setlocale(LC_ALL, "Portuguese");
    menu_inicial();
    return 0;
}

void menu_inicial (void){
    char ops;
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
    printf("||                               5 [Informações Educacionais]                                              ||\n");
    printf("||                               0 [Sair]                                                                  ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               Selecione a opção:                                                        ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf("%c", &ops);
    getchar();
}

