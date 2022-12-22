#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "../include/interface.hpp"

class Jogador_t {
    private:
        InterfaceGrafica* _interface;
    public:
        /// @brief Construtor
        /// @param interface ponteiro para a interface
        Jogador_t(InterfaceGrafica* interface);

        /// @brief Por meio dessa função o jogador interage com a interface e faz
        ///         seu movimento
        /// @return true para continuar o jogo e false para sair do jogo
        bool jogar();
};

#endif //JOGADOR_HPP