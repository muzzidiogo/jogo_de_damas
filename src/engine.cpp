#include "../include/engine.hpp"
#include <iostream>
#include <vector>

Tabuleiro_t * Engine::aloca_tabuleiro_com_captura(Tabuleiro_t tabuleiro, Movimento_t movimento, Peca_t peca) {
  Tabuleiro_t *tabuleiroNovo = new Tabuleiro_t(); 
  tabuleiroNovo->copia_tabuleiro(tabuleiro);
  tabuleiroNovo->captura_peca(peca, movimento);

  return tabuleiroNovo;
}

bool Engine::conta_jogadas(Tabuleiro_t tabuleiro, Peca_t peca) {
  std::vector<Movimento_t> movimentos = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  
  for (Movimento_t movimento : movimentos) {
    if (tabuleiro.verifica_validade_captura(peca, movimento)) { 
      Tabuleiro_t *tabuleiroNovo = aloca_tabuleiro_com_captura(tabuleiro, movimento, peca);
      
      _numCapturas++; 
      _posRemover.push_back({peca.get_posicao().linha + movimento.linha, peca.get_posicao().coluna + movimento.coluna});
      peca = Peca_t(peca.get_cor(), {peca.get_posicao().linha + 2*movimento.linha, peca.get_posicao().coluna + 2*movimento.coluna});
      if (_numCapturas > _numCapturasMax) {
        _numCapturasMax = _numCapturas;
        _posRemoverMax.clear();
        for (Posicao_t pos : _posRemover) {
          _posRemoverMax.push_back(pos);
        }
      }    
      if(conta_jogadas(*tabuleiroNovo, peca)) return 1;
      delete tabuleiroNovo;    
    }
  }

  _posRemover.pop_back();
  _numCapturas--;
  return 0;    
}

void Engine::get_maior(Tabuleiro_t tabuleiro, char cor, Peca_t &pecaPreencher, std::vector<Posicao_t> &posicaoPreencher) {
  int maiorQuantidade = 0;
  
  for (Peca_t peca : tabuleiro.get_tabuleiro()) {
    if (peca.get_cor() == cor) {
      _numCapturas = 0; _numCapturasMax = 0;
      _posRemover.clear(); _posRemoverMax.clear();
      this->conta_jogadas(tabuleiro, peca);

      if (_numCapturasMax >= maiorQuantidade) {
        maiorQuantidade = _numCapturasMax;
        pecaPreencher = peca;
        posicaoPreencher.clear();
        for (Posicao_t pos : _posRemoverMax) posicaoPreencher.push_back(pos); 
      }
    }
  }
}