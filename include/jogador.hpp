#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "../include/interface.hpp"

class Jogador_t {
    private:
        InterfaceGrafica* _interface;
    public:
        Jogador_t(InterfaceGrafica* interface);
        bool jogar();
};

#endif //JOGADOR_HPP