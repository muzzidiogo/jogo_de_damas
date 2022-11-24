#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <ncurses.h>
#include <string>
#include <array>
#include <fstream>
#include "../include/tabuleiro.hpp"

//================ DEFINE ================
const int VERMELHO = 1;
const int VERDE = 2;
const std::string CLEAR_LINES = "                                                                                   ";
const std::string SMALL_CLEAR = "                           ";
enum Menu {Reiniciar=0, Info=1, Sair=2, Default=3};
enum Jogador {O=0,X=1};
// FIM DEFINE ============================


class InterfaceGrafica {
    private:
        WINDOW *_win;
        int _linhas, _colunas;
        std::array<int, 2> _placarRodadas = {0,0};
        std::array<int, 2> _placarCapturas = {0,0};
        Tabuleiro_t* _tabuleiro;
        std::array<std::string,2> _memJogadas = {"",""};

    public:
        /// @brief Construtor
        /// @param tabuleiro ponteiro para o tabuleiro do jogo 
        /// @param linhas quantidade de linhas que a interface deve ter
        /// @param colunas quantidade de colunas que a interface deve ter
        InterfaceGrafica(Tabuleiro_t *tabuleiro, unsigned int linhas, unsigned int colunas);

        /// @brief Desenha a página principal da interface gráfica
        void desenhar_main();

        /// @brief Desenha a página de informações da interface gráfica
        void desenhar_info();

        /// @brief apaga a tela de interface
        void apagar_tela();

        /// @brief Lê o comando dado pelo jogador
        /// @return Retorna uma string com o comando dado pelo indivíduo
        std::string ler_comando();

        /// @brief Essa função adiciona ao placar do jogador X
        /// @param jogador Jogador que estará tendo seu placar somado
        /// @param valor Um unsigned int equivalente ao valor que será somado
        void somarPlacarRodadas(int jogador,unsigned int valor);

        /// @brief Essa função adiciona ao placar do jogador X
        /// @param jogador Jogador que estará tendo seu placar somado
        /// @param valor Um unsigned int equivalente ao valor que será somado
        void somarPlacarCapturas(int jogador, unsigned int valor);

        /// @brief Essa função realça o comando do menu escolhido 
        /// @param opcao A opção que está sendo escolhida
        void realcar_menu(unsigned int opcao);

        /// @brief Adiciona uma jogada na memoria de jogadas para ser apresentada
        /// @param jogada string da jogada que será armazenada
        void adicionar_jogada(std::string jogada);

        /// @brief Reinicia a jogada 
        void reiniciar_rodada();

        /// @brief Retorna o ponteiro da janela produzida 
        /// @return
        WINDOW* get_Win();

        ~InterfaceGrafica();
};

#endif //INTERFACE_HPP
