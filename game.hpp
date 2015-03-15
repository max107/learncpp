/*
 * Game.h
 *
 *  Created on: Mar 15, 2015
 *      Author: max
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <sstream>
#include <list>
#include <assert.h>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "fps.hpp"

namespace Fastcraft {

class Game {
public:
	Game(sf::VideoMode videoMode, const char* title);
	virtual ~Game();

	void run();

private:
	sf::RenderWindow m_window;
};

} /* namespace Fastcraft */

#endif /* GAME_H_ */
