#include<stdio.h>
#include <stdlib.h>
#include<locale.h>

#define lin 8
#define col 8

#define vazio 1
#define preto 2
#define branco 3
#define damabranca 4
#define damapreta 5

#include "Funcoes.h"

int main()
{
    int tab[lin][col]=
    {
        {3,1,3,1,3,1,3,1},
        {1,3,1,3,1,3,1,3},
        {3,1,3,1,3,1,3,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,2,1,2,1,2,1,2},
        {2,1,2,1,2,1,2,1},
        {1,2,1,2,1,2,1,2}
    };
    int int1,int2;
    unsigned char ch1,ch2;
    int j=branco;

    setlocale(LC_ALL,"");




    while(1)
    {
        mostraTab(tab);

        if (j==branco)
        {
            vencedor(tab,j);

            printf("É a vez das peças brancas.\n");
            printf("Insira as coords. da peça que tenciona mover(na forma de, por exemplo 3a):");
            scanf("%d%c",&int1,&ch1);
            printf("Para que localização:");
            scanf("%d%c",&int2,&ch2);


            if(verificaErro(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(verificaCome(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(contComer(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(movimento(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(verificaDama(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

        }
//os if's e continue estão aqui pois as funções vão retornar 0 e 1
//se a função retornar 0 quer dizer que está valido
//se retornar 1 vai pedir novamente os valores
        else
        {
            vencedor(tab,j);

            printf("É a vez das peças pretas.\n");
            printf("Insira as coords. da peça que tenciona mover:");
            scanf("%d%c",&int1,&ch1);
            printf("Para que localização:");
            scanf("%d%c",&int2,&ch2);


            if(verificaErro(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(verificaCome(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(contComer(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(movimento(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

            if(verificaDama(tab,j,int1-1,int2-1,ch1-'a',ch2-'a'))
                continue;

        }

        //se for a vez do jogador branco torna-se o preto e se for preto torna-se o branco
        if(j==preto) j=branco;
        else j=preto;
    }
}
