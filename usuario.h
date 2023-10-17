// assinatura das funções 

char menu_inf_usuario();
char tela_dados_pessoais();
char tela_restricao_alimentar ();
char tela_novo_usuario();
char tela_mudar_usuario();
char tela_atualizar_usuario ();
char tela_excluir_usuario ();
void modulo_usuario();

struct usuario {
  char nome[100];
  int idade;
  char sexo[100];
  char email[100];
  float peso;
  float altura;
  char ativ_fisica[100];
};
