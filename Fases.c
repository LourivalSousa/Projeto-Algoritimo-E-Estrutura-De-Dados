#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.c"
#include "Game.c"

void comandosFaseUm(char (*ptrComandos)[4]){
    int i;

    for(i=0;i<4;i++){
        for(int j=0;j<4;j++){
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

int FaseUm(){
    char matriz[8][8],comandos[4][4];
    char (*ptrMatriz)[8] = matriz;
    char (*ptrComandos)[4] = comandos;
    initBoard(ptrMatriz);
    comandosFaseUm(ptrComandos);
}


int main (){
    // char matriz[8][8],comandos[4][4];
    // char (*ptrMatriz)[8] = matriz;
    // char (*ptrComandos)[4] = comandos;
    // initBoard(ptrMatriz);
    return 0;
}
