#include "../include/dama.hpp"
#include <cmath>

Dama::Dama(int cor, Posicao_t posicao): Peca_t(cor, posicao){};

void Dama::andar(Posicao_t novaPosicao) {
    if(abs((int)get_posicao().linha - (int)novaPosicao.linha) == abs((int)get_posicao().coluna - (int)novaPosicao.linha)
    && novaPosicao.linha < 8 && novaPosicao.coluna < 8){
        andar(novaPosicao);
    }
}