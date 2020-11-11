#include "Sprite.h"
#include <SDL_image.h>

Sprite::Sprite(SDL_Renderer* rend, int w, int h, int x, int y) {
	sprite_renderer = rend;
	texture = SDL_CreateTexture(
		rend,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET,
		1920, 1080);
	cRect.x = x;
	cRect.y = y;
	cRect.w = w;
	cRect.h = h;
}

Sprite::~Sprite() {}
void Sprite::draw() {
	SDL_SetRenderTarget(sprite_renderer, texture);
	SDL_SetRenderDrawColor(sprite_renderer, 76, 182, 245, 255); //Set to blue
	SDL_RenderFillRect(sprite_renderer, &cRect);
	SDL_SetRenderTarget(sprite_renderer, NULL);
	SDL_RenderCopy(sprite_renderer, texture, &cRect, &cRect);
}


void Sprite::update() const {
	
}

void Sprite::move(int x, int y) {
	cRect.x += x;
	cRect.y += y;
	draw();
}