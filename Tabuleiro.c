#include <stdio.h>
#include <stdlib.h>
#define LADOBOARD 8
#define ALTURABOARD 8

char** alocBoard(){
    int i;
    char **board;
    board = (char*) malloc(LADOBOARD*sizeof(char));
    if(board!=NULL){
        for(i=0;i<LADOBOARD;i++){
            board[i] = (char*) calloc(ALTURABOARD,sizeof(char));
        }
    }else{
        printf("Externo Erro ao alocar memoria\n");
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

void printDirectons(char direction){
    printf("DIRECOES \n");
    switch (direction)
    {
    case '>':
    case '<':
        printf(" | P%c |",direction);
        break;
    case '^':
        printf(" | %c |\n",direction);
        printf(" | P |");
        break;
    case 'v':
        printf(" | P |\n");
        printf(" | %c |",direction);
    default:
        break;
    }
}

void printComands(char *comandos){
    int i,j;
    for(i=0;i<3;i++){
       for(j=0;j<3;j++){
            if(*comandos[i][j]!=0){
                printf("| %c ",comandos[i][j]);
            }
       }
       printf("|")
    }
}

void printBoard(){
    system("cls");
    int i,j;
    char **ptrBoard;
    ptrBoard = alocBoard();
    initBoard(ptrBoard);
    for(i=0; i<LADOBOARD; i++){
        printf("|---|---|---|---|---|---|---|---|\n");
        printf("|");
        for(j=0;j<ALTURABOARD;j++){
            char caracter = ptrBoard[i][j];
            switch (caracter)
            {
            case 'P':
            case 'X':
            case 'O':
                printf(" %c |",ptrBoard[i][j]);
                break;
            default:
                printf("   |",ptrBoard[i][j]);
                break;
            }
        }
         printf("\n");
    }
    printf("|---|---|---|---|---|---|---|---|\n");
    printf("\n");
    printDirectons('>');
    desalocarBoard(ptrBoard);
}

int main (){
   printBoard();
    return 0;
}
