#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define lin 8
#define col 8

//função que vai iterar as linhas e colunas e mostra depois o tabuleiro
void mostraTab(int tab[lin][col]);

//função que mostra se é uma peça preta ou branca no tabuleiro
char simbolos(int tab);

//função que faz um movimento de diagonal simples
int  movimento(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//função que verifica os valores que o utilizador colocou, se são válidos ou não
int verificaErro(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//função que faz o movimento no tabuleiro
void salto(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//função que verifica se o movimento é para comer uma peça, se for faz o movimento
int verificaCome(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//função que verifica o tabuleiro todo para ver se há alguma dama
int verificaDama(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//função que verifica se depois do movimento pode comer alguma peça
int contComer(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//função que dita quem é o vencedor
void vencedor(int tab[lin][col],int jogador);

#endif // FUNCOES_H_INCLUDED
