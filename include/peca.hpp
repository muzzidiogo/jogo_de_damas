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
public:
    Peca_t(bool dama, int cor, Posicao_t posicao);
    void Andar(Posicao_t posicao);
    void Capturar_Peca(Posicao_t posicao, Peca_t pecaCapturada);
    Posicao_t get_posicao();
    int get_cor();
};

#endif //PECA_HPP
