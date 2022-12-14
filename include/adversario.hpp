#ifndef ADVERSARIO_HPP
#define ADVERSARIO_HPP

#include "engine.hpp"

class Adversario_t {
private:
    Tabuleiro_t *_tabuleiro;
    Engine *_engine;
public:
    Adversario_t(Tabuleiro_t *tabuleiro, Engine *engine);
    void jogar();
};

#endif //ADVERSARIO_HPP