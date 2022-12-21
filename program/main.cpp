#include <iostream>
#include "../include/tabuleiro.hpp"
#include "../include/engine.hpp"
#include "../include/adversario.hpp"
#include "../include/interface.hpp"
#include "../include/jogador.hpp"

//================ DEFINE ================
#define LINHAS 18
#define COLUNAS 85
// FIM DEFINE ============================

int main(int argc, char const *argv[]) {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    Engine engine = Engine();
    Adversario_t adversario = Adversario_t(&tabuleiro, &engine);

    // GERAR JANELA ======================
    InterfaceGrafica interface = InterfaceGrafica(&tabuleiro, LINHAS, COLUNAS);
    //====================================
    
    Jogador_t jogador = Jogador_t(&interface);
    
    bool loopJogo = true;
    int jogadorAtivo = Jogador::X;
    while(loopJogo){
        switch (jogadorAtivo)
        {
        case Jogador::X:
            loopJogo = jogador.jogar();
            jogadorAtivo = Jogador::O;
            break;
        
        case Jogador::O:
            adversario.jogar();
            interface.desenhar_main();
            jogadorAtivo = Jogador::X;
            break;
        
        default:
            break;
        }
    }
    jogador.jogar();
    return 0;
}
