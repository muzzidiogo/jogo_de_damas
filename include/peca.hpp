#ifndef PECA_HPP
#define PECA_HPP
#include <vector>
#include <cmath>
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

    /// @brief Funcao responsavel pelo movimento das pecas.
    /// @param posicao Posicao de destino da peca
    void andar(Posicao_t novaPosicao);
    
    /// @brief Funcao que verifica se o movimento da peca e valido. E sobrescrita na classe Dama
    /// @param posicao Posicao de destino da peca
    virtual bool verifica_movimento(Posicao_t novaPosicao);
    
    /// @brief Funcao que retorna a posicao da peca
    /// @return _posicao
    Posicao_t get_posicao();

    /// @brief Funcao que retorna a cor da peca
    /// @return _cor
    int get_cor();

    /// @brief Funcao que retorna se a peca e dama ou nao
    /// @return _cor
    virtual bool e_dama() const;

    /// @brief Operador == para duas pecas. Uma peca é igual a outra quando sua
    ///         sua posicao e  cor são iguais
    /// @param peca outra peca comparada
    /// @return true para igual e false para diferente
    bool operator ==(Peca_t peca) const;

    /// @brief Operador != para duas pecas. Uma peca é diferente da outra quando sua
    ///         sua posicao ou cor são diferentes
    /// @param peca outra peca comparada
    /// @return false para igual e true para diferente
    bool operator !=(Peca_t peca) const;

    
};

#endif //PECA_HPP
