#ifndef PECA_HPP
#define PECA_HPP
#include <vector>
//================ EXTRAS ================
typedef struct {
    unsigned int linha;
    unsigned int coluna;
} Posicao_t;

enum Cores {
    BRANCO, PRETO
};
// FIM EXTRAS ============================

class Peca_t {
private:
    int _cor;
    Posicao_t _posicao;
    int _quantidadeJogadas = 0;
    std::vector<Peca_t> _pecasRemover;
public:
    Peca_t(); //construtor vazio 
    Peca_t(int cor, Posicao_t posicao);
    virtual void andar(Posicao_t posicao);
    Posicao_t get_posicao();
    int get_cor();
    void set_quantidadeJogadas(int quantidade);
    int get_quantidadeJogadas();
    std::vector<Peca_t> get_pecasRemover();
    void set_pecasRemover(std::vector<Peca_t> pecasRemover);
};

#endif //PECA_HPP
