#include <iostream>
#include "Game.h"
#include "Animation.h"

using namespace sf;
int main(void) {
	//InitGame Engine.
	Game game;

	//Game Loop
	while (game.running()) {


		//Updates
		game.update();
		//Render
		game.render();
	}

	return 0;
}