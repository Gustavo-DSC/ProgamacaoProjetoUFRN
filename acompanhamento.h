

typedef struct avaliacao avaliacao;
struct avaliacao{
    char data[15];
    char cpf_avaliado[14];
    float novo_peso, nova_altura;
    int situacao;
    char nova_ativ_fisc[5];
};

char menu_acompanhamento();
char tela_avaliacao_paciente ();
char tela_progreso_paciente();
char tela_lista_avaliacao_paciente();
void modulo_acompanhamento();
char* obterData();
void compracao_peso(float, float);
void lista_aval_tab();
