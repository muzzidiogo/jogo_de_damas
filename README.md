# Projeto Pds2 - Jogo de Damas

## Desenvolvedores:
1. Elias Miranda Nacif Rocha
2. Diogo Muzzi
3. Samuel Felipe Verçosa Gonçalves

## User Stories:
1. Eu, como **jogador**, desejo **movimentar as peças brancas do tabuleiro por meio de comandos do teclado** para **posicionar estrategicamente as minhas peças no jogo**.

2. Eu, como **jogador**, desejo, quando possível, **capturar peças inimigas** para **ganhar o jogo**

3. Eu, como **jogador**, desejo **ter o computador como adversário** para que **não seja necessário outro usuário para o funcionamento do jogo**.

4. Eu, como **jogador**, desejo **visualizar o placar de acordo com o andamento dos jogos contra o computador**, para que **o entendimento da sotiação atual das partidas seja facilitado**.

5. Eu, como **jogador**, desejo **ser avisado se as minhas jogadas são válidas ou não**, para que **eu consiga seguir as regras do jogo corretamente**.

6. Eu, como **jogador**, gostaria de **visualizar o tabuleiro e o jogo por meio de uma interface no terminal**, para que **a    progressão do jogo seja facilitada**.

7. Eu, como **jogador**, desejo que o **computador faça jogadas coerentes**, para que **as partidas sejam competitivas**.

## Funcionalidade do Jogo:

Para jogar o Jogo de Damas desenvolvido nesse projeto, é essencial a leitura da explicação a seguir:

### Menu:

<div align="center">
<img src="https://user-images.githubusercontent.com/68508499/209154419-a3a75afd-2c2c-46f1-8398-e4203f558b4e.png" alt="Menu">
</div>

O menu do jogo constitui-se da barra com comandos aparente na parte superior da interface.
Na página principal do jogo o Menu apresenta-se com três comandos diferentes: Reiniciar, Info e Sair, como pode ser visto na imagem acima.

Cada uma das funcionalidades acima podem ser descritas a seguir:

* **Reiniciar**: ao ativar esse comando o jogo será reinicializado.
* **Info**: ao ativar esse comando você será redirecionado para outra página que conterá um resumo das informações presentes aqui no readme, caso necessite de se relembrar de alguma informação importante
* **Sair**: ao ativar esse comando você sairá do jogo

Ademais, para ativar as funcionalidades presentes no menu é necessário se apertar 2 vezes as teclas concernentes às iniciais de cada funcionalidade (uma vez para ativar e outra para confirmar). Desse modo, por exemplo, se desejo Reiniciar o jogo, devo apertar duas vezes a tecla "_r_" minusculo, para Informações, duas vezes "_i_" e para Sair, duas vezes o "_s_";

**obs.:** Na página de informações, no menu haverá a funcionalidade Retornar para voltar para a página principal. Para ativá-la aperte duas vezes a letra "_r_" minuscula;


### Jogar:

Ao longo do jogo você irá alternar entre sua jogada e a jogada do computador. Se você deseja registrar sua jogada, deverá, na sua vez, apertar a tecla "_j_" minuscula (inicial de jogada).

Após isso digitará seu comando de jogada que deverá ser do formato: _Xinicial Yinicial Xfinal Yfinal_. Desse modo, você deverá digitar as coordenadas da peca que você deseja movimentar e as coordenadas do local final que você deseja que essa peca esteja.

É importante citar que, pós você digitar "_j_", você entra no Modo Jogada e tudo que você digitar será adicionado à linha de comando. Por isso, se você deseja sair do Modo Jogada para utilizar alguma funcionalidade do Menu, você deverá digitar a tecla "_!_"

Se seu comando for inválido você será avisado e deverá reiniciar o processo, apertando "_j_" novamente e em seguida escrevendo o comando correto.

**obs.:** O jogo utiliza-se de uma engine criada pelos desenvolvedores para adquirir a melhor captura do jogo. Desse modo, como é obrigação nas regras do jogo o jogador, em uma situação de captura, efetuá-la, o jogo irá ignorar o comando escrito e irá capturar a maior quantidadade de pecas possíveis, assim seguindo as diretrizes do jogo. Quando isso ocorrer aparecerá na memória de jogadas a frase "Captura Automática" em vez do comando digitado.

### Peca e Dama:

Para diferenciar uma peça normal de uma dama a interface utilizou-se da diferenciação por meio do minúsculo e maiúsculo. Ou seja, as peças normais são representadas por letras minusculas e as damas são representadas por letras maiúsculas.

## Considerações:

Devido ao uso da biblioteca <ncurses>, o programa provavelmente apresentará leak de memória independentemente da qualidade do código. Pedimos que isso seja levado em consideração caso o valgrind seja utilizado como critério de avaliação.
