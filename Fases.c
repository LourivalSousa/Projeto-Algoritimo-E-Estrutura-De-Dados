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
            sleep(2);
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
            sleep(2);
            comandosJogo = desenfileirar(ptrFila);
            for(i=0;i<comandosInicio.vezes;i++){
                executarComandos(comandosJogo.comando,ptrMatriz,ptrComandos,ptrDirecao,ptrPosicao);
            }
        }
        if(chegouObjetivo(ptrPosicao,ptrMatriz)==1){
            if(filaVazia(ptrFila)==1){
                system("cls");
                printBoard(ptrMatriz,fase);
                printComands(ptrComandos,direcao);
                sleep(2);
                free(ptrFila);
                return 1;
            }else{
                sleep(2);
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
    
    while(tentativa!=0){
        comandosFaseDois(ptrComandos);
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
            sleep(2);
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
                sleep(2);
                return 1;
            }else{
                sleep(2);
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
    comandosFaseTres(ptrComandos);
    inicializarFila(ptrFila);
    
    while(tentativa!=0){
        comandosFaseTres(ptrComandos);
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
            sleep(2);
            comandosJogoFila = desenfileirar(ptrFila);
            for(i=0;i<comandosJogoFila.vezes;i++){
                executarComandos(comandosJogoFila.comando,ptrMatriz,ptrComandos,ptrDirecao,ptrPosicao);
            }
        }
        if(chegouObjetivo(ptrPosicao,ptrMatriz)==1){
            if(filaVazia(ptrFila)==1){
                system("cls");
                printBoard(ptrMatriz,fase);
                printComands(ptrComandos,direcao);
                sleep(2);
                free(ptrFila);
                break;
            }else{
                sleep(2);
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
        comandosFaseTres(ptrComandos);
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
            sleep(2);
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
                sleep(2);
                return 1;
            }else{
                sleep(2);
                resetBoardFaseTres(ptrMatriz,ptrPosicao,ptrDirecao);
                tentativa--;
            }
        }
    }
    return 0;

}