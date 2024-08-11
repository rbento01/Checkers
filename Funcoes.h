#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define lin 8
#define col 8

//fun��o que vai iterar as linhas e colunas e mostra depois o tabuleiro
void mostraTab(int tab[lin][col]);

//fun��o que mostra se � uma pe�a preta ou branca no tabuleiro
char simbolos(int tab);

//fun��o que faz um movimento de diagonal simples
int  movimento(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//fun��o que verifica os valores que o utilizador colocou, se s�o v�lidos ou n�o
int verificaErro(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//fun��o que faz o movimento no tabuleiro
void salto(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//fun��o que verifica se o movimento � para comer uma pe�a, se for faz o movimento
int verificaCome(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//fun��o que verifica o tabuleiro todo para ver se h� alguma dama
int verificaDama(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//fun��o que verifica se depois do movimento pode comer alguma pe�a
int contComer(int tab[lin][col],int jogador, int int1, int int2, int ch1, int ch2);

//fun��o que dita quem � o vencedor
void vencedor(int tab[lin][col],int jogador);

#endif // FUNCOES_H_INCLUDED
