#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "Sprite.h"
#include "window.h"

using namespace std;

int main(int argc, char* argv[])
{
#pragma region Local Variable
	int vx = 0, vy = 0;


#pragma endregion

#pragma region Things to do
	
	window _main_window("The Main Window");
	



#pragma endregion

#pragma region Program Loop
	while (!_main_window.isClosed()) {

		_main_window.pollEvent();
			
	}
#pragma endregion

#pragma region Clean Up Stuff
	SDL_Quit();
#pragma endregion

	return 0;
}