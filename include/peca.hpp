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
public:
    Peca_t(); //construtor vazio 
    Peca_t(int cor, Posicao_t posicao);
    virtual void andar(Posicao_t posicao);
    Posicao_t get_posicao();
    int get_cor();
    bool operator ==(Peca_t peca) const;
    bool operator !=(Peca_t peca) const;
};

#endif //PECA_HPP
