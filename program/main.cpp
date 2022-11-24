#include <iostream>
#include "../include/tabuleiro.hpp"
#include "../include/interface.hpp"

//================ DEFINE ================
#define LINHAS 18
#define COLUNAS 85
// FIM DEFINE ============================

int main(int argc, char const *argv[]) {
    Tabuleiro_t tabuleiro = Tabuleiro_t();

    // GERAR JANELA ======================
    InterfaceGrafica interface = InterfaceGrafica(&tabuleiro, LINHAS, COLUNAS);
    WINDOW* win = interface.get_Win();
    //====================================

    // VARIÁVEIS PARA O MENU
    bool reiniciar = false;
    bool sair = false;
    bool info = false;
    // =====================

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
                interface.realcar_menu(Menu::Reiniciar);
                reiniciar = true;
            }
            else {
                tabuleiro = Tabuleiro_t();
                interface.desenhar_main();
                reiniciar = false;
            }
            break;
        
        case 'i':   // COMANDO INFORMAÇÕES 
            sair = false;
            reiniciar = false;
            if(!info) {
                interface.realcar_menu(Menu::Info);
                info = true;
            }
            else {
                info = false;
                interface.desenhar_info();
                interface.apagar_tela();
                interface.desenhar_main();
            }
            break;

        case 's':   //  COMANDO SAIR
            reiniciar=false;
            info=false;
            if(!sair) {
                interface.realcar_menu(Menu::Sair);
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
            interface.realcar_menu(Menu::Default);
            // ======================
            
            mvwprintw(win, (LINHAS-3), 1, "%s", CLEAR_LINES.c_str());
            mvwprintw(win, (LINHAS-3), 1, "Jogada: ");
            std::string comando = interface.ler_comando();
            mvwprintw(win, (LINHAS-3), 1, "%s", CLEAR_LINES.c_str());
            if(comando.size() == 10 || comando == "") {
                interface.adicionar_jogada(comando);
            }
            else {
                wattron(win, COLOR_PAIR(VERMELHO));
                mvwprintw(win, (LINHAS-3), 1, "Comando inválido, tente novamente");              
                wattroff(win, COLOR_PAIR(VERMELHO));
            }

            interface.desenhar_main();
        }
        break; 
        
        default:
            interface.realcar_menu(Menu::Default);
            break;
        }
    }

    endwin();
    return 0;
}
