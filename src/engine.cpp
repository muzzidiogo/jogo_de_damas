#include "../include/engine.hpp"

bool Engine::contaJogadas(Tabuleiro_t _tabuleiro, Peca_t _peca) {
    unsigned int linha = _peca.get_posicao().linha;
    unsigned int coluna = _peca.get_posicao().coluna;
    char cor = _peca.get_cor();
    char outraCor = 'b';
    if (cor == 'b') outraCor = 'p';

    if (linha - 2 >= 0 && coluna - 2 >= 0 &&  //se a jogada puder ser feita
      !_tabuleiro.VerificarPosicao({linha - 2, coluna - 2}) && //e houver espaço para a captura 
      _tabuleiro.procura_peca(linha - 1, coluna - 1, outraCor)) { //e uma peça inimiga estiver na diagonal
        
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t(); //cria um tabuleiro novo para fazer as modificações necessárias para a contagem
        tabuleiroNovo.copiaTabuleiroDe(_tabuleiro);
        tabuleiroNovo.capturaPeca(_peca, {linha - 1, coluna - 1}, -2, -2); //será que a peça vai alterar sua posição???
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(contaJogadas(tabuleiroNovo, _peca)) return 1;    
    }

    if (linha + 2 < 8 && coluna + 2 < 8 && //0 a 7, 8 pecas. 8 é o max + 1  
      !_tabuleiro.VerificarPosicao({linha + 2, coluna + 2}) &&
      _tabuleiro.procura_peca(linha + 1, coluna + 1, outraCor)) { 
        
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
        tabuleiroNovo.copiaTabuleiroDe(_tabuleiro);
        tabuleiroNovo.capturaPeca(_peca, {linha + 1, coluna + 1}, 2, 2);
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(contaJogadas(tabuleiroNovo, _peca)) return 1;    
    }

    if (linha + 2 < 8 && coluna - 2 >= 0  &&   
      !_tabuleiro.VerificarPosicao({linha + 2, coluna - 2}) &&
      _tabuleiro.procura_peca(linha + 1, coluna - 1, outraCor)) { 
        
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
        tabuleiroNovo.copiaTabuleiroDe(_tabuleiro);
        tabuleiroNovo.capturaPeca(_peca, {linha + 1, coluna - 1}, 2, -2);
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(contaJogadas(tabuleiroNovo, _peca)) return 1;    
    }
    
    if (linha - 2 >= 0 && coluna + 2 < 8  &&   
      !_tabuleiro.VerificarPosicao({linha - 2, coluna + 2}) &&
      _tabuleiro.procura_peca(linha - 1, coluna + 1, outraCor)) { 
        
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
        tabuleiroNovo.copiaTabuleiroDe(_tabuleiro);
        tabuleiroNovo.capturaPeca(_peca, {linha - 1, coluna + 1}, -2, 2);
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(contaJogadas(tabuleiroNovo, _peca)) return 1;    
        
    }

    quantidadeDeJogadas--;
    return 0;    
}

void Engine::rodaEngine(Tabuleiro_t _tabuleiro, char _cor) {
  for (unsigned int i = 0; i < _tabuleiro.get_tabuleiro().size(); i++) {
    if (_tabuleiro.get_tabuleiro()[i].get_cor() == _cor) {
      quantidadeDeJogadas = 0;
      quantidadeDeJogadasMax = 0;
      this->contaJogadas(_tabuleiro, _tabuleiro.get_tabuleiro()[i]);
      _tabuleiro.get_tabuleiro()[i].set_quantidadeJogadas(quantidadeDeJogadasMax);
    }
  }
}

