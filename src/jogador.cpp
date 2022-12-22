#include "../include/jogador.hpp"
#include <sstream>
#include <iostream>

Jogador_t::Jogador_t(InterfaceGrafica* interface, Tabuleiro_t* tabuleiro, Engine* engine){
    _interface = interface;
    _tabuleiro = tabuleiro;
    _engine = engine;
}

bool Jogador_t::verifica_comando(std::string comando, int* index, Posicao_t* posFinal) {
    //Separar o comando por palavras
    std::vector<std::string> elementosComando;
    std::stringstream ss(comando);
    std::string tok;
    while (getline(ss, tok, ' ')) {
        if (!tok.empty())
            elementosComando.push_back(tok);
    }
    //Analisar comando
    if(elementosComando.size() != 5) return false;
    if(elementosComando[0] != "m") return false;
    std::vector<unsigned int> posicoes;
    for(int i=1;i<=4;i++) {
        try {posicoes.push_back(std::stoul(elementosComando[i]));}
        catch(std::exception &excpt){ return false; }
    }
    //Analisa pecano tabuleiro e posicao final
    for(size_t i=0;i<_tabuleiro->get_ptr_tabuleiro()->size();i++) {
        if(_tabuleiro->get_ptr_tabuleiro()->at(i) == Peca_t(Cores::BRANCO, Posicao_t{posicoes[1], posicoes[0]})){
            *index = i;
            posFinal->coluna = posicoes[2];
            posFinal->linha= posicoes[3];
            return true;
        }
    }
    return false;
}

bool Jogador_t::jogar(){
    // VARIÁVEIS PARA O MENU
    bool reiniciar = false;
    bool sair = false;
    bool info = false;
    // =====================

    char ch;
    bool LOOP = true;
    while(LOOP) {
        ch = wgetch(_interface->get_win());
        switch (ch)
        {
        case 'r':  // COMANDO REINICIAR
            sair = false;
            info = false;
            if(!reiniciar) {
                _interface->realcar_menu(Menu::Reiniciar);
                reiniciar = true;
            }
            else {
                _interface->reiniciar();
                _interface->reiniciar_placar();
                _interface->desenhar_main();
                reiniciar = false;
            }
            break;
        
        case 'i':   // COMANDO INFORMAÇÕES 
            sair = false;
            reiniciar = false;
            if(!info) {
                _interface->realcar_menu(Menu::Info);
                info = true;
            }
            else {
                info = false;
                _interface->desenhar_info();
                _interface->desenhar_main();
            }
            break;

        case 's':   //  COMANDO SAIR
            reiniciar=false;
            info=false;
            if(!sair) {
                _interface->realcar_menu(Menu::Sair);
                sair = true;
            }
            else {
                LOOP =  false;
            }
            break;

        case  'j':  //  COMANDO JOGAR
        {
            // Reiniciar elementos
            sair=false;
            reiniciar=false;
            info=false;
            _interface->realcar_menu(Menu::Default);
            // ======================
            
            mvwprintw(_interface->get_win(), (_interface->get_linhas()-3), 1, "%s", CLEAR_LINES.c_str());
            mvwprintw(_interface->get_win(), (_interface->get_linhas()-3), 1, "Jogada: ");
            std::string comando = _interface->ler_comando();
            mvwprintw(_interface->get_win(), (_interface->get_linhas()-3), 1, "%s", CLEAR_LINES.c_str());
            int index;
            Posicao_t posFinal;
            if(verifica_comando(comando, &index, &posFinal)) {
                Peca_t pecaMover;
                std::vector<Posicao_t> pecasCapturar;
                _engine->get_maior(*_tabuleiro, Cores::BRANCO, pecaMover, pecasCapturar);
                if(pecasCapturar.size()==0) {
                    _interface->adicionar_jogada(comando);
                    _tabuleiro->get_ptr_tabuleiro()->at(index).andar(posFinal);
                    _interface->desenhar_main();
                }
                else{
                    for(Posicao_t posicao : pecasCapturar) {
                        int linha = posicao.linha - pecaMover.get_posicao().linha;
                        int coluna = posicao.coluna - pecaMover.get_posicao().coluna;
                        Movimento_t movimento = {linha, coluna};
                        _tabuleiro->captura_peca(pecaMover, movimento);
                        pecaMover.andar({pecaMover.get_posicao().linha+(movimento.linha),
                                         pecaMover.get_posicao().coluna+(movimento.coluna)});
                        pecaMover.andar({pecaMover.get_posicao().linha+(movimento.linha),
                                         pecaMover.get_posicao().coluna+(movimento.coluna)});
                    }
                    _interface->adicionar_jogada("Captura Automatica");
                }
                return true;
            }
            else {
                _interface->mensagem_de_erro("COMANDO INVALIDO");
            }
        }
        break;
        
        default:
            _interface->realcar_menu(Menu::Default);
            break;
        }
    }
    return false;
}