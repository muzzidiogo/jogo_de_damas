#ifndef TABULEIRO_H
#define TABULEIRO_H


#include "peca.hpp"
#include "dama.hpp"

typedef struct {
    int linha;
    int coluna;
} Movimento_t;

class Tabuleiro_t {
private:
    const static unsigned int TAMANHO;
    std::vector<Peca_t> _tabuleiro;
public:
    /// @brief Construtor que cria um tabuleiro padrao de damas
    Tabuleiro_t();

    /// @brief Remove uma peca com uma posicao especifica do tabuleiro
    /// @param posicao Posicao da peca a ser removida
    void remover_peca(Posicao_t posicao);

    /// @brief Funcao que verifica se uma posicao espefica do tabuleiro esta ocupada ou nao 
    /// @return True, caso a posicao esteja ocupada, false caso contrario
    bool verificar_posicao(Posicao_t posicao);

    bool verificar_pos_saiu_tabuleiro(Posicao_t posicao);

    /// @brief Funcao que anda com a peca e verifica se ela virou dama ou nao
    /// @param novaPosicao Posicao para a qual a peca se movera
    /// @param peca Referencia da peca que sera movida
    void atualizar_tabuleiro(Posicao_t novaPosicao, Peca_t & peca);
    
    /// @brief Funcao que retorna o vetor de pecas (_tabuleiro)
    /// @return Vetor de pecas
    std::vector<Peca_t> get_tabuleiro();
    
    /// @brief Funcao usada para copiar um tabuleiro especifico no _tabuleiro
    /// @param tabuleiroAntigo Tabuleiro a ser copiado
    void copia_tabuleiro(Tabuleiro_t tabuleiroAntigo);

    /// @brief Funcao que captura uma peca de acordo com o movimento especificado
    /// @param pecaJogada Peca que sera usada para a captura 
    /// @param movimento Direcao que a captura tomara (Ex: [2, 2] comendo [1, 1] tem movimento [-1, -1])
    void captura_peca(Peca_t pecaJogada, Movimento_t movimento);

    /// @brief Funcao usada pela engine para saber se uma captura eh valida
    /// @param pecaJogada Peca que sera usada para a captura 
    /// @param movimento Direcao que a captura tomara (Ex: [2, 2] comendo [1, 1] tem movimento [-1, -1])
    /// @return True, caso a captura seja valida, false caso contrario
    bool verifica_validade_captura(Peca_t peca, Movimento_t movimento);

    void reiniciar_tabuleiro();
    std::vector<Peca_t>* get_ptr_tabuleiro();
    void set_tabuleiro_testes(std::vector<Peca_t> tabuleiro); 
};

#endif //TABULEIRO_H
