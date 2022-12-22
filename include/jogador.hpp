#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "../include/interface.hpp"
#include "../include/engine.hpp"

class Jogador_t {
    private:
        InterfaceGrafica* _interface;
        Tabuleiro_t* _tabuleiro;
        Engine* _engine;

        /// @brief verifica se o comando enviado é valido ou não
        /// @param comando string produzida na leitura do comando
        /// @param peca peca que irá se mover que será gerada do comando
        /// @param posFinal posicao final da peca que será gerada do comando
        /// @return true para valido e false para invalido
        bool verifica_comando(std::string comando, int* index, Posicao_t* posFinal);
    public:
        /// @brief Construtor
        /// @param interface ponteiro para a interface
        /// @param tabuleiro ponteiro para o tabuleiro do jogo
        /// @param engine ponteiro para a engine do jogo
        Jogador_t(InterfaceGrafica* interface, Tabuleiro_t* tabuleiro, Engine* engine);

        /// @brief Por meio dessa função o jogador interage com a interface e faz
        ///         seu movimento
        /// @return true para continuar o jogo e false para sair do jogo
        bool jogar();
};

#endif //JOGADOR_HPP