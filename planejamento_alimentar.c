#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cardapios.h"
#include "planejamento_alimentar.h"
#include "usuario.h"





void modulo_plan_alimentar(void) {
    usuario Usuario;
    cardapio Cardapio;
    //carregar_cardapios(&ListaCardapio);
    char opc;
    do {
        opc = menu_plan_alimentar();
        switch(opc) {
            case '1': 	tela_imc_cal(&Usuario);
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
    scanf(" %c", &opc); getchar();
    return opc;
}


char tela_imc_cal(usuario *Usuario)
{
    FILE *arquivo = fopen("usuarios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    char opc;
    char buscar_cpf[14];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ======================================   IMC DO PACIENTE  =====================================     ||\n");
    printf("||     CPF DO PACIENTE: ");
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;

    while (fread(Usuario, sizeof(usuario), 1, arquivo))
    {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(Usuario->cpf, buscar_cpf) == 0 && Usuario->estatos == 0)
        {
            Usuario->imc = Usuario->peso / (Usuario->altura * Usuario->altura);
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(Usuario, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);

            if (strcmp(Usuario->sexo, "masculino") == 0)
            {
                Usuario->nec_cal = 10 * Usuario->peso + 6.25 * (Usuario->altura * 100) - 5 * Usuario->idade + 5;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(Usuario, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(Usuario->sexo, "feminino") == 0)
            {
                Usuario->nec_cal = 10 * Usuario->peso + 6.25 * (Usuario->altura * 100) - 5 * Usuario->idade - 161;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(Usuario, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            if (strcmp(Usuario->ativ_fisica, "1") == 0)
            {
                Usuario->nec_cal = Usuario->nec_cal * 1.2;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(Usuario, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(Usuario->ativ_fisica, "2") == 0)
            {
                Usuario->nec_cal = Usuario->nec_cal * 1.375;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(Usuario, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(Usuario->ativ_fisica, "3") == 0)
            {
                Usuario->nec_cal = Usuario->nec_cal * 1.55;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(Usuario, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(Usuario->ativ_fisica, "4") == 0)
            {
                Usuario->nec_cal = Usuario->nec_cal * 1.725;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(Usuario, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(Usuario->ativ_fisica, "5") == 0)
            {
                Usuario->nec_cal = Usuario->nec_cal * 1.9;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(Usuario, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }

            printf("||                                                                                                         \n");
            printf("||         tabela de valores de IMC          |   PACIENTE: \033[32m %s \033[0m \n", Usuario->nome);
            printf("||     IMC               CLASSIFICAÇÃO       |\n");
            printf("||     < 16,00           Magreza grau III    |   IMC: \033[32m %.2f \033[0m \n", Usuario->imc);
            printf("||     16,00 - 16,99     Magreza grau II     |\n");
            printf("||     17,00 - 18,49     Magreza grau I      |   ESTIMATIVA DAS NECESSIDADES CALÓRICAS COM BASE  \n");
            printf("||     18,50 - 24,99     Peso normal         |   NO NÍVEL DE ATIVIDADE FÍSICA:\033[32m %.2f \033[0m \n", Usuario->nec_cal);
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
            getchar();
            // Fecha o arquivo
            fclose(arquivo);
            return opc;
        }
    }
}




char tela_cardapio_peso()
{
    FILE *arquivo = fopen("usuarios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    FILE *arquivoC = fopen("cardapios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivoC == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    char opc;
    int slc;
    char buscar_cpf[14];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ==========================     CARDÁPIOS PARA OBJETIVOS DE PESO    ============================     ||\n");
    printf("||   1 [Ganhar peso]                                                                                       ||\n");
    printf("||   2 [Perder peso]                                                                                       ||\n");
    printf("||   3 [Manter peso]                                                                                       ||\n");
    printf("||   4 [Ganhar massa muscular]                                                                             ||\n");
    printf("||   5 [sair]                                                                                              ||\n");
    do
    {
        printf("\n");
        printf("     ESCOLHA A OPÇÃO DE LISTAGEM: ");
        while (scanf("%d", &slc) != 1)
        {
            while ((slc = getchar()) != '\n' && slc != EOF)
                ;
            printf("     Entrada inválida. Por favor, insira um número: ");
        }

        getchar();
        printf("||     CPF DO PACIENTE: ");
        fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
        buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;
        usuario UsuarioLocal;
        cardapio CardapioLocal;
      
        while (fread(&UsuarioLocal, sizeof(usuario), 1, arquivo))
        {

            if (strcmp(UsuarioLocal.cpf, buscar_cpf) == 0 && UsuarioLocal.estatos == 0)
            {
                
                printf("\n\033[32m       PACIENTE:\033[0m %s", UsuarioLocal.nome);
                printf("\n       CALORIAS NECESSÁRIAS: %.2f", UsuarioLocal.nec_cal);

                printf("\n");
                printf("\033[32m   +----------------------+--------------------------------+---------------------------+------------------+\n");
                printf("   |   CODIGO DO CARDÁPIO |              NOME              |    OBJETIVO DO CARDÁPIO   |      CALORIAS    |\n");
                printf("   +----------------------+--------------------------------+---------------------------+------------------+ \033[0m\n");
              
                while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivoC))
                {

                    if (slc == 1 && CardapioLocal.objetivo == 1 && CardapioLocal.cal_cardapio >= (UsuarioLocal.nec_cal + 200))
                    {
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                    else if (slc == 2 && CardapioLocal.objetivo == 2 && CardapioLocal.cal_cardapio <= (UsuarioLocal.nec_cal - 200))
                    {
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                    else if (slc == 3 && CardapioLocal.objetivo == 3 && UsuarioLocal.nec_cal <= CardapioLocal.cal_cardapio + 200 && UsuarioLocal.nec_cal >= CardapioLocal.cal_cardapio - 200)
                    {
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                    else if (slc == 4 && CardapioLocal.objetivo == 4 && CardapioLocal.cal_cardapio <= (UsuarioLocal.nec_cal - 200))
                    {
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                }
            }
        }
    } while (slc != 5 && slc != 4 && slc != 1 && slc != 2 && slc != 3);

    fclose(arquivo);
    fclose(arquivoC);
    printf("||                                                                                                         ||\n");
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return opc;
}


char tela_cardapio_nutricional()
{
    FILE *arquivo = fopen("usuarios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    FILE *arquivoC = fopen("cardapios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivoC == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    char opc;
    char buscar_cpf[14];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ========================   CARDÁPIOS PARA NECESSIDADES NUTRICIONAIS   =========================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     CPF DO PACIENTE: ");
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;
    usuario UsuarioLocal;
    cardapio CardapioLocal;
  
    while (fread(&UsuarioLocal, sizeof(usuario), 1, arquivo))
    {
        if (strcmp(UsuarioLocal.cpf, buscar_cpf) == 0 && UsuarioLocal.estatos == 0)
        {
            printf("\n\033[32m       PACIENTE:\033[0m %s", UsuarioLocal.nome);
            printf("\n       CALORIAS NECESSÁRIAS: %.2f", UsuarioLocal.nec_cal);

            printf("\n");
            printf("\033[32m   +----------------------+--------------------------------+---------------------------+------------------+\n");
            printf("   |   CODIGO DO CARDÁPIO |              NOME              |    OBJETIVO DO CARDÁPIO   |      CALORIAS    |\n");
            printf("   +----------------------+--------------------------------+---------------------------+------------------+ \033[0m\n");
          
            while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivoC))
            {
                if (UsuarioLocal.imc <= 18.49 && CardapioLocal.cal_cardapio >= (UsuarioLocal.nec_cal + 200))
                {
                  imprimir_cardapio_tab(CardapioLocal);
                }
                else if (UsuarioLocal.imc >= 18.5 && UsuarioLocal.imc < 25 && UsuarioLocal.nec_cal <= CardapioLocal.cal_cardapio + 200 && UsuarioLocal.nec_cal >= CardapioLocal.cal_cardapio - 200)
                {
                  imprimir_cardapio_tab(CardapioLocal);
                }
                else if (UsuarioLocal.imc > 29.99 && CardapioLocal.cal_cardapio <= (UsuarioLocal.nec_cal - 200))
                {
                  imprimir_cardapio_tab(CardapioLocal);
                }
            }
        }
    }
    fclose(arquivo);
    fclose(arquivoC);
    printf("||                                                                                                         ||\n");
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a opção:\n");
    scanf(" %c", &opc);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return opc;
}