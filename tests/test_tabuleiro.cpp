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