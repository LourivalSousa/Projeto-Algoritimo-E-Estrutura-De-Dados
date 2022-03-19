#include "stdio.h"
#include "stdlib.h"
#include "Fases.c"
int main (){
    int op;
    do{
        printf("Selecione uma opcao:\n");
        printf("1 - Iniciar jogo\n");
        printf("2 - Sair\n");
        printf("--> ");
        scanf("%d",&op);
        fflush(stdin);
        switch(op){
            case 1: 
                do{
                    if(faseUm()){
                        printf("Muito bem! Voce passou da Fase 1!\n");
                        sleep(1);
                        if(faseDois()){
                            printf("Boa! Voce passou da Fase 2!\n");
                            sleep(1);
                            if(faseTres()){
                                printf("Parabens!! Voce passou as 3 fases e ganhou o jogo!!\n");
                            }
                        }
                    }else{
                        printf("Que pena! Voce perdeu!\n");
                    }
                    do{
                        printf("Deseja jogar novamente?\n");
                        printf("1 - Sim\n");
                        printf("2 - Nao\n");
                        printf("--> ");
                        scanf("%d", &op);
                        fflush(stdin);
                        if(op!=1&&op!=2){
                            printf("Opcao invalida! Tente novamente.\n");
                            sleep(2);
                            system("cls");
                        }
                    }while(op!=1&&op!=2);
                }while(op!=2);
                break;
            case 2:
                break;
            default:
                printf("Opcao invalida! Tente novamente.");
                sleep(2);
                system("cls");
                break;
        }
    }while(op!=2);
    printf("Saindo...");
    return 0;
}