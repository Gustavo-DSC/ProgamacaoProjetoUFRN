
struct usuario {
  char nome[100];
  char cpf[14];
  int idade;
  char sexo[100];
  char email[100];
  float peso;
  float altura;
  char ativ_fisica[100];
  int estatos;
  float imc;
  float nec_cal; 
};

typedef struct usuario usuario;

typedef struct Elemento {
  usuario dados;
  struct Elemento* proximo;
} Elemento;

char menu_inf_usuario();
void tela_buscar_paciente(usuario *Usuario);
char tela_novo_usuario(usuario *Usuario);
char tela_lista_pacientes();
char tela_atualizar_paciente (usuario *Usuario);
char tela_excluir_paciente (usuario *Usuario);
void modulo_usuario();
void imprimir_usuario(usuario u);
void imprimir_cab_tab();
void imprimir_usuario_tab(usuario u);
float imc_usuario(usuario u);
int cpf_existe_no_arquivo(char *cpf);
void remover_nova_linha(char *str);
Elemento* inserir_em_ordem(Elemento* inicio, usuario dados);
void listar_em_ordem_alfabetica();
