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

    if (_numCapturas > quantidadeDeJogadasMax) {
      quantidadeDeJogadasMax = _numCapturas;
      pecasRemoverMax = pecasRemover;
    }
    if(conta_jogadas(*tabuleiroNovo, peca)) return 1;
    delete tabuleiroNovo;    
  }

  if (tabuleiro.verifica_validade_captura(peca, {1, 1})) { 
      Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
      tabuleiroNovo.copia_tabuleiro(tabuleiro);
      tabuleiroNovo.captura_peca(peca, {linha + 1, coluna + 1}, {2, 2});
      quantidadeDeJogadas++;

      if (quantidadeDeJogadas > quantidadeDeJogadasMax) {
        quantidadeDeJogadasMax = quantidadeDeJogadas;
        pecasRemoverMax = pecasRemover;
      }
      if(conta_jogadas(tabuleiroNovo, peca)) return 1;    
  }

  if (tabuleiro.verifica_validade_captura(peca, {1, -1})){ 
      Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
      tabuleiroNovo.copia_tabuleiro(tabuleiro);
      tabuleiroNovo.captura_peca(peca, {linha + 1, coluna - 1}, {2, -2});
      quantidadeDeJogadas++;

      if (quantidadeDeJogadas > quantidadeDeJogadasMax) {
        quantidadeDeJogadasMax = quantidadeDeJogadas;
        pecasRemoverMax = pecasRemover;
      }
      if(conta_jogadas(tabuleiroNovo, peca)) return 1;    
  }
  
  if (tabuleiro.verifica_validade_captura(peca, {-1, 1})) { 
      Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
      tabuleiroNovo.copia_tabuleiro(tabuleiro);
      tabuleiroNovo.captura_peca(peca, {linha - 1, coluna + 1}, {-2, 2});
      quantidadeDeJogadas++;
      
      if (quantidadeDeJogadas > quantidadeDeJogadasMax) {
        quantidadeDeJogadasMax = quantidadeDeJogadas;
        pecasRemoverMax = pecasRemover;
      }
      if(conta_jogadas(tabuleiroNovo, peca)) return 1;            
  }

  quantidadeDeJogadas--;
  return 0;    
}

void Engine::roda_engine(Tabuleiro_t tabuleiro, char cor) {
  for (unsigned int i = 0; i < tabuleiro.get_tabuleiro().size(); i++) {
    if (tabuleiro.get_tabuleiro()[i].get_cor() == cor) {
      quantidadeDeJogadas = 0; quantidadeDeJogadasMax = 0;
      pecasRemover.clear(); pecasRemoverMax.clear();
      this->conta_jogadas(tabuleiro, tabuleiro.get_tabuleiro()[i]);
      tabuleiro.get_tabuleiro()[i].set_quantidadeJogadas(quantidadeDeJogadasMax);
      tabuleiro.get_tabuleiro()[i].set_pecasRemover(pecasRemoverMax);
    }
  }
}

Peca_t Engine::get_maior(Tabuleiro_t tabuleiro, char cor) {
  this->roda_engine(tabuleiro, cor);

  Peca_t maior = Peca_t(Cores::PRETO, {1, 1}); //definicao de peca inicial para comparacoes
  maior.set_quantidadeJogadas(-1);
  for (Peca_t peca : tabuleiro.get_tabuleiro()) {
    if (peca.get_cor() == cor && 
      peca.get_quantidadeJogadas() > maior.get_quantidadeJogadas()) maior = peca; 
  }
  
  return maior;
}