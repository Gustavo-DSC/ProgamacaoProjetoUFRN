#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "cardapios.h"
#include "utilidades.h"

void modulo_cardapios(void)
{
    cardapio Cardapio;
    char opc;
    do
    {
        opc = menu_cardapios();
        switch (opc)
        {
        case '1':
            tela_adicionar_cardapio(&Cardapio);
            break;
        case '2':
            tela_lista_cardapio();
            break;
        case '3':
            tela_editar_cardapio(&Cardapio);
            break;
        case '4':
            tela_buscar_cardapio();
            break;
        case '5':
            tela_excluir_cardapio(&Cardapio);
            break;
        }
    } while (opc != '0');
}

char menu_cardapios()
{
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
    printf("||                               4 [Buscar Cardápio]                                                       ||\n");
    printf("||                               5 [Excluir Cardápio]                                                      ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    opc = digite_opcao();
    return opc;
}

void tela_adicionar_cardapio(cardapio *Cardapio)
{
    FILE *arquivo = fopen("cardapios.data", "ab+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }

    Cardapio = (cardapio *)malloc(sizeof(cardapio));
  
    char opc;
    int resultado;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================   ADICIONAR CARDÁPIO   ===================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");

    strcpy(Cardapio->cod_cardapio, gerar_codigo_unico());
    printf("     	  CÓDIGO DO CARDÁPIO: %s\n", Cardapio->cod_cardapio);
    printf("\n");
    printf("     	  NOME DO CARDÁPIO:");
    fgets(Cardapio->nome, sizeof(Cardapio->nome), stdin);
    Cardapio->nome[strcspn(Cardapio->nome, "\n")] = '\0';
    do
    {
        printf("    	  OBJETIVO DO CARDÁPIO: 1(Ganhar peso) 2(Perde peso) 3(Manter peso) 4(Ganha massa muscular): ");
        resultado = scanf("%d", &Cardapio->objetivo);
        getchar(); // Limpa o buffer
    } while (resultado != 1 || Cardapio->objetivo < 1 || Cardapio->objetivo > 4);

    printf("     	  DIETA DO CARDÁPIO (digite FIM para termina): \n");
    char dieta[2000] = "";
    char linha[200];
    int contador = 0;
    int max_chars = 105; // número máximo de caracteres por linha

    while (fgets(linha, sizeof(linha), stdin))
    {
        if (strcmp(linha, "FIM\n") == 0)
        {
            break;
        }
        int i = 0;
        while (linha[i] != '\0' && contador < sizeof(dieta) - 1)
        {
            dieta[contador++] = linha[i++];
            if (contador % max_chars == 0)
            {
                dieta[contador++] = '\n';
            }
        }
    }
    dieta[contador] = '\0'; // termina a string
    strncpy(Cardapio->dieta_cardapio, dieta, sizeof(Cardapio->dieta_cardapio) - 1);
    Cardapio->dieta_cardapio[sizeof(Cardapio->dieta_cardapio) - 1] = '\0'; // Garante que a string é terminada

    do
    {
        printf("     	  CALORIAS DO CARDÁPIO: ");
        resultado = scanf("%f", &Cardapio->cal_cardapio);
        getchar(); // Limpa o buffer
    } while (resultado != 1);
    fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
    fclose(arquivo);
    free(Cardapio);
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}

void tela_lista_cardapio()
{
    FILE *arquivo = fopen("cardapios.data", "rb");
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }

    char opc, slc;
    float min_cal, max_cal;
    cardapio CardapioLocal;

    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ====================================   LISTA DE CARDÁPIOS   ===================================     ||\n");
    // Solicite ao usuário o critério de listagem
    printf("||   1 [Todos os cardápios]                                                                                ||\n");
    printf("||   2 [Cardápios para ganhar peso]                                                                        ||\n");
    printf("||   3 [Cardápios para perder peso]                                                                        ||\n");
    printf("||   4 [Cardápios para manter peso]                                                                        ||\n");
    printf("||   5 [Cardápios para ganhar massa muscular]                                                              ||\n");
    printf("||   6 [Cardápios com valor nutricional específico]                                                        ||\n");
    printf("||   0 [Sair]                                                                                              ||\n");
    do
    {
    printf("     ESCOLHA A OPÇÃO DE LISTAGEM: ");
    slc = digite_opcao();
    }while(slc != '1' && slc != '2' && slc != '3' && slc != '4' && slc != '5' && slc != '6' && slc != '0');
  
    printf("\n");
    printf("\033[32m   +----------------------+--------------------------------+---------------------------+------------------+\n");
    printf("   |   CODIGO DO CARDÁPIO |              NOME              |    OBJETIVO DO CARDÁPIO   |      CALORIAS    |\n");
    printf("   +----------------------+--------------------------------+---------------------------+------------------+ \033[0m\n");
    switch (slc)
    {
    case '1':
        // Filtro para todos os cardápios
        while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo))
        {
            imprimir_cardapio_tab(CardapioLocal);
        }
        break;
    case '2':
        // Filtro para cardápios para ganhar peso
        while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo))
        {
            if (CardapioLocal.objetivo == 1)
            {
                imprimir_cardapio_tab(CardapioLocal);
            }
        }
        break;
    case '3':
        // Filtro para cardápios para perder peso
        while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo))
        {
            if (CardapioLocal.objetivo == 2)
            {
                imprimir_cardapio_tab(CardapioLocal);
            }
        }
        break;
    case '4':
        // Filtro para cardápios para manter peso
        while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo))
        {
            if (CardapioLocal.objetivo == 3)
            {
                imprimir_cardapio_tab(CardapioLocal);
            }
        }
        break;
    case '5':
        // Filtro para cardápios para ganhar massa muscular
        while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo))
        {
            if (CardapioLocal.objetivo == 4)
            {
                imprimir_cardapio_tab(CardapioLocal);
            }
        }
        break;
    case '6':
        // Filtro para cardápios com valor nutricional específico
        printf("Digite o valor mínimo de calorias: ");
        scanf("%f", &min_cal);
        printf("Digite o valor máximo de calorias: ");
        scanf("%f", &max_cal);
        while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo))
        {
            if (CardapioLocal.cal_cardapio >= min_cal && CardapioLocal.cal_cardapio <= max_cal)
            {
                imprimir_cardapio_tab(CardapioLocal);
            }
        }
        break;
    }

    fclose(arquivo);
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}

void tela_buscar_cardapio()
{
    FILE *arquivo = fopen("cardapios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }
    char opc;
    char buscar_cod[11];
    cardapio CardapioLocal;

    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================   BUSCAR CARDÁPIO   ====================================      ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     	PESQUISAR POR CODIGO: ");
    fgets(buscar_cod, sizeof(buscar_cod), stdin);
    getchar();
    // Lê os cardapios do arquivo um por um
    while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivo))
    {
        // Compara o codigo do cardapio com o codigo buscado
        if (strcmp(CardapioLocal.cod_cardapio, buscar_cod) == 0)
        {
            printf("\n");
            printf("\033[32m   +----------------------+--------------------------------+---------------------------+------------------+\n");
            printf("   |   CODIGO DO CARDÁPIO |              NOME              |    OBJETIVO DO CARDÁPIO   |      CALORIAS    |\n");
            printf("   +----------------------+--------------------------------+---------------------------+------------------+ \033[0m\n");
            printf("   | \033[31m%-20s\033[0m | %-30s | %-25s | %-16.2f |\n", CardapioLocal.cod_cardapio, CardapioLocal.nome,
                   CardapioLocal.objetivo == 1 ? "Ganhar peso" : CardapioLocal.objetivo == 2 ? "Perder peso"
                                                             : CardapioLocal.objetivo == 3   ? "Manter peso"
                                                             : CardapioLocal.objetivo == 4   ? "Ganhar massa muscular"
                                                                                             : "Objetivo inválido",
                   CardapioLocal.cal_cardapio);
            printf("   +----------------------+--------------------------------+---------------------------+------------------+\n");
            printf("\n    DIETA DO CARDÁPIO: \n");
            printf("   ========================================================================================================\n");
            char *dieta = CardapioLocal.dieta_cardapio;
            char *linha = strtok(dieta, "\n");

            while (linha != NULL)
            {
                printf("    %s%s\n", "", linha); // Adiciona 6 espaços antes de cada linha
                linha = strtok(NULL, "\n");
            }
            printf("   ========================================================================================================\n");
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}

void tela_editar_cardapio(cardapio *Cardapio)
{
    FILE *arquivo = fopen("cardapios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }

    Cardapio = (cardapio *)malloc(sizeof(cardapio));
  
    char opc;
    char buscar_cod[11];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ======================================   EDITAR CARDÁPIO   ====================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     	PESQUISAR POR CODIGO: ");
    fgets(buscar_cod, sizeof(buscar_cod), stdin);
    printf("||\n");
    printf("||\n");

    while (fread(Cardapio, sizeof(cardapio), 1, arquivo))
    {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(Cardapio->cod_cardapio, buscar_cod) == 0)
        {
            printf("\033[33m=============================================================================================================\n");
            printf("--------- Deseja atualizar a nome? (s/n) -\033[0m ");
            scanf(" %c", &opc);
            getchar();
            if (opc == 's' || opc == 'S')
            {
                printf("    NOME DO CARDÁPIO: ");
                fgets(Cardapio->nome, sizeof(Cardapio->nome), stdin);
                Cardapio->nome[strcspn(Cardapio->nome, "\n")] = '\0';
                fseek(arquivo, -sizeof(cardapio), SEEK_CUR);
                fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            printf("\033[33m=============================================================================================================\n");
            printf("--------- Deseja atualizar a objetivo? (s/n) -\033[0m ");
            scanf(" %c", &opc);
            getchar();
            if (opc == 's' || opc == 'S')
            {
                printf("    Objetivo do cardápio: 1(Ganhar peso) 2(Perde peso) 3(Manter peso) 4(Ganha massa muscular):");
                scanf("%d", &Cardapio->objetivo);
                getchar();
                fseek(arquivo, -sizeof(cardapio), SEEK_CUR);
                fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            printf("\033[33m=============================================================================================================\n");
            printf("--------- Deseja atualizar a dieta? (s/n) -\033[0m ");
            scanf(" %c", &opc);
            getchar();
            if (opc == 's' || opc == 'S')
            {
                printf("     	  DIETA DO CARDÁPIO (digite FIM para termina): \n");
                char dieta[2000] = "";
                char linha[200];
                int contador = 0;
                int max_chars = 105; // número máximo de caracteres por linha
  
                while (fgets(linha, sizeof(linha), stdin))
                {
                    if (strcmp(linha, "FIM\n") == 0)
                    {
                        break;
                    }
                    int i = 0;
                    while (linha[i] != '\0' && contador < sizeof(dieta) - 1)
                    {
                        dieta[contador++] = linha[i++];
                        if (contador % max_chars == 0)
                        {
                            dieta[contador++] = '\n';
                        }
                    }
                }
                dieta[contador] = '\0'; // termina a string
                strncpy(Cardapio->dieta_cardapio, dieta, sizeof(Cardapio->dieta_cardapio) - 1);
                Cardapio->dieta_cardapio[sizeof(Cardapio->dieta_cardapio) - 1] = '\0'; // Garante que a string é terminada
            }
            printf("\033[33m=============================================================================================================\n");
            printf("--------- Deseja atualizar a calorias? (s/n) -\033[0m ");
            scanf(" %c", &opc);
            getchar();
            if (opc == 's' || opc == 'S')
            {
                printf("    CALORIAS DO CARDÁPIO: ");
                scanf("%f", &Cardapio->cal_cardapio);
                getchar();
                fseek(arquivo, -sizeof(cardapio), SEEK_CUR);
                fwrite(Cardapio, sizeof(cardapio), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
        }
    }
    fclose(arquivo);
    free(Cardapio);
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}

void tela_excluir_cardapio(cardapio *Cardapio)
{
    FILE *arquivo = fopen("cardapios.data", "rb");
    FILE *temp = fopen("temp.data", "wb"); // Arquivo temporário
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }

    Cardapio = (cardapio *)malloc(sizeof(cardapio));
    char opc;
    char buscar_cod[11];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================   EXCLUIR CARDÁPIO   ====================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     CODIGO DO CARDÁPIO A SER EXCLUÍDO: ");
    fgets(buscar_cod, sizeof(buscar_cod), stdin);
    getchar();
    // Lê os cardapios do arquivo um por um
    while (fread(Cardapio, sizeof(cardapio), 1, arquivo))
    {
        // Compara o CPF do cardapio com o CPF buscado
        if (strcmp(Cardapio->cod_cardapio, buscar_cod) == 0)
        {
            // Pergunta se o cardapio quer excluir o cardapio
            printf("\033[33m=============================================================================================================\n");
            printf("--------- Deseja realmente excluir este cardapio? (s/n) -\033[0m ");
            do
            {
                scanf("%c", &opc);
                getchar();
                if (opc == 'S' || opc == 's')
                {
                  printf("\033[31m||=========================================================================================================||\n");    
                  printf("||                                        Exclusão física realizada!                                       ||\n");
                  printf("||=========================================================================================================||\033[0m\n");  
                }
                else if (opc == 'N' || opc == 'n')
                {
                  printf("\033[32m||=========================================================================================================||\n");    
                  printf("||                                             Exclusão cancelada!                                         ||\n");
                  printf("||=========================================================================================================||\033[0m\n");  
                    // Copia o cardapio para o novo arquivo
                    fwrite(Cardapio, sizeof(cardapio), 1, temp);
                }
            } while (opc != 'S' && opc != 's' && opc != 'N' && opc != 'n');
        }
        else
        {
            // Copia o cardapio para o novo arquivo
            fwrite(Cardapio, sizeof(cardapio), 1, temp);
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temp);
    free(Cardapio);
    // Exclui o arquivo antigo
    remove("cardapios.data");

    // Renomeia o novo arquivo para o nome do arquivo antigo
    rename("temp.data", "cardapios.data");
    
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}

void substituir_caractere(char *str, char procurar, char substituir)
{
    char *posicao_atual = strchr(str, procurar);
    while (posicao_atual)
    {
        *posicao_atual = substituir;
        posicao_atual = strchr(posicao_atual, procurar);
    }
}

char *gerar_codigo_unico()  
{
    time_t agora = time(NULL);
    struct tm *t = localtime(&agora);

    long long numero_unico = (t->tm_year + 1900) * 10000000000LL +
                             (t->tm_mon + 1) * 100000000LL +
                             t->tm_mday * 1000000LL +
                             t->tm_hour * 10000LL +
                             t->tm_min * 100LL +
                             t->tm_sec;

    char digitos_base30[] = "0123456789ABCDEFGHIJKLMNOPQRST";
    char *string_base30 = malloc(11 * sizeof(char));
    int indice_digito = 0;

    while (numero_unico != 0)
    {
        string_base30[indice_digito++] = digitos_base30[numero_unico % 30];
        numero_unico /= 30;
    }

    string_base30[indice_digito] = '\0';

    return string_base30;
}

void imprimir_cardapio_tab(cardapio u)
{
    printf("   | \033[31m%-20s\033[0m | %-30s | %-25s | %-16.2f |\n", u.cod_cardapio, u.nome,
           u.objetivo == 1 ? "Ganhar peso" : u.objetivo == 2 ? "Perder peso"
                                         : u.objetivo == 3   ? "Manter peso"
                                         : u.objetivo == 4   ? "Ganhar massa muscular"
                                                             : "Objetivo inválido",
           u.cal_cardapio);
    printf("   +----------------------+--------------------------------+---------------------------+------------------+\n");
}