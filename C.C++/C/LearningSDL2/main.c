#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define GRAVITY_ACCEL 1
#define JUMP_VELOCITY 15

#define FPS 60

// clear && gcc mainGPT.c -lSDL2 && ./a.out

void SDLInit() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(-1);
	}
}

void SDLQuit(SDL_Renderer* renderer, SDL_Window* window) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Window* WindowInit() {

	SDL_Window* window = SDL_CreateWindow(
		"SDL2 Window",									// Window title
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // X and Y coordinates
		SCREEN_WIDTH, SCREEN_HEIGHT,					// Dimensions in pixels: w, h
		SDL_WINDOW_SHOWN								// Window flags
	);

	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(-1);
	}

	return window;
}

SDL_Renderer* RendererInit(SDL_Window* window) {

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(-1);
	}

	return renderer;
}

typedef struct {
	SDL_Rect rect;
	float velocityX, velocityY;
	bool moveRight, moveLeft;
	bool ascending, onAir;
} Character;

void handleCharacterEvents(SDL_Event event, Character* character) {

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_a:
				character->moveLeft = true;
			break;
			case SDLK_d:
				character->moveRight = true;
			break;
			case SDLK_SPACE:
				if (!character->onAir) {
					character->onAir = true;
					character->ascending = true;
					character->velocityY = JUMP_VELOCITY;
				}
			break;
		}
	}
	
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
			case SDLK_a:
				character->moveLeft = false;
			break;
			case SDLK_d:
				character->moveRight = false;
			break;
		}
	}
}

void updateCharacter(Character* character) {

	if (character->moveLeft) character->rect.x -= character->velocityX;

	if (character->moveRight) character->rect.x += character->velocityX;

	if (character->onAir) {
	
		if (character->ascending) {
			character->rect.y -= character->velocityY;
			character->velocityY -= GRAVITY_ACCEL;
			if (character->velocityY <= 0) {
				character->ascending = false;
				character->velocityY = 0;
			}
		}

		else {
			character->rect.y += character->velocityY;
			character->velocityY += GRAVITY_ACCEL;
			if (character->rect.y >= SCREEN_HEIGHT - character->rect.h) {
				character->onAir = false;
			}
		}

	}
}

void renderCharacter(SDL_Renderer* renderer, Character* character) {

	// Render the white "canvas"
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	// Render the Character
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &character->rect);

	SDL_RenderPresent(renderer);
}

void handleCharacter(Character* character, SDL_Renderer* renderer) {
	updateCharacter(character);
	renderCharacter(renderer, character);
}

Character newCharacter(int speed, int w, int h, int x, int y) {
	return (Character){
		.rect = { .x = x, .y = y, .h = h, .w = w },
		.velocityX = speed,
		.velocityY = 0,
		.moveRight = false,
		.moveLeft = false,
		.onAir = false,
		.ascending = false // Add logic to test if it is or not
	};
}

int main() {

	SDLInit();

	SDL_Window* window = WindowInit();
	SDL_Renderer* renderer = RendererInit(window);

	bool quit = false;
	SDL_Event event;

	int w = 50, h = 150;
	Character character = newCharacter(5, w, h, (SCREEN_WIDTH - w) / 2, SCREEN_HEIGHT - h);

	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) quit = true;
			handleCharacterEvents(event, &character);
		}

		handleCharacter(&character, renderer);

		SDL_Delay(1000 / FPS); // Delay to cap the frame rate at ~FPS
	}

	SDLQuit(renderer, window);

	return 0;
}
