#include <stdio.h>
#include <stdlib.h>
#define LADOBOARD 8
#define ALTURABOARD 8

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

void printBoard(char **ptrBoard){
    system("cls");
    int i,j;
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
