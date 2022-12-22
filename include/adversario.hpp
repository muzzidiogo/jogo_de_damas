#ifndef ADVERSARIO_HPP
#define ADVERSARIO_HPP

#include "engine.hpp"

class Adversario_t {
private:
    Tabuleiro_t *_tabuleiro;
    Engine *_engine;
public:
    /// @brief Construtor
    /// @param tabuleiro ponteiro para o tabuleiro do jogo
    /// @param engine ponteiro para a engine do jogo
    Adversario_t(Tabuleiro_t *tabuleiro, Engine *engine);

    /// @brief Por meio dessa função o adversário faz seu movimento
    void jogar();
};

#endif //ADVERSARIO_HPP