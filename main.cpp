#include <iostream>
#include <sstream>
#include <list>
#include <assert.h>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "game.hpp"

using namespace Fastcraft;

int main()
{
	sf::VideoMode videoMode;
	videoMode.width = 1024;
	videoMode.height = 768;
	videoMode.bitsPerPixel = 32;
	assert(videoMode.isValid());

	Game game(videoMode, "FastCraft");
	game.run();

	return 0;
}
