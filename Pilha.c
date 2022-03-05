#include <stdio.h>
#include <stdlib.h>

typedef struct sComandos{
    int comando;
    int vezes;
}Comandos;

typedef struct sNO{
    Comandos info;
    struct sNO *prox;
}NO;


NO* alocarNo(){
    return (NO*) malloc(sizeof(NO));
}
 
void desalocarNo(NO *No){
    free(No);
}
 
void inicializarPilha(NO **topo){
    *topo = NULL;
}
 
int vazia(NO *topo){
    if(topo==NULL){
        return 1;
    }
    return 0;
}

void empilhar(NO **topo, Comandos elemento){
    NO *novo;
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

Comandos desempilhar(NO **topo){
    NO *aux;
    if(!vazia(*topo)){
        Comandos elemento;
        elemento =  (*topo)->info;
        aux = (*topo);
        (*topo) = (*topo)->prox;
        desalocarNo(aux);
        return elemento;
    }else{
        printf("ERRO-Pilha vazia...\n");
    }
    return;
}

void impressaoNaoClassicaPilha(NO *topo){
    printf("Pilha: ");
    if(!vazia(topo)){
        NO *aux;
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

Comandos retornarTopo (NO *topo){
    if(!vazia(topo)){
        Comandos elemento = topo->info;
        return elemento;
    }else{
        printf("Vazia\n");
    }
    return;
}
