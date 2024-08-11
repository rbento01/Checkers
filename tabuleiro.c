#include<stdio.h>
#include "Funcoes.h"

#define lin 8
#define col 8

#define vazio 1
#define preto 2
#define branco 3
#define damabranca 4
#define damapreta 5

char simbolos(int tab)
{
    //switch que da os simbolos no tabuleiro
    switch (tab)
    {
    case 1:
        return ' ';
        break;
    case 2:
        return 'P';
        break;

    case 3:
        return 'B';
        break;
    case 4:
        return 'b';
        break;
    case 5:
        return 'p';
        break;
    }
    return 'N';
}

void mostraTab(int tab[lin][col])
{
    int i, j;

    printf("    a   b   c   d   e   f   g   h\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    //vai iterar as linhas e colunas fazendo o tabuleiro
    for (i=0; i<lin; ++i)
    {
        printf("%d |", i+1);
        for (j=0; j<col; ++j)
        {
            printf(" %c |", simbolos(tab[i][j]) );
        }
        printf(" %d\n",i+1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }

    printf("    a   b   c   d   e   f   g   h\n");
}
