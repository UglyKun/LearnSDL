#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <iostream>


class Sprite
{
public:
	Sprite(SDL_Renderer*,int, int, int x = 0, int y = 0);
	~Sprite();
	void draw();
	void update() const;
	void move(int,int);
	

private:
	SDL_Rect cRect; //Clipping of surface
	SDL_Surface* surface = NULL; //Surface for blitting image
	SDL_Renderer* sprite_renderer = NULL; // Pointer to renderer passed in
	SDL_Texture* texture = NULL; // Pointer of Texture for rendering

};
#endif