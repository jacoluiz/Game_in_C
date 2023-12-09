#include <stdio.h>
#include <SDL.h>
#include "Constants.h"
SDL_Window* window = NULL;
SDL_Renderer* ren = NULL;

int main(int argc, char* args[]) {
	int jogo_em_execucao = initialize_window();

	setup();
	while (jogo_em_execucao) {
		inputs();
		atualizar();
		renderizar();
	}

	printf("Olá mundo");
	return 0;
}

int initialize_window(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "Erro ao inicializar o SDL. \n");
		return FALSE;
	}
	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		LARGURA_JANELA,
		ALTURA_JANELA,
		SDL_WINDOW_BORDERLESS
	);

	if (!window) {
		fprintf(stderr, "Erro ao criar a janela SDL. \n");
		return FALSE;
	}

	ren = SDL_CreateRenderer(window, -1, 0);

	if (!ren) {
		fprintf(stderr, "Erro ao inicializar o renderizador. \n");
		return FALSE;
	}


	return TRUE;
}