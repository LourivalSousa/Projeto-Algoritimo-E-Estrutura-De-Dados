#include <stdio.h>
#include <stdlib.h>
#include "Game.c"

void definirComandosFaseUm(char (*ptrComandos)[4]){
    int i;

    for(i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ptrComandos[1][i] = '0';
        }
    }
    ptrComandos[0][0] = 'F';
    ptrComandos[0][1] = 'F';
    ptrComandos[0][2] = 'F';

    ptrComandos[1][0] = 'E';
    ptrComandos[1][1] = 'F';

    ptrComandos[2][0] = 'D';
    ptrComandos[2][1] = 'F';

    ptrComandos[3][0] = 'F';
    ptrComandos[3][1] = 'E';
  
}

void primeiraFase(){
    // definir a matriz de comandos

    // Inicializando as variaveis
    char matriz[8][8],direcao,comando;
    char (*ptrMatriz)[8] = &matriz;
    char *ptrDirecao = &direcao;
    int posicao[2],x,y;
    int *ptrPosicao = &posicao;
    //Comandos
    char comandos[4][4], *ptrComandos;
    (*ptrComandos)[4] = &comandos;

}