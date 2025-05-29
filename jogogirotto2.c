#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // Para getch()

// Limpa a tela do console
void limpar_tela() {
    system("cls");
}

// Espera o usuário pressionar ENTER para continuar
void esperar_enter() {
    printf("Pressione ENTER para continuar...\n");
    while (getchar() != '\n');
}

// Declarações das funções principais do jogo
void titulo();
void iniciar();
void Tutorial();
void Controles();
void CreditosF();
void Fase1();
void Fase2();
void Fase3();
void MapaNPC();

int escolha;

// Exibe o título do jogo
void titulo() {
    printf("\t\t===== >|< THE DUNGEON CRAWLER >|< =====\n\n");
}

// Mapa do NPC para interação inicial
void MapaNPC() {
    limpar_tela();
    char tecla;
    int a = 10, l = 10;
    int y = 5, x = 1; // Posição inicial do jogador
    int chavePegou = 0;
    char mapa[a][l];
    int i, j;

    // Inicializa o mapa com paredes e espaços vazios
    for (i = 0; i < a; i++) {
        for (j = 0; j < l; j++) {
            if (i == 0 || j == 0 || i == a - 1 || j == l - 1) {
                mapa[i][j] = '*'; // Paredes
            } else {
                mapa[i][j] = ' '; // Espaço vazio
            }
        }
    }

    // Paredes extras para dificultar o caminho (puzzle)
    mapa[3][3] = '*';
    mapa[3][4] = '*';
    mapa[3][5] = '*';
    mapa[5][3] = '*';
    mapa[6][4] = '*';

    mapa[y][x] = '&'; // Jogador
    mapa[4][4] = 'P'; // NPC
    mapa[2][2] = '@'; // Chave

    while (1) {
        limpar_tela();
        titulo();
        for (i = 0; i < a; i++) {
            for (j = 0; j < l; j++) {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }
        printf("Digite um comando (w/a/s/d para mover, i para interagir, q para sair): ");
        tecla = getch(); // Captura tecla sem enter

        mapa[y][x] = ' '; // Limpa a posição anterior do jogador

        // Movimentação do jogador
        if (tecla == 'w' && mapa[y - 1][x] != '*') y--;
        else if (tecla == 'a' && mapa[y][x - 1] != '*') x--;
        else if (tecla == 's' && mapa[y + 1][x] != '*') y++;
        else if (tecla == 'd' && mapa[y][x + 1] != '*') x++;

        // Interação com a chave
        if (y == 2 && x == 2 && !chavePegou) {
            printf("Aperte 'i' para pegar a chave\n");
            tecla = getch();
            if (tecla == 'i') {
                chavePegou = 1;
                mapa[2][2] = ' '; // Remove a chave do mapa
                limpar_tela();
                printf("Você pegou a chave! Essa chave abre portas da dungeon.\n");
                esperar_enter();
            }
        }

        // Interação com o NPC
        if (y == 4 && x == 4) {
            printf("Aperte 'i' para interagir com o NPC\n");
            tecla = getch();
            if (tecla == 'i') {
                limpar_tela();
                printf("Voce encontrou o Giroto.\n");
                printf("Giroto diz: 'Você precisa de uma chave para abrir as portas das dungeons.'\n");
                printf("Giroto diz: 'A chave mais em cima e igual as chaves que abrem as portas das Fases.'\n");
                printf("Giroto diz: 'Aperte 'i' para interagir com objetos.'\n");
                printf("Giroto diz: 'Aperte 'q' para sair da vila e escolha a Fase 1 para iniciar.'\n");
                printf("Em cada fase o nivel de dificuldade aumenta.\n");
                printf("Giroto diz: 'Eu estarei te esperando mais a frente na Dungeon'\n");
                printf("Boa sorte para passar das fases.\n");
                printf("Aperte 'i' para continuar.\n");
                esperar_enter();
            }
        }

        mapa[y][x] = '&'; // Atualiza a posição do jogador

        // Se o jogador quiser sair do mapa, pressione 'q'
        if (tecla == 'q') {
            break;
        }
    }
}

// Menu inicial do jogo
void iniciar() {
    while (1) {
        limpar_tela();
        titulo();
        printf("1 - Tutorial\n\n");
        printf("2 - Mapa do NPC\n\n");
        printf("3 - Fase 1\n\n");
        printf("4 - Voltar\n\n");
        printf("Escolha: ");
        if (scanf("%d", &escolha) != 1) {
            while (getchar() != '\n'); // limpar entrada inválida
            printf("Escolha invalida! Tente novamente.\n");
            esperar_enter();
            continue;
        }
        while (getchar() != '\n'); // limpar nova linha após a entrada do número

        switch (escolha) {
            case 1:
                Tutorial();
                break;
            case 2:
                MapaNPC();
                break;
            case 3:
                Fase1();
                break;
            case 4:
                return; // Volta para o menu principal
            default:
                printf("Escolha invalida! Tente novamente.\n");
                esperar_enter();
                break;
        }
    }
}

// Implementação da Fase 1
void Fase1() {
    limpar_tela();
    char tecla;
    int a = 11, l = 11;
    int y = 8, x = 1;       // Posição inicial do jogador
    int NPCX = 8, NPCY = 1; // Posição do NPC Giroto
    int PY = 9, PX = 9;     // Posição da porta
    int CY = 1, CX = 9;     // Posição da chave
    int chavePegou = 0;
    char mapa[a][l];
    int i, j;

    // Inicializa o mapa com paredes nas bordas e algumas internas
    for (i = 0; i < a; i++) {
        for (j = 0; j < l; j++) {
            if (i == 0 || j == 0 || i == a - 1 || j == l - 1 || (i >= 2 && i <= 9 && j == 5)) {
                mapa[i][j] = '*';
            } else {
                mapa[i][j] = ' ';
            }
        }
    }

    // Paredes adicionais para formar maze/puzzle
    mapa[2][7] = '*';
    mapa[3][7] = '*';
    mapa[4][7] = '*';
    mapa[5][7] = '*';
    mapa[6][7] = '*';
    mapa[7][7] = '*';

    // Adicionando algumas paredes adicionais para desafio
    mapa[2][3] = '*';
    mapa[2][4] = '*';
    mapa[3][2] = '*';
    mapa[3][3] = '*';
    mapa[5][1] = '*';
    mapa[5][2] = '*';
    mapa[5][3] = '*';
    mapa[6][3] = '*';
    mapa[7][1] = '*';
    mapa[7][2] = '*';
    mapa[8][3] = '*';

    // Posiciona jogador, NPC, porta e chave no mapa
    mapa[y][x] = '&';       // Jogador
    mapa[NPCY][NPCX] = 'P'; // NPC Giroto
    mapa[PY][PX] = 'D';     // Porta
    mapa[CY][CX] = '@';     // Chave

    while (1) {
        titulo();
        // Exibe o mapa
        for (i = 0; i < a; i++) {
            for (j = 0; j < l; j++) {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }
        printf("Digite um comando (w/a/s/d para mover, i para interagir): ");
        tecla = getch(); // Captura tecla sem enter
        //printf("%c\n", tecla);

        // Limpa posição anterior do jogador
        mapa[y][x] = ' ';

        // Movimenta jogador respeitando paredes
        if (tecla == 'w' && mapa[y - 1][x] != '*') y--;
        else if (tecla == 'a' && mapa[y][x - 1] != '*') x--;
        else if (tecla == 's' && mapa[y + 1][x] != '*') y++;
        else if (tecla == 'd' && mapa[y][x + 1] != '*') x++;

        // Verifica se jogador está na posição da chave e pega se interagir
        if (y == CY && x == CX && !chavePegou) {
            printf("Aperte 'i' para pegar a chave\n");
            tecla = getch();
            if (tecla == 'i') {
                chavePegou = 1;
                mapa[CY][CX] = ' ';  // Remove chave do mapa
                mapa[PY][PX] = '=';  // Abre a porta
                limpar_tela();
                printf("Voce pegou a chave. A porta abriu!\n");
                esperar_enter();
            }
        }

        // Verifica porta aberta e interação para entrar
        if (mapa[PY][PX] == '=' && y == PY && x == PX) {
            printf("Aperte 'i' para entrar na porta\n");
            tecla = getch();
            if (tecla == 'i') {
                limpar_tela();
                printf("Iniciando a Fase 2\n");
                esperar_enter();
                break;
            }
        }

        // Interação com o NPC Giroto
        if (y == NPCY && x == NPCX) {
            printf("Aperte 'i' para interagir com o NPC\n");
            tecla = getch();
            if (tecla == 'i') {
                limpar_tela();
                printf("Voce novamente encontrou o Girotto!! \n");
                printf("Giroto diz: 'Você precisa de uma chave para abrir a porta.'\n");
                printf("Giroto diz: 'A chave esta do meu lado como ja disse antes.'\n");
                printf("Giroto diz: 'A chave abre a porta.'\n");
                printf("Giroto diz: 'A partir daqui voce ira encontrar mais chaves e portas.'\n");
                printf("Giroto diz: 'Eu tenho medo de entrar la, voce vai sozinho. Boa sorte!\n");
                esperar_enter();
            }
        }

        // Atualiza mapa com posições atuais
        mapa[y][x] = '&';
        mapa[NPCY][NPCX] = 'P';
        if (!chavePegou) {
            mapa[CY][CX] = '@';
            mapa[PY][PX] = 'D'; // Porta fechada
        } else {
            mapa[PY][PX] = '=';
        }

        limpar_tela();
    }
    Fase2();
}

// Implementação da Fase 2
void Fase2() {
    limpar_tela();
    char tecla;
    int a = 20, l = 20; // Diminuir o tamanho da fase
    int y = 13, x = 1;  // Posição inicial do jogador
    int health = 3;
    int i, j;

    char mapa[a][l];

    // Posições atualizadas
    int K0Y = 12, K0X = 1;    // Chave externa
    int K1Y = 6, K1X = 16;    // Chave atrás dos espinhos (abre a área fechada)
    int K3Y = 13, K3X = 18;   // Chave final que abre a fase 3

    int D0Y = 10, D0X = 2;
    int D1Y = 6, D1X = 13;    // Porta área espinhos trancada pela chave 1
    int D3Y = 12, D3X = 19;   // Porta final fase 2

    int BY = 8, BX = 10;
    int botaoescolhido = 0;

    // Estendendo espinhos para fechar a parte inferior do mapa
    int posicao_espinhos[][2] = {
        {7,14},{8,14},{9,14},{10,14},{11,14},{12,14},
        {7,15},{7,16},{7,17},{6,14},{6,15},{8,15},{9,15},{10,15},{11,15},{12,15}
    };
    int cont_espinhos = sizeof(posicao_espinhos) / sizeof(posicao_espinhos[0]);

    int monsterY = 12, monsterX = 10;

    int chave0 = 0, chave1 = 0, chave3 = 0;

    // Inicializa o mapa com paredes e espaços
    for(i=0;i<a;i++){
        for(j=0;j<l;j++){
            if(i==0 || j==0 || i==a-1 || j==l-1){
                mapa[i][j] = '*';
            }
            else if((i>=10 && i<=14 && (j==0 || j==7)) || (j>=0 && j<=7 && (i==10 || i==14))){
                mapa[i][j] = '*';
            }
            else if((i>=1 && i<=9 && (j==13 || j==19)) || (j>=13 && j<=19 && (i==1 || i==9))){
                mapa[i][j] = '*';
            }
            else if(i==D0Y && j==D0X) mapa[i][j] = 'D';
            else if(i==D1Y && j==D1X) mapa[i][j] = 'D';
            else if(i==D3Y && j==D3X) mapa[i][j] = 'D';
            else if(i==BY && j==BX) mapa[i][j] = 'B';
            else mapa[i][j] = ' ';
        }
    }

    // Paredes extras para adicionar mais maze/puzzle na Fase2
    mapa[3][3] = '*';
    mapa[3][4] = '*';
    mapa[3][5] = '*';
    mapa[4][1] = '*';
    mapa[4][2] = '*';
    mapa[4][3] = '*';
    mapa[5][3] = '*';
    mapa[6][3] = '*';
    mapa[5][5] = '*';
    mapa[8][5] = '*';
    mapa[8][3] = '*';
    mapa[8][5] = '*';
    mapa[9][3] = '*';
    mapa[9][5] = '*';
    mapa[10][5] = '*';
    mapa[11][5] = '*';
    mapa[12][5] = '*';
    mapa[2][10] = '*';
    mapa[3][10] = '*';
    mapa[4][10] = '*';
    mapa[5][10] = '*';
    mapa[6][10] = '*';
    mapa[7][10] = '*';

    for(i=0;i<cont_espinhos;i++){
        mapa[posicao_espinhos[i][0]][posicao_espinhos[i][1]] = '^';
    }

    mapa[K0Y][K0X] = '@';  // Chave externa
    mapa[K1Y][K1X] = '@';  // Chave atrás dos espinhos (abre área)
    mapa[K3Y][K3X] = '@';  // Chave final

    mapa[monsterY][monsterX] = 'M';

    srand(time(NULL));

    while(1){
        titulo();
        printf("Vida: %d\n\n",health);
        for(i=0;i<a;i++){
            for(j=0;j<l;j++){
                if(i==y && j==x) printf("& ");
                else printf("%c ",mapa[i][j]);
            }
            printf("\n");
        }

        tecla = getch();

        // Limpando o local antigo do monstro somente se a posição atual for espaço ' '
        if(mapa[monsterY][monsterX] == 'M') {
            mapa[monsterY][monsterX] = ' ';
        }

        // Movimentação aleatória do monstro
        int move = rand() % 4;
        int newMY = monsterY, newMX = monsterX;
        if(move == 0) newMY--;
        else if(move == 1) newMX--;
        else if(move == 2) newMY++;
        else if(move == 3) newMX++;

        if(newMY > 0 && newMY < a-1 && newMX > 0 && newMX < l-1 && mapa[newMY][newMX] != '*' && mapa[newMY][newMX] != 'D' && mapa[newMY][newMX] != '^' && mapa[newMY][newMX] != 'B' && mapa[newMY][newMX] != 'O')
        {
            monsterY = newMY; monsterX = newMX; 
        }
        mapa[monsterY][monsterX] = 'M';

        int newY = y, newX = x;
        if(tecla == 'w') newY--;
        else if(tecla == 'a') newX--;
        else if(tecla == 's') newY++;
        else if(tecla == 'd') newX++;

        if(newY > 0 && newY < a && newX > 0 && newX < l && mapa[newY][newX] != '*' && mapa[newY][newX] != 'D'){
            y = newY; x = newX;
        }

        if(y == BY && x == BX && tecla == 'i' && botaoescolhido == 0){
            botaoescolhido = 1;
            for(i=0;i<cont_espinhos;i++){
                mapa[posicao_espinhos[i][0]][posicao_espinhos[i][1]] = ' ';
            }
            limpar_tela();
            printf("Voce apertou o Botao! Os espinhos foram desativados.\n");
            esperar_enter();
            continue;
        }

        if(y == K0Y && x == K0X && !chave0){
            printf("Aperte 'i' para pegar a chave externa\n");
            tecla = getch();
            if(tecla == 'i'){
                chave0 = 1;
                mapa[K0Y][K0X] = ' ';
                mapa[D0Y][D0X] = ' ';
                limpar_tela();
                printf("Voce pegou a chave externa! A porta inicial abriu.\n");
                esperar_enter();
                continue;
            }
        }
        else if(y == K1Y && x == K1X && chave0 && !chave1){
            printf("Aperte 'i' para pegar a chave que abre a area de espinhos\n");
            tecla = getch();
            if(tecla == 'i' && botaoescolhido){
                chave1 = 1;
                mapa[K1Y][K1X] = ' ';
                mapa[D1Y][D1X] = ' ';
                limpar_tela();
                printf("Voce pegou a chave da area de espinhos! A porta da area abriu.\n");
                esperar_enter();
                continue;
            }
            else if(tecla == 'i' && !botaoescolhido){
                limpar_tela();
                printf("Os espinhos estao ativos! Aperte o botao para desativa-los.\n");
                esperar_enter();
                continue;
            }
        }
        else if(y == K3Y && x == K3X && chave1 && !chave3){
            printf("Aperte 'i' para pegar a chave da porta final\n");
            tecla = getch();
            if(tecla == 'i'){
                chave3 = 1;
                mapa[K3Y][K3X] = ' ';
                mapa[D3Y][D3X] = ' ';
                limpar_tela();
                printf("Voce pegou a chave final! Porta para a fase 3 aberta.\n");
                esperar_enter();
                continue;
            }
        }

        int no_espinho = 0;
        if(!botaoescolhido){
            for(i=0;i<cont_espinhos;i++){
                if(y==posicao_espinhos[i][0] && x==posicao_espinhos[i][1]){
                    no_espinho=1;
                    break;
                }
            }
            if(no_espinho){
                health--;
                y=18; x=1; // Respawn válida
                limpar_tela();
                printf("Voce pisou nos espinhos e perdeu uma vida! Vida atual: %d\n", health);
                if(health <= 0){
                    printf("Voce morreu! Fim de jogo.\n");
                    esperar_enter();
                    return;
                }
                esperar_enter();
                continue;
            }
        }

        if(y == monsterY && x == monsterX){
            health--;
            y=13; x=1; // Respawn posição inicial fase 2
            limpar_tela();
            printf("Voce foi atacado pelo monstro e perdeu uma vida! Vida atual: %d\n", health);
            if(health <= 0){
                printf("Voce morreu! Fim de jogo.\n");
                esperar_enter();
                return;
            }
            esperar_enter();
            continue;
        }

        if(chave3 && y == D3Y && x == D3X){
            printf("Aperte 'i' para entrar na porta e ir para a Fase 3\n");
            tecla = getch();
            if(tecla == 'i'){
                limpar_tela();
                printf("Iniciando a Fase 3\n");
                esperar_enter();
                break;
            }
        }

        limpar_tela();
    }
    Fase3();
}

// Implementação da Fase 3
void Fase3() {
    limpar_tela();
    char tecla;
    int a = 40, l = 40;
    int y = 18, x = 1; // Posição inicial do jogador
    int vida = 5;
    int i, j;

    int chave0 = 0, chave1 = 0, chave2 = 0, chave3 = 0;
    char mapa[a][l];

    int K0Y = 15, K0X = 1;
    int K1Y = 17, K1X = 1;
    int K2Y = 10, K2X = 15;
    int K3Y = 14, K3X = 17;

    int D0Y = 15, D0X = 2;
    int D1Y = 12, D1X = 16;
    int D2Y = 10, D2X = 16;
    int D3Y = 17, D3X = 19;

    int BY = 1, BX = 8;

    int botaoescolhido = 0;

    int posicaoespinhos[][2] = {
        {6,4},{7,4},{8,4},
        {9,9},{9,10},{10,9},{10,10},
        {13,12},{14,12},{15,12},{16,12},{17,12},
        {13,13},{13,14},{13,15},
        {5,15},{6,15},{7,15},{8,15},{9,15},{10,15},{11,15},
        {16,17},{17,17},{18,17},
        {12,6},{12,7},{12,8}
    };
    int contespinhos = sizeof(posicaoespinhos) / sizeof(posicaoespinhos[0]);

    int M_Y = 15, M_X = 10;
    int N_Y = 18, N_X = 16;

    srand(time(NULL));

    for(i=0;i<a;i++) {
        for(j=0;j<l;j++) {
            if(i==0 || j==0 || i==a-1 || j==l-1) {
                mapa[i][j] = '*';
            }
            else if((i>=15 && i<=19 && (j==0 || j==7)) ||
                    (j>=0 && j<=7 && (i==15 || i==19)) ||
                    (i>=1 && i<=14 && (j==15 || j==19)) ||
                    (j>=15 && j<=19 && (i==1 || i==14))) {
                mapa[i][j] = '*';
            }
            else if ((i >= 2 && i <= 6) && (j >= 5 && j <= 12)) {
                mapa[i][j] = '*';
            }
            else if ((i == 8 && j >= 3 && j <= 14) ||
                     (i == 9 && (j == 3 || j == 14)) ||
                     (i == 10 && (j >= 3 && j <= 14)) ||
                     (i == 11 && j == 3) ||
                     (i == 12 && (j >= 3 && j <= 11)) ||
                     (j == 11 && i >= 12 && i <= 14) ||
                     (i == 14 && (j >= 4 && j <= 11)) ||
                     (j == 4 && i >= 11 && i <= 14)) {
                if(!((i == 13 || i == 14) && (j == 12 || j == 13 || j == 14))) {
                    mapa[i][j] = '*';
                } else {
                    mapa[i][j] = ' ';
                }
            }
            else mapa[i][j] = ' ';
        }
    }

    // Paredes extras para aumentar dificuldade na parte inferior da fase 3
    for(i=30;i<40;i++){
        for(j=0;j<l;j++){
            mapa[i][j] = '*';
        }
    }

    mapa[K0Y][K0X] = '@';
    mapa[K1Y][K1X] = '@';
    mapa[K2Y][K2X] = '@';
    mapa[K3Y][K3X] = '@';

    mapa[M_Y][M_X] = 'M';
    mapa[N_Y][N_X] = 'N';

    int O_Y = 9, O_X = 2;  // posição do quebrador de paredes fora da área fechada
    mapa[O_Y][O_X] = 'O';

    mapa[BY][BX] = 'B'; // botão fora da área fechada

    // Variável para controlar movimentos do monstro N
    int N_moved_last_turn = 0;

    while(1){
        titulo();
        printf("Vida: %d\n\n",vida);
        for(i=0;i<a;i++){
            for(j=0;j<l;j++){
                if(i==y && j==x) printf("& ");
                else printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }

        tecla = getch();

        // Movimentação do monstro M
        if(mapa[M_Y][M_X] == 'M') {
            mapa[M_Y][M_X] = ' ';
        }
        int moveM = rand() % 4;
        int newMY = M_Y, newMX = M_X;
        if(moveM == 0) newMY--;
        else if(moveM == 1) newMX--;
        else if(moveM == 2) newMY++;
        else if(moveM == 3) newMX++;
        if(newMY > 0 && newMY < a-1 && newMX > 0 && newMX < l-1 &&
           mapa[newMY][newMX] != '*' && mapa[newMY][newMX] != '^' && mapa[newMY][newMX] != 'B' &&
           mapa[newMY][newMX] != 'O' && mapa[newMY][newMX] != 'D' && (newMY != y || newMX != x))
        {
            M_Y = newMY; M_X = newMX;
        }
        mapa[M_Y][M_X] = 'M';

        // Movimentação do monstro N (persegue o jogador)
        mapa[N_Y][N_X] = ' ';
        int newNY = N_Y, newNX = N_X;
        int prev_NY = N_Y, prev_NX = N_X;

        if(N_Y < y && mapa[N_Y+1][N_X] != '*' && mapa[N_Y+1][N_X] != '^' &&
           mapa[N_Y+1][N_X] != 'B' && mapa[N_Y+1][N_X] != 'O' && mapa[N_Y+1][N_X] != 'D' &&
           (N_Y+1 != y || N_X != x))
            newNY++;
        else if(N_Y > y && mapa[N_Y-1][N_X] != '*' && mapa[N_Y-1][N_X] != '^' &&
                mapa[N_Y-1][N_X] != 'B' && mapa[N_Y-1][N_X] != 'O' && mapa[N_Y-1][N_X] != 'D' &&
                (N_Y-1 != y || N_X != x))
            newNY--;

        if(N_X < x && mapa[newNY][N_X+1] != '*' && mapa[newNY][N_X+1] != '^' &&
           mapa[newNY][N_X+1] != 'B' && mapa[newNY][N_X+1] != 'O' && mapa[newNY][N_X+1] != 'D' &&
           (newNY != y || N_X+1 != x))
            newNX++;
        else if(N_X > x && mapa[newNY][N_X-1] != '*' && mapa[newNY][N_X-1] != '^' &&
                mapa[newNY][N_X-1] != 'B' && mapa[newNY][N_X-1] != 'O' && mapa[newNY][N_X-1] != 'D' &&
                (newNY != y || N_X-1 != x))
            newNX--;

        int moved = (newNY != N_Y || newNX != N_X);

        if(!moved && N_moved_last_turn == 0) {
            int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
            int k;
            int movedRand = 0;
            for(k=0;k<4;k++){
                int tryY = N_Y + directions[k][0];
                int tryX = N_X + directions[k][1];
                if(tryY > 0 && tryY < a-1 && tryX > 0 && tryX < l-1 &&
                   mapa[tryY][tryX] != '*' && mapa[tryY][tryX] != '^' &&
                   mapa[tryY][tryX] != 'B' && mapa[tryY][tryX] != 'O' &&
                   mapa[tryY][tryX] != 'D' && (tryY != y || tryX != x)) {
                    newNY = tryY; newNX = tryX;
                    movedRand = 1;
                    break;
                }
            }
            if(!movedRand){
                newNY = N_Y;
                newNX = N_X;
            }
        }

        if(newNY > 0 && newNY < a-1 && newNX > 0 && newNX < l-1){
            mapa[newNY][newNX] = 'N';
            N_Y = newNY;
            N_X = newNX;
            N_moved_last_turn = moved ? 1 : 0;
        } else {
            mapa[N_Y][N_X] = 'N';
            N_moved_last_turn = 0;
        }

        int newY = y, newX = x;

        if(tecla=='w') newY--;
        else if(tecla=='a') newX--;
        else if(tecla=='s') newY++;
        else if(tecla=='d') newX++;

        if(mapa[newY][newX] == 'O' && tecla == 'i'){
            int di, dj, paredesDestruidas = 0;
            for(di = -1; di <= 1; di++){
                for(dj = -1; dj <=1; dj++){
                    int ny = newY + di;
                    int nx = newX + dj;
                    if(ny > 0 && ny < a-1 && nx > 0 && nx < l-1){
                        if(mapa[ny][nx] == '*'){
                            mapa[ny][nx] = ' ';
                            paredesDestruidas++;
                        }
                    }
                }
            }
            limpar_tela();
            if(paredesDestruidas > 0){
                printf("Quebrador destruiu %d paredes ao redor!\n", paredesDestruidas);
            } else {
                printf("Nao ha paredes ao redor para destruir.\n");
            }
            esperar_enter();
        }
        else if(newY > 0 && newY < a && newX > 0 && newX < l && mapa[newY][newX] != '*' && mapa[newY][newX] != 'D' && mapa[newY][newX] != 'O'){
            y = newY; x = newX;
        }

        if(y==BY && x==BX && tecla=='i' && botaoescolhido==0){
            botaoescolhido=1;
            for(i=0;i<contespinhos;i++){
                mapa[posicaoespinhos[i][0]][posicaoespinhos[i][1]]=' ';
            }
            limpar_tela();
            printf("Voce pressionou o botao! Os espinhos foram desativados.\n");
            esperar_enter();
            continue;
        }

        // Interação para pegar chaves na Fase3
        if(y==K0Y && x==K0X && !chave0){
            printf("Aperte 'i' para pegar a chave externa\n");
            tecla=getch();
            if(tecla=='i'){
                chave0 =1;
                mapa[K0Y][K0X]=' ';
                mapa[D0Y][D0X]=' ';
                limpar_tela();
                printf("Chave externa adquirida! Porta inicial aberta.\n");
                esperar_enter();
                continue;
            }
        }
        else if(y==K1Y && x==K1X && chave0 && !chave1){
            printf("Aperte 'i' para pegar a chave da area 1\n");
            tecla=getch();
            if(tecla=='i'){
                chave1=1;
                mapa[K1Y][K1X]=' ';
                mapa[D1Y][D1X]=' ';
                limpar_tela();
                printf("Chave da area 1 adquirida! Porta da area 1 aberta.\n");
                esperar_enter();
                continue;
            }
        }
        else if(y==K2Y && x==K2X && chave1 && !chave2){
            printf("Aperte 'i' para pegar a chave da area 2\n");
            tecla=getch();
            if(tecla=='i'){
                chave2=1;
                mapa[K2Y][K2X]=' ';
                mapa[D2Y][D2X]=' ';
                limpar_tela();
                printf("Chave da area 2 adquirida! Porta da area 2 aberta.\n");
                esperar_enter();
                continue;
            }
        }
        else if(y==K3Y && x==K3X && chave2 && !chave3){
            printf("Aperte 'i' para pegar a chave da porta final\n");
            tecla=getch();
            if(tecla=='i'){
                chave3=1;
                mapa[K3Y][K3X]=' ';
                mapa[D3Y][D3X]=' ';
                limpar_tela();
                printf("Chave da porta final adquirida! Porta final aberta.\n");
                esperar_enter();
                continue;
            }
        }

        int noespinho = 0;
        if(!botaoescolhido){
            for(i=0;i<contespinhos;i++){
                if(y==posicaoespinhos[i][0] && x==posicaoespinhos[i][1]){
                    noespinho=1;
                    break;
                }
            }
            if(noespinho){
                vida--;
                y=18; x=1;
                limpar_tela();
                printf("Voce pisou nos espinhos e perdeu uma vida! Vida atual: %d\n", vida);
                if(vida <= 0){
                    printf("Voce morreu! Fim de jogo.\n");
                    esperar_enter();
                    return;
                }
                esperar_enter();
                continue;
            }
        }

        if(y == M_Y && x == M_X){
            vida--;
            y=18; x=1;
            limpar_tela();
            printf("Voce foi atacado pelo monstro M e perdeu uma vida! Vida atual: %d\n", vida);
            if(vida <= 0){
                printf("Voce morreu! Fim de jogo.\n");
                esperar_enter();
                return;
            }
            esperar_enter();
            continue;
        }

        if(y == N_Y && x == N_X){
            vida--;
            y=18; x=1;
            limpar_tela();
            printf("Voce foi atacado pelo monstro N e perdeu uma vida! Vida atual: %d\n", vida);
            if(vida <= 0){
                printf("Voce morreu! Fim de jogo.\n");
                esperar_enter();
                return;
            }
            esperar_enter();
            continue;
        }

        // Interação da porta final para vencer o jogo
        if(chave3 && y == D3Y && x == D3X){
            printf("Aperte 'i' para entrar na porta e vencer o jogo\n");
            tecla = getch();
            if(tecla == 'i'){
                limpar_tela();
                printf("Parabéns, você conquistou a Dungeon!\n");
                printf("Fim de jogo. Pressione 'q' para fechar o programa.\n");

                // Espera o jogador pressionar 'q' para sair
                while(getch() != 'q');

                return;
            }
        }

        limpar_tela();
    }
}

void Tutorial() {
    limpar_tela();
    titulo();
    printf("Este e o tutorial do jogo.\n");
    printf("Você deve explorar as câmaras e pegar as chaves para abrir as portas.\n");
    printf("Aperte 'i' para interagir com objetos e NPCs.\n");
    printf("Use 'w', 'a', 's' e 'd' para mover o personagem.\n");
    printf("Pressione ENTER para voltar ao menu.\n");
    esperar_enter();
}

void Controles() {
    limpar_tela();
    titulo();
    printf("Controles:\n");
    printf("Mover para cima: w\n");
    printf("Mover para esquerda: a\n");
    printf("Mover para direita: d\n");
    printf("Mover para baixo: s\n");
    printf("Interagir: i\n");
    printf("Pressione ENTER para voltar ao menu.\n");
    esperar_enter();
}

void CreditosF() {
    limpar_tela();
    titulo();
    printf("\t\t===== >|< THE DUNGEON CRAWLER GAME >|< =====\n\n");
    printf("Jogo de aventura no qual o jogador assume o papel de protagonista e tenta conquistar uma dungeon passando por diversos puzzles.\n");
    printf("Desenvolvedores: Lucas Pinto, Mario Henrique e Pedro Mansour\n");
    printf("Pressione ENTER para voltar ao menu...\n");
    esperar_enter();
}

int main() {
    srand(time(NULL));
    while(1){
        limpar_tela();
        titulo();
        escolha = 0;

        printf("\t1 - Iniciar\n");
        printf("\t2 - Controles\n");
        printf("\t3 - Creditos\n");
        printf("\t4 - Sair\n\n");
        printf("\tEscolha: ");
        if(scanf("%d", &escolha) != 1){
            while(getchar() != '\n');
            printf("Escolha invalida! Tente novamente.\n");
            esperar_enter();
            continue;
        }
        while(getchar() != '\n');

        switch(escolha){
            case 1:
                iniciar();
                break;
            case 2:
                Controles();
                break;
            case 3:
                CreditosF();
                break;
            case 4:
                limpar_tela();
                titulo();
                printf("Saindo do jogo...\n");
                return 0;
            default:
                printf("Escolha invalida! Tente novamente.\n");
                esperar_enter();
                break;
        }
    }
    return 0;
}

