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

void salto(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2)
{
    //mudança no tabuleiro
    tab[int2][ch2] = tab[int1][ch1];

    tab[int1][ch1] = vazio;

    system("cls");

}
int  movimento(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2)
{

    if(tab[int1][ch1] == preto || tab[int1][ch1] == branco)
    {
        if(jogador == branco)
        {
            //movimento simples da peça branca, para as duas diagonais
            if(int1 + 1 == int2 && (ch1 + 1 == ch2 || ch1 - 1 == ch2))
            {
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
        }

        if(jogador == preto)
        {
            //movimento simples da peça preta, para as duas diagonais
            if(int1 - 1  == int2  && (ch1 + 1 == ch2 || ch1 - 1 == ch2))
            {
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
        }
    }
    if(tab[int1][ch1] == damabranca ||tab[int1][ch1] == damapreta)
    {
        if(jogador == branco)
        {
            //movimento simples de uma dama branca para ambas as diagonais
            if(int2 - int1 == 1 && (ch2 - ch1 == 1 || ch2-ch1 == -1))
            {
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
            if(int2-int1 == -1 && (ch2-ch1 == -1 || ch2-ch1 == 1))
            {
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
        }
        else
        {
            //movimento simples de uma dama branca para ambas as diagonais
            if(int2-int1 == -1 && (ch2-ch1 == -1 || ch2-ch1 == 1))
            {
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
            if(int2 - int1 == 1 && (ch2 - ch1 == 1 || ch2-ch1 == -1))
            {
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
        }
    }

    system("cls");
    return 0;
}
int verificaErro(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2)
{
    //ver se o utilizador pôs menos ou mais linhas do que devia
    if(int1<0 || int2<0 || int1>=8 || int2>=8)
    {
        system("cls");
        printf("Tem que inserir no intervalo de 1 a 8\n");
        return 1;

    }
    if(jogador == branco)
    {
        if(tab[int1][ch1] != branco && tab[int1][ch1] != damabranca)
        {
            //ver se o utilizador clicou numa das suas peças
            system("cls");
            printf("Inseriu uma peça que não é sua ou espaço vazio.\n");
            return 1;

        }
    }
    else
    {
        //ver se o utilizador clicou numa das suas peças
        if(tab[int1][ch1] != preto && tab[int1][ch1] != damapreta)
        {
            system("cls");
            printf("Inseriu uma peça que não é sua.\n");
            return 1;

        }
    }
    //ver se a peça está a andar para trás ou para a frente dependendo da vez do utilizador
    if(jogador == preto)
    {
        if(int1 <= int2 && tab[int1][ch1] == preto)
        {
            system("cls");
            printf("As peças pretas têm que se movimentar para cima.\n");
            return 1;

        }
    }
    else
    {
        if(int1 >= int2 && tab[int1][ch1] == branco)
        {
            system("cls");
            printf("As peças brancas têm que se movimentar para baixo.\n");
            return 1;

        }
    }
    //ver se utilizador quer meter alguma peça por cima de outra peça
    if(tab[int2][ch2] != vazio)
    {
        system("cls");
        printf("Insira um espaço válido.\n");
        return 1;
    }
    //ver se o utilizador quer movimentar-se na vertical
    if(int1 + 1 == int2 && ch1 == ch2)
    {
        system("cls");
        printf("Os movimentos só são válidos na diagonal.\n");
        return 1;
    }
    return 0;
}
