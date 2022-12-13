#ifndef PECA_HPP
#define PECA_HPP

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
    bool _dama;
    int _cor;
    Posicao_t _posicao;
    int quantidadeJogadas = 0;
public:
    Peca_t(); //construtor vazio 
    Peca_t(bool dama, int cor, Posicao_t posicao);
    void andar(Posicao_t posicao);
    Posicao_t get_posicao();
    int get_cor();
    void set_quantidadeJogadas(int quantidade);
    int get_quantidadeJogadas();
};

#endif //PECA_HPP
