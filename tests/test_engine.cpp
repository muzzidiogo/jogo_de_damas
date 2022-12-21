#include <vector>
#include "../third_party/doctest.h"
#include "../include/engine.hpp"
#include "../include/tabuleiro.hpp"

TEST_CASE("Teste sem captura 1") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    Engine engine;

    Peca_t peca;
    std::vector<Posicao_t> capturas;
    engine.get_maior(tabuleiro, Cores::BRANCO, peca, capturas);
    CHECK_EQ(0, capturas.size());
}

TEST_CASE("Teste Sem Captura 2") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{1,5})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    Peca_t peca;
    std::vector<Posicao_t> capturas;
    engine.get_maior(tabuleiro, Cores::BRANCO, peca, capturas);

    CHECK_EQ(capturas.size(), 0);
    CHECK_EQ(peca.get_posicao().linha, NovoTabuleiro[1].get_posicao().linha);
    CHECK_EQ(peca.get_posicao().coluna, NovoTabuleiro[1].get_posicao().coluna);
} 

TEST_CASE("Teste com captura 1") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{2,2})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    Peca_t peca;
    std::vector<Posicao_t> capturas;
    engine.get_maior(tabuleiro, Cores::BRANCO, peca, capturas);

    CHECK_EQ(capturas.size(), 1);
    CHECK_EQ(capturas[0].linha, NovoTabuleiro[0].get_posicao().linha);
    CHECK_EQ(capturas[0].coluna, NovoTabuleiro[0].get_posicao().coluna);
    CHECK_EQ(peca.get_posicao().linha, NovoTabuleiro[1].get_posicao().linha);
    CHECK_EQ(peca.get_posicao().coluna, NovoTabuleiro[1].get_posicao().coluna);
}

TEST_CASE("Teste com captura 2") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::BRANCO,Posicao_t{1,1}), 
                                         Peca_t(Cores::PRETO,Posicao_t{2,2}),
                                         Peca_t(Cores::PRETO,Posicao_t{4,4}),
                                         Peca_t(Cores::BRANCO, Posicao_t{7, 7}), //mao deve escolher esse caminho
                                         Peca_t(Cores::PRETO, Posicao_t{6, 6}),
                                         Peca_t(Cores::PRETO,Posicao_t{4,6}),
                                         Peca_t(Cores::PRETO,Posicao_t{2,6})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    Peca_t peca;
    std::vector<Posicao_t> capturas;
    engine.get_maior(tabuleiro, Cores::BRANCO, peca, capturas);

    CHECK_EQ(capturas.size(), 4);
    CHECK_EQ(capturas[0].linha, NovoTabuleiro[1].get_posicao().linha);
    CHECK_EQ(capturas[0].coluna, NovoTabuleiro[1].get_posicao().coluna);
    CHECK_EQ(capturas[1].linha, NovoTabuleiro[2].get_posicao().linha);
    CHECK_EQ(capturas[1].coluna, NovoTabuleiro[2].get_posicao().coluna);
    CHECK_EQ(capturas[2].linha, NovoTabuleiro[5].get_posicao().linha);
    CHECK_EQ(capturas[2].coluna, NovoTabuleiro[5].get_posicao().coluna);
    CHECK_EQ(capturas[3].linha, NovoTabuleiro[6].get_posicao().linha);
    CHECK_EQ(capturas[3].coluna, NovoTabuleiro[6].get_posicao().coluna);
    CHECK_EQ(peca.get_posicao().linha, NovoTabuleiro[0].get_posicao().linha);
    CHECK_EQ(peca.get_posicao().coluna, NovoTabuleiro[0].get_posicao().coluna);
}
