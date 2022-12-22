#include "../third_party/doctest.h"
#include "../include/peca.hpp"

TEST_CASE("Construtor Peça"){
    Posicao_t pos;
    pos.linha = 0;
    pos.coluna = 0;
    Peca_t p = Peca_t(Cores::BRANCO, pos);

    CHECK_EQ(pos.linha, p.get_posicao().linha);
    CHECK_EQ(pos.coluna, p.get_posicao().coluna);
    CHECK_EQ(Cores::BRANCO, p.get_cor());
}

TEST_CASE("Andar Peça"){
    Posicao_t pos = {0,0};
    Peca_t p = Peca_t(Cores::BRANCO, pos);

    Posicao_t novaPos1 = {1,1}; //Posicao valida
    p.andar(novaPos1);
    CHECK_EQ(1, p.get_posicao().linha);
    CHECK_EQ(1, p.get_posicao().coluna);

    Posicao_t novaPos2 = {1,1}; //Posicao invalida => a peca nao move
    p.andar(novaPos2);
    CHECK_EQ(1, p.get_posicao().linha);
    CHECK_EQ(1, p.get_posicao().coluna);

    Posicao_t novaPos3 = {2,0};//Posicao valida
    p.andar(novaPos3);
    CHECK_EQ(2, p.get_posicao().linha);
    CHECK_EQ(0, p.get_posicao().coluna);
}