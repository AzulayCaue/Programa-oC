#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para imprimir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializando o tabuleiro com zeros (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (definidas no código)
    int linha_horizontal = 2, coluna_horizontal = 4; // Começa na linha 2, coluna 4
    int linha_vertical = 5, coluna_vertical = 7;     // Começa na linha 5, coluna 7

    // Validação dos limites do tabuleiro para o navio horizontal
    if (coluna_horizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        // Verifica se há sobreposição antes de posicionar
        int pode_posicionar = 1;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
            }
        } else {
            printf("Erro: Sobreposição detectada no navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Validação dos limites do tabuleiro para o navio vertical
    if (linha_vertical + TAM_NAVIO <= TAM_TABULEIRO) {
        int pode_posicionar = 1;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = 3;
            }
        } else {
            printf("Erro: Sobreposição detectada no navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Exibindo o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
