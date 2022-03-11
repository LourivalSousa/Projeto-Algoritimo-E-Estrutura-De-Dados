#include <stdio.h>
#include <stdlib.h>
#define LADOBOARD 8
#define ALTURABOARD 8

void printComands(char (*ptrComandos)[4],char direction){
    int i,j;
    printf("Comandos: ");
    printf("                DIRECAO \n");
    for(i=0;i<4;i++){
        printf("%d) |",i+1);
        for(j=0;j<4;j++){
           switch(ptrComandos[i][j]){
            case 'F':
            case 'E':
            case 'D':
                printf(" %c |",ptrComandos[i][j]);
                break;
            default:
                printf("    ");
                break;
           }
        }
        if(i<2){
            printDirectons(direction,i);
        }
        printf("\n");
    }
    printf("\n");
}
void printDirectons(char direction,int linha){
    switch (direction)
    {
    case '>':
        if(linha==0){
            printf("       | P%c |",direction);
        }
        break;
    case '<':
        if(linha==0){
            printf("       | %cP |",direction);
        }
        break;
    case '^':
        if(linha==0){
            printf("       | %c |",direction);
        }
        if(linha==1){
            printf("       | P |");
        }
        break;
    case 'v':
        if(linha==0){
            printf("       | P |");
        }
        if(linha==1){
            printf("       | %c |",direction);
        }
        break;
    default:
        break;
    }
}

void printBoard(char (*ptrBoard)[8]){
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
                printf("   |");
                break;
            }
        }
        printf("\n");
    }
    printf("|---|---|---|---|---|---|---|---|\n\n");
}
