#include <stdio.h>
#include <stdlib.h>

void initMoviment(int *ptrPosicao, char *ptrDirecao){
    ptrPosicao[0] = 0;
    ptrPosicao[1] = 0;
    ptrDirecao = ">";
}

void resetBoard(char (*ptrMatriz)[8],int *ptrCoord){
    int x = ptrCoord[0];
    int y = ptrCoord[1];
    ptrMatriz[x][y] = ' ';
    ptrMatriz[0][0] = 'P';
    ptrMatriz[7][7] = 'O';
    ptrCoord[0] = 0;
    ptrCoord[1] = 0;
}


void initBoard(char (*ptrMatriz)[8]){
    ptrMatriz[0][0] = 'P';
    ptrMatriz[1][0] = 'X';
    ptrMatriz[1][3] = 'X';
    ptrMatriz[1][4] = 'X';
    ptrMatriz[2][0] = 'X';
    ptrMatriz[2][6] = 'X';
    ptrMatriz[3][6] = 'X';
    ptrMatriz[4][2] = 'X';
    ptrMatriz[4][3] = 'X';
    ptrMatriz[4][4] = 'X';
    ptrMatriz[5][6] = 'X';
    ptrMatriz[5][7] = 'X';
    ptrMatriz[6][0] = 'X';
    ptrMatriz[6][1] = 'X';
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

