#include "../include/interface.hpp"

InterfaceGrafica::InterfaceGrafica(Tabuleiro_t *tabuleiro, unsigned int linhas, unsigned int colunas) {
    _linhas = linhas;
    _colunas = colunas;
    initscr();
    noecho();
    curs_set(0);
    _win = newwin(linhas, colunas, 4, 10);
    _tabuleiro = tabuleiro;

    // INICIALIZAR CORES
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    // =====================

    desenhar_main();
    wattron(_win, COLOR_PAIR(VERDE));
    mvwprintw(_win, (_linhas-3), 1, "Para começar sua jogada aperte 'j'");
    wattroff(_win, COLOR_PAIR(VERDE));
}

void InterfaceGrafica::desenhar_main() {
    box(_win, 0, 0);
    wrefresh(_win);
    apagar_tela();

    //Gerar o MENU
    wattron(_win, A_STANDOUT);
    mvwprintw(_win, 0, 33, "JOGO DE DAMAS");
    wattroff(_win, A_STANDOUT);
    mvwprintw(_win, 0, 2, "Reiniciar");
    mvwprintw(_win, 0, 12, "Info");
    mvwprintw(_win, 0, 17, "Sair");

    int inicio = _colunas/20;

    // Gerar o Tabuleiro Vazio
    for(int linha = inicio; linha<inicio+8; linha++) {
        for(int coluna = inicio; coluna<inicio+8; coluna++) {
            mvwprintw(_win, inicio-1, coluna+(3*(coluna)), "_%i_", int(coluna-inicio));
            mvwprintw(_win, linha, inicio+(2*(inicio)), "_%i_|", int(linha-inicio));
            if((linha%2 != 0 && coluna%2 != 0) || ((linha%2 == 0 && coluna%2 == 0))) {
                wattron(_win, A_STANDOUT);
                mvwprintw(_win, linha, coluna+(3*(coluna)), "___");
                wattroff(_win, A_STANDOUT);
            } 
            else {
                mvwprintw(_win, linha, coluna+(3*(coluna)), "___");
            } 
        }
    }

    // Colocar as Pecas do Tabuleiro na interface
    for(Peca_t peca : _tabuleiro->get_tabuleiro()) {
        int linha = peca.get_posicao().linha+inicio;
        int coluna = peca.get_posicao().coluna+inicio;
        if(peca.get_cor() == Cores::PRETO) {
            wattron(_win, A_STANDOUT);
            mvwprintw(_win, linha, coluna+(3*(coluna)), "_O_");
            wattroff(_win, A_STANDOUT);
        }
        else if(peca.get_cor() == Cores::BRANCO) {
            wattron(_win, A_STANDOUT);
            mvwprintw(_win, linha, coluna+(3*(coluna)), "_X_");
            wattroff(_win, A_STANDOUT);
        }
    }

    wattron(_win, A_UNDERLINE);
    mvwprintw(_win, 2, (_colunas-25), "Jogadas:");
    wattroff(_win, A_UNDERLINE);

    int i=3;
    for(std::string jogada: _memJogadas) {
        mvwprintw(_win, i++, (_colunas-20),"%s", jogada.c_str());
    }

    somar_placar_capturas();
    somar_placar_rodadas();

    wattron(_win, A_UNDERLINE);
    mvwprintw(_win, 7, (_colunas-25), "Capturas:");
    wattroff(_win, A_UNDERLINE);
    std::string capturas = "X: " + std::to_string(_placarCapturas[Jogador::X]) + " x " + std::to_string(_placarCapturas[Jogador::O]) + " :O";
    mvwprintw(_win, 9, (_colunas-20),"%s", capturas.c_str());

    wattron(_win, A_UNDERLINE);
    mvwprintw(_win, 11, (_colunas-25), "Placar:");
    wattroff(_win, A_UNDERLINE);
    std::string rodadas = "X: " + std::to_string(_placarRodadas[Jogador::X]) + " x " + std::to_string(_placarRodadas[Jogador::O]) + " :O";
    mvwprintw(_win, 13, (_colunas-20),"%s", rodadas.c_str());

    wattron(_win, COLOR_PAIR(VERDE));
    mvwprintw(_win, (_linhas-2), 1, "Para informações aperte duas vezes 'i'");
    wattroff(_win, COLOR_PAIR(VERDE));
}

void InterfaceGrafica::desenhar_info() {
    wrefresh(_win);
    box(_win, 0,0);
    mvwprintw(_win, 0, 2, "Retornar");
    apagar_tela();

    std::ifstream fileInfo("info.txt");
    if(fileInfo.is_open()) {
        std::string linha;
        for(int i=1; i<(_linhas-1); i++) {
            if(getline(fileInfo, linha)) mvwprintw(_win, i, 1, "%s", linha.c_str());
        }
        fileInfo.close();
    }

    char ch;
    bool retornar=false;
    while((ch = wgetch(_win))){
        if(ch == 'r') {
            if(!retornar) {
                retornar=true;
                wattron(_win, A_STANDOUT);
                mvwprintw(_win, 0, 2, "Retornar");
                wattroff(_win, A_STANDOUT);
            }
            else return;
        }
    }
}

void InterfaceGrafica::apagar_tela() {
    for(int i=1; i<(_linhas-1);i++) {
        mvwprintw(_win, i, 1, "%s", CLEAR_LINES.c_str());
    }
}

std::string InterfaceGrafica::ler_comando() {
    char ch = ' ';
    unsigned int pontoXinicial = 10;
    unsigned int pontoYinicial = _linhas-3;
    std::string linha;
    while(ch != '\n') {
        ch = wgetch(_win);
        // DELETAR CARACTERES
        if(ch == 127) {
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
        if(linha[0] != 'm') {
            wattron(_win, COLOR_PAIR(VERMELHO));
            mvwprintw(_win,pontoYinicial, pontoXinicial, "%s", linha_c);
            mvwprintw(_win,pontoYinicial, pontoXinicial+linha.size(), "%s", SMALL_CLEAR.c_str());
            wattroff(_win, COLOR_PAIR(VERMELHO));
        }
        else {
            mvwprintw(_win,pontoYinicial, pontoXinicial, "%s", linha_c);
            mvwprintw(_win,pontoYinicial, pontoXinicial+linha.size(), "%s", SMALL_CLEAR.c_str()); 
        }
    }
    return linha;
}

void InterfaceGrafica::realcar_menu(unsigned int opcao) {
    switch (opcao)
    {
    case Menu::Reiniciar:
        wattron(_win, A_STANDOUT);
        mvwprintw(_win, 0, 2, "Reiniciar");
        wattroff(_win, A_STANDOUT);
        mvwprintw(_win, 0, 12, "Info");
        mvwprintw(_win, 0, 17, "Sair");
        break;
    
    case Menu::Info:
        wattron(_win, A_STANDOUT);
        mvwprintw(_win, 0, 12, "Info");
        wattroff(_win, A_STANDOUT);
        mvwprintw(_win, 0, 2, "Reiniciar");
        mvwprintw(_win, 0, 17, "Sair");
        break;

    case Menu::Sair:
        wattron(_win, A_STANDOUT);
        mvwprintw(_win, 0, 17, "Sair");
        wattroff(_win, A_STANDOUT);
        mvwprintw(_win, 0, 2, "Reiniciar");
        mvwprintw(_win, 0, 12, "Info");
        break;
    
    default:
        mvwprintw(_win, 0, 2, "Reiniciar");
        mvwprintw(_win, 0, 12, "Info");
        mvwprintw(_win, 0, 17, "Sair");
        break;
    }
}

void InterfaceGrafica::adicionar_jogada(std::string jogada) {
    for(auto it = _memJogadas.begin(); it!=_memJogadas.end(); it++) {
        if((*it) == "") {
            (*it) = jogada;
            return;
        }
    }
    _memJogadas[0] = _memJogadas[1];
    _memJogadas[1] = _memJogadas[2];
    _memJogadas[2] = jogada;
}

void InterfaceGrafica::reiniciar() {
    for(auto it = _memJogadas.begin(); it != _memJogadas.end(); it++) {
        *it = "";
    }
    _placarCapturas[Jogador::X] = 0;
    _placarCapturas[Jogador::O] = 0;
    _tabuleiro->reiniciar_tabuleiro();
}

void InterfaceGrafica::somar_placar_rodadas() {
    if(_placarCapturas[Jogador::X] == 12){
        _placarRodadas[Jogador::X]++;
        reiniciar();
    }
    else if(_placarCapturas[Jogador::O] == 12){
        _placarRodadas[Jogador::O]++;
        reiniciar();
    }
}
void InterfaceGrafica::somar_placar_capturas() {
    int preto=0;
    int branco=0;
    for(Peca_t peca : _tabuleiro->get_tabuleiro()) {
        if(peca.get_cor() == Cores::BRANCO) branco++;
        else preto++;
    }
    _placarCapturas[Jogador::O] = abs(12-branco);
    _placarCapturas[Jogador::X] = abs(12-preto);
}

WINDOW* InterfaceGrafica::get_win() {
    return _win;
}

InterfaceGrafica::~InterfaceGrafica() {
    endwin();
}

void InterfaceGrafica::reiniciar_placar() {
    _placarRodadas[Jogador::O] = 0;
    _placarRodadas[Jogador::X] = 0;
}
