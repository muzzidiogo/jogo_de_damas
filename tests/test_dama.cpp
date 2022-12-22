#include "../third_party/doctest.h"
#include "../include/dama.hpp"

TEST_CASE("Construtor Dama + getters"){
    Posicao_t pos;
    pos.linha = 1;
    pos.coluna = 0;
    Dama d = Dama(BRANCO, pos);

    CHECK_EQ(pos.linha, d.get_posicao().linha);
    CHECK_EQ(pos.coluna, d.get_posicao().coluna);
    CHECK_EQ(0, d.get_cor());
}

TEST_CASE("Andar Dama"){
    Posicao_t pos;
    pos.linha = 0;
    pos.coluna = 0;
    Dama d = Dama(BRANCO, pos);

    Posicao_t novaPos1 = {4,4};//Posicao valida
    d.andar(novaPos1);
    CHECK_EQ(4, d.get_posicao().linha);
    CHECK_EQ(4, d.get_posicao().coluna);

    Posicao_t novaPos2 = {5, 2}; //Posicao invalida => dama nao se move
    d.andar(novaPos2);
    CHECK_EQ(4, d.get_posicao().linha);
    CHECK_EQ(4, d.get_posicao().coluna);

    Posicao_t novaPos3 = {6, 2}; //Posicao invalida => dama nao se move
    d.andar(novaPos3);
    CHECK_EQ(6, d.get_posicao().linha);
    CHECK_EQ(2, d.get_posicao().coluna);
}