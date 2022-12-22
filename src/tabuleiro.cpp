#include "../include/tabuleiro.hpp"
#include <cstddef>

Tabuleiro_t::Tabuleiro_t() {
    for(unsigned int i = 0; i<3; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                _tabuleiro.push_back(Peca_t(Cores::PRETO, Posicao_t{i, j}));
            }
        }
    }
    for(unsigned int i = 5; i<8; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                _tabuleiro.push_back(Peca_t(Cores::BRANCO, Posicao_t{i, j}));
            }
        }
    }
}

void Tabuleiro_t::remover_peca(Posicao_t posicao) { //fonte de bug???
    for(auto it = _tabuleiro.begin(); it != _tabuleiro.end(); it++) {
        if((it->get_posicao().coluna == posicao.coluna) &&
           (it->get_posicao().linha == posicao.linha))
        {
            _tabuleiro.erase(it);
            break;
        }
    }
}

bool Tabuleiro_t::verificar_posicao(Posicao_t posicao){
    for(size_t i = 0; i<_tabuleiro.size(); i++) {
        if((_tabuleiro[i].get_posicao().coluna == posicao.coluna) && 
           (_tabuleiro[i].get_posicao().linha == posicao.linha)) 
        {
            return true;
        }
    }
    return false;
}

bool Tabuleiro_t::verificar_pos_saiu_tabuleiro(Posicao_t posicao) {
    if(posicao.coluna<0||posicao.coluna>7||posicao.linha<0||posicao.linha>7){
        return true;
    }
    return false;
}

void Tabuleiro_t::atualizar_tabuleiro(Posicao_t novaPosicao, Peca_t & peca){
    peca.andar(novaPosicao);
    
    Dama dama;
    if ((peca.get_cor() == Cores::BRANCO && peca.get_posicao().linha == 7) ||
        (peca.get_cor() == Cores::PRETO && peca.get_posicao().linha == 0)) {
        
        dama = Dama(peca.get_cor(), peca.get_posicao());
        size_t i;
        for (i = 0; i < _tabuleiro.size(); i++) {
            if (_tabuleiro[i] == peca) break;
        }

        auto it = _tabuleiro.begin() + i;
        _tabuleiro.erase(it);
        _tabuleiro.push_back(dama);
    }
}

std::vector<Peca_t> Tabuleiro_t::get_tabuleiro(){
    return _tabuleiro;
}

void Tabuleiro_t::copia_tabuleiro(Tabuleiro_t tabuleiroAntigo) {
    _tabuleiro.clear();

    for (Peca_t peca : tabuleiroAntigo.get_tabuleiro()) {
        _tabuleiro.push_back(peca);
    }
}

void Tabuleiro_t::captura_peca(Peca_t pecaJogada, Movimento_t movimento) {
    unsigned int linha = pecaJogada.get_posicao().linha;
    unsigned int coluna = pecaJogada.get_posicao().coluna;
    
    for (size_t i = 0; i < _tabuleiro.size(); i++) {
        if (_tabuleiro[i].get_posicao().linha == linha && _tabuleiro[i].get_posicao().coluna == coluna) {
            this->atualizar_tabuleiro({linha + movimento.linha, coluna + movimento.coluna}, _tabuleiro[i]);
            this->atualizar_tabuleiro({_tabuleiro[i].get_posicao().linha + movimento.linha, _tabuleiro[i].get_posicao().coluna + movimento.coluna}, _tabuleiro[i]);
        }
    }
    this->remover_peca({linha + movimento.linha, coluna + movimento.coluna});
}

bool Tabuleiro_t::verifica_validade_captura(Peca_t pecaMover, Movimento_t movimento) {
    unsigned int linha = pecaMover.get_posicao().linha;
    unsigned int coluna = pecaMover.get_posicao().coluna;
    char cor = pecaMover.get_cor();
    char outraCor = Cores::PRETO;
    if (cor == Cores::PRETO) outraCor = Cores::BRANCO;

    bool movimentoEvalido =  (linha + 2*movimento.linha >= 0) && 
        (linha + 2*movimento.linha < 8) &&
        (coluna + 2*movimento.coluna >= 0) && 
        (coluna + 2*movimento.coluna < 8);  
                                
    bool casaCapturarEvalida = false; //loop dentro da funcao porque é mecessário verificar a cor
    for (Peca_t peca : _tabuleiro) {
        if (peca.get_posicao().linha ==  linha + movimento.linha && 
           peca.get_posicao().coluna ==  coluna + movimento.coluna && 
           peca.get_cor() == outraCor) {
            casaCapturarEvalida = true;    
        } 
    }

    bool casaMoverOcupada = this->verificar_posicao({linha + 2*movimento.linha, coluna + 2*movimento.coluna});

    return (movimentoEvalido && casaCapturarEvalida && !casaMoverOcupada); 
}

void Tabuleiro_t::set_tabuleiro_testes(std::vector<Peca_t> tabuleiro) {
    _tabuleiro = tabuleiro;
}

std::vector<Peca_t>* Tabuleiro_t::get_ptr_tabuleiro(){
    return &_tabuleiro;
}

void Tabuleiro_t::reiniciar_tabuleiro() {
    _tabuleiro.clear();
    for(unsigned int i = 0; i<3; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                _tabuleiro.push_back(Peca_t(Cores::PRETO, Posicao_t{i, j}));
            }
        }
    }
    for(unsigned int i = 5; i<8; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                _tabuleiro.push_back(Peca_t(Cores::BRANCO, Posicao_t{i, j}));
            }
        }
    }
}