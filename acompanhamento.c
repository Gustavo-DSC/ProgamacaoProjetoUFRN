#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "acompanhamento.h"
#include "usuario.h"
#include "validacoes.h"
#include "utilidades.h"


void modulo_acompanhamento(void) {
    char opc;
    do {
        opc = menu_acompanhamento();
        switch(opc) {
            case '1': 	tela_avaliacao_paciente();
                        break;
            case '2': 	tela_lista_avaliacao_paciente();
                        break;
            case '3':   tela_progreso_paciente();
                        break;
         } 		
    } while (opc != '0');
}



char menu_acompanhamento (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===================================    ACOMPANHAMENTO    ======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Adicionar avaliação de paciente]                                       ||\n");
    printf("||                               2 [Listar avaliações de paciente]                                         ||\n");
    printf("||                               3 [Avaliar progreso de paciente]                                          ||\n");
    printf("||                               0 [Voltar]                                                                ||\n");    
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



void tela_avaliacao_paciente(){
    
    FILE *arquivo = fopen("usuarios.data", "rb+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        tela_erro();
        return;
    }
    FILE *arquivo_acompanhamento  = fopen("avaliacao.data", "ab+");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL) {
        tela_erro();
        return;
    }

  
    char opc;
    char buscar_cpf[14];
  
    usuario UsuarioLocal;
    avaliacao AvaliacaoLocal;
  
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===========================   ADICIONAR UMA AVALIAÇÃO DE PACIENTE   ===========================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||          PESQUISAR POR CPF: "); 
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;

    // Lê os usuários do arquivo um por um
    while (fread(&UsuarioLocal, sizeof(usuario), 1, arquivo)) {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(UsuarioLocal.cpf, buscar_cpf) == 0 && UsuarioLocal.estatos == 0) {
            strcpy(AvaliacaoLocal.data, obterData()); // obter a data atual
            strcpy(AvaliacaoLocal.cpf_avaliado, UsuarioLocal.cpf);
          
            printf("||          DATA DA AVALIAÇÃO: %s\n", AvaliacaoLocal.data); 
            printf("||          NOME DO AVALIADO: %s\n", UsuarioLocal.nome);
            printf("||          SITUAÇÃO DO PACIENTE: \n");
            printf("||          1 [Péssimo]\n");
            printf("||          2 [Ruim]\n");
            printf("||          3 [Regular]\n");
            printf("||          4 [Bom]\n");
            printf("||          5 [Ótimo]\n");
            printf("||          6 [Excelente]");
            scanf("%d", &AvaliacaoLocal.situacao);
            getchar();
            printf("\n");
  
            printf("            ATUALIZAÇÂO DO PESO, ALTURA E ATIVIDADE FISICA\n");
            do {
              printf("            PESO: ");   /// Peso do usuário
              scanf("%f", &AvaliacaoLocal.novo_peso); getchar();
              if (valida_peso(AvaliacaoLocal.novo_peso) != 0){
                printf("\033[32m            PESO VALIDO \033[0m\n");
              }
              else {
                printf("\033[31m            PESO INVALIDO! \033[0m\n");
              }
            } while (valida_peso(AvaliacaoLocal.novo_peso) == 0);

            do {
              printf("            ALTURA: "); /// Altura do usuário
              scanf("%f", &AvaliacaoLocal.nova_altura); getchar();
              if (valida_altura(AvaliacaoLocal.nova_altura) != 0){
                printf("\033[32m            ALTURA VALIDO \033[0m\n");
              }
              else {
                printf("\033[31m            ALTURA INVALIDO! \033[0m\n");
              }
            } while (valida_altura(AvaliacaoLocal.nova_altura) == 0);

          
            do {
              printf("            FREQUÊNCIA DE ATIVIDADE FÍSICA\n");  // nivel de atividade física
              printf("            (1)sedentário (2)leve (3)moderado (4)intenso (5)muito intenso  \n");
              printf("            ---");
              fgets(AvaliacaoLocal.nova_ativ_fisc, sizeof(AvaliacaoLocal.nova_ativ_fisc), stdin);
              if (valida_atividade_fisica(AvaliacaoLocal.nova_ativ_fisc) != 0){
                printf("\033[32m            ATIVIDADE FÍSICA VALIDA \033[0m\n");
              }
              else {
                printf("\033[31m            ATIVIDADE FÍSICA INVALIDA! \033[0m\n");
              }
            } while (valida_atividade_fisica(AvaliacaoLocal.nova_ativ_fisc) == 0);
        
            printf("\n");
            printf("            COMPRAÇÂO DE PESO:\n");
            compracao_peso(AvaliacaoLocal.novo_peso, UsuarioLocal.peso);
            
            UsuarioLocal.peso = AvaliacaoLocal.novo_peso;
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(&UsuarioLocal, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          
            UsuarioLocal.altura = AvaliacaoLocal.nova_altura;
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(&UsuarioLocal, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);
          
            strcpy(UsuarioLocal.ativ_fisica, AvaliacaoLocal.nova_ativ_fisc);
            fseek(arquivo, -sizeof(usuario), SEEK_CUR);
            fwrite(&UsuarioLocal, sizeof(usuario), 1, arquivo);
            fseek(arquivo, 0, SEEK_CUR);

            fwrite(&AvaliacaoLocal, sizeof(avaliacao), 1, arquivo_acompanhamento);
      
            printf("\033[32m            ATUALIZAÇÃO REALIZADA COM SUCESSO! \033[0m\n");
        }
    }
    fclose(arquivo);  
    fclose(arquivo_acompanhamento);
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}

void tela_lista_avaliacao_paciente(){
  FILE *arquivo = fopen("usuarios.data", "rb");
  // Verifica se o arquivo está aberto
  if (arquivo == NULL) {
      tela_erro();
      return;
  }
  FILE *arquivo_acompanhamento  = fopen("avaliacao.data", "rb");
  // Verifica se o arquivo está aberto
  if (arquivo == NULL) {
      tela_erro();
      return;
  }


  char opc;
  char buscar_cpf[14];

  usuario UsuarioLocal;
  avaliacao AvaliacaoLocal;
  
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===============================   LISTAR AVALIAÇÕES DE PACIENTE   =============================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||          PESQUISAR POR CPF: "); 
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;
    
    while (fread(&UsuarioLocal, sizeof(usuario), 1, arquivo)) {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(UsuarioLocal.cpf, buscar_cpf) == 0 && UsuarioLocal.estatos == 0) {
            // Fecha o arquivo de usuários
            fclose(arquivo);
          
            printf("\n");
            printf("\033[32m   +----------------------+--------------------------------+----------+----------+------------------------+\n");
            printf("   |         DATA         |              NOME              |   PESO   |  ALTURA  |        SITUAÇÃO        |\n");
            printf("   +----------------------+--------------------------------+----------+----------+------------------------+ \033[0m\n");
            // Lê as avaliações do arquivo um por um
            while (fread(&AvaliacaoLocal, sizeof(avaliacao), 1, arquivo_acompanhamento)) {
                // Compara o CPF do usuário avaliado com o CPF buscado
                
                if (strcmp(AvaliacaoLocal.cpf_avaliado, buscar_cpf) == 0) {
                    // Lista a avaliação
                    lista_aval_tab(AvaliacaoLocal, UsuarioLocal);
                }
            }
            // Sai do loop
            break;
        }
    }
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}


void tela_progreso_paciente()
{
    FILE *arquivo = fopen("usuarios.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }
    FILE *arquivo_acompanhamento = fopen("avaliacao.data", "rb");
    // Verifica se o arquivo está aberto
    if (arquivo == NULL)
    {
        tela_erro();
        return;
    }
    // Aloca memória para o array de pesos
    double *pesos = (double *)malloc(10 * sizeof(double));
    if (pesos == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return;
    }

    int count = 0;

    char opc;
    char buscar_cpf[14];

    usuario UsuarioLocal;
    avaliacao AvaliacaoLocal;

    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ==================================   PROGRESO DE PACIENTE   ===================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||          PESQUISAR POR CPF: ");
    fgets(buscar_cpf, sizeof(buscar_cpf), stdin);
    buscar_cpf[strcspn(buscar_cpf, "\n")] = 0;

    while (fread(&UsuarioLocal, sizeof(usuario), 1, arquivo))
    {
        // Compara o CPF do usuário com o CPF buscado
        if (strcmp(UsuarioLocal.cpf, buscar_cpf) == 0 && UsuarioLocal.estatos == 0)
        {
            // Fecha o arquivo de usuários
            fclose(arquivo);

            printf("\n");
            printf("\033[32m   +----------------------+--------------------------------+----------+----------+------------------------+\n");
            printf("   |         DATA         |              NOME              |   PESO   |  ALTURA  |        SITUAÇÃO        |\n");
            printf("   +----------------------+--------------------------------+----------+----------+------------------------+ \033[0m\n");
            // Lê as avaliações do arquivo um por um
            while (fread(&AvaliacaoLocal, sizeof(avaliacao), 1, arquivo_acompanhamento))
            {
                // Compara o CPF do usuário avaliado com o CPF buscado

                if (strcmp(AvaliacaoLocal.cpf_avaliado, buscar_cpf) == 0)
                {
                    // Lista a avaliação
                    lista_aval_tab(AvaliacaoLocal, UsuarioLocal);
                    pesos[count % 10] = AvaliacaoLocal.novo_peso;
                    count++;
                }
            }
            // Imprime os pesos das últimas 10 avaliações
            printf("\n");
            printf("   +------------------------------------------------------------------------------------------------------+\n");
            printf("   +-------------------------------| GRÁFICO  Últimas 10 avaliações (peso) |------------------------------+\n");
            printf("   |\n");
            for (int i = count > 10 ? count % 10 : 0; i < count && i < 10; i++)
            {
                printf("   |  DATA: %s   ", AvaliacaoLocal.data);
                for (int j = 0; j < (int)pesos[i] / 5; j++)
                {
                    printf("\033[32m|\033[0m");
                }
                printf("   %.2f\n", pesos[i]);
            }
            printf("   +------------------------------------------------------------------------------------------------------+\n");
            // Libera a memória alocada para o array de pesos
            free(pesos);
            fclose(arquivo_acompanhamento);
            // Sai do loop
            break;
        }
    }
    printf("||                                                                                                         ||\n");
    printf("||       <<< APERTE ENTER VOLTAR >>                                                                        ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    getchar();
}



char* obterData() {
    time_t agora = time(NULL);
    struct tm *data = localtime(&agora);
    static char dataStr[20];
    strftime(dataStr, sizeof(dataStr), "%d/%m/%Y", data);
    return dataStr;
}


void compracao_peso(float peso_novo, float peso_antigo) {
  peso_novo = peso_novo/5;
  peso_antigo = peso_antigo/5;

  // imprimir peso antigo em barra 
  printf("            PESO ANTIGO:  ");
  for(int i = 0; i < (int)peso_antigo; i++) {
      printf("\033[31m|\033[0m");
  }
  printf("%.2f\n", peso_antigo*5);
  /// imprimir peso novo em barra 
  printf("            PESO NOVO:    ");
  for(int i = 0; i < (int)peso_novo; i++) {
      printf("\033[32m|\033[0m");
  }
  printf("%.2f\n", peso_novo*5);
}

void lista_aval_tab(avaliacao a, usuario u){

  printf("   | \033[31m%-20s\033[0m | %-30s | %-8.2f | %-8.2f |  %-21s |\n", a.data, u.nome, a.novo_peso, a.nova_altura, 
    a.situacao == 1 ? "Péssimo" :
    a.situacao == 2 ? "Ruim" :
    a.situacao == 3 ? "Regular" :
    a.situacao == 4 ? "Bom" :
    a.situacao == 5 ? "Ótimo" :
    a.situacao == 6 ? "Excelente" : "nada informado"
    );
  printf("   +----------------------+--------------------------------+----------+----------+------------------------+\n");
}