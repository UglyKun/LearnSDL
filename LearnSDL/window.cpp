#include "window.h"
#include <iostream>
#include <SDL.h>

using namespace std;

window::window(const std::string t, int w, int h) :
	title(t), width(w), height(h)
{
	if(!init()) {
		cerr << "Error initializing" << endl;
	}
	
}

window::~window() {
	SDL_DestroyWindow(win);
}

bool window::init() {
	//Check and initialize SDL Video
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Failed to initialize SDL VIDEO" << endl;
		return 0;
	}
	
	win = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		flags);

	if (win == nullptr) {
		cout << "Unable to create window: " << SDL_GetError() << endl;
		return 0;
	}
	return 1;
}

void window::clear() {

}

bool window::isClosed() {
	return closed;
}

void window::pollEvent() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
		case SDL_QUIT:
			closed = true;
			break;
		default:
			break;
		}
	}
}