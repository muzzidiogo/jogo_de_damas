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
    Posicao_t novaPos = {1,1};
    Peca_t p = Peca_t(Cores::BRANCO, pos);
    p.andar(novaPos);

    CHECK_EQ(novaPos.linha, p.get_posicao().linha);
    CHECK_EQ(novaPos.coluna, p.get_posicao().coluna);
}