#ifndef POKEMON_H
#define POKEMON_H
#include <stdlib.h>
#include <stdio.h>

typedef struct move{
	char *nome;
	int base;
} Move;

typedef struct pokemon{
	char *nome;
	int numero, nivel, ataque, defesa, HP, salvaHP;
	Move *golpes;
} Pokemon;

Pokemon leituraPokemon(FILE *f);
//faz a leitura dos dados do Pokemon.
int estaVivo(Pokemon p);
//retorna 1 se o hp atual do Pokemon é maior que 0.
char* nomePokemon(Pokemon p);
// retorna o nome do Pokemon.
int numeroPokemon(Pokemon p);
// retorna o número de um Pokemon.
int numeroGolpes(Pokemon p);
// retorna o número de golpes de um Pokemon.
int ataque(Pokemon p1, int m, Pokemon *p2);
//simula um ataque do Pokemon p1 ao Pokemon p2 utilizando o golpe m, retornando o dano causado.
void curaPokemon(Pokemon *p);
//restora o hp do pokemon ao máximo.
void desalocaPokemon(Pokemon *p);
//desaloca todos os ponteiros do poekmon.

#endif