//+----------------------------------------------+//
//| Universidade Federal do Rio Grande do Norte  |//
//| CERES - Caic�                                |//
//| Per�odo da faculdade: 2023.2                 |//
//| Disciplina: DCT1206 - Programa��o            |//
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
    printf("||                               1 [Informa��es do Usu�rio]                                                ||\n");
    printf("||                               2 [Avalia��o Nutricional]                                                 ||\n");
    printf("||                               3 [Planejamento Alimentar]                                                ||\n");
    printf("||                               4 [Acompanhamento do Usu�rio]                                             ||\n");
    printf("||                               5 [Informa��es Educacionais]                                              ||\n");
    printf("||                               0 [Sair]                                                                  ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               Selecione a op��o:                                                        ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf("%c", &ops);
    getchar();
}


void menu_inf_usuario (void){
    char ops;
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
    printf("||                               2 [Medidas Corporais]                                                     ||\n");
    printf("||                               3 [Atividade F�sica]                                                      ||\n");
    printf("||                               4 [Prefer�ncias Alimentares]                                              ||\n");
    printf("||                               5 [Restri��es Alimentares]                                                ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               Selecione a op��o:                                                        ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf("%c", &ops);
    getchar();
}


void menu_avaliacao_nutri (void){
    char ops;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ================================    AVALIA��O  NUTRICIONAL   ==================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [C�lculo do IMC]                                                        ||\n");
    printf("||                               2 [Avalia��o da Ingest�o Alimentar]                                       ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               Selecione a op��o:                                                        ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf("%c", &ops);
    getchar();
}

void menu_plan_alimentar(void){
    char ops;
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
    printf("||                               1 [C�lculo das Necessidades Energ�ticas]                                  ||\n");
    printf("||                               2 [C�lculo das Necessidades de Nutrientes]                                ||\n");
    printf("||                               3 [Sele��o de Alimentos]                                                  ||\n");
    printf("||                               4 [Cria��o de Card�pios]                                                  ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               Selecione a op��o:                                                        ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf("%c", &ops);
    getchar();
}