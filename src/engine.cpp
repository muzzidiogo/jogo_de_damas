#include "../include/engine.hpp"

bool Engine::conta_jogadas(Tabuleiro_t tabuleiro, Peca_t peca) {
    unsigned int linha = peca.get_posicao().linha;
    unsigned int coluna = peca.get_posicao().coluna;
    char cor = peca.get_cor();
    char outraCor = 'b';
    if (cor == 'b') outraCor = 'p';

    if (linha - 2 >= 0 && coluna - 2 >= 0 &&
      tabuleiro.verifica_validade_movimento_casas(peca.get_posicao(), {-1, -1}, outraCor)) { 
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t(); //cria um tabuleiro novo para fazer as modificað§ðµes necessð¡rias para a contagem
        tabuleiroNovo.copia_tabuleiro(tabuleiro);
        tabuleiroNovo.captura_peca(peca, {linha - 1, coluna - 1}, {-2, -2}); //serð¡ que a peð§a vai alterar sua posið§ð£o???
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(conta_jogadas(tabuleiroNovo, peca)) return 1;    
    }

    if (linha + 2 < 8 && coluna + 2 < 8 && 
      tabuleiro.verifica_validade_movimento_casas(peca.get_posicao(), {1, 1}, outraCor)) { 
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
        tabuleiroNovo.copia_tabuleiro(tabuleiro);
        tabuleiroNovo.captura_peca(peca, {linha + 1, coluna + 1}, {2, 2});
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(conta_jogadas(tabuleiroNovo, peca)) return 1;    
    }

    if (linha + 2 < 8 && coluna - 2 >= 0  &&   
      tabuleiro.verifica_validade_movimento_casas(peca.get_posicao(), {1, -1}, outraCor)){ 
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
        tabuleiroNovo.copia_tabuleiro(tabuleiro);
        tabuleiroNovo.captura_peca(peca, {linha + 1, coluna - 1}, {2, -2});
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(conta_jogadas(tabuleiroNovo, peca)) return 1;    
    }
    
    if (linha - 2 >= 0 && coluna + 2 < 8  &&
      tabuleiro.verifica_validade_movimento_casas(peca.get_posicao(), {-1, 1}, outraCor)) { 
        Tabuleiro_t tabuleiroNovo = Tabuleiro_t();
        tabuleiroNovo.copia_tabuleiro(tabuleiro);
        tabuleiroNovo.captura_peca(peca, {linha - 1, coluna + 1}, {-2, 2});
        quantidadeDeJogadas++;

        if (quantidadeDeJogadas > quantidadeDeJogadasMax) quantidadeDeJogadasMax = quantidadeDeJogadas;
        if(conta_jogadas(tabuleiroNovo, peca)) return 1;            
    }

    quantidadeDeJogadas--;
    return 0;    
}

void Engine::roda_engine(Tabuleiro_t tabuleiro, char cor) {
  for (unsigned int i = 0; i < tabuleiro.get_tabuleiro().size(); i++) {
    if (tabuleiro.get_tabuleiro()[i].get_cor() == cor) {
      quantidadeDeJogadas = 0;
      quantidadeDeJogadasMax = 0;
      this->conta_jogadas(tabuleiro, tabuleiro.get_tabuleiro()[i]);
      tabuleiro.get_tabuleiro()[i].set_quantidadeJogadas(quantidadeDeJogadasMax);
    }
  }
}

Peca_t Engine::get_maior(Tabuleiro_t tabuleiro, char cor) {
  Peca_t maior;
  maior.set_quantidadeJogadas(-1);

  for (Peca_t peca : tabuleiro.get_tabuleiro()) {
    if (peca.get_cor() == cor && 
      peca.get_quantidadeJogadas() > maior.get_quantidadeJogadas()) {
      
      maior = peca;
    } 
  }
  
  return maior;
}