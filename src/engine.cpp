#include "../include/engine.hpp"

void Engine::rodaEngine(Tabuleiro_t tabuleiro) {

}
#include <stdio.h>
#include <stdlib.h>

typedef struct { //struct para definir cada peça
    int x;
    int y;
    int quantidade;
} peca_t;

char **criaTabuleiro(int s);
void liberaTabuleiro(int s, char **tabuleiro);
void preencheTabuleiro(int s, char **tabuleiro);
int contaJogadas(int s, char **tabuleiro, int l, int c);
void copiaTabuleiro(int s, char **tabuleiroOriginal, char **tabuleiroNovo);
peca_t achaMaior(int s, peca_t *resultados);
int quantidadeDeJogadas, quantidadeDeJogadasMax;

int main() {
    int s; scanf("%d", &s);

    char **tabuleiro = criaTabuleiro(s);
    preencheTabuleiro(s, tabuleiro);
    
    int contador = 0;
    peca_t *resultados = malloc(0);
    for (int i = 0; i < s; i++) {
        if (i%2 == 0) { // se o i for um número positivo, o loop do j vai de 0 a s - 1 
            for (int j = 0; j < s; j++) { 
                if (tabuleiro[i][j] == 'b') {  
                    quantidadeDeJogadas = 0;
                    quantidadeDeJogadasMax = 0;
                    contaJogadas(s, tabuleiro, i, j);
                    if (quantidadeDeJogadasMax) { // se o valor máximo de jogadas for diferente de 0, ou seja, se for possível comer com a peça branca
                        resultados = realloc(resultados, (contador + 1)*sizeof(peca_t));
                        peca_t aux = {i, j, quantidadeDeJogadasMax};
                        resultados[contador] = aux;
                        contador++;
                    } 
                        
                }
            }
        }
        else {  // se o i for um número negatuvo, o loop do j vai de s - 1 a 0 (isso é feito para garantir a ordem de printagem dos itens) 
            for (int j = s - 1; j >= 0; j--) {
                if (tabuleiro[i][j] == 'b') { 
                    quantidadeDeJogadas = 0;
                    quantidadeDeJogadasMax = 0;
                    contaJogadas(s, tabuleiro, i, j);
                    if (quantidadeDeJogadasMax) { // se o valor máximo de jogadas for diferente de 0, ou seja, se for possível comer com a peça branca
                        resultados = realloc(resultados, (contador + 1)*sizeof(peca_t)); 
                        peca_t aux = {i, j, quantidadeDeJogadasMax};
                        resultados[contador] = aux;
                        contador++;
                    } 
                        
                }
            }
        }
    }
    peca_t maior = achaMaior(contador, resultados);
    printf("%d %d %d\n", maior.x, maior.y, maior.quantidade);
    for (int i = 0; i < contador; i++) {
        printf("%d %d %d\n", resultados[i].x, resultados[i].y, resultados[i].quantidade);
    }

    free(resultados);
    liberaTabuleiro(s, tabuleiro);
    return 0;
}
// essa funç?o aloca dinâmicamente um tabuleiro de caracteres de tamanho s x s
char **criaTabuleiro(int s) {
    char **tabuleiro = malloc(s*sizeof(char*));
    for (int i = 0; i < s; i++) {
        tabuleiro[i] = malloc(s);
    }
    return tabuleiro;
}
// essa funç?o libera um tabuleiro de tamanho s x s criado por meio da funç?o anterioro
void liberaTabuleiro(int s, char **tabuleiro) {
    for (int i = 0; i < s; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
}
// essa funç?o preenche o tabuleiro com os inputs do usuário 
void preencheTabuleiro(int s, char **tabuleiro) {
    char c;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            tabuleiro[i][j] = getchar();
            if (tabuleiro[i][j] == '\n') 
                tabuleiro[i][j] = getchar();
        }
    }   
}
// essa é a funç?o recursiva responsável por contar a quantidade máxima de jogadas disponíves para cada peça 
int contaJogadas(int s, char **tabuleiro, int l, int c) {
    if (l - 2 >= 0 && c - 2 >= 0) {
        if(tabuleiro[l - 1][c - 1] == 'p' && tabuleiro[l - 2][c - 2] == 'o') {
            char **tabuleiroNovo = criaTabuleiro(s);
            copiaTabuleiro(s, tabuleiro, tabuleiroNovo);
            tabuleiroNovo[l - 1][c - 1] = 'o';
            tabuleiroNovo[l][c] = 'o';
            tabuleiroNovo[l - 2][c - 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, tabuleiroNovo, l - 2, c - 2)) return 1;    
            liberaTabuleiro(s, tabuleiroNovo);
        }
    }
    if (l + 2 <= s && c + 2 <= s) {
        if(tabuleiro[l + 1][c + 1] == 'p' && tabuleiro[l + 2][c + 2] == 'o') {
            char **tabuleiroNovo = criaTabuleiro(s);
            copiaTabuleiro(s, tabuleiro, tabuleiroNovo);
            tabuleiroNovo[l + 1][c + 1] = 'o';
            tabuleiroNovo[l][c] = 'o';
            tabuleiroNovo[l + 2][c + 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, tabuleiroNovo, l + 2, c + 2)) return 1;
            liberaTabuleiro(s, tabuleiroNovo);
        }
    }
    if (l - 2 >= 0 && c + 2 <= s) {
        if(tabuleiro[l - 1][c + 1] == 'p' && tabuleiro[l - 2][c + 2] == 'o') {
            char **tabuleiroNovo = criaTabuleiro(s);
            copiaTabuleiro(s, tabuleiro, tabuleiroNovo);
            tabuleiroNovo[l - 1][c + 1] = 'o';
            tabuleiroNovo[l][c] = 'o';
            tabuleiroNovo[l - 2][c + 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, tabuleiroNovo, l - 2, c + 2)) return 1;
            liberaTabuleiro(s, tabuleiroNovo);
        }
    }
    if (l + 2 <= s && c - 2 >= 0) {
        if (tabuleiro[l + 1][c - 1] == 'p' && tabuleiro[l + 2][c - 2] == 'o') {
            char **tabuleiroNovo = criaTabuleiro(s);
            copiaTabuleiro(s, tabuleiro, tabuleiroNovo);
            tabuleiroNovo[l + 1][c - 1] = 'o';
            tabuleiroNovo[l][c] = 'o';
            tabuleiroNovo[l + 2][c - 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, tabuleiroNovo, l + 2, c - 2)) return 1;
            liberaTabuleiro(s, tabuleiroNovo);
        }
    }
    quantidadeDeJogadas--;
    return 0;
}
//essa funç?o é responsável por copiar os dados de um tabuleiro para outro
void copiaTabuleiro(int s, char **tabuleiroOriginal, char **tabuleiroNovo) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            tabuleiroNovo[i][j] = tabuleiroOriginal[i][j];
        }
    }
}
//essa funç?o é responsável por achar a peça com maior quantidade de jogadas 
peca_t achaMaior(int s, peca_t *resultados) {
    peca_t maior = {-1, -1, -999};
    for (int i = 0; i < s; i++) {
        if (maior.quantidade < resultados[i].quantidade) {
            maior = resultados[i];
        }
    }
    return maior;
}