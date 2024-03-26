#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int escolha;
    char resposta = 'S';
    char nomearquivo[50];
    char criararquivo;

    while (resposta == 'S') {
        printf("Digite 1 - Abrir a Calculadora\n"
               "Digite 2 - Abrir o bloco de Notas\n"
               "Digite 3 - Para abrir um Arquivo no formato .txt\n"
               "Resposta: ");
        scanf("%d", &escolha);

        // abrir calculadora
        if (escolha == 1) {
            system("calc");
        }
        // abrir bloco de notas
        else if (escolha == 2) {
            system("notepad");
        }
        // abrir arquivo .txt
        else if (escolha == 3) {
            printf("Digite o nome do arquivo .txt a ser aberto (Digite .txt no final do nome do arquivo): ");
            scanf("%s", nomearquivo);

            FILE *arquivo = fopen(nomearquivo, "r");
            if (arquivo == NULL) {
                printf("Esse arquivo não existe. Deseja criar esse arquivo? (S/N):\n");
                scanf(" %c", &criararquivo);

                if (criararquivo == 'S') {
                    arquivo = fopen(nomearquivo, "w");
                    if (arquivo != NULL) {
                        printf("Arquivo criado com sucesso!\n");
                        fclose(arquivo);
                        system(nomearquivo);
                    } else {
                        printf("Erro ao criar o arquivo.\n");
                    }
                } else {
                    printf("Operação cancelada.\n");
                }
            } else {
                fclose(arquivo);
                printf("Arquivo aberto com sucesso!\n");
                system(nomearquivo);
            }
        } else {
            printf("Resposta Inválida\n");
        }
        printf("Você deseja continuar? (S/N): ");
        scanf(" %c", &resposta);
        system("cls");
    }

    return 0;
}