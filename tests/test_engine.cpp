#include <vector>
#include "../third_party/doctest.h"
#include "../include/engine.hpp"
#include "../include/tabuleiro.hpp"

TEST_CASE("Teste de declaração dos resultados Tabuleiro Inicial") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    char cor = 'b';
    Engine engine;
    PecaPorCapturas_t *pTest = engine.get_maior(tabuleiro, cor);
    CHECK_EQ(0, pTest->posRemover->size());
}

TEST_CASE("Teste 2") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{1,5})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    char cor = 'b';
    Engine engine;
    PecaPorCapturas_t *pTest = engine.get_maior(tabuleiro, cor);
    CHECK_EQ(0, pTest->posRemover->size());
}
