#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cardapios.h"
#include "planejamento_alimentar.h"
#include "usuario.h"
#include "utilidades.h"





void modulo_plan_alimentar(void) {
    char opc;
    do {
        opc = menu_plan_alimentar();
        switch(opc) {
            case '1': 	tela_imc_cal();
                        break;
            case '2': 	tela_cardapio_peso();
                        break;
            case '3': 	tela_cardapio_nutricional();
                        break;
            case '4':   visualizar_cardapio_paciente();
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
    printf("||                               4 [Visualizar Cardapio selecinado]                                        ||\n");
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
    opc = digite_opcao();
    return opc;
}


void tela_imc_cal()
{
    FILE *arquivo = fopen("usuarios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }

    usuario *UsuarioLocal;
    UsuarioLocal = (usuario *)malloc(sizeof(usuario));
 
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

    while (fread(UsuarioLocal, sizeof(usuario), 1, arquivo))
    {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(UsuarioLocal->cpf, buscar_cpf) == 0 && UsuarioLocal->estatos == 0)
        {
            UsuarioLocal->imc = UsuarioLocal->peso / (UsuarioLocal->altura * UsuarioLocal->altura);
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);

            if (strcmp(UsuarioLocal->sexo, "masculino") == 0)
            {
                UsuarioLocal->nec_cal = 10 * UsuarioLocal->peso + 6.25 * (UsuarioLocal->altura * 100) - 5 * UsuarioLocal->idade + 5;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(UsuarioLocal->sexo, "feminino") == 0)
            {
                UsuarioLocal->nec_cal = 10 * UsuarioLocal->peso + 6.25 * (UsuarioLocal->altura * 100) - 5 * UsuarioLocal->idade - 161;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            if (strcmp(UsuarioLocal->ativ_fisica, "1") == 0)
            {
                UsuarioLocal->nec_cal = UsuarioLocal->nec_cal * 1.2;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(UsuarioLocal->ativ_fisica, "2") == 0)
            {
                UsuarioLocal->nec_cal = UsuarioLocal->nec_cal * 1.375;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(UsuarioLocal->ativ_fisica, "3") == 0)
            {
                UsuarioLocal->nec_cal = UsuarioLocal->nec_cal * 1.55;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(UsuarioLocal->ativ_fisica, "4") == 0)
            {
                UsuarioLocal->nec_cal = UsuarioLocal->nec_cal * 1.725;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }
            else if (strcmp(UsuarioLocal->ativ_fisica, "5") == 0)
            {
                UsuarioLocal->nec_cal = UsuarioLocal->nec_cal * 1.9;
                fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                fwrite(UsuarioLocal, sizeof(usuario), 1, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
            }

            printf("||                                                                                                         \n");
            printf("||         tabela de valores de IMC          |   PACIENTE: \033[32m %s \033[0m \n", UsuarioLocal->nome);
            printf("||     IMC               CLASSIFICAÇÃO       |\n");
            printf("||     < 16,00           Magreza grau III    |   IMC: \033[32m %.2f \033[0m \n", UsuarioLocal->imc);
            printf("||     16,00 - 16,99     Magreza grau II     |\n");
            printf("||     17,00 - 18,49     Magreza grau I      |   ESTIMATIVA DAS NECESSIDADES CALÓRICAS COM BASE  \n");
            printf("||     18,50 - 24,99     Peso normal         |   NO NÍVEL DE ATIVIDADE FÍSICA:\033[32m %.2f \033[0m \n", UsuarioLocal->nec_cal);
            printf("||     25,00 - 29,99     Sobrepeso           |\n");
            printf("||     30,00 - 34,99     Obesidade grau I    |\n");
            printf("||     35,00 - 39,99     Obesidade grau II   |\n");
            printf("||     40,00 >           Obesidade grau III  |\n");

            }
          }
  fclose(arquivo);
  free(UsuarioLocal);
  UsuarioLocal = NULL; // aponta o ponteiro para NULL
  printf("||                                                                                                         ||\n");
  printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
  printf("||                                                                                                         ||\n");
  printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
  getchar();
}




void tela_cardapio_peso()
{
    FILE *arquivo = fopen("usuarios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }
    FILE *arquivoC = fopen("cardapios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivoC == NULL)
    {
        tela_erro();
        return;
    }
    usuario UsuarioLocal;
    cardapio CardapioLocal;
    char buscar_cod[11];
    char opc;
    int slc;
    char buscar_cpf[14];
    int found = 0;
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
                        found = 1;
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                    else if (slc == 2 && CardapioLocal.objetivo == 2 && CardapioLocal.cal_cardapio <= (UsuarioLocal.nec_cal - 200))
                    {
                        found = 1;
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                    else if (slc == 3 && CardapioLocal.objetivo == 3 && UsuarioLocal.nec_cal <= CardapioLocal.cal_cardapio + 200 && UsuarioLocal.nec_cal >= CardapioLocal.cal_cardapio - 200)
                    {
                        found = 1;
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                    else if (slc == 4 && CardapioLocal.objetivo == 4 && CardapioLocal.cal_cardapio <= (UsuarioLocal.nec_cal - 200))
                    {
                        found = 1;
                        imprimir_cardapio_tab(CardapioLocal);
                    }
                }
                if(found == 1)
                {
                  printf("       Deseja selecionar um cardapio para o paciente? (s/n): ");
                  scanf(" %c", &opc); getchar();
                  if (opc == 's' || opc == 'S') 
                  {
                    do 
                    {
                      printf("   DIGITE O CODIGO DO CARDÁPIO: ");
                      fgets(buscar_cod, sizeof(buscar_cod), stdin); getchar();
                      fseek(arquivoC, 0, SEEK_SET);  // Adicionado para reiniciar a posição do arquivo
                      int encontrado = 0;
                      while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivoC))
                      {
                        if (strcmp(CardapioLocal.cod_cardapio, buscar_cod) == 0)
                        {
                          strcpy(UsuarioLocal.pac_card_cod, CardapioLocal.cod_cardapio);
                          printf("\033[32m   Cardapio selecionado! \033[0m\n");
                          encontrado = 1;
                          // Move o ponteiro do arquivo para a posição do usuário atual
                          fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                          // Escreve a estrutura do usuário de volta no arquivo
                          fwrite(&UsuarioLocal, sizeof(usuario), 1, arquivo);
                          break;
                        }
                      }
                      if (encontrado) break;
                      printf("   Cardápio não encontrado. Deseja continuar? (s/n): ");
                      scanf(" %c", &opc); getchar();
                      if (opc == 'n' || opc == 'N') 
                      {
                        printf("   Seleção cancelada.\n");
                        break;
                      }
                    } while (strcmp(CardapioLocal.cod_cardapio, buscar_cod) != 0);
                  }
                }
                else if(found == 0)
                {
                  printf("\033[31m||=========================================================================================================||\n");    
                  printf("||                                      NENHUM CARDÁPIO ENCONTRADO!                                        ||\n");
                  printf("||  Não foi localizado um cardápio que satisfaça as necessidades nutricionais específicas deste paciente.  ||\n");
                  printf("||                    Por favor, considere a possibilidade de criar um personalizado.                      ||\n");
                  printf("||=========================================================================================================||\033[0m\n"); 
                }
            }
        }
    } while (slc != 5 && slc != 4 && slc != 1 && slc != 2 && slc != 3);

    fclose(arquivo);
    fclose(arquivoC);
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}


void tela_cardapio_nutricional()
{
    FILE *arquivo = fopen("usuarios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }
    FILE *arquivoC = fopen("cardapios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivoC == NULL)
    {
        tela_erro();
        return;
    }

    char opc;
    char buscar_cpf[14];
    char buscar_cod[11];
    int found = 0; 
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
                if (UsuarioLocal.imc <= 18.49 && CardapioLocal.cal_cardapio >= (UsuarioLocal.nec_cal + 200) && CardapioLocal.objetivo == 1)
                {
                  found = 1;
                  imprimir_cardapio_tab(CardapioLocal);
                }
                else if (UsuarioLocal.imc >= 18.5 && UsuarioLocal.imc < 25 && UsuarioLocal.nec_cal <= CardapioLocal.cal_cardapio + 200 && UsuarioLocal.nec_cal >= CardapioLocal.cal_cardapio - 200 && CardapioLocal.objetivo == 3)
                {
                  found = 1;
                  imprimir_cardapio_tab(CardapioLocal);
                }
                else if (UsuarioLocal.imc > 29.99 && CardapioLocal.cal_cardapio <= (UsuarioLocal.nec_cal - 200 && CardapioLocal.objetivo == 2))
                {
                  found = 1;
                  imprimir_cardapio_tab(CardapioLocal);
                }
            }
            if (found == 1)
            {
              printf("\033[33m||=========================================================================================================||\n");
              printf("--------\033[0m Deseja selecionar um cardapio para o paciente? (s/n): ");
              scanf(" %c", &opc); getchar();
              if (opc == 's' || opc == 'S') 
              {
                do 
                {
                  printf("-------- DIGITE O CODIGO DO CARDÁPIO: ");
                  fgets(buscar_cod, sizeof(buscar_cod), stdin); getchar();
                  fseek(arquivoC, 0, SEEK_SET);  // Adicionado para reiniciar a posição do arquivo
                  int encontrado = 0;
                  while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivoC))
                  {
                    if (strcmp(CardapioLocal.cod_cardapio, buscar_cod) == 0)
                    {
                      strcpy(UsuarioLocal.pac_card_cod, CardapioLocal.cod_cardapio);
                      printf("\033[32m||======================================== Cardapio selecionado! ==========================================||\033[0m\n");
                      encontrado = 1;
                      // Move o ponteiro do arquivo para a posição do usuário atual
                      fseek(arquivo, -sizeof(usuario), SEEK_CUR);
                      // Escreve a estrutura do usuário de volta no arquivo
                      fwrite(&UsuarioLocal, sizeof(usuario), 1, arquivo);
                      break;
                    }
                  }
                  if (encontrado) break;
                  printf("\033[33m||=========================================================================================================||\033[0m\n");
                  printf("-------- Cardápio não encontrado. Deseja continuar? (s/n): ");
                  scanf(" %c", &opc); getchar();
                  if (opc == 'n' || opc == 'N') 
                  {
                    printf("\033[31m||========================================== Seleção cancelada ============================================||\033[0m\n");
                    break;
                  }
                } while (strcmp(CardapioLocal.cod_cardapio, buscar_cod) != 0);
              }
            }
            else if (found == 0)
            {
              printf("\033[31m||=========================================================================================================||\n");    
              printf("||                                      NENHUM CARDÁPIO ENCONTRADO!                                        ||\n");
              printf("||  Não foi localizado um cardápio que satisfaça as necessidades nutricionais específicas deste paciente.  ||\n");
              printf("||                    Por favor, considere a possibilidade de criar um personalizado.                      ||\n");
              printf("||=========================================================================================================||\033[0m\n"); 
            }  
        }
    }
    fclose(arquivo);
    fclose(arquivoC);
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}



void visualizar_cardapio_paciente()
{
    FILE *arquivo = fopen("usuarios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }
    FILE *arquivoC = fopen("cardapios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivoC == NULL)
    {
        tela_erro();
        return;
    }

    char opc;
    char buscar_cpf[14];
    char buscar_cod[11];
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ==============================  VISUALIZAR CARDÁPIO DO PACIENTE   =============================     ||\n");
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
            printf("\n");
            while (fread(&CardapioLocal, sizeof(cardapio), 1, arquivoC))
            {
                if (strcmp(CardapioLocal.cod_cardapio, UsuarioLocal.pac_card_cod) == 0)
                {
                  printf("\n");
                  printf("\033[32m   +----------------------+--------------------------------+---------------------------+------------------+\n");
                  printf("   |   CODIGO DO CARDÁPIO |              NOME              |    OBJETIVO DO CARDÁPIO   |      CALORIAS    |\n");
                  printf("   +----------------------+--------------------------------+---------------------------+------------------+ \033[0m\n");
                  printf("   | \033[31m%-20s\033[0m | %-30s | %-25s | %-16.2f |\n", CardapioLocal.cod_cardapio, CardapioLocal.nome, 
                    CardapioLocal.objetivo == 1 ? "Ganhar peso" : 
                    CardapioLocal.objetivo == 2 ? "Perder peso" : 
                    CardapioLocal.objetivo == 3 ? "Manter peso" : 
                    CardapioLocal.objetivo == 4 ? "Ganhar massa muscular" : 
                    "Objetivo inválido", 
                    CardapioLocal.cal_cardapio);
                  printf("   +----------------------+--------------------------------+---------------------------+------------------+\n");
                  printf("\n    DIETA DO CARDÁPIO: \n");
                  printf("   ========================================================================================================\n");
                  char *dieta = CardapioLocal.dieta_cardapio;
                  char *linha = strtok(dieta, "\n");

                  while (linha != NULL) {
                      printf("    %s%s\n", "", linha); 
                      linha = strtok(NULL, "\n");
                  }
                  printf("   ========================================================================================================\n");
                }

            }

        }
    }
    fclose(arquivo);
    fclose(arquivoC);
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}