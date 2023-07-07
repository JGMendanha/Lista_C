#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main()
{
    TLista lista1, lista2;
    TProduto produto;
    IniciaLista(&lista1);
    IniciaLista(&lista2);
    MENU(&lista1,&lista2);
    ExcluirTudo(&lista1);
    return 0;
}
