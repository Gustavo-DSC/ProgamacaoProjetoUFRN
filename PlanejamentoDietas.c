//+-------------------------------------------------------+//
//| Universidade Federal do Rio Grande do Norte           |//
//| CERES - Caicó                                         |//
//| Per�odo da faculdade: 2023.2                          |//
//| Disciplina: DCT1206 - Programa��o                     |//
//| Professor: Flavius Gorgonio                           |//
//| Discente: Gustavo Douglas Silva Cruz                  |//
//| Projeto: Sistema de Planejamento de Dietas vers�o 0.3 |//
//+-------------------------------------------------------+//


#include <stdio.h>
#include <stdlib.h>

char menu_inicial();
char menu_inf_usuario();
char tela_dados_pessoais();
char tela_restricao_alimentar ();
char menu_avaliacao_nutri();
char tela_imc ();
char tela_ingestao_alimentar ();
char menu_plan_alimentar();
char tela_cria_cardapio();
char tela_suges_substituicao();
char menu_acompanhamento();
char tela_registro_medidas ();
char tela_adesao_plan_alimentar ();
char menu_sobre();

int main(void){
    menu_inicial();
    menu_inf_usuario();
    tela_dados_pessoais();
    tela_restricao_alimentar();
    menu_avaliacao_nutri();
    tela_imc();
    tela_ingestao_alimentar ();
    menu_plan_alimentar();
    tela_cria_cardapio();
    tela_suges_substituicao();
    menu_acompanhamento();
    tela_registro_medidas();
    tela_adesao_plan_alimentar();
    menu_sobre();
    return 0;
}

char menu_inicial (){
    char opc;
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
    printf("||                               5 [Sobre]                                                                 ||\n");
    printf("||                               0 [Sair]                                                                  ||\n");
    printf("||                                                                                                         ||\n");  
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
}


char menu_inf_usuario (){
    char opc;
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
    printf("||                               2 [Restri��es Alimentares]                                                ||\n");    
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
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_dados_pessoais (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =====================================    DADOS PESSOAIS    ====================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                   NOME:                                                                                 ||\n");
    printf("||                   IDADE:                                                                                ||\n");
    printf("||                   SEXO:                                                                                 ||\n");    
    printf("||                   E-MAIL                                                                                ||\n");
    printf("||                   PESO:                                                                                 ||\n");
    printf("||                   ALTURA                                                                                ||\n");
    printf("||                   FREQU�NCIA DE ATIVIDADE F�SICA - NUNCA | RARAMENTE | FREQUENTEMENTE | TODO DIA        ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                   0 [Voltar]                                                                            ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_restricao_alimentar (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =================================    RESTRI��ES ALIMENTARES    ================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                 OP��ES R�PIDAS                                                                          ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                  1 - Intoler�ncia � lactose                                                             ||\n");
    printf("||                  2 - Alergia ao gl�ten                                                                  ||\n");
    printf("||                  3 - Alergia a crust�ceos                                                               ||\n");
    printf("||                  4 - Diabetes                                                                           ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                  INFORME SUAS RESTRI��ES ALIMENTARES                                                    ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                 0 [Voltar]                                                                              ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||\n");
    scanf(" %c", &opc);
    return opc;
}

char menu_avaliacao_nutri (){
    char opc;
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
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
}
char tela_imc (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ========================================   IMC US�ARIO  =======================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||         tabela de valores de IMC          | INFORMA��ES                                                 ||\n");
    printf("||     IMC               CLASSIFICA��O       | O IMC (�ndice de Massa Corporal). � uma t�cnica utilizada   ||\n");
    printf("||     < 16,00           Magreza grau III    | para verificar o estado nutricional e observar se a pessoa  ||\n");
    printf("||     16,00 - 16,99     Magreza grau II     | est� dentro dos padr�es de normalidade com rela��o ao seu   ||\n");
    printf("||     17,00 - 18,49     Magreza grau I      | peso e estatura                                             ||\n");
    printf("||     18,50 - 24,99     Peso normal         |                                                             ||\n");
    printf("||     25,00 - 29,99     Sobrepeso           | SEU IMC :                                                   ||\n");    
    printf("||     30,00 - 34,99     Obesidade grau I    |                                                             ||\n");
    printf("||     35,00 - 39,99     Obesidade grau II   |                                                             ||\n");
    printf("||     ? 40,00           Obesidade grau III  |                                                             ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||     0 -[voltar]                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
}
char tela_ingestao_alimentar (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =============================   AVALIA��O DA INGEST�O ALIMENTAR   =============================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      INFORME SE DEIXOU DE FAZER UMA REFEI��O DA DIETA                                                   ||\n");
    printf("||          1 - caf� da manh�                                                                              ||\n");
    printf("||          2 - almo�o                                                                                     ||\n");
    printf("||          3 - jantar                                                                                     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||      INFORME COMO VOC� EST� SE SENTINDO COM A ALIMENTA��O                                               ||\n");
    printf("||          1 - bem                                                                                        |\n");    
    printf("||          2 - normal                                                                                     ||\n");
    printf("||          3 - ruim                                                                                       ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||      INFOEME SE ALGUM ALIMENTO EST� FAZENDO MAL                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||          0 [Voltar]                                                                                     ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
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
    printf("||                                                                                                         ||\n");
    printf("||                               1 [Cria��o de Card�pios]                                                  ||\n");
    printf("||                               2 [Sugest�es de substitui��es]                                            ||\n");
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
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_cria_cardapio(){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ================================     CRIA��O DE CARD�PIOS    ==================================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Este card�pio foi crido, utilizando informa��es sobre sua altura, peso, idade e n�vel de atividade  ||\n");
    printf("||     f�sica para calcular suas necessidades cal�ricas di�rias e criar um card�pio personalizado que      ||\n");
    printf("||     atenda �s suas necessidades nutricionais.                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Caf� da manh�:                                                                                      ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Almo�o:                                                                                             ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Jantar :                                                                                            ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
    
}

char tela_suges_substituicao(){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===============================   SUSGEST�ES DE SUBSTITUI��ES   ===============================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     A substitui��o de alimentos com valor nutricional igual permite variar as refei��es, mantendo       ||\n");
    printf("||     o equil�brio nutricional. Isso � feito substituindo um alimento por outro de valor nutricional      ||\n");
    printf("||     semelhante. Essa estrat�gia � �til para evitar a monotonia alimentar e permitir que o paciente      ||\n");
    printf("||     tenha mais autonomia na hora de fazer suas escolhas alimentares.                                    ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Caf� da manh�:                                                                                      ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Almo�o:                                                                                             ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Jantar :                                                                                            ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
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
    printf("||                               1 [Registro de Peso e Medidas Corporais]                                  ||\n");
    printf("||                               2 [Avalia��o da Ades�o ao Plano Alimentar]                                ||\n");
    printf("||                               3 [Ajuste do Plano Alimentar]                                             ||\n");
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
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_registro_medidas (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     =========================    REGISTRO DE PESO E MEDIDAS CORPORAIS    ==========================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     O registro de peso e medidas corporais � uma ferramenta �til para acompanhar o progresso de um      ||\n");
    printf("||     plano de dieta. Ele permite que voc� monitore as mudan�as em seu peso, altura, �ndice de massa      ||\n");
    printf("||     corporal e outras medidas importantes ao longo do tempo. Isso pode ajud�-lo a avaliar a efic�cia    ||\n");
    printf("||     de sua dieta e fazer ajustes conforme necess�rio.                                                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     INFORME SUAS NOVAS MEDIDAS                                                                          ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||     PESO:                                                                                               ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ALTURA:                                                                                             ||\n");  
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
}

char tela_adesao_plan_alimentar (){
    char opc;
    system("clear||cls");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     ===========================  AVALIA��O DA ADES�O AO PLANO ALIMENTAR  ==========================     ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Com que frequ�ncia voc� segue o plano alimentar recomendado?                                        ||\n");
    printf("||     1- Sempre                                                                                           ||\n");
    printf("||     2- �s vezes                                                                                         ||\n");
    printf("||     3- Nunca                                                                                            ||\n");
    printf("||     Voc� costuma pular refei��es ou substitu�-las por lanches n�o saud�veis?                            ||\n");
    printf("||     1- Sim                                                                                              ||\n");
    printf("||     2- �s vezes                                                                                         ||\n");    
    printf("||     3- N�o                                                                                              ||\n");
    printf("||     Voc� costuma comer alimentos n�o recomendados pelo plano alimentar?                                 ||\n");
    printf("||     1- Sim                                                                                              ||\n");  
    printf("||     2- �s vezes                                                                                         ||\n");
    printf("||     3- N�o                                                                                              ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||    0 [Voltar]                                                                                           ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    printf("||Selecione a op��o:\n");
    scanf(" %c", &opc);
    return opc;
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
    printf("||     Silva Cruz como parte da disciplina DCT1206 - Programa��o, ministrada pelo Professor Flavius        ||\n");
    printf("||     Gorgonio na Universidade Federal do Rio Grande do Norte, CERES - Caic�, no per�odo 2023.2.          ||\n");
    printf("||                                                                                                         ||\n");
    printf("||     Este programa foi criado com o objetivo de auxiliar no planejamento de dietas e � destinado         ||\n");
    printf("||     apenas para fins de aprendizagem, n�o sendo comercializado. O autor n�o se responsabiliza por       ||\n"); 
    printf("||     quaisquer problemas que possam ocorrer durante o uso do programa.                                   ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");    
    printf("||                                                                                                         ||\n");
    printf("||                                                                                                         ||\n");
    printf("MWMWMWMWMWMWMMWMWMWMWMMWMWMWMWMMWMWMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMMWMWMWMWMWMWMMWMWMWMMWMWMWMWMWMWMWMWMMWM\n");
    scanf(" %c", &opc);
    return opc;
}
