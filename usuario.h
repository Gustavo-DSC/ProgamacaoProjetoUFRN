#ifndef USUARIOS_H
#define USUARIOS_H

struct usuario {
  char nome[100];
  int idade;
  char sexo[100];
  char email[100];
  float peso;
  float altura;
  char ativ_fisica[100];
  int estatos;
};

typedef struct usuario usuario;

struct lista_usuarios {
  usuario usuarios[100];
  int qtd_usuarios;
};

typedef struct lista_usuarios lista_usuarios;

char menu_inf_usuario();
char tela_dados_pessoais(lista_usuarios *Lista, usuario *Usuario);
char tela_restricao_alimentar ();
char tela_novo_usuario(lista_usuarios *Lista, usuario *Usuario);
char tela_mudar_usuario(lista_usuarios *Lista);
char tela_atualizar_usuario (lista_usuarios *Lista, usuario *Usuario);
char tela_excluir_usuario (lista_usuarios *Lista);
void modulo_usuario();
void salvar_usuarios(lista_usuarios *Lista);
void carregar_usuarios(lista_usuarios *Lista);

#endif

