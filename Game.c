#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.c"


char** alocBoard(){
    int i;
    char **board;
    board = (char*) malloc(LADOBOARD*sizeof(char));
    if(board!=NULL){
        for(i=0;i<LADOBOARD;i++){
            board[i] = (char*) calloc(ALTURABOARD,sizeof(char));
        }
    }else{
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    return board;
}

void desalocarBoard(char **board){
    int i;
    for(i=0;i<LADOBOARD;i++){
        free(board[i]);
    }
    free(board);
}


void initBoard(char **board){
    board[0][0] = 'P';
    board[1][1] = 'X';
    board[2][1] = 'X';
    board[2][3] = 'X';
    board[2][4] = 'X';
    board[2][7] = 'X';
    board[3][7] = 'X';
    board[5][4] = 'X';
    board[5][5] = 'X';
    board[5][6] = 'X';
    board[6][0] = 'X';
    board[7][0] = 'X';
    board[7][3] = 'X';
    board[7][4] = 'X';
    board[7][7] = 'O';
}

void moverParaFrente(int coord[2],char direcao){
    switch (direcao)
    {
    case '^':
        coord[0] -=1;
        break;
    case 'v':
        coord[0] +=1;
        break;
    case '>':
        coord[1] +=1;
        break;
    case '<':
        coord[1] -=1;
        break;
    default:
        break;
    }
}

void movimentar(int coord[2],char comando){
    switch(comando){
        case 'F':
            // mover para frente
            break;
        case 'E':
            // manipular lista circular
            break;
        case 'D'
            // manipular lista circular
            break;
    }
}

// funcao responsavel pelos movimentos
// funcao responsavel pela conferencia se o player passou em lugar invalido ou esta na parece
// funcao para conferir se o player chegou ao objetivo
// funcao de fases 


int main (){
    return 0;
}