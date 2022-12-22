#include "../third_party/doctest.h"
#include "../include/tabuleiro.hpp"
#include <iostream>

TEST_CASE("TESTANDO O CONSTRUTOR") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    CHECK_EQ(24, tabuleiro.get_tabuleiro().size());
    int peca = 0;
    for(unsigned int i = 0; i<3; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                CHECK_EQ(i, tabuleiro.get_tabuleiro()[peca].get_posicao().linha);
                CHECK_EQ(j, tabuleiro.get_tabuleiro()[peca].get_posicao().coluna);
                peca++;
            }
        }
    }
    for(unsigned int i = 5; i<8; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                CHECK_EQ(i, tabuleiro.get_tabuleiro()[peca].get_posicao().linha);
                CHECK_EQ(j, tabuleiro.get_tabuleiro()[peca].get_posicao().coluna);
                peca++;
            }
        }
    }
}

TEST_CASE("TESTANDO remove_peca") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    bool tester=false;
    Posicao_t posTeste{0,6};
    tabuleiro.remover_peca(posTeste);
    for (Peca_t peca : tabuleiro.get_tabuleiro()) {
        if((peca.get_posicao().coluna == posTeste.coluna) 
            && (peca.get_posicao().linha == posTeste.linha)){
            tester=true;
        }
    }
    CHECK_EQ(false, tester);
}

TEST_CASE("TESTANDO verifica_posicao") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    CHECK_EQ(false, tabuleiro.verificar_posicao({4,4}));
    CHECK_EQ(false, tabuleiro.verificar_posicao({3,1}));
    CHECK_EQ(true, tabuleiro.verificar_posicao({0,0}));
    CHECK_EQ(true, tabuleiro.verificar_posicao({7,7}));
}

TEST_CASE("TESTANDO verificar_pos_saiu_tabuleiro") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    CHECK_EQ(false, tabuleiro.verificar_pos_saiu_tabuleiro({4,4}));
    CHECK_EQ(false, tabuleiro.verificar_pos_saiu_tabuleiro({3,1}));
    CHECK_EQ(false, tabuleiro.verificar_pos_saiu_tabuleiro({2,2}));
    CHECK_EQ(true, tabuleiro.verificar_pos_saiu_tabuleiro({10,0}));
    CHECK_EQ(true, tabuleiro.verificar_pos_saiu_tabuleiro({7,8}));
}

TEST_CASE("TESTANDO set_tabuleiro_testes") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{1,5})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    CHECK_EQ(2, tabuleiro.get_tabuleiro().size());
    CHECK_EQ(Peca_t(Cores::PRETO,Posicao_t{1,1}), tabuleiro.get_tabuleiro()[0]);
    CHECK_EQ(Peca_t(Cores::BRANCO,Posicao_t{1,5}), tabuleiro.get_tabuleiro()[1]);
}

TEST_CASE("TESTANDO copia_tabuleiro") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{1,5})};
    Tabuleiro_t tabuleiroAntigo = Tabuleiro_t();
    tabuleiroAntigo.set_tabuleiro_testes(NovoTabuleiro);
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.copia_tabuleiro(tabuleiroAntigo);
    CHECK_EQ(2, tabuleiro.get_tabuleiro().size());
    CHECK_EQ(Peca_t(Cores::PRETO,Posicao_t{1,1}), tabuleiro.get_tabuleiro()[0]);
    CHECK_EQ(Peca_t(Cores::BRANCO,Posicao_t{1,5}), tabuleiro.get_tabuleiro()[1]);
}

TEST_CASE("TESTANDO verifica_validade_captura") {
    Tabuleiro_t tabuleiro;
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{4,4}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{5,5})};
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    bool test = tabuleiro.verifica_validade_captura(tabuleiro.get_tabuleiro()[1], {-1,-1});
    bool test2 = tabuleiro.verifica_validade_captura(tabuleiro.get_tabuleiro()[0], {1,1});
    bool test3 = tabuleiro.verifica_validade_captura(tabuleiro.get_tabuleiro()[1], {-1,1});
    CHECK_EQ(true, test);
    CHECK_EQ(true, test2);
    CHECK_EQ(false, test3);

}

TEST_CASE("Teste de criacao de dama") {
    Tabuleiro_t tabuleiro;
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::BRANCO,Posicao_t{6,6})};
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    tabuleiro.atualizar_tabuleiro({7, 7}, tabuleiro.get_tabuleiro()[0]);

    CHECK_EQ(tabuleiro.get_tabuleiro()[0].get_posicao().linha, 7);
    CHECK_EQ(tabuleiro.get_tabuleiro()[0].get_posicao().coluna, 7);
    CHECK_EQ(tabuleiro.get_tabuleiro().size(), 1);
    CHECK(tabuleiro.get_tabuleiro()[0].e_dama());
}