#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

int main(int argc, char const *argv[])
{	
	int qtd = atoi(argv[2]); 
	FILE *f = fopen(argv[1], "r");
	if (f == NULL) exit(1);
	char *aux = (char*)  malloc(2 * sizeof(char));
	aux = "S";
	char *resp = (char*)  malloc(2 * sizeof(char));

	int auxAtaque, poke1, poke2, dano, contAtaques;

	Pokemon *poke;
	poke  = (Pokemon*) malloc(qtd * sizeof(Pokemon));

	for (int i = 0;  i < qtd; i++){
		poke[i] = leituraPokemon(f);
	}

	do {
		printf("\n");
		contAtaques = 0;
		for (int i = 0; i < qtd; i++){
			curaPokemon(&poke[i]);
		}

		printf("Digite o numero do primeiro pokemon a atacar:\n");
		scanf("%d", &poke1);
		printf("Digite o numero do segunda pokemon a atacar:\n");
		scanf("%d", &poke2);

		poke1--; poke2--;

		while (estaVivo(poke[poke1]) && estaVivo(poke[poke2])){
			printf("O pokemon %s esta atacando.\n", nomePokemon(poke[poke1]));
			printf("Digite o movimento que ele deve usar (1 ou 2):\n");
			scanf("%d", &auxAtaque); auxAtaque--;
			dano = ataque(poke[poke1], auxAtaque, &poke[poke2]);
			contAtaques++;
			printf("Dano causado em %s = %d\n", nomePokemon(poke[poke2]), dano);
			if (estaVivo(poke[poke2])){
				printf("O pokemon %s esta atacando.\n", nomePokemon(poke[poke2]));
				printf("Digite o movimento que ele deve usar (1 ou 2):\n");
				scanf("%d", &auxAtaque); auxAtaque--;
				dano = ataque(poke[poke2], auxAtaque, &poke[poke1]);
				contAtaques++;
				printf("Dano causado em %s = %d\n", nomePokemon(poke[poke1]), dano);
			}
		}
		printf("Fim da Batalha!\n");
		if (estaVivo(poke[poke1])){
			printf("O pokemon %s (# %d) venceu apos %d movimentos!\n", nomePokemon(poke[poke1]), numeroPokemon(poke[poke1]), contAtaques);
		}
		else{
			printf("O pokemon %s (# %d) venceu apos %d movimentos!\n", nomePokemon(poke[poke2]), numeroPokemon(poke[poke2]), contAtaques);
		}
		printf("Deseja simular outra batalha?\n");
		scanf(" 	%s", resp);
	} while(!strcmp(aux, resp));
	
	desalocaPokemon(poke);

	free(poke);
	fclose(f);

	return 0;
}

