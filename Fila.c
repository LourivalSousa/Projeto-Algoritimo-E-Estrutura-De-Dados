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

typedef struct sFila{
    NO *inicio;
    NO *fim;
}Fila;

NO* alocarNo(){
    return (NO*) malloc(sizeof(NO));
}
 
void desalocarNo(NO *No){
    free(No);
}
 
void inicializarFila(Fila *ptrFila){
    ptrFila->inicio = NULL;
    ptrFila->fim = NULL;
}
 
int filaVazia(Fila *ptrFila){
    if(ptrFila->inicio==NULL){
        return 1;
    }
    return 0;
}

void enfileirar(Fila *ptrFila,Comandos elemento){
    NO *novo;
    novo = alocarNo();
    if(novo!=NULL){
        novo->info.comando = elemento.comando;
        novo->info.vezes = elemento.vezes;
        novo->prox = NULL;
        if(filaVazia(ptrFila)){
            ptrFila->inicio = novo;
            ptrFila->fim = novo;
        }else{
            (ptrFila->fim)->prox = novo;
            ptrFila->fim = novo;
        }
    }else{
        printf("ERRO-Alocacao de memoria falhou...\n");
    }
}

Comandos desenfileirar (Fila *ptrFila){
    NO *aux;
    Comandos elemento;
    if(!filaVazia(ptrFila)){
        elemento = (ptrFila->inicio)->info;
        aux = ptrFila->inicio;
        (ptrFila->inicio) = (ptrFila->inicio)->prox;
        desalocarNo(aux);
        return elemento;
    }else{
        printf("ERRO-Fila filaVazia...\n");
    }
    return elemento;
}

void impressaoNaoClassicaFila(Fila *ptrFila){
    printf("Fila: ");
    if(!filaVazia(ptrFila)){
        NO *aux;
        aux = ptrFila->inicio;
        while(aux!=NULL){
            printf("%d-%d ",aux->info.comando,aux->info.vezes);
            aux = aux->prox;
        }
        printf("\n");
    }else{
        printf("Vazia\n");
    }
}

Comandos retornarInicio(Fila *ptrFila){
    Comandos elemento;
    if(!filaVazia(ptrFila)){
        elemento = (ptrFila->inicio)->info;
    }
    return elemento;
}