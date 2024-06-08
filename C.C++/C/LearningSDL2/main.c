#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define GRAVITY 1

// clear && gcc main.c -lSDL2 && ./a.out

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
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Initial positions
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

	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(-1);
	}

	return renderer;
}

typedef struct {
	SDL_Rect rect;
	bool jumping, goingUp;
} Character;

void moveCharacter(Character* character, int speed, int acceleration, SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_a:
			character->rect.x -= speed;
			break;
		case SDLK_d:
			character->rect.x += speed;
			break;
		}
	}
}

void jumpCharacter(Character* character, SDL_Renderer* renderer, SDL_Event event) {

	static int velocity = 10; // Initial jump impulse
	static int maxHeight = 30;

	if (
		!character->jumping
		&& event.type == SDL_KEYDOWN
		&& event.key.keysym.sym == SDLK_SPACE
	) {
		character->jumping = character->goingUp = true;
		maxHeight += character->rect.h;
		// printf("maxHeight: %d\n", maxHeight);
	}

	if (character->goingUp == true) {
		// printf("character->rect.y: %d\n", character->rect.y);
		character->rect.y -= velocity;
		velocity += GRAVITY;
		if (character->rect.y <= maxHeight) {
			character->goingUp = false;
			velocity = 10;
		}
	}

	else if (character->jumping) {
		
		if (character->rect.y >= SCREEN_HEIGHT - character->rect.h) {
			character->jumping = false;
			// character->rect.y = (character->rect.y - SCREEN_HEIGHT) / 2;
		}

		else {
			character->rect.y += velocity;
			velocity += GRAVITY;
		}
	}
}

void mainCharacter(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {

	const int h = 150, w = 50;

	static Character character = {
		.jumping = false,
		.rect = {
			.h = h, .w = w,				 // Dimensions in pixels
			.x = (SCREEN_WIDTH - w) / 2, // X coordinate (Center)
			.y = SCREEN_HEIGHT - h,		 // Y coordinate (Bottom)
		},
	};

	moveCharacter(&character, 5, 1, event);
	jumpCharacter(&character, renderer, event);

	// Setting the color of the "Canvas"
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	// Setting and Rendering the color of the Rectangle
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &character.rect);

	SDL_RenderPresent(renderer);
}

int main() {

	SDLInit();

	SDL_Window* window = WindowInit();
	SDL_Renderer* renderer = RendererInit(window);

	SDL_Event event;
	bool quit = false;

	while (!quit) {

		while (SDL_PollEvent(&event) != 0) {

			if (event.type == SDL_QUIT) quit = true;
			
			else {
				// All the entities
				mainCharacter(event, renderer, window);
			}
		}
	}

	SDLQuit(renderer, window);

	return 0;
}