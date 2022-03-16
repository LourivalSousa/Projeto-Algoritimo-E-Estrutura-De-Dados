#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.c"
#include "Game.c"
#include "Fila.c"
#include "Pilha.c"

Comandos pegarComandoFila(){
    Comandos input;
    printf("Para encerrar a escolha de comandos e prosseguir no jogo digite 0\n");
    printf("Insira o comando: ");
    scanf("%d",&input.comando);
    if(input.comando==0){
        return input;
    }
    printf("Insira o numero de vezes que deseja executar este comando: ");
    scanf("%d",&input.vezes);
    return input;
}
ComandosPilha pegarComandoPilha(){
    ComandosPilha input;
    printf("Para encerrar a escolha de comandos e prosseguir no jogo digite 0\n");
    printf("Insira o comando: ");
    scanf("%d",&input.comando);
    if(input.comando==0){
        return input;
    }
    printf("Insira o numero de vezes que deseja executar este comando: ");
    scanf("%d",&input.vezes);
    return input;
}


void enfileirarComandos(Fila *ptrFila,char (*ptrMatriz)[8],char (*ptrComandos)[4],char direcao,int fase,int tentativa){
    Comandos comandosJogador;
    do {
        system("cls");
        printBoard(ptrMatriz,fase);
        printComands(ptrComandos,direcao);
        printf("TENTATIVAS: %d\n",tentativa);
        impressaoNaoClassicaFila(ptrFila);
        comandosJogador = pegarComandoFila();
        if(comandosJogador.comando==0 || comandosJogador.vezes==0){
            break;
        }
        if(comandosJogador.comando > 4 || comandosJogador.comando < 0 ){
            printf("Comando invalido, insira seu comando novamente...\n");
            sleep(1);
        }else{
            enfileirar(ptrFila,comandosJogador);
        }
    } while (comandosJogador.comando > 0 || comandosJogador.vezes > 0);
}


void empilharComandos(NOPilha **ptrPilha,char (*ptrMatriz)[8],char (*ptrComandos)[4],char direcao,int fase, int tentativa){
    ComandosPilha comandosJogador;
    do {
        system("cls");
        printBoard(ptrMatriz,fase);
        printComands(ptrComandos,direcao);
        printf("TENTATIVAS: %d\n",tentativa);
        impressaoNaoClassicaPilha(*ptrPilha);
        comandosJogador = pegarComandoPilha();
        if(comandosJogador.comando==0 || comandosJogador.vezes==0){
            break;
        }
        if(comandosJogador.comando > 4 || comandosJogador.comando < 0 ){
            printf("Comando invalido, insira seu comando novamente...\n");
            sleep(1);
        }else{
            empilhar(ptrPilha,comandosJogador);
        }
    }while (comandosJogador.comando > 0 || comandosJogador.vezes > 0);
}

void executarComandos(int comandoJogo,char (*ptrMatriz)[8],char (*ptrComandos)[4],char *ptrDirecao,int *ptrPosicao){
    int i,x=0,y=0,coluna = 0;
    char comando;
    int linha = comandoJogo - 1;
    while(ptrComandos[linha][coluna]!='0'){
        comando = ptrComandos[linha][coluna];
        x = ptrPosicao[0];
        y = ptrPosicao[1];
        movimentar(ptrPosicao,comando,ptrDirecao);
        if(posicaoValida(ptrPosicao,ptrMatriz)!=0){
            ptrMatriz[x][y]=' ';
            x = ptrPosicao[0];
            y = ptrPosicao[1];
            ptrMatriz[x][y] = 'P';
        }else{
            ptrPosicao[0] = x;
            ptrPosicao[1] = y;
        }
        coluna++;
    }
}

void comandosFaseUm(char (*ptrComandos)[4]){
    int i,j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            ptrComandos[i][j] = '0';
        }
    }
    //Comando 1
    ptrComandos[0][0] = 'F';
    ptrComandos[0][1] = 'F';
    ptrComandos[0][2] = 'F';
    //Comando 2
    ptrComandos[1][0] = 'E';
    ptrComandos[1][1] = 'F';
    // Comando 3
    ptrComandos[2][0] = 'D';
    ptrComandos[2][1] = 'F';
    // Comando 4
    ptrComandos[3][0] = 'F';
    ptrComandos[3][1] = 'E';
}

int faseUm(){
    //  Variaveis do jogo
    Comandos comandosJogo,comandosInicio;
    int i,tentativa = 3, posicao[2],fase=1;
    int *ptrPosicao = &posicao;
    char matriz[8][8],comandos[4][4],direcao;
    char *ptrDirecao = &direcao;
    char (*ptrMatriz)[8] = matriz;
    char (*ptrComandos)[4] = comandos;
    //Inicializando o jogo
    Fila *ptrFila;
    ptrFila = (Fila*) malloc(sizeof(Fila));
    initBoard(ptrMatriz);
    initMoviment(ptrPosicao,ptrDirecao);
    comandosFaseUm(ptrComandos);
    inicializarFila(ptrFila);
    
    while(tentativa!=0){
        comandosFaseUm(ptrComandos);
        enfileirarComandos(ptrFila,ptrMatriz,ptrComandos,direcao,fase,tentativa);
        // loop interno
        while(!chegouObjetivo(ptrPosicao,ptrMatriz)){
             if(filaVazia(ptrFila)==1){
                resetBoard(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
                break;
            }
            comandosInicio = retornarInicio(ptrFila);
            system("cls");
            printBoard(ptrMatriz,fase);
            printComands(ptrComandos,direcao);
            printf("TENTATIVAS: %d\n",tentativa);
            impressaoNaoClassicaFila(ptrFila);
            printf("Comando: %d\n",comandosInicio.comando);
            printf("Numero de vezes que sera executado: %d\n",comandosInicio.vezes);
            sleep(1);
            comandosJogo = desinfileirar(ptrFila);
            for(i=0;i<comandosInicio.vezes;i++){
                executarComandos(comandosJogo.comando,ptrMatriz,ptrComandos,ptrDirecao,ptrPosicao);
            }
        }
        if(chegouObjetivo(ptrPosicao,ptrMatriz)==1){
            if(filaVazia(ptrFila)==1){
                system("cls");
                printBoard(ptrMatriz,fase);
                printComands(ptrComandos,direcao);
                sleep(1);
                free(ptrFila);
                return 1;
            }else{
                sleep(1);
                resetBoard(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
            }
        }
        if(tentativa == 0){
            free(ptrFila);
            return 0;
        }
    }
    return 0;
}

int faseDois(){
    //  Variaveis do jogo
    ComandosPilha comandosJogo,comandosInicio;
    int i,tentativa = 3, posicao[2],fase=2;
    int *ptrPosicao = &posicao;
    char matriz[8][8],comandos[4][4],direcao;
    char *ptrDirecao = &direcao;
    char (*ptrMatriz)[8] = matriz;
    char (*ptrComandos)[4] = comandos;
    //Inicializando o jogo
    NOPilha *ptrPilha;
    inicializarPilha(&ptrPilha);
    initBoard(ptrMatriz);
    initMoviment(ptrPosicao,ptrDirecao);
    comandosFaseUm(ptrComandos);
    
    while(tentativa!=0){
        comandosFaseUm(ptrComandos);
        empilharComandos(&ptrPilha,ptrMatriz,ptrComandos,direcao,fase,tentativa);
        // loop interno
        while(!chegouObjetivo(ptrPosicao,ptrMatriz)){
             if(pilhaVazia(ptrPilha)){
                resetBoard(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
                break;
            }
            comandosInicio = retornarTopo(ptrPilha);
            system("cls");
            printBoard(ptrMatriz,fase);
            printComands(ptrComandos,direcao);
            printf("TENTATIVAS: %d\n",tentativa);
            impressaoNaoClassicaPilha(ptrPilha);
            printf("Comando: %d\n",comandosInicio.comando);
            printf("Numero de vezes que sera executado: %d\n",comandosInicio.vezes);
            sleep(1);
            comandosJogo = desempilhar(&ptrPilha);
            for(i=0;i<comandosInicio.vezes;i++){
                executarComandos(comandosJogo.comando,ptrMatriz,ptrComandos,ptrDirecao,ptrPosicao);
            }
        }
        if(chegouObjetivo(ptrPosicao,ptrMatriz)==1){
            if(pilhaVazia(ptrPilha)){
                system("cls");
                printBoard(ptrMatriz,fase);
                printComands(ptrComandos,direcao);
                sleep(1);
                return 1;
            }else{
                sleep(1);
                resetBoard(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
            }
        }
    }
    return 0;
}

int faseTres(){
    ComandosPilha comandosJogoPilha, comandosInicioPilha;
    Comandos comandosJogoFila,comandosInicioFila;
    int i,tentativa = 3, posicao[2],fase=3;
    int *ptrPosicao = &posicao;
    char matriz[8][8],comandos[4][4],direcao;
    char *ptrDirecao = &direcao;
    char (*ptrMatriz)[8] = matriz;
    char (*ptrComandos)[4] = comandos;
    //Inicializando o jogo
    Fila *ptrFila;
    ptrFila = (Fila*) malloc(sizeof(Fila));
    initBoard(ptrMatriz);
    initMoviment(ptrPosicao,ptrDirecao);
    comandosFaseUm(ptrComandos);
    inicializarFila(ptrFila);
    
    while(tentativa!=0){
        comandosFaseUm(ptrComandos);
        enfileirarComandos(ptrFila,ptrMatriz,ptrComandos,direcao,fase,tentativa);
        // loop interno
        while(!chegouObjetivo(ptrPosicao,ptrMatriz)){
             if(filaVazia(ptrFila)==1){
                resetBoard(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
                break;
            }
            comandosInicioFila = retornarInicio(ptrFila);
            system("cls");
            printBoard(ptrMatriz,fase);
            printComands(ptrComandos,direcao);
            printf("TENTATIVAS: %d\n",tentativa);
            impressaoNaoClassicaFila(ptrFila);
            printf("Comando: %d\n",comandosInicioFila.comando);
            printf("Numero de vezes que sera executado: %d\n",comandosInicioFila.vezes);
            sleep(1);
            comandosJogoFila = desinfileirar(ptrFila);
            for(i=0;i<comandosJogoFila.vezes;i++){
                executarComandos(comandosJogoFila.comando,ptrMatriz,ptrComandos,ptrDirecao,ptrPosicao);
            }
        }
        if(chegouObjetivo(ptrPosicao,ptrMatriz)==1){
            if(filaVazia(ptrFila)==1){
                system("cls");
                printBoard(ptrMatriz,fase);
                printComands(ptrComandos,direcao);
                sleep(1);
                free(ptrFila);
                break;
            }else{
                sleep(1);
                resetBoard(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
            }
        }
    }
    if(tentativa == 0){
        free(ptrFila);
        return 0;
    }
    // Fase 3 parte 2
    NOPilha *ptrPilha;
    inicializarPilha(&ptrPilha);
    ptrMatriz[0][0] = 'O';
    printf("X-%d Y-%d",posicao[0],posicao[1]);
    direcao = '<';
    while(tentativa!=0){
        comandosFaseUm(ptrComandos);
        empilharComandos(&ptrPilha,ptrMatriz,ptrComandos,direcao,fase,tentativa);
        // loop interno
        while(!chegouObjetivoFaseTres(ptrPosicao,ptrMatriz)){
             if(pilhaVazia(ptrPilha)){
                resetBoardFaseTres(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
                break;
            }
            comandosInicioPilha = retornarTopo(ptrPilha);
            system("cls");
            printBoard(ptrMatriz,fase);
            printComands(ptrComandos,direcao);
            impressaoNaoClassicaPilha(ptrPilha);
            printf("Comando: %d\n",comandosInicioPilha.comando);
            printf("Numero de vezes que sera executado: %d\n",comandosInicioPilha.vezes);
            sleep(1);
            comandosJogoPilha = desempilhar(&ptrPilha);
            for(i=0;i<comandosJogoPilha.vezes;i++){
                executarComandos(comandosJogoPilha.comando,ptrMatriz,ptrComandos,ptrDirecao,ptrPosicao);
            }
        }
        if(chegouObjetivoFaseTres(ptrPosicao,ptrMatriz)==1){
            if(pilhaVazia(ptrPilha)){
                system("cls");
                printBoard(ptrMatriz,fase);
                printComands(ptrComandos,direcao);
                sleep(1);
                return 1;
            }else{
                sleep(1);
                resetBoardFaseTres(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
            }
        }
    }
    return 0;

}
int main (){
    
    if(faseUm()){
        printf("Voce passou da Fase 1!\n");
        sleep(1);
        if(faseDois()){
            printf("Voce passou da Fase 2!");
            sleep(1);
            if(faseTres()){
                printf("Voce Ganhou o jogo!!");
            }
        }
    }
    // if(faseTres()){
    //     printf("Voce passou da fase 3");
    // }
    

    return 0;
}
