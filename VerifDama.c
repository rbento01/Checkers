#include<stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

#define lin 8
#define col 8

#define vazio 1
#define preto 2
#define branco 3
#define damabranca 4
#define damapreta 5

int verificaDama(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2)
{
    //vai verificar se nas extremidades estão peças especificas, se estiverem tornam-se numa dama
    int i;
    if(jogador == branco)
    {
        for(i=0; i<lin; i++)
        {
            if(tab[7][i]==branco)
            {
                tab[7][i] = damabranca;
            }
        }
    }
    if(jogador == preto)
    {
        for(i=0; i<lin; i++)
        {
            if(tab[0][i] == preto)
            {
                tab[0][i] = damapreta;
            }
        }
    }
    return 0;

}
