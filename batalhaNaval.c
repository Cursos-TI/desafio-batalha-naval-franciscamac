#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para verificar se o navio cabe no tabuleiro e não ultrapassa os limites
int verifica_posicao(int linha, int coluna, int orientacao, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0); // 1 = vertical
        int c = coluna + (orientacao == 0 ? i : 0); // 0 = horizontal
        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO) return 0; // Fora dos limites
        if (tabuleiro[l][c] != 0) return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posiciona_navio(int linha, int coluna, int orientacao, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);
        int c = coluna + (orientacao == 0 ? i : 0);
        tabuleiro[l][c] = 3;
    }
}

int main() {
    // Declaração e inicialização do tabuleiro 10x10 com zeros (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (definidas no código)
    int linha_navio_h = 2, coluna_navio_h = 1; // Navio horizontal
    int linha_navio_v = 5, coluna_navio_v = 7; // Navio vertical

    // Validação e posicionamento do navio horizontal
    if (verifica_posicao(linha_navio_h, coluna_navio_h, 0, tabuleiro)) {
        posiciona_navio(linha_navio_h, coluna_navio_h, 0, tabuleiro);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    // Validação e posicionamento do navio vertical
    if (verifica_posicao(linha_navio_v, coluna_navio_v, 1, tabuleiro)) {
        posiciona_navio(linha_navio_v, coluna_navio_v, 1, tabuleiro);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
