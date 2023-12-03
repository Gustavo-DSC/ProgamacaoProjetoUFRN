#ifndef USUARIOS_H
#define USUARIOS_H

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


char menu_inf_usuario();
void tela_buscar_paciente(usuario *Usuario);
char tela_novo_usuario(usuario *Usuario);
char tela_lista_pacientes();
char tela_atualizar_paciente (usuario *Usuario);
char tela_excluir_paciente (usuario *Usuario);
void modulo_usuario();
void imprimir_usuario(usuario u);
float imc_usuario(usuario u);
int cpf_existe_no_arquivo(char *cpf);
#endif
