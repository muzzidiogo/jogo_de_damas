/* #include "../include/adversario.hpp"

Adversario_t::Adversario_t(Tabuleiro_t *tabuleiro, Engine *engine) {
    _tabuleiro = tabuleiro;
    _engine = engine;
}

void Adversario_t::jogar() {
    PecaPorCapturas_t *melhorMovimento = _engine->get_maior(*_tabuleiro, Cores::PRETO);
    if(melhorMovimento->posRemover->size() > 0) {
        for(Posicao_t posicao : *(melhorMovimento->posRemover)) {
            Movimento_t movimento = {int(posicao.linha), int(posicao.coluna)};
            _tabuleiro->captura_peca(melhorMovimento->peca, movimento);
        }
    }
    else {
        for(Peca_t peca : _tabuleiro->get_tabuleiro()){
            Posicao_t novaPosDir = {peca.get_posicao().linha+1, peca.get_posicao().coluna+1};
            Posicao_t novaPosEsq = {peca.get_posicao().linha+1, peca.get_posicao().coluna-1};
            if(!_tabuleiro->verificar_posicao(novaPosDir)&&
               !_tabuleiro->verificar_pos_saiu_tabuleiro(novaPosDir)) {
                peca.andar(novaPosDir);
                return;
            }
            if(!_tabuleiro->verificar_posicao(novaPosEsq)&&
               !_tabuleiro->verificar_pos_saiu_tabuleiro(novaPosEsq)){
                peca.andar(novaPosEsq);
                return;
            }
        }
    }
    delete melhorMovimento;
} */