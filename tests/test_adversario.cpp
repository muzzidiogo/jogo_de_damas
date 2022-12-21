#include "../third_party/doctest.h"
#include "../include/adversario.hpp"

TEST_CASE("Teste Sem Captura 1") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{1,5})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    Peca_t peca;
    std::vector<Posicao_t> capturas;
    Adversario_t adversarioTeste = Adversario_t(&tabuleiro, &engine);
    adversarioTeste.jogar();
    CHECK_EQ(tabuleiro.get_tabuleiro()[0].get_posicao().coluna, 2);
    CHECK_EQ(tabuleiro.get_tabuleiro()[0].get_posicao().linha, 2);
}

TEST_CASE("Teste Com Captura 1") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{2,2}),
                                         Peca_t(Cores::BRANCO,Posicao_t{4,4}),
                                         Peca_t(Cores::PRETO, Posicao_t{7, 7}), //mao deve escolher esse caminho
                                         Peca_t(Cores::BRANCO, Posicao_t{6, 6}),
                                         Peca_t(Cores::BRANCO,Posicao_t{4,6}),
                                         Peca_t(Cores::BRANCO,Posicao_t{2,6})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    Peca_t peca;
    std::vector<Posicao_t> capturas;
    Adversario_t adversarioTeste = Adversario_t(&tabuleiro, &engine);
    adversarioTeste.jogar();
    CHECK_EQ(tabuleiro.get_tabuleiro().size(), 3);
    CHECK_EQ(tabuleiro.get_tabuleiro()[0].get_posicao().coluna, 5);
    CHECK_EQ(tabuleiro.get_tabuleiro()[0].get_posicao().linha, 1);
} 