#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

#define GRAVITY 1
#define JUMP_VELOCITY 15

#define FPS 60

// clear && gcc main.c -lSDL2 && ./a.out

// Initialize SDL
void SDLInit() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(-1);
	}
}

// Cleanup SDL
void SDLQuit(SDL_Renderer* renderer, SDL_Window* window) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// Initialize SDL Window
SDL_Window* WindowInit() {

	SDL_Window* window = SDL_CreateWindow(
		"SDL2 Window",									// Window title
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // X and Y coordinates
		SCREEN_WIDTH, SCREEN_HEIGHT,					// Dimensions in pixels: w, h
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE			// Window flags
	);

	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(-1);
	}

	return window;
}

// Initialize SDL Renderer
SDL_Renderer* RendererInit(SDL_Window* window) {

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(-1);
	}

	return renderer;
}

// Character struct to hold character properties
typedef struct {
	SDL_Rect rect;
	float velocityX, velocityY;
	bool moveRight, moveLeft;
	bool isAscending, isInAir;
} Character;

// Handle keyboard events
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
				if (!character->isInAir) {
					character->isInAir = true;
					character->isAscending = true;
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

// Update character position and state
void updateCharacter(Character* character) {

	if (character->moveLeft) {
		character->rect.x -= character->velocityX;
	}

	else if (character->moveRight) {
		character->rect.x += character->velocityX;
	}

	const int BOTTOM_OF_SCREEN = SCREEN_HEIGHT - character->rect.h;

	if (character->isInAir) {

		if (character->isAscending) {
			character->rect.y -= character->velocityY;
			character->velocityY -= GRAVITY;
			if (character->velocityY <= 0) {
				character->velocityY = 0;
				character->isAscending = false;
			}
		}

		else {
			character->rect.y += character->velocityY;
			character->velocityY += GRAVITY;
			if (character->rect.y >= BOTTOM_OF_SCREEN) {
				character->isInAir = false;
				character->rect.y = BOTTOM_OF_SCREEN;
				character->velocityY = 0;
			}
		}
	}
}

// Render character on screen
void renderCharacter(SDL_Renderer* renderer, Character* character) {
	// Render the white "canvas"
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	// Render the Character
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &character->rect);

	SDL_RenderPresent(renderer);
}

// Handle character updates and rendering
void handleCharacter(Character* character, SDL_Renderer* renderer) {
	updateCharacter(character);
	renderCharacter(renderer, character);
}

// Create a new character
Character newCharacter(int speed, int w, int h, int x, int y) {
	return (Character){
		.rect = { .x = x, .y = y, .h = h, .w = w },
		.velocityX = speed,
		.velocityY = 0,
		.moveRight = false,
		.moveLeft = false,
		.isInAir = false,
		.isAscending = false
	};
}

// Handle window events, including resizing
void handleWindowEvent(SDL_Event event, Character* character) {

	if (event.type == SDL_WINDOWEVENT) {
		if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
			SCREEN_WIDTH = event.window.data1;
			SCREEN_HEIGHT = event.window.data2;
			character->isInAir = true;
			character->isAscending = false;
		}
	}
}

// Main function
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
			handleWindowEvent(event, &character);
		}

		handleCharacter(&character, renderer);

		SDL_Delay(1000 / FPS); // Delay to cap the frame rate at ~FPS
	}

	SDLQuit(renderer, window);

	return 0;
}
