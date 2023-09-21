#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int numeros_escolhidos[5];
    int numeros_sorteados[100];
    int i, acertos = 0;

    for (i = 0; i < 100; i++) {
        numeros_sorteados[i] = i + 1;
    }

    for (i = 0; i < 100; i++) {
        int temp = numeros_sorteados[i];
        int random_index = rand() % 100;
        numeros_sorteados[i] = numeros_sorteados[random_index];
        numeros_sorteados[random_index] = temp;
    }

    printf("Digite seus números (5 números de 1 a 100, separados por espaços): ");

    for (i = 0; i < 5; i++) {
        scanf("%d", &numeros_escolhidos[i]);

        if (numeros_escolhidos[i] < 1 || numeros_escolhidos[i] > 100) {
            printf("Os números devem estar entre 1 e 100.\n");
            return 1;
        }

        for (int j = 0; j < i; j++) {
            if (numeros_escolhidos[i] == numeros_escolhidos[j]) {
                printf("Os números escolhidos não podem ser repetidos.\n");
                return 1;
            }
        }
    }

    for (i = 0; i < 5; i++) {
        for (int j = 0; j < 50; j++) {
            if (numeros_escolhidos[i] == numeros_sorteados[j]) {
                acertos++;
                break;
            }
        }
    }

    printf("Os números sorteados foram: ");
    for (i = 0; i < 50; i++) {
        printf("%d ", numeros_sorteados[i]);
    }
    printf("\n");

    printf("Você escolheu os números: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeros_escolhidos[i]);
    }
    printf("\n");

    if (acertos == 5) {
        printf("Parabéns! Você ganhou!\n");
    } else {
        printf("Você perdeu. Tente novamente.\n");
    }

    return 0;
}
