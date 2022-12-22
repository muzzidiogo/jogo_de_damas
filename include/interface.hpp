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
        std::array<std::string,3> _memJogadas = {"","",""};

        /// @brief Essa função adiciona a quantidade de capturas
        void somar_placar_capturas();

        /// @brief Essa função adiciona ao placar do jogador X
        void somar_placar_rodadas();

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

        /// @brief Essa função realça o comando do menu escolhido 
        /// @param opcao A opção que está sendo escolhida
        void realcar_menu(unsigned int opcao);

        /// @brief Adiciona uma jogada na memoria de jogadas para ser apresentada
        /// @param jogada string da jogada que será armazenada
        void adicionar_jogada(std::string jogada);

        /// @brief Apaga a memória de jogadas 
        void reiniciar();

        /// @brief Retorna o ponteiro da janela produzida 
        /// @return
        WINDOW* get_win();

        
        /// @brief Retorna quantidade max de linhas
        /// @return
        int get_linhas();
        
        /// @brief Retorna quantidade max de colunas 
        /// @return
        int get_colunas();

        /// @brief reinicia o placar de rodadas para 0x0
        void reiniciar_placar();

        /// @brief Escreve uma mensagem de erro na interface
        /// @param mensagem mensagem que irá aparecer na interface
        void mensagem_de_erro(char const * mensagem);
        
        /// @brief Escreve uma mensagem na interface
        /// @param mensagem mensagem que irá aparecer na interface
        /// @param cor cor da mensagem que terá seu display
        void mensagem(char const * mensagem, int cor);

        ~InterfaceGrafica();
};

#endif //INTERFACE_HPP
