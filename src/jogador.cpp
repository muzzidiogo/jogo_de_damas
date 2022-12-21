#include "../include/jogador.hpp"

Jogador_t::Jogador_t(InterfaceGrafica* interface){
    _interface = interface;
}

void Jogador_t::jogar(){
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
                LOOP = false;
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
            if(comando.size() == 10 || comando == "") {
                _interface->adicionar_jogada(comando);
                _interface->desenhar_main();
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
}