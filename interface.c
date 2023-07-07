#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR ITEM");
    printf("  \n\t2. PESQUISAR ITEM PELO CODIGO");
    printf("  \n\t3. EXCLUIR ITEM PELO CODIGO");
    printf("  \n\t4. IMPRIMIR LISTA");
    printf("  \n\t5. VERIFICAR SE DUAS LISTAS SAO IGUAIS");
    printf("  \n\t6. CONCATENA A LISTA 2 NA LISTA 1");
    printf("  \n\t7. DIVIDE A LISTA EM OUTRAS DUAS LISTAS");
    printf("  \n\t8. IMPRIMI AS INFORMACOES DE UMA CELULA A SUA ESCOLHA DE UMA LISTA");
    printf("  \n\t9. EXCLUIR AS INFORMACOES DE UMA CELULA A SUA ESCOLHA DE UMA LISTA");
    printf("  \n\t10. SAIR");
}

void MENU(TLista *lista1, TLista *lista2)
{
    TProduto produto;
    TLista lista3, lista4;
    IniciaLista(&lista3);
    IniciaLista(&lista4);
    int opcao=0;
    int i, j, x;
    TProduto ProAux;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerProduto(&produto);
            printf("\nDeseja inserir em qual lista ? (1 ou 2) ");
            scanf("%d",&j);
            if(j == 1)
                Inserir(produto, lista1);
            else
                Inserir(produto, lista2);
            printf("Produto inserido\n");
            system("PAUSE");
            break;
        case 2:
            printf("\nDigite o codigo do produto que quer procurar ");
            scanf("%d",&i);
            printf("Digite a lista que quer procurar (1 ou 2) ");
            scanf("%d",&j);

            ProAux.codigo = i;
            if(j == 1){
                TCelula *Aux2 = Pesquisa(*lista1, ProAux);

                if(Pesquisa(*lista1, ProAux) == NULL)
                    printf("\nProduto nao encontrado \n==================================\n");
                else
                    ImprimirProduto(Aux2->prox->item);

                system("PAUSE");
            }
            else{
                 TCelula *Aux2 = Pesquisa(*lista2, ProAux);

                if(Pesquisa(*lista2, ProAux) == NULL)
                    printf("\nProduto nao encontrado \n==================================\n");
                else
                    ImprimirProduto(Aux2->prox->item);

                system("PAUSE");
            }
            break;
        case 3:
            printf("\nDigite o codigo do produto que quer excluir ");
            scanf("%d",&i);
            printf("Digite em qual lista quer excluir (1 ou 2) ");
            scanf("%d",&j);
            ProAux.codigo = i;

            if(j == 1){
                TCelula *Aux3 = Pesquisa(*lista1, ProAux);

                if(Pesquisa(*lista1, ProAux) == NULL)
                    printf("\nProduto nao encontrado \n==================================\n");
                else
                    Excluir(lista1, &Aux3->prox->item);
                system("PAUSE");
            }
            else{
                 TCelula *Aux3 = Pesquisa(*lista2, ProAux);

                if(Pesquisa(*lista2, ProAux) == NULL)
                    printf("\nProduto nao encontrado \n==================================\n");
                else
                    Excluir(lista2, &Aux3->prox->item);
                system("PAUSE");
            }

            break;
        case 4:
            printf("Digite qual lista quer imprimir (1 ou 2) ");
            scanf("%d",&j);
            if(j == 1)
                Imprimir(*lista1);
            else
                 Imprimir(*lista2);
            system("PAUSE");
            break;
        case 5:
                printf("Verificando...");
                j = VerificaIgualdade(lista1, lista2);
                if(j)
                    printf("\nIguais\n");
                else
                    printf("\nDiferentes\n");
                system("PAUSE");
                break;
        case 6:
            printf("Concatenando...\n");
            Concatena(lista1, lista2);
            system("PAUSE");
            break;
        case 7:
            printf("Digite a lista que quer dividir (1 ou 2) ");
            scanf("%d",&j);
            if(j == 1)
                DividirLista(lista1,&lista3,&lista4);
            else
                DividirLista(lista2,&lista3,&lista4);
            system("PAUSE");
            break;
        case 8:
            printf("Digite a lista que deseja imprimir a celula (1 ou 2) ");
            scanf("%d",&j);
            printf("Digite a celula que quer imprimir ");
            scanf("%d",&x);
            if(j == 1)
                ImprimirCelula(lista1, x);
            else
                ImprimirCelula(lista2, x);
            system("PAUSE");
            break;
        case 9:
            printf("Digite a lista que deseja excluir a celula (1 ou 2) ");
            scanf("%d",&j);
            printf("Digite a celula que quer excluir ");
            scanf("%d",&x);
            if(j == 1)
                ExcluirCelula(lista1, x);
            else
                ExcluirCelula(lista2, x);
            system("PAUSE");
            break;
        case 10:
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
            system("PAUSE");
            break;
        default:
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            system("PAUSE");
        } // fim do bloco switch

    }
    while(opcao != 10);
}
