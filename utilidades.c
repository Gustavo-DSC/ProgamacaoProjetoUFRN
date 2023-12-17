#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char digite_opcao() {
    char ch, ch_next;

    if (scanf(" %c", &ch) != 1) { // lê um caractere
        return '\0'; // retorna o caractere nulo se nenhum caractere foi digitado
    }

    ch_next = getchar(); // lê o próximo caractere

    // Verifica se o próximo caractere é uma nova linha
    if (ch_next != '\n') {
        // Limpa o buffer de entrada
        while (getchar() != '\n');
        return '\0'; // retorna o caractere nulo se mais de um caractere foi digitado
    }

    return ch;
}


void tela_erro(){
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                       _   _           _            _   _____   _                                        ||\n");
    printf("||                      | | | |  _   _  | |_   _ __  (_) |  _  | | |   __ _   _ __                         ||\n");
    printf("||                      |  || | | | | | | __| | '__| | | | |_) | | |  / _` | | '_  |                       ||\n");
    printf("||                      | ||  | | |_| | | |_  | |    | | |  __/  | | | (_| | | | | |                       ||\n");
    printf("||                      |_| |_| |_____| |___| |_|    |_| |_|     |_| |_| |_| |_| |_|                       ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================       ERRO        =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                 ERRO: Não foi possível abrir o arquivo.                                 ||\n");
    printf("||                       Provavelmente nada foi cadastrado ainda. Tente cadastrar algo.                    ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}