# PROJETO DUNGEON CRAWLER
Projeto de um jogo do professor Pedro Girotto do Cesupa sobre um jogo "puzzle" desenvolvido em C.

Feito na ferramenta 'Visual Studio Code' , a qual foi a ferramenta utilizada pelos professores das materias de programação no bimestre atual.
##
  ⁉️INFORMAÇÕES SOBRE O JOGO⁉️
##
  👾 JOGO 👾
  ##
-  Dungeon Crawler 🐍 
O jogo é do estilo aventura/puzzle onde o objetivo é o jogador conseguir passar de
três fases. Em cada fase o jogador deve se movimentar para pegar uma chave para
abrir a porta fechada.
##
O jogador possui os seguintes comando:
● W: O jogador movimenta uma unidade para cima;
● A: O jogador movimenta uma unidade para esquerda;
● S: O jogador movimenta uma unidade para baixo;
● D: O jogador movimenta uma unidade para direita;
● i: O jogador interage com o objeto que está em cima.
##
O jogo possui os seguintes elementos nas fases:
● &amp;: Símbolo que representa o jogador.
● P: Símbolo que representa um NPC.
● *: Símbolo que representa uma parede, o jogador ao se movimentar não pode
passar pela parede.
● @: Simbolo que representa a chave para abrir a porta para finalizar a fase, a
porta abre no momento que o jogador interage com a chave.
● D: Símbolo que representa a porta fechada.
● =: Simbolo que representa a porta aberta quando o jogador interage com a
chave.
● O: Símbolo que representa um botão que o usuário pode interagir, o botão
fica no chão e o jogador deve ficar em cima dele para poder interagir. A ação
do botão fica a critério da equipe (ex: aparecer mais espinhos no chão, abrir
uma passagem secreta, etc.).
● #: Símbolo que representa um espinho. A fase é reiniciada quando o jogador
toca no espinho, caso a fase seja reiniciada três vezes, o jogo volta para o
menu principal.
● &: Símbolo que representa um teletransporte. O teletransporte sempre deve
vir em pares, quando o jogador toca em um ele é transportado para o outro e
vice-versa.
● X: Símbolo que representa o monstro nível 1. Esse monstro tem um
movimento aleatório para cima, para esquerda, para baixo e para direita. Caso
o monstro toque no jogador, a fase é reiniciada.
● V: Símbolo que representa o monstro nível 2. Esse monstro tem uma
inteligência para seguir o jogador (há várias maneiras de implementar isso).
Caso o monstro toque no jogador, a fase é reiniciada.
##
O jogo possui as seguintes telas:
● Menu Principal: Menu com o título do jogo e com as opções: jogar, crédito e
sair;
● Crédito: Texto com o nome dos desenvolvedores do jogo;
● Sair: Texto de despedida e encerramento do programa;
● Vila: A vila serve como um tutorial. Apresenta NPCs que o jogador ao interagir
vão ensinar como jogar e dicas sobre o jogo. Na vila apresenta a entrada da
masmorra.
● Fase 1: A Fase 1 é inicializada quando o jogador entra na masmorra da vila;
● Fase 2: A Fase 2 é inicializada quando o jogador termina a Fase 1;
● Fase 3: A Fase 3 é inicializada quando o jogador termina a Fase 2;
● Vitória: Texto elogiando o jogador por ter conseguido terminar o jogo, depois
dessa tela o jogador volta para o Menu Principal. Essa tela só pode ser
acessada se o jogador finalizar a Fase 3;
● Derrota: Texto caçoando o jogador, depois dessa tela o jogador volta para o
Menu Principal. Essa tela só pode ser acessada quando o jogador perde em
uma fase.
A imagem abaixo apresenta a transição entre as telas do jogo.
Cada fase deve possuir as seguintes características:
● Vila: Essa fase possui uma dimensão de 10x10 e possui os seguintes
elementos: NPC(s), parede, chave e porta;
● Fase 1: Essa fase possui uma dimensão de 10x10 e possui os seguintes
elementos: jogador, parede, chave e porta;
● Fase 2: Essa fase possui uma dimensão de 20x20 e possui os seguintes
elementos: todos da Fase 1 mais botão, espinhos e o monstro nível 1;
● Fase 3: Essa fase possui uma dimensão de 40x40 e possui os seguintes
elementos: todos da Fase 2 mais teletransporte e o monstro nível 2.
##
  📖Historia📖
Um jogo de aventura é um gênero de videogame no qual o jogador assume o papel
de protagonista em uma história interativa impulsionada pela exploração e/ou
resolução de quebra-cabeças (Rollings &amp; Adams 2003, p. 43). O foco do gênero na
história permite que ele se baseie fortemente em outras mídias, literatura e filmes.
Muitos jogos de aventura (texto e gráfico) são projetados para um único jogador, já
que essa ênfase na história e no personagem dificulta o design multijogador
(Hitchens 2002, p. 258). Colossal Cave Adventure é identificado (&quot;The Colossal Cave
Adventure page&quot;. rickadams.org. Retrieved 31 July 2020.) como o primeiro jogo de
aventura, lançado pela primeira vez em 1976, enquanto outras séries de jogos de
aventura notáveis incluem Zork, King&#39;s Quest, The Secret of Monkey Island e Myst.
##
  📌Objetivo📌
Este projeto tem como objetivo desenvolver a habilidade do aluno de resolução de
problema, raciocínio lógico algorítmico e competência interpessoal, além de treinar
todos os conhecimentos adquiridos na programação e algoritmos.
##
EQUIPE👬:
- Lucas Pinto🙎‍♂️
- Mario Henrique🙎‍♂️
- Pedro Mansour 🙎‍♂️
##
PROFESSOR🙋‍♂️:
- Pedro Girotto🤵
