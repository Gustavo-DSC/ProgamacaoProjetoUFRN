#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "utilidades.h"

// Validador de email 
// Criar na função principal char email[100]
int verificar_email(char *email) {
    char *arroba = strchr(email, '@');
    char *ponto = strrchr(email, '.');
    scanf("%s", email);
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
                        }
                    }
                }
            }
        }
    }
    return 0;
}