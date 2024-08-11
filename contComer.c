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

int contComer(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2)
{
    if(jogador==branco)
    {
        //vê se tem a oportunidade de ainda comer uma peça
        if(tab[int2+2][ch2+2] == vazio && \
                (tab[int2+1][ch2+1] == preto || tab[int2+1][ch2+1] == damapreta) && \
                int1 + 1 != int2 && (ch1 + 1 != ch2 || ch1 - 1 != ch2) && \
                int1 - 1  != int2  && (ch1 + 1 != ch2 || ch1 - 1 != ch2))
        {
            return 1;
        }
        else if(tab[int2+2][ch2-2] == vazio && \
                (tab[int2+1][ch2-1] == preto || tab[int2+1][ch2-1] == damapreta) && \
                int1 + 1 != int2 && (ch1 + 1 != ch2 || ch1 - 1 != ch2) && \
                int1 - 1 != int2 && (ch1 + 1 != ch2 || ch1 - 1 != ch2))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        //vê se tem a oportunidade de ainda comer uma peça
        if(tab[int2-2][ch2+2] == vazio && \
                (tab[int2-1][ch2+1] == branco || tab[int2-1][ch2+1] == damabranca) && \
                int1 + 1 != int2 && (ch1 + 1 != ch2 || ch1 - 1 != ch2) && \
                int1 - 1 != int2 && (ch1 + 1 != ch2 || ch1 - 1 != ch2))
        {
            return 1;
        }
        else if(tab[int2-2][ch2-2] == vazio && \
                (tab[int2-1][ch2-1] == branco || tab[int2-1][ch2-1] == damabranca) && \
                int1 + 1 != int2 && (ch1 + 1 != ch2 || ch1 - 1 != ch2) && \
                int1 - 1 != int2 && (ch1 + 1 != ch2 || ch1 - 1 != ch2))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
