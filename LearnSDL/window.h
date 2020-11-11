#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>

class window
{
public:
	window(const std::string, int = 680, int = 480);
	~window();
	bool init();
	void clear();
	bool isClosed();
	void pollEvent();

private:
	std::string title;
	int width;
	int height;
	bool closed = false;
	Uint32 flags = SDL_WINDOW_OPENGL;

	SDL_Window* win = nullptr;
};


#endif
