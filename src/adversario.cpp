#include "../include/adversario.hpp"

Adversario_t::Adversario_t(Tabuleiro_t *tabuleiro, Engine *engine) {
    _tabuleiro = tabuleiro;
    _engine = engine;
}

void Adversario_t::jogar() {
    Peca_t pecaMover;
    std::vector<Posicao_t> pecasCapturar;
    _engine->get_maior(*_tabuleiro, Cores::PRETO, pecaMover, pecasCapturar);
    if(pecasCapturar.size() != 0) {
        for(Posicao_t posicao : pecasCapturar) {
            Movimento_t movimento = {int(posicao.linha), int(posicao.coluna)};
            _tabuleiro->captura_peca(pecaMover, movimento);
        }
    }
    else {
        for(Peca_t peca : _tabuleiro->get_tabuleiro()){
            Posicao_t novaPosDir{peca.get_posicao().linha+1, peca.get_posicao().coluna+1};
            Posicao_t novaPosEsq{peca.get_posicao().linha+1, peca.get_posicao().coluna-1};
            if(!_tabuleiro->verificar_posicao(novaPosDir)&&
               !_tabuleiro->verificar_pos_saiu_tabuleiro(novaPosDir)) {
                _tabuleiro->atualizar_tabuleiro(novaPosDir, peca);
                return;
            }
            if(!_tabuleiro->verificar_posicao(novaPosEsq)&&
               !_tabuleiro->verificar_pos_saiu_tabuleiro(novaPosEsq)){
                _tabuleiro->atualizar_tabuleiro(novaPosEsq, peca);
                return;
            }
        }
    }
}