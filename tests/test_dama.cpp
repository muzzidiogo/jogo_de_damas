#include "../third_party/doctest.h"
#include "../include/dama.hpp"

TEST_CASE("Construtor Dama"){
    Posicao_t pos;
    pos.linha = 1;
    pos.coluna = 0;
    Dama d = Dama(BRANCO, pos);
    d.set_quantidadeJogadas(0);

    CHECK_EQ(pos.linha, d.get_posicao().linha);
    CHECK_EQ(pos.coluna, d.get_posicao().coluna);
    CHECK_EQ(0, d.get_cor());
    CHECK_EQ(0, d.get_quantidadeJogadas());
}