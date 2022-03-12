#include <stdio.h>
#include <stdlib.h>

typedef struct sComandosPilha{
    int comando;
    int vezes;
}ComandosPilha;

typedef struct sNOPilha{
    ComandosPilha info;
    struct sNO *prox;
}NOPilha;


NOPilha* alocarNoPilha(){
    return (NOPilha*) malloc(sizeof(NOPilha));
}
 
void desalocarNoPilha(NOPilha *No){
    free(No);
}
 
void inicializarPilha(NOPilha **topo){
    *topo = NULL;
}
 
int pilhaVazia(NOPilha *topo){
    if(topo==NULL){
        return 1;
    }
    return 0;
}

void empilhar(NOPilha **topo, ComandosPilha elemento){
    NOPilha *novo;
    novo = alocarNo();
    if(novo!=NULL){
        novo->info.comando = elemento.comando;
        novo->info.vezes = elemento.vezes;
        novo->prox = (*topo);
        *topo = novo;
    }else{
        printf("ERRO-Alocacao de memoria falhou...\n");
    }
}

ComandosPilha desempilhar(NOPilha **topo){
    NOPilha *aux;
    if(!pilhaVazia(*topo)){
        ComandosPilha elemento;
        elemento =  (*topo)->info;
        aux = (*topo);
        (*topo) = (*topo)->prox;
        desalocarNo(aux);
        return elemento;
    }else{
        printf("ERRO-Pilha pilhaVazia...\n");
    }
    return;
}

void impressaoNaoClassicaPilha(NOPilha *topo){
    printf("Pilha: ");
    if(!pilhaVazia(topo)){
        NOPilha *aux;
        aux = topo;
        while(aux!=NULL){
            printf("%d-%d ",aux->info.comando,aux->info.vezes);
            aux = aux->prox;
        }
        printf("\n");
    }else{
        printf("Vazia\n");
    }
}

ComandosPilha retornarTopo (NOPilha *topo){
    if(!pilhaVazia(topo)){
        ComandosPilha elemento = topo->info;
        return elemento;
    }else{
        printf("Vazia\n");
    }
    return;
}
