#include "../include/engine.hpp"

Tabuleiro_t * Engine::aloca_tabuleiro_com_captura(Tabuleiro_t tabuleiro, Movimento_t movimento, Peca_t peca) {
  Tabuleiro_t *tabuleiroNovo = new Tabuleiro_t(); 
  tabuleiroNovo->copia_tabuleiro(tabuleiro);
  tabuleiroNovo->captura_peca(peca, movimento);

  return tabuleiroNovo;
}

bool Engine::conta_jogadas(Tabuleiro_t tabuleiro, Peca_t peca) {
  if (tabuleiro.verifica_validade_captura(peca, {-1, -1})) { 
    Tabuleiro_t *tabuleiroNovo = aloca_tabuleiro_com_captura(tabuleiro, {-1, -1}, peca);
    
    _numCapturas++; 
    _posRemover.push_back({peca.get_posicao().linha - 1, peca.get_posicao().coluna - 1});
    
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

  if (tabuleiro.verifica_validade_captura(peca, {1, 1})) { 
    Tabuleiro_t *tabuleiroNovo = aloca_tabuleiro_com_captura(tabuleiro, {1, 1}, peca);
    
    _numCapturas++; 
    _posRemover.push_back({peca.get_posicao().linha + 1, peca.get_posicao().coluna + 1});
    
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

  if (tabuleiro.verifica_validade_captura(peca, {1, -1})){ 
    Tabuleiro_t *tabuleiroNovo = aloca_tabuleiro_com_captura(tabuleiro, {1, -1}, peca);

    _numCapturas++; 
    _posRemover.push_back({peca.get_posicao().linha + 1, peca.get_posicao().coluna - 1});
    
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
  
  if (tabuleiro.verifica_validade_captura(peca, {-1, 1})) { 
    Tabuleiro_t *tabuleiroNovo = aloca_tabuleiro_com_captura(tabuleiro, {-1, 1}, peca);
    
    _numCapturas++; 
    _posRemover.push_back({peca.get_posicao().linha - 1, peca.get_posicao().coluna + 1});
    
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

  _posRemover.pop_back();
  _numCapturas--;
  return 0;    
}

Peca_t Engine::get_maior(Tabuleiro_t tabuleiro, char cor) {
  for (Peca_t peca : tabuleiro.get_tabuleiro()) {
    if (peca.get_cor() == cor) {
      _numCapturas = 0; _numCapturasMax = 0;
      _posRemover.clear(); _posRemoverMax.clear();
      this->conta_jogadas(tabuleiro, peca);
      
    }
  }
}