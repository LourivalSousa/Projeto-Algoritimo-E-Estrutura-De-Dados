#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.c"
#include "Game.c"
#include "Fila.c"


Comandos pegarComando(){
    Comandos input;
    printf("Digite 0 para sair\n");
    printf("Digite o comando: ");
    scanf("%d",&input.comando);
    printf("Digite o numero de vezes que quer executar este comando: ");
    scanf("%d",&input.vezes);
    return input;
}


void enfileirarComandos(Fila *ptrFila){
    Comandos comandosJogador;
    do {
        comandosJogador = pegarComando();
        enfileirar(ptrFila,comandosJogador);
    } while (comandosJogador.comando > 0 || comandosJogador.vezes > 0);
}

//
//void pegarComandosJogadorPilha(**ptrPilha){
//    Comandos comandosJogador;
//    do {
//        comandosJogador = pegarComando();
//        empilhar(ptrPilha,comandosJogador);
//    } while (comandosJogador.comando<1 || comandosJogador.vezes<1);
//}

void executarComandos(Comandos comandosJogo,char (*ptrMatriz)[8],char (*ptrComandos)[4],char *ptrDirecao,int *ptrPosicao){
    int i,x,y,coluna = 0;
    int linha =  comandosJogo.comando-1;
    for(i=0;i<comandosJogo.vezes;i++){
        while(ptrComandos[linha][coluna]!='0'){
            char comando = ptrComandos[linha][coluna];
            if(comando == 'F'){
                x = ptrPosicao[0];
                y = ptrPosicao[1];
            }
            movimentar(ptrPosicao,comando,ptrDirecao);
            if(posicaoValida(ptrPosicao,ptrMatriz)){
                ptrMatriz[x][y]=' ';
                x = ptrPosicao[0];
                y = ptrPosicao[1];
                ptrMatriz[x][y] = 'P';
            }else{
                ptrPosicao[0] = x;
                ptrPosicao[1] = y;
            }
        }
    }
}

void comandosFaseUm(char (*ptrComandos)[4]){
    int i,j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            ptrComandos[1][i] = '0';
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
    Comandos comandosJogo;
    int tentativa = 3, posicao[2];
    int ptrPosicao = &posicao;
    char matriz[8][8],comandos[4][4],direcao='>';
    char ptrDirecao = &direcao;
    char (*ptrMatriz)[8] = matriz;
    char (*ptrComandos)[4] = comandos;
    Fila *ptrFila;
    //Inicializando o jogo
    initBoard(ptrMatriz);
    comandosFaseUm(ptrComandos);
    ptrFila = (Fila*) malloc(sizeof(Fila));
    inicializarFila(ptrFila);

    while(tentativa!=0){
        printBoard(ptrMatriz);
        printComands(ptrComandos,direcao);
        enfileirarComandos(ptrFila);
        while(!filaVazia(ptrFila)){
            system("cls");
            printBoard(ptrMatriz);
            printComands(ptrComandos,direcao);
            Comandos comandosInicio = retornarInicio(ptrFila);
            printf("Comando: %d\n",comandosInicio.comando);
            printf("Numero de vezes que sera executado: %d\n",comandosInicio.vezes);
            impressaoNaoClassicaFila(ptrFila);
            comandosJogo = desinfileirar(ptrFila);
            executarComandos(comandosJogo,ptrMatriz,ptrComandos,ptrDirecao,ptrPosicao);
            sleep(2);
            if(chegouObjetivo(ptrPosicao,ptrMatriz)){
                tentativa--;
                break;
            }
        }
        if(chegouObjetivo(ptrPosicao,ptrMatriz)){
            return 1;
        }else{
            tentativa--;
        }
    }
    return 0;
}


int main (){
    if(faseUm()){
        printf("Parabens vc é tchola");
    }else{
        printf("voce nao e tchola :(");
    }
    return 0;
}
