#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<SDL2/SDL.h>

const int screenWidth = 1920;
const int screenHeight = 1080;

float framerate = 0.5

void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main(){

	uint32_t screenBuffer[screenWidth * screenHeight];
	SDL_Window * window = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture * screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, screenWidth, screenHeight);
	int size = screenWidth*screenHeight;
	player.angle = 0.0f;
	clock_t lastUpdate = clock();
	// Game loop
	int running = 1; // adding kill functionality	
	while(running){
		SDL_Event event; // queues event
		clock_t startGameLoop = clock();

		// delta time calculations
		clock_t currentUpdate = clock();
		float deltaTime =(double)(currentUpdate - lastUpdate)/CLOCKS_PER_SEC;
		lastUpdate = currentUpdate;
		
		while(SDL_PollEvent(&event)){ // dequeues event and checks its value
			switch(event.type){
			case SDL_QUIT:
				running = 0;
				break;
			}
		}

		
		// Render 

	SDL_UpdateTexture(screen, NULL, screenBuffer, screenWidth * sizeof(uint32_t));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screen, NULL, NULL);
	SDL_RenderPresent(renderer);

	// frame cap
	clock_t endGameLoop = clock();
	double elapsedLoopTime = (double)(endGameLoop - startGameLoop) / CLOCKS_PER_SEC;
	delay((1/framerate*1000)-elapsedLoopTime*1000);
	}

	SDL_DestroyTexture(screen);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
