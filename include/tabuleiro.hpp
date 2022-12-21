#ifndef TABULEIRO_H
#define TABULEIRO_H


#include "peca.hpp"

typedef struct {
    int linha;
    int coluna;
} Movimento_t;

class Tabuleiro_t {
private:
    const static unsigned int TAMANHO;
    std::vector<Peca_t> _tabuleiro;
public:
    Tabuleiro_t();
    void remover_peca(Posicao_t posicao);
    bool verificar_posicao(Posicao_t posicao);
    bool verificar_pos_saiu_tabuleiro(Posicao_t posicao);
    bool atualizar_tabuleiro(Posicao_t novaPosicao, Peca_t peca);
    std::vector<Peca_t> get_tabuleiro();
    void copia_tabuleiro(Tabuleiro_t tabuleiroAntigo);
    void captura_peca(Peca_t pecaJogada, Movimento_t movimento);  
    bool verifica_validade_captura(Peca_t peca, Movimento_t movimento);
    void reiniciar_tabuleiro();
    std::vector<Peca_t>* get_ptr_tabuleiro();

    void set_tabuleiro_testes(std::vector<Peca_t> tabuleiro); 
};

#endif //TABULEIRO_H
