#ifndef PECA_HPP
#define PECA_HPP
#include <vector>
//================ EXTRAS ================
typedef struct {
    unsigned int linha;
    unsigned int coluna;
} Posicao_t;

enum Cores {
    BRANCO, PRETO
};
// FIM EXTRAS ============================

class Peca_t {
private:
    int _cor;
    Posicao_t _posicao;
public:
    /// @brief Construtor vazio padrao
    Peca_t();  

    /// @brief Construtor completo das pecas
    /// @param cor Cor da peca
    /// @param posicao Struct de posicao da peca
    Peca_t(int cor, Posicao_t posicao);

    /// @brief Funcao responsavel pelo movimento das pecas. É sobrescrita na classe Dama
    /// @param posicao Posicao de destino da peca
    virtual void andar(Posicao_t posicao);
    
    /// @brief Funcao que retorna a posicao da peca
    /// @return _posicao
    Posicao_t get_posicao();

    /// @brief Funcao que retorna a cor da peca
    /// @return _cor
    int get_cor();

    bool operator ==(Peca_t peca) const;
    bool operator !=(Peca_t peca) const;
};

#endif //PECA_HPP
