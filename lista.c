#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

void IniciaLista(TLista *Lista) {
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

void LerProduto(TProduto *x){
    printf("\ndigite o codigo do produto: ");
    scanf("%d",&x->codigo);
    printf("digite a quantidade do produto: ");
    scanf("%d",&x->qnt);
    printf("digite o peso do produto: ");
    scanf("%f",&x->peso);
    printf("digite a descricao do produto (ate 100 letras): ");
    fflush(stdin);
    scanf ("%s", x->descricao);
    printf("digite o nome do produto (ate 10 letras): ");
    fflush(stdin);
    scanf ("%s", x->nome);
    printf("\n==========================================\n");

}

void Imprimir(TLista Lista){
    TCelula* Aux = Lista.primeiro->prox;
        while(Aux != NULL){
            ImprimirProduto(Aux->item);
            Aux = Aux->prox;
        }
}

void ImprimirProduto(TProduto x){
    printf("\ncodigo: %d\n", x.codigo);
    printf("quantidade: %d\n", x.qnt);
    printf("peso: %f\n", x.peso);
    printf("nome: ");
    puts(x.nome);
    printf("descricao: ");
    puts(x.descricao);
    printf("\n==========================================\n");
}

TCelula* Pesquisa(TLista Lista,TProduto x){
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux->prox != NULL){
        if(Aux->prox->item.codigo == x.codigo){
            return Aux;

        }
        Aux = Aux->prox;
    }

    return NULL;
}

void Excluir(TLista *Lista, TProduto *item){
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisa(*Lista, *item);
    if(Aux1 != NULL){
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *item = Aux2->item;
        if(Aux1->prox == NULL){
            Lista->ultimo = Aux1;
        }
        free(Aux2);
        Lista->tamanho--;

    }
}

void ExcluirImpar(TLista *Lista){
    TCelula *Aux1;
    Aux1 = Lista->primeiro;
    while(Aux1->prox != NULL){
        if(Aux1->prox->item.codigo % 2 != 0){
            Excluir(Lista, &Aux1->prox->item);
        }
        else
        {
            Aux1= Aux1->prox;
        }

    }
}

void ExcluirTudo(TLista *Lista){
    TCelula *Aux1, *Aux2;
    Aux1 = Lista->primeiro;
    while(Aux1->prox != NULL){

        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        free(Aux2);
        Lista->tamanho--;
        Aux1= Aux1->prox;
    }

    free(Lista->primeiro);
    free(Lista->ultimo);
    free(Lista);
}

int VerificaIgualdade(TLista *lista1, TLista *lista2){
    int i = 0;
    TCelula *Aux1, *Aux2;
    Aux1 = lista1->primeiro;
    Aux2 = lista2->primeiro;
    if(lista1->tamanho != lista2->tamanho){
        return 0;
    }
    while(Aux1->prox != NULL){
        while(Aux2->prox != NULL){
            if(Aux2->prox->item.codigo == Aux1->prox->item.codigo){
                i++;
            }
            Aux2 = Aux2->prox;
        }
        Aux2 = lista2->primeiro;
        Aux1 = Aux1->prox;
    }
    if(i == lista1->tamanho){
        return 1;
    }
    else{
        return 0;
    }
}

void Concatena(TLista *lista1, TLista *lista2){
    TCelula *Aux1;
    Aux1 = lista2->primeiro;
    while(Aux1->prox != NULL){
        Inserir(Aux1->prox->item, lista1);
        Aux1 = Aux1->prox;
    }

    printf("\nResultado: \n");
    Imprimir(*lista1);
}

void DividirLista(TLista *lista1, TLista *lista2, TLista *lista3){
    if(lista1->tamanho != 0){
        int tamanho1, tamanho2, i, j;
        TCelula *Aux1;
        Aux1 = lista1->primeiro;

        tamanho2 = lista1->tamanho / 2;
        tamanho1 = lista1->tamanho - tamanho2;

        for(i = 0; i < tamanho1; i++){
            Inserir(Aux1->prox->item, lista2);
            Aux1 = Aux1->prox;
        }

        for(j = 0; j < tamanho2; j++){
            Inserir(Aux1->prox->item, lista3);
            Aux1 = Aux1->prox;
        }

        printf("Resultado:\n\n\nPrimeira lista formada: \n");
        Imprimir(*lista2);
        printf("\n\n\nSegunda lista formada: \n");
        Imprimir(*lista3);
    }
    else
        printf("A lista esta fazia\n");

}

void ImprimirCelula(TLista *lista, int celula){
    TCelula *Aux1;
    Aux1 = lista->primeiro;

    if(lista->tamanho < celula)
        printf("A celula que voce digitou nao existe\n");
    else{
        for(int i = 0; i < celula; i++){
            Aux1 = Aux1->prox;
        }

        ImprimirProduto(Aux1->item);
    }
}

void ExcluirCelula(TLista *lista, int celula){
    TCelula *Aux1;
    Aux1 = lista->primeiro;

    if(lista->tamanho < celula)
        printf("A celula que voce digitou nao existe\n");
    else{
        for(int i = 0; i < celula; i++){
            Aux1 = Aux1->prox;
        }

        Excluir(lista, &Aux1->item);
        printf("Celula excluida\n");
    }
}
