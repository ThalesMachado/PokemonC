#include "pokemon.h"
#include <stdio.h>
#include <stdlib.h>

Pokemon leituraPokemon(FILE *f){
	Pokemon p;
	int aux;
	p.nome = (char*) malloc(101 * sizeof(char));
	fscanf(f, "%s %d %d %d %d %d", p.nome, &p.numero, &p.nivel, &p.ataque, &p.defesa, &p.HP);
	
	p.salvaHP = p.HP;

	fscanf(f, "%d", &aux);

	if (aux > 42) exit(1);

	p.golpes = (Move*) malloc(aux * sizeof(Move));

	for (int i = 0; i < aux; i++){
		p.golpes[i].nome = (char*) malloc(101 * sizeof(char));
		fscanf(f, "%s %d", p.golpes[i].nome, &p.golpes[i].base);
	}

	return p;
}

int estaVivo(Pokemon p){
	if (p.HP > 0) return 1;
	return 0;
}

char* nomePokemon(Pokemon p){
	return p.nome;
}

int numeroPokemon(Pokemon p){
	return p.numero;
}

int numeroGolpes(Pokemon p){
	int aux = sizeof(p.golpes)/sizeof(Move);
	return aux;
}

int ataque(Pokemon p1, int m, Pokemon *p2){
	int ataque;

	ataque = (((((2.0 * (float) p1.nivel + 10.0) / 250.0) * ( (float) p1.ataque / (float) (*p2).defesa) * (float) p1.golpes[m].base) + 2.0) * 4.0);
	(*p2).HP = (*p2).HP - (int)ataque;

	return ataque; 
}

void curaPokemon(Pokemon *p){
	p->HP = p->salvaHP;
	return;
}

void desalocaPokemon(Pokemon *p){
	Pokemon *aux;
	for (int i = 0; i < numeroGolpes(*p); i++){
		free(p->golpes[i].nome);
	}
	free(p->golpes);
	free(p->nome);
} 
