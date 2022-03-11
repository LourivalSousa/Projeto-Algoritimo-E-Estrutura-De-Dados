#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.c"
#include "Game.c"
#include "Fila.c"
#include "Pilha.c"


Comandos pegarComando(){
    Comandos input;
    printf("Digite 0 para sair\n");
    printf("Digite o comando: ");
    scanf("%d",&input.comando);
    printf("Digite o numero de vezes que quer executar este comando: ");
    scanf("%d",&input.vezes);
    return input;
}


void enfileirarComandos(*ptrFila){
    Comandos comandosJogador;
    do {
        comandosJogador = pegarComando();
        enfileirar(ptrFila,comandosJogador);
    } while (comandosJogador.comando<1 || comandosJogador.vezes<1);
    
// }

void pegarComandosJogadorPilha(**ptrPilha){
    Comandos comandosJogador;
    do {
        comandosJogador = pegarComando();
        empilhar(ptrPilha,comandosJogador);
    } while (comandosJogador.comando<1 || comandosJogador.vezes<1);
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
    char matriz[8][8],comandos[4][4];
    char (*ptrMatriz)[8] = matriz;
    char (*ptrComandos)[4] = comandos;
    initBoard(ptrMatriz);
    comandosFaseUm(ptrComandos);
    printBoard(ptrMatriz);
    printComands(ptrComandos,'v');
    
    return 1;
}


int main (){
    // char matriz[8][8],comandos[4][4];
    // char (*ptrMatriz)[8] = matriz;
    // char (*ptrComandos)[4] = comandos;
    // initBoard(ptrMatriz);
    faseUm();
    return 0;
}
