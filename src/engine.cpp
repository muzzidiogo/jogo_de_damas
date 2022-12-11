#include "../include/engine.hpp"

bool Engine::contaJogadas(Tabuleiro_t _tabuleiro, Peca_t _peca, char _cor) {
    int l = _peca.get_posicao().linha;
    int c =  _peca.get_posicao().coluna;
    
    if (l - 2 >= 0 && c - 2 >= 0) {
        if(_tabuleiro[l - 1][c - 1] == 'p' && _tabuleiro[l - 2][c - 2] == 'o') {
            char **_tabuleiroNovo = cria_Tabuleiro(s);
            copia_Tabuleiro(s, _tabuleiro, _tabuleiroNovo);
            _tabuleiroNovo[l - 1][c - 1] = 'o';
            _tabuleiroNovo[l][c] = 'o';
            _tabuleiroNovo[l - 2][c - 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, _tabuleiroNovo, l - 2, c - 2)) return 1;    
            libera_Tabuleiro(s, _tabuleiroNovo);
        }
    }
    if (l + 2 <= s && c + 2 <= s) {
        if(_tabuleiro[l + 1][c + 1] == 'p' && _tabuleiro[l + 2][c + 2] == 'o') {
            char **_tabuleiroNovo = cria_Tabuleiro(s);
            copia_Tabuleiro(s, _tabuleiro, _tabuleiroNovo);
            _tabuleiroNovo[l + 1][c + 1] = 'o';
            _tabuleiroNovo[l][c] = 'o';
            _tabuleiroNovo[l + 2][c + 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, _tabuleiroNovo, l + 2, c + 2)) return 1;
            libera_Tabuleiro(s, _tabuleiroNovo);
        }
    }
    if (l - 2 >= 0 && c + 2 <= s) {
        if(_tabuleiro[l - 1][c + 1] == 'p' && _tabuleiro[l - 2][c + 2] == 'o') {
            char **_tabuleiroNovo = cria_Tabuleiro(s);
            copia_Tabuleiro(s, _tabuleiro, _tabuleiroNovo);
            _tabuleiroNovo[l - 1][c + 1] = 'o';
            _tabuleiroNovo[l][c] = 'o';
            _tabuleiroNovo[l - 2][c + 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, _tabuleiroNovo, l - 2, c + 2)) return 1;
            libera_Tabuleiro(s, _tabuleiroNovo);
        }
    }
    if (l + 2 <= s && c - 2 >= 0) {
        if (_tabuleiro[l + 1][c - 1] == 'p' && _tabuleiro[l + 2][c - 2] == 'o') {
            char **_tabuleiroNovo = cria_Tabuleiro(s);
            copia_Tabuleiro(s, _tabuleiro, _tabuleiroNovo);
            _tabuleiroNovo[l + 1][c - 1] = 'o';
            _tabuleiroNovo[l][c] = 'o';
            _tabuleiroNovo[l + 2][c - 2] = 'b';
            quantidadeDeJogadas++;
            if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
            if(contaJogadas(s, _tabuleiroNovo, l + 2, c - 2)) return 1;
            libera_Tabuleiro(s, _tabuleiroNovo);
        }
    }
    quantidadeDeJogadas--;
    return 0;    
}

void Engine::rodaEngine(_Tabuleiro_t __tabuleiro, char _cor) {
    if (_cor == 'b') {
        for (Peca_t peca : __tabuleiro.get__tabuleiro()) {
            if (peca.get_cor() == _cor) {
                quantidadeDeJogadas = 0;
                quantidadeDeJogadasMAX = 0;
                this->contaJogadas(__tabuleiro, peca, _cor);
            }            
        }
    }
}



