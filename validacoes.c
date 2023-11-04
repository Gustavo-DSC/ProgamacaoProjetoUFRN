#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "validacoes.h"

int valida_nome(char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i]) && !isspace(str[i])) {
            return 0;
        }
    }
    return 1;
}


int valida_idade(int idade) {
    int idade_min = 8;  
    int idade_max = 120;  

    if (idade >= idade_min && idade <= idade_max){
      return 1;
    }
  return 0;
}


int valida_sexo(char *str) {
    char *espaco = strchr(str, '\n');  // procura por '\n' na string
      if (espaco){                        // se '\n' foi encontrado
        *espaco = 0;                     // substitui '\n' por '\0'
      }
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }

    if (strcmp(str, "masculino") == 0 || strcmp(str, "feminino") == 0){
      return 1;
    }
  return 0;
}



int valida_email(char *email) {
    char *arroba = strchr(email, '@');
    char *ponto = strrchr(email, '.');
    char *espaco = strchr(email, '\n');  
    if (espaco){                        
      *espaco = 0;                     
    }
    if (arroba != NULL && ponto != NULL && arroba < ponto) {
        // Verifica se há apenas um '@' no email 
        if (strchr(arroba + 1, '@') == NULL) {
            // Verifica se tem pelo menos um caractere antes do '@'
            if (arroba != email) {
                // Verifica se tem pelo menos um caractere entre '@' e '.'
                if (arroba + 1 < ponto) {
                    // Verifica se tem pelo menos dois caracteres após o '.'
                    if (strlen(ponto) > 2) {
                        // Verifica se o email contém caracteres especiais
                        for (char *c = email; *c; c++) {
                            if ((*c < 'a' || *c > 'z') && (*c < 'A' || *c > 'Z') && (*c < '0' || *c > '9') && *c != '@' && *c != '.' && *c != '-' && *c != '_') {
                                return 0;
                            }
                        }
                        // Verifica o comprimento da parte local e do domínio
                        if ((arroba - email <= 64) && (strlen(arroba) - strlen(ponto) <= 255)) {
                            return 1;
                            printf("legal\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}



int valida_peso(float peso) {
    float peso_min = 20.0;  
    float peso_max = 650.0;  

    if (peso >= peso_min && peso <= peso_max){
        return 1;
    }
    return 0;
}


int valida_altura(float altura) {
    float altura_min = 0.40; 
    float altura_max = 2.5; 

    if (altura >= altura_min && altura <= altura_max){
        return 1;
    }
    return 0;
}


int valida_atividade_fisica(char *str) {
    // Remove o caractere de nova linha do final da string
      str[strcspn(str, "\n")] = 0;

    // Converte a string para minúsculas para facilitar a comparação
    for(int i = 0; str[i]; i++){
          str[i] = tolower(str[i]);
    }

    // Compara a string com os níveis de atividade física permitidos
    if (strcmp(str, "sedentário") == 0 ||
        strcmp(str, "leve") == 0 ||
        strcmp(str, "moderado") == 0 ||
        strcmp(str, "intenso") == 0 ||
        strcmp(str, "muito intenso") == 0) {
        return 1;
    } else {
        return 0;
    }
}