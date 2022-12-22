#ifndef ENGINE_H
#define ENGINE_H

#include "peca.hpp"
#include "tabuleiro.hpp"
#include <vector>

typedef struct {
    Peca_t peca;
    std::vector<Posicao_t> * posRemover;
} PecaPorCapturas_t;

class Engine {
    private:
        //variaveis usadas para que sejam encontradas a maior quantidade de jogadas e tal caminho, na funcao conta_jogadas
        int _numCapturas;  
        int _numCapturasMax;
        std::vector<Posicao_t> _posRemover;
        std::vector<Posicao_t> _posRemoverMax;

        /// @brief Funcao recursiva responsavel por encontrar o caminho com maior quantidade de jogadas de uma peca
        /// @param tabuleiro Tabuleiro do jogo 
        /// @param peca Peca a ser analisada (ira capturar as outras)
        /// @return True, caso seja possivel realizar alguma captura, false caso contrario
        bool conta_jogadas(Tabuleiro_t tabuleiro, Peca_t peca);

        /// @brief Funcao que cria uma copia do tabuleiro, realiza a captura determinada pela conta_jogadas e retorna o tabuleiro modificado
        /// @param tabuleiro Tabuleiro a ser copiado 
        /// @param peca Peca que ira realizar a captura
        /// @param movimento Direcao que a captura tomara (Ex: [2, 2] comendo [1, 1] tem movimento [-1, -1])
        /// @return Copia do tabuleiro antigo, com a captura
        Tabuleiro_t * aloca_tabuleiro_com_captura(Tabuleiro_t tabuleiro, Movimento_t movimento, Peca_t peca);
    public:
        /// @brief Funcao que conta as capturas possiveis para cada peca e "retorna" a peca que tiver a maior quantidade de capturas, junto com as capturas possiveis
        /// @param tabuleiro Tabuleiro do jogo 
        /// @param cor Cor que sera usada para analise
        /// @param pecaPreencher Peca recebida como referencia, que, ao final da execucao da funcao, sera a peca do tabuleiro com maior quantidade de jogadas
        /// @param posicaoPreencher Vetor recebido como referencia que, ao final da execucao da funcao, sera o vetor com as capturas possiveis da peca com maior quantidade de jogadas 
        void get_maior(Tabuleiro_t tabuleiro, char cor, Peca_t &pecaPreencher, std::vector<Posicao_t> &posicaoPreencher);
};

#endif