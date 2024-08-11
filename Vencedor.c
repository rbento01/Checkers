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

void vencedor(int tab[lin][col],int jogador)
{
    int a,b,c,d,contadorbranco=0,contadorpreto=0;

    if(jogador == branco)
    {
        for(a=0; a<lin; a++)
        {
            for(b=0; b<col; b++)
            {
                if(tab[a][b] == branco || tab[a][b] == damabranca)
                {
                    contadorbranco++;
                }
            }
        }
        if(contadorbranco == 0)
        {
            printf("O vencedor do jogo é o preto");
            exit(0);
        }

    }
    else
    {
        for(c=0; c<lin; c++)
        {
            for(d=0; d<col; d++)
            {
                if(tab[c][d] == preto || tab[c][d] == damapreta)
                {
                    contadorpreto++;
                }
            }
        }
        if(contadorpreto == 0)
        {
            printf("O vencedor é o jogador branco");
            exit(0);
        }
    }
}
