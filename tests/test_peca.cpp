/* #include "../third_party/doctest.h"
#include "../include/peca.hpp"

TEST_CASE("Construtor e set_quantidadeJogadas Peça"){
    Posicao_t pos;
    pos.linha = 1;
    pos.coluna = 0;
    Peca_t p = Peca_t(0, pos);
    p.set_quantidadeJogadas(0);

    CHECK_EQ(pos.linha, p.get_posicao().linha);
    CHECK_EQ(pos.coluna, p.get_posicao().coluna);
    CHECK_EQ(0, p.get_cor());
    CHECK_EQ(0, p.get_quantidadeJogadas());
} */