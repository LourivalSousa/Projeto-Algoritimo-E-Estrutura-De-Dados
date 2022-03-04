#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.c"


// char** alocBoard(){
//     int i,j;
//     char **board;
//     board = (char*) malloc(LADOBOARD*sizeof(char));
//     if(board!=NULL){
//         for(i=0;i<LADOBOARD;i++){
//             board[i] = (char*) malloc(ALTURABOARD*sizeof(char));
//         }
//     }else{
//         printf("Erro ao alocar memoria\n");
//         return NULL;
//     }
//     return board;
// }

// void desalocarBoard(char **board){
//     int i;
//     for(i=0;i<LADOBOARD;i++){
//         free(board[i]);
//     }
//     free(board);
// }


void initBoard(char (*ptrMatriz)[8]){
    ptrMatriz[0][0] = 'P';
    ptrMatriz[1][1] = 'X';
    ptrMatriz[2][1] = 'X';
    ptrMatriz[2][3] = 'X';
    ptrMatriz[2][4] = 'X';
    ptrMatriz[2][7] = 'X';
    ptrMatriz[3][7] = 'X';
    ptrMatriz[5][4] = 'X';
    ptrMatriz[5][5] = 'X';
    ptrMatriz[5][6] = 'X';
    ptrMatriz[6][0] = 'X';
    ptrMatriz[7][0] = 'X';
    ptrMatriz[7][3] = 'X';
    ptrMatriz[7][4] = 'X';
    ptrMatriz[7][7] = 'O';
}


char proximaDirecao(char direcao){
    char proximaDirecao;
    switch (direcao)
    {
    case '>':
        proximaDirecao = 'v';
        break;
    case 'v':
        proximaDirecao = '<';
        break;
    case '<':
        proximaDirecao = '^';
        break;
    case '^':
        proximaDirecao = '>';
        break;
    default:
        break;
    }
    return proximaDirecao;
}

char direcaoAnterior(char direcao){
    char direcaoAnterior;
     switch (direcao)
    {
    case '>':
        direcaoAnterior = '^';
        break;
    case 'v':
        direcaoAnterior = '>';
        break;
    case '<':
        direcaoAnterior = 'v';
        break;
    case '^':
        direcaoAnterior = '<';
        break;
    default:
        break;
    }
    return direcaoAnterior;

}


void moverParaFrente(int *ptrCoord,char direcao){
    switch (direcao)
    {
    case '^':
        ptrCoord[0] -=1;
        break;
    case 'v':
        ptrCoord[0] +=1;
        break;
    case '>':
        ptrCoord[1] +=1;
        break;
    case '<':
        ptrCoord[1] -=1;
        break;
    default:
        break;
    }
}
void movimentar(int *ptrCoord,char comando,char *direcao){
    switch(comando){
        case 'F':
            moverParaFrente(ptrCoord,*direcao);
            break;
        case 'E':
            *direcao = direcaoAnterior(*direcao);
            break;
        case 'D':
            *direcao = proximaDirecao(*direcao);
            break;
        default:
            break;
    }
}

int posicaoValida(int *ptrCoord,char (*ptrMatriz)[8]){
    int x,y;
    x = ptrCoord[0];
    y = ptrCoord[1];
    if(x>7 && y>7) return 0;
    if(x<0 && y<0) return 0;
    if(ptrMatriz[x][y]=='X') return 0;
    return 1;
}

int chegouObjetivo(int *ptrCoord,char (*ptrMatriz)[8]){
    int x,y;
    x = ptrCoord[0];
    y = ptrCoord[1];
    if(ptrMatriz[x][y]=='O') return 1;
    return 0;
}

