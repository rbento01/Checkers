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

int verificaCome(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2)
{

    if(tab[int1][ch1] == preto ||tab[int1][ch1] == branco)
    {
        if(jogador == branco)
        {
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 6 && (tab[int1+1][ch1+1] == preto || tab[int1+1][ch1+1] == damapreta))
            {
                system("cls");
                return 0;
            }
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 1 && (tab[int1+1][ch1-1] == preto || tab[int1+1][ch1-1] == damapreta))
            {
                system("cls");
                return 0;
            }
            //v� se a pe�a se tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 + 1 == int2 && ch1 - 1 == ch2 && tab[int1+2][ch1+2] == vazio && \
                    (tab[int1+1][ch1+1] == preto || tab[int1+1][ch1+1] == damapreta))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a pe�a se tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 + 1 == int2 && ch1 + 1 == ch2 && tab[int1+2][ch1-2] == vazio && \
                    (tab[int1+1][ch1-1] == preto || tab[int1+1][ch1-1] == damapreta))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //movimento quando uma pe�a come a outra
            if(int1 + 2 == int2 && ch1 + 2 == ch2 && \
                    (tab[int1+1][ch1+1] == preto || tab[int1+1][ch1+1] == damapreta))
            {
                tab[int2-1][ch2-1] = vazio;
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma pe�a come a outra
            if(int1 + 2 == int2 && ch1 - 2 == ch2 && \
                    (tab[int1+1][ch1-1] == preto || tab[int1+1][ch1-1] == damapreta))
            {
                tab[int1+1][ch1-1] = vazio;
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
        }

        if(jogador == preto)
        {
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 1 && (tab[int1-1][ch1-1] == branco || tab[int1-1][ch1-1] == damabranca))
            {
                system("cls");
                return 0;
            }
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 6 && (tab[int1-1][ch1+1] == branco || tab[int1-1][ch1+1] == damabranca))
            {
                system("cls");
                return 0;
            }
            //v� se a pe�a se tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 - 1 == int2 && ch1 - 1 == ch2 && tab[int1-2][ch1+2] == vazio && \
                    (tab[int1-1][ch1+1] == branco || tab[int1-1][ch1+1] == damabranca))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a pe�a se tenta "fugir" enquanto que pode comer uma pe�a
            if((int1 - 1 == int2 && ch1 + 1 == ch2) && (tab[int1-2][ch1-2] == vazio) && \
                    (tab[int1-1][ch1-1] == branco || tab[int1-1][ch1-1] == damabranca))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //movimento quando uma pe�a come a outra
            if(int1 - 2 == int2 && ch1 + 2 == ch2 && \
                    tab[int2][ch2] == vazio && \
                    (tab[int1-1][ch1+1] == branco || tab[int1-1][ch1+1] == damabranca))
            {
                tab[int2+1][ ch2-1] = vazio;
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma pe�a come a outra
            if(int1 - 2 == int2 && ch1 - 2 == ch2 && \
                    tab[int2][ch2] == vazio && \
                    (tab[int1-1][ch1-1] == branco || tab[int1-1][ch1-1] == damabranca))
            {
                tab[int1-1][ch1-1] = vazio;
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
        }
    }
    if(tab[int1][ch1] == damabranca || tab[int1][ch1] == damapreta)
    {
        if(jogador == branco)
        {
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 6 && (tab[int1+1][ch1+1] == preto || tab[int1+1][ch1+1] == damapreta))
            {
                system("cls");
                return 0;
            }
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 1 && (tab[int1+1][ch1-1] == preto || tab[int1+1][ch1-1] == damapreta))
            {
                system("cls");
                return 0;
            }
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 1 && (tab[int1-1][ch1-1] == preto || tab[int1-1][ch1-1] == damapreta))
            {
                system("cls");
                return 0;
            }
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 6 && (tab[int1-1][ch1+1] == preto || tab[int1-1][ch1+1] == damapreta))
            {
                system("cls");
                return 0;
            }
            //v� se a dama se tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 + 1 == int2 && ch1 - 1 == ch2 && tab[int1+2][ch1+2] == vazio && \
                    (tab[int1+1][ch1+1] == preto || tab[int1+1][ch1+1] == damapreta))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a dama se tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 + 1 == int2 && ch1 + 1 == ch2 && tab[int1+2][ch1-2] == vazio && \
                    (tab[int1+1][ch1-1] == preto || tab[int1+1][ch1-1] == damapreta))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a dama se tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 - 1 == int2 && ch1 - 1 == ch2 && tab[int1-2][ch1+2] == vazio && \
                    (tab[int1-1][ch1+1] == preto || tab[int1-1][ch1+1] == damapreta))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a dama se tenta "fugir" enquanto que pode comer uma pe�a
            if((int1 - 1 == int2 && ch1 + 1 == ch2) && (tab[int1-2][ch1-2] == vazio) && \
                    (tab[int1-1][ch1-1] == preto || tab[int1-1][ch1-1] == damapreta))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 + 2 == int2 && ch1 + 2 == ch2 && \
                    (tab[int1+1][ch1+1] == preto || tab[int1+1][ch1+1] == damapreta))
            {
                tab[int2-1][ch2-1] = vazio;
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 + 2 == int2 && ch1 - 2 == ch2 && \
                    (tab[int1+1][ch1-1] == preto || tab[int1+1][ch1-1] == damapreta))
            {
                tab[int1+1][ch1-1] = vazio;
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 - 2 == int2 && ch1 + 2 == ch2 && \
                    tab[int2][ch2] == vazio && \
                    (tab[int1-1][ch1+1] == preto || tab[int1-1][ch1+1] == damapreta))
            {
                tab[int2+1][ ch2-1] = vazio;
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 - 2 == int2 && ch1 - 2 == ch2 && \
                    tab[int2][ch2] == vazio && \
                    (tab[int1-1][ch1-1] == preto || tab[int1-1][ch1-1] == damapreta))
            {
                tab[int1-1][ch1-1] = vazio;
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
        }
        else
        {
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 1 && (tab[int1-1][ch1-1] == branco || tab[int1-1][ch1-1] == damabranca))
            {
                system("cls");
                return 0;
            }
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 6 && (tab[int1-1][ch1+1] == branco || tab[int1-1][ch1+1] == damabranca))
            {
                system("cls");
                return 0;
            }
            //O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 6 && (tab[int1+1][ch1+1] == branco || tab[int1+1][ch1+1] == damabranca))
            {
                system("cls");
                return 0;
            }//O objetivo � se puder continuar a comer, continua mas se a pe�a advers�ria estiver numa parede n�o pode comer
            if(ch1 == 1 && (tab[int1+1][ch1-1] == branco || tab[int1+1][ch1-1] == damabranca))
            {
                system("cls");
                return 0;
            }
            //v� se a dama tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 - 1 == int2 && ch1 - 1 == ch2 && tab[int1-2][ch1+2] == vazio && \
                    (tab[int1-1][ch1+1] == branco || tab[int1-1][ch1+1] == damabranca))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a dama tenta "fugir" enquanto que pode comer uma pe�a
            if((int1 - 1 == int2 && ch1 + 1 == ch2) && (tab[int1-2][ch1-2] == vazio) && \
                    (tab[int1-1][ch1-1] == branco || tab[int1-1][ch1-1] == damabranca))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a dama tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 + 1 == int2 && ch1 - 1 == ch2 && tab[int1+2][ch1+2] == vazio && \
                    (tab[int1+1][ch1+1] == branco || tab[int1+1][ch1+1] == damabranca))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //v� se a dama tenta "fugir" enquanto que pode comer uma pe�a
            if(int1 + 1 == int2 && ch1 + 1 == ch2 && tab[int1+2][ch1-2] == vazio && \
                    (tab[int1+1][ch1-1] == branco || tab[int1+1][ch1-1] == damabranca))
            {
                system("cls");
                printf("Tem que comer a pe�a na diagonal\n");
                return 1;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 - 2 == int2 && ch1 + 2 == ch2 && \
                    tab[int2][ch2] == vazio && \
                    (tab[int1-1][ch1+1] == branco || tab[int1-1][ch1+1] == damabranca))
            {
                tab[int2+1][ ch2-1] = vazio;
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 - 2 == int2 && ch1 - 2 == ch2 && \
                    tab[int2][ch2] == vazio && \
                    (tab[int1-1][ch1-1] == branco || tab[int1-1][ch1-1] == damabranca))
            {
                tab[int1-1][ch1-1] = vazio;
                salto(tab,preto,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 + 2 == int2 && ch1 + 2 == ch2 && \
                    (tab[int1+1][ch1+1] == branco || tab[int1+1][ch1+1] == damabranca))
            {
                tab[int2-1][ch2-1] = vazio;
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
            //movimento quando uma dama come uma pe�a
            if(int1 + 2 == int2 && ch1 - 2 == ch2 && \
                    (tab[int1+1][ch1-1] == branco || tab[int1+1][ch1-1] == damabranca))
            {
                tab[int1+1][ch1-1] = vazio;
                salto(tab,branco,int1,int2,ch1,ch2);
                return 0;
            }
        }
    }
    system("cls");
    return 0;
}
