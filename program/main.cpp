#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <fstream>
#include "../include/tabuleiro.hpp"

//================ DEFINE ================
#define LINHAS 18
#define COLUNAS 74
#define VERMELHO 1
#define VERDE 2
const char *CLEAR_LINES = "                                                                        ";
const char *SMALL_CLEAR = "                              ";
// FIM DEFINE ============================

/// @brief Essa função desenha na tela o tabuleiro e a caixa da janela
/// @param win Equivale a um ponteiro apontando para a janela sendo usada na interface
/// @param pontoInicial Equivale ao tamanho calculado da janela quando inicializada
/// @param tabuleiro Equivale ao tabuleiro do jogo de damas sendo rodado
void desenhar(WINDOW *win, int pontoInicial, Tabuleiro_t &tabuleiro) {
    box(win, 0, 0);
    wrefresh(win);

    //Gerar o MENU
    wattron(win, A_STANDOUT);
    mvwprintw(win, 0, 30, "JOGO DE DAMAS");
    wattroff(win, A_STANDOUT);
    mvwprintw(win, 0, 2, "Reiniciar");
    mvwprintw(win, 0, 12, "Info");
    mvwprintw(win, 0, 17, "Sair");

    int inicio = pontoInicial/13;

    // Gerar o Tabuleiro Vazio
    for(int linha = inicio; linha<inicio+8; linha++) {
        for(int coluna = inicio; coluna<inicio+8; coluna++) {
            if((linha%2 != 0 && coluna%2 != 0) || ((linha%2 == 0 && coluna%2 == 0))) {
                wattron(win, A_STANDOUT);
                mvwprintw(win, linha, coluna+(3*(coluna)), "___");
                wattroff(win, A_STANDOUT);
            } 
            else {
                mvwprintw(win, linha, coluna+(3*(coluna)), "___");
            } 
        }
    }

    // Colocar as Pecas do Tabuleiro na interface
    for(Peca_t peca : tabuleiro.get_tabuleiro()) {
        int linha = peca.get_posicao().linha+inicio;
        int coluna = peca.get_posicao().coluna+inicio;
        if(peca.get_cor() == Cores::PRETO) {
            wattron(win, A_STANDOUT);
            mvwprintw(win, linha, coluna+(3*(coluna)), "_O_");
            wattroff(win, A_STANDOUT);
        }
        else if(peca.get_cor() == Cores::BRANCO) {
            wattron(win, A_STANDOUT);
            mvwprintw(win, linha, coluna+(3*(coluna)), "_X_");
            wattroff(win, A_STANDOUT);
        }
    }

    wattron(win, COLOR_PAIR(VERDE));
    mvwprintw(win, (LINHAS-2), 1, "Para informações aperte duas vezes 'i'");
    wattroff(win, COLOR_PAIR(VERDE));
}

/// @brief Apaga toda a tela para poder escrever de novo
/// @param win Equivale a um ponteiro apontando para a janela sendo usada na interface
void ApagarTela(WINDOW *win) {
    for(int i=1; i<(LINHAS-1);i++) {
        mvwprintw(win, i, 1, "%s", CLEAR_LINES);
    }
}

/// @brief Desenha as informações do jogo na janela
/// @param win Equivale a um ponteiro apontando para a janela sendo usada na interface 
void desenhar_info(WINDOW *win) {
    wrefresh(win);
    box(win, 0,0);
    mvwprintw(win, 0, 2, "Retornar");
    ApagarTela(win);

    std::ifstream fileInfo("info.txt");
    if(fileInfo.is_open()) {
        std::string linha;
        for(int i=1; i<(LINHAS-1); i++) {
            if(getline(fileInfo, linha)) mvwprintw(win, i, 1, "%s", linha.c_str());
        }
        fileInfo.close();
    }

    char ch;
    bool retornar=false;
    while((ch = wgetch(win))){
        if(ch == 'r') {
            if(!retornar) {
                retornar=true;
                wattron(win, A_STANDOUT);
                mvwprintw(win, 0, 2, "Retornar");
                wattroff(win, A_STANDOUT);
            }
            else return;
        }
    }
}

/// @brief Lê uma linha no terminal para a obtenção da jogada
/// @param win Equivale a um ponteiro apontando para a janela sendo usada na interface
/// @param pontoYinicial Linha inicial de escrita 
/// @param pontoXinicial Coluna inicial de escrita
/// @return Retorna uma string equivalente ao comando lido no teminal, se retornar 
///         vazio quer dizer que saiu-se do comando de leitura
std::string LerComando(WINDOW *win, int pontoYinicial, int pontoXinicial) {
    char ch = ' ';
    std::string linha;
    while(ch != '\n') {
        ch = wgetch(win);
        // DELETAR CARACTERES
        if(ch == '-') {
            if(linha.size() > 0) linha.pop_back();
        }
        // SAIR DA FUNÇÃO
        else if(ch == '!') {
            return "";
        }
        else {
            linha.push_back(ch);
        }
        const char *linha_c = linha.c_str();
        // SE O COMANDO NÃO FOR VÁLIDO ESCREVER EM VERMELHO
        if(linha[0] != 'm' && linha[0] != 'c') {
            wattron(win, COLOR_PAIR(VERMELHO));
            mvwprintw(win,pontoYinicial, pontoXinicial, "%s", linha_c);
            mvwprintw(win,pontoYinicial, pontoXinicial+linha.size(), "%s", SMALL_CLEAR);
            wattroff(win, COLOR_PAIR(VERMELHO));
        }
        else {
            mvwprintw(win,pontoYinicial, pontoXinicial, "%s", linha_c);
            mvwprintw(win,pontoYinicial, pontoXinicial+linha.size(), "%s", SMALL_CLEAR); 
        }
    }
    return linha;
}

int main(int argc, char const *argv[]) {
    Tabuleiro_t tabuleiro = Tabuleiro_t();

    // GERAR JANELA ======================
    initscr();
    noecho();
    curs_set(0);
    WINDOW *win = newwin(LINHAS,COLUNAS, 4, 10);
    desenhar(win, COLUNAS, tabuleiro);
    //====================================

    // VARIÁVEIS PARA O MENU
    bool reiniciar = false;
    bool sair = false;
    bool info = false;
    // =====================
    // INICIALIZAR CORES
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    // =====================

    wattron(win, COLOR_PAIR(VERDE));
    mvwprintw(win, (LINHAS-3), 1, "Para começar sua jogada aperte 'j'");
    wattroff(win, COLOR_PAIR(VERDE));

    char ch;
    bool LOOP = true;
    while(LOOP) {
        ch = wgetch(win);
        switch (ch)
        {
        case 'r':  // COMANDO REINICIAR
            sair = false;
            info = false;
            if(!reiniciar) {
                wattron(win, A_STANDOUT);
                mvwprintw(win, 0, 2, "Reiniciar");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, 0, 12, "Info");
                mvwprintw(win, 0, 17, "Sair");
                reiniciar = true;
            }
            else {
                tabuleiro = Tabuleiro_t();
                desenhar(win, COLUNAS, tabuleiro);
                reiniciar = false;
            }
            break;
        
        case 'i':   // COMANDO INFORMAÇÕES 
            sair = false;
            reiniciar = false;
            if(!info) {
                wattron(win, A_STANDOUT);
                mvwprintw(win, 0, 12, "Info");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, 0, 2, "Reiniciar");
                mvwprintw(win, 0, 17, "Sair");
                info = true;
            }
            else {
                info = false;
                desenhar_info(win);
                ApagarTela(win);
                desenhar(win, COLUNAS, tabuleiro);
            }
            break;

        case 's':   //  COMANDO SAIR
            reiniciar=false;
            info=false;
            if(!sair) {
                wattron(win, A_STANDOUT);
                mvwprintw(win, 0, 17, "Sair");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, 0, 2, "Reiniciar");
                mvwprintw(win, 0, 12, "Info");
                sair = true;
            }
            else {
                LOOP = false;
            }
            break;

        case  'j':  //  COMANDO JOGAR
        {
            // Reiniciar elementos
            sair=false;
            reiniciar=false;
            info=false;
            mvwprintw(win, 0, 2, "Reiniciar");
            mvwprintw(win, 0, 12, "Info");
            mvwprintw(win, 0, 17, "Sair");
            mvwprintw(win, (LINHAS-3), 1, "%s", CLEAR_LINES);
            // ======================
            
            mvwprintw(win, (LINHAS-3), 1, "Jogada: ");
            std::string comando = LerComando(win, (LINHAS-3), 10);
            mvwprintw(win, (LINHAS-3), 1, "%s", CLEAR_LINES);
            if(comando.size() == 10 || comando == "") {
                mvwprintw(win, 1, COLUNAS-comando.size(), "%s", comando.c_str());
            }
            else {
                wattron(win, COLOR_PAIR(VERMELHO));
                mvwprintw(win, (LINHAS-3), 1, "Comando inválido, tente novamente");              
                wattroff(win, COLOR_PAIR(VERMELHO));
            }

            desenhar(win, COLUNAS, tabuleiro);
        }
        break; 
        
        default:
            mvwprintw(win, 0, 2, "Reiniciar");
            mvwprintw(win, 0, 12, "Info");
            mvwprintw(win, 0, 17, "Sair");
            break;
        }
    }

    endwin();
    return 0;
}
