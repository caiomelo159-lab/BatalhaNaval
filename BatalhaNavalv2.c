#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para verificar se a posição está livre (0 = água)
int posicao_livre(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

// Função para posicionar navio horizontal
int posiciona_navio_horizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // Não cabe no tabuleiro

    // Verifica sobreposição
    for (int i = 0; i < TAM_NAVIO; i++)
        if (!posicao_livre(tabuleiro, linha, coluna + i)) return 0;

    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha][coluna + i] = 3;

    return 1;
}

// Função para posicionar navio vertical
int posiciona_navio_vertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        if (!posicao_livre(tabuleiro, linha + i, coluna)) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha + i][coluna] = 3;

    return 1;
}

// Função para posicionar navio diagonal (linha e coluna aumentam)
int posiciona_navio_diagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        if (!posicao_livre(tabuleiro, linha + i, coluna + i)) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha + i][coluna + i] = 3;

    return 1;
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais para os navios
    int linhaH1 = 1, colunaH1 = 1; // Horizontal
    int linhaV1 = 5, colunaV1 = 2; // Vertical
    int linhaD1 = 0, colunaD1 = 7; // Diagonal
    int linhaD2 = 6, colunaD2 = 6; // Diagonal

    // Posicionar navios e validar
    if (!posiciona_navio_horizontal(tabuleiro, linhaH1, colunaH1))
        printf("Erro ao posicionar navio horizontal!\n");

    if (!posiciona_navio_vertical(tabuleiro, linhaV1, colunaV1))
        printf("Erro ao posicionar navio vertical!\n");

    if (!posiciona_navio_diagonal(tabuleiro, linhaD1, colunaD1))
        printf("Erro ao posicionar navio diagonal 1!\n");

    if (!posiciona_navio_diagonal(tabuleiro, linhaD2, colunaD2))
        printf("Erro ao posicionar navio diagonal 2!\n");

    // Exibir o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
