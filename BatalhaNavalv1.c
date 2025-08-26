#include <stdio.h>

#define TAM_TABULEIRO 10   // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3        // Tamanho fixo dos navios

int main() {
    // 1. Criar o tabuleiro e inicializar todas as posições com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // 2. Definir coordenadas iniciais dos navios
    // Navio horizontal (linha 2, coluna 1)
    int linhaNavioH = 2;
    int colunaNavioH = 1;

    // Navio vertical (linha 5, coluna 5)
    int linhaNavioV = 5;
    int colunaNavioV = 5;

    // 3. Posicionar navio horizontal
    // Validar se o navio cabe dentro do tabuleiro
    if (colunaNavioH + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaNavioH][colunaNavioH + i] = 3;  // Valor 3 representa navio
        }
    } else {
        printf("Erro: navio horizontal não cabe no tabuleiro!\n");
    }

    // 4. Posicionar navio vertical
    // Validar se o navio cabe dentro do tabuleiro
    if (linhaNavioV + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;  // Valor 3 representa navio
        }
    } else {
        printf("Erro: navio vertical não cabe no tabuleiro!\n");
    }

    // 5. Exibir o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
