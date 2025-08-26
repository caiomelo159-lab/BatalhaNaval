#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

#define TAM_HABILIDADE 5
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

// Inicializa o tabuleiro com água (0)
void inicializaTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for(int i=0;i<TAM_TABULEIRO;i++)
        for(int j=0;j<TAM_TABULEIRO;j++)
            tabuleiro[i][j]=0;
}

// Posiciona navio horizontal
int posiciona_navio_horizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
    for(int i=0;i<TAM_NAVIO;i++)
        if(tabuleiro[linha][coluna+i]!=0) return 0;
    for(int i=0;i<TAM_NAVIO;i++)
        tabuleiro[linha][coluna+i]=VALOR_NAVIO;
    return 1;
}

// Posiciona navio vertical
int posiciona_navio_vertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
    for(int i=0;i<TAM_NAVIO;i++)
        if(tabuleiro[linha+i][coluna]!=0) return 0;
    for(int i=0;i<TAM_NAVIO;i++)
        tabuleiro[linha+i][coluna]=VALOR_NAVIO;
    return 1;
}

// Cria habilidade Cone 5x5
void criaCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for(int i=0;i<TAM_HABILIDADE;i++){
        for(int j=0;j<TAM_HABILIDADE;j++){
            if(j >= 2 - i && j <= 2 + i) 
                cone[i][j]=1;
            else
                cone[i][j]=0;
        }
    }
}

// Cria habilidade Cruz 5x5
void criaCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]){
    for(int i=0;i<TAM_HABILIDADE;i++){
        for(int j=0;j<TAM_HABILIDADE;j++){
            if(i==2 || j==2)
                cruz[i][j]=1;
            else
                cruz[i][j]=0;
        }
    }
}

// Cria habilidade Octaedro 5x5
void criaOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]){
    for(int i=0;i<TAM_HABILIDADE;i++){
        for(int j=0;j<TAM_HABILIDADE;j++){
            if(abs(i-2)+abs(j-2)<=2)
                octaedro[i][j]=1;
            else
                octaedro[i][j]=0;
        }
    }
}

// Aplica habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origemLinha, int origemColuna){
    int offset = TAM_HABILIDADE/2;
    for(int i=0;i<TAM_HABILIDADE;i++){
        for(int j=0;j<TAM_HABILIDADE;j++){
            int tabLinha = origemLinha + i - offset;
            int tabColuna = origemColuna + j - offset;
            if(tabLinha>=0 && tabLinha<TAM_TABULEIRO && tabColuna>=0 && tabColuna<TAM_TABULEIRO){
                if(habilidade[i][j]==1 && tabuleiro[tabLinha][tabColuna]==0)
                    tabuleiro[tabLinha][tabColuna]=VALOR_HABILIDADE;
            }
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]){
    for(int i=0;i<TAM_TABULEIRO;i++){
        for(int j=0;j<TAM_TABULEIRO;j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializaTabuleiro(tabuleiro);

    // Posicionar navios
    posiciona_navio_horizontal(tabuleiro,1,1);
    posiciona_navio_vertical(tabuleiro,5,2);
    posiciona_navio_horizontal(tabuleiro,3,6);
    posiciona_navio_vertical(tabuleiro,7,7);

    // Criar habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criaCone(cone);
    criaCruz(cruz);
    criaOctaedro(octaedro);

    // Exibir tabuleiro original
    printf("Tabuleiro original com navios:\n");
    exibirTabuleiro(tabuleiro);
    printf("\n----------------------------\n\n");

    // Aplicar Cone
    int tabCone[TAM_TABULEIRO][TAM_TABULEIRO];
    for(int i=0;i<TAM_TABULEIRO;i++)
        for(int j=0;j<TAM_TABULEIRO;j++)
            tabCone[i][j]=tabuleiro[i][j]; // copiar tabuleiro original
    aplicarHabilidade(tabCone, cone, 2, 2);
    printf("Tabuleiro com habilidade Cone aplicada:\n");
    exibirTabuleiro(tabCone);
    printf("\n----------------------------\n\n");

    // Aplicar Cruz
    int tabCruz[TAM_TABULEIRO][TAM_TABULEIRO];
    for(int i=0;i<TAM_TABULEIRO;i++)
        for(int j=0;j<TAM_TABULEIRO;j++)
            tabCruz[i][j]=tabuleiro[i][j];
    aplicarHabilidade(tabCruz, cruz, 6, 5);
    printf("Tabuleiro com habilidade Cruz aplicada:\n");
    exibirTabuleiro(tabCruz);
    printf("\n----------------------------\n\n");

    // Aplicar Octaedro
    int tabOcta[TAM_TABULEIRO][TAM_TABULEIRO];
    for(int i=0;i<TAM_TABULEIRO;i++)
        for(int j=0;j<TAM_TABULEIRO;j++)
            tabOcta[i][j]=tabuleiro[i][j];
    aplicarHabilidade(tabOcta, octaedro, 4, 7);
    printf("Tabuleiro com habilidade Octaedro aplicada:\n");
    exibirTabuleiro(tabOcta);

    return 0;
}
