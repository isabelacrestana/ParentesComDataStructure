#ifndef PILHAS_H_INCLUDED
#define PILHAS_H_INCLUDED
#include <stdlib.h>

typedef struct No
{
    int ind;         //abreviação para índicie
    struct No* prox;
} NO;

typedef struct Stack
{
    NO* TOPO;
} STACK;

STACK* Inicializar(STACK* p)
{
    p = (STACK*) malloc(sizeof(STACK));
    p -> TOPO = NULL;
    return p;
}

NO* ins_inic(NO* aux, int elem)
{
    NO* novo = (NO*) malloc(sizeof(NO));
    novo -> ind = elem;
    novo -> prox = aux;
    return novo;
}

void PUSH (STACK* p, int elem)
{
    p -> TOPO = ins_inic(p -> TOPO, elem);
}

NO* rem_inic(NO* aux)
{
    NO* a = aux -> prox;
    free(aux);
    aux = NULL;
    return a;
}

int POP (STACK* p)
{
    int valor;
    if (p -> TOPO == NULL)
    {
        printf("Pilha vazia");
        exit(0);
    }

    valor = p -> TOPO -> ind;
    p -> TOPO = rem_inic(p -> TOPO);
    return valor;
}

void Imprimir(STACK* p)
{
    NO* aux;
    if (p -> TOPO == NULL || p == NULL)
    {
        printf("Pilha vazia");
    }

    aux = p -> TOPO;

    while(aux != NULL)
    {
        printf("%d ", aux -> ind);
        aux = aux -> prox;
    }
}

STACK* Liberar(STACK* p)
{
    NO* aux = p -> TOPO;
    NO* aux2;

    while(aux != NULL)
    {
        aux2 = aux -> prox;
        free(aux);
        aux = aux2;
    }
    free(p);

    return NULL;
}

#endif // PILHAS_H_INCLUDED
