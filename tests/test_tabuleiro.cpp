#include "../third_party/doctest.h"
#include "../include/tabuleiro.hpp"

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