#include "../include/dama.hpp"

Dama::Dama() {};
Dama::Dama(int cor, Posicao_t posicao): Peca_t(cor, posicao){};

bool Dama::verifica_movimento(Posicao_t novaPosicao){
    if(novaPosicao.linha < 8 && novaPosicao.coluna < 8
    && abs((int)get_posicao().linha - (int)novaPosicao.linha)==abs((int)get_posicao().coluna - (int)novaPosicao.coluna)){
        return true;
    }
    else return false;
}