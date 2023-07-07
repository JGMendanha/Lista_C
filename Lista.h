#ifndef Lista_HEADER
#define Lista_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char nome[10];
    int qnt;
    float peso;
    char descricao[100];
}TProduto;

typedef struct celula{
    TProduto item;
    struct celula* prox;
}TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

void IniciaLista(TLista *Lista);

void Inserir(TProduto x, TLista *Lista);

void LerProduto(TProduto *x);

void Imprimir(TLista Lista);

void ImprimirProduto(TProduto x);

TCelula* Pesquisa(TLista Lista,TProduto x);

void Excluir(TLista *Lista, TProduto *item);

void ExcluirImpar(TLista *Lista);

void ExcluirTudo(TLista *Lista);

int Vazia(TLista Lista);

int VerificaIgualdade(TLista *lista1, TLista *lista2);

void Concatena(TLista *lista1, TLista *lista2);

void DividirLista(TLista *lista1, TLista *lista2, TLista *lista3);

void ImprimirCelula(TLista *lista, int celula);

void ExcluirCelula(TLista *lista, int celula);

#endif
