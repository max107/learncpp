/*
 * Game.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: max
 */

#include "game.hpp"

namespace Fastcraft {

Game::Game(sf::VideoMode videoMode, const char* title)
	: m_window(videoMode, title, sf::Style::Close | sf::Style::Titlebar) // Create window
	{

	// Set a framrate limit to reduce the CPU load
	m_window.setFramerateLimit(60);
	// Hide the cursor
	m_window.setMouseCursorVisible(true);
	m_window.setTitle(title);
	m_window.setActive();

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void cube(float size)
{
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
	glTexCoord2f(1, 1); glVertex3f( size,  size, -size);
	glTexCoord2f(1, 0); glVertex3f( size, -size, -size);

	glTexCoord2f(0, 0); glVertex3f(-size, -size, size);
	glTexCoord2f(0, 1); glVertex3f(-size,  size, size);
	glTexCoord2f(1, 1); glVertex3f( size,  size, size);
	glTexCoord2f(1, 0); glVertex3f( size, -size, size);

	glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
	glTexCoord2f(1, 1); glVertex3f(-size,  size,  size);
	glTexCoord2f(1, 0); glVertex3f(-size, -size,  size);

	glTexCoord2f(0, 0); glVertex3f(size, -size, -size);
	glTexCoord2f(0, 1); glVertex3f(size,  size, -size);
	glTexCoord2f(1, 1); glVertex3f(size,  size,  size);
	glTexCoord2f(1, 0); glVertex3f(size, -size,  size);

	glTexCoord2f(0, 1); glVertex3f(-size, -size,  size);
	glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 0); glVertex3f( size, -size, -size);
	glTexCoord2f(1, 1); glVertex3f( size, -size,  size);

	glTexCoord2f(0, 1); glVertex3f(-size, size,  size);
	glTexCoord2f(0, 0); glVertex3f(-size, size, -size);
	glTexCoord2f(1, 0); glVertex3f( size, size, -size);
	glTexCoord2f(1, 1); glVertex3f( size, size,  size);

	glEnd();
}

void Game::run() {
	Fps fps;
		fps.setPosition(10.f, 10.f);

		sf::View fixed = m_window.getView(); // The 'fixed' view will never change
		sf::View standard = fixed; // The 'standard' view will be the one that gets always displayed

		sf::Font font;
		// TODO
		font.loadFromFile("data/fonts/PTS55F.ttf");

		sf::Text fpstext;
		// select the font
		fpstext.setFont(font);
		// font is a sf::Font
		fpstext.setString("");
		// set the character size
		fpstext.setCharacterSize(16); // in pixels, not points!
		// set the color
		fpstext.setColor(sf::Color::White);

		// Create a clock for measuring the time elapsed
		sf::Clock runtimeClock;

		// Enable Z-buffer read and write
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);
		glClearDepth(1.f);

		sf::Texture texture;
		if (!texture.loadFromFile("data/background.png")) {
			std::cout << "Failed to load texture" << std::endl;
		}
		texture.setSmooth(true);
		sf::Texture::bind(&texture);
		glEnable(GL_TEXTURE_2D);

		while (m_window.isOpen()) { // As long as the window is open
			// Normal event handling
			sf::Event event;
			// Events
			while (m_window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					// Default event for stop and destroy application if window closed
					m_window.close();
				} else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
					// Quit if pressed Escape key
					m_window.close();
				} else if (event.type == sf::Event::Resized) {
					// Catch the resize events
					// Update the view to the new size of the window
					glViewport(0, 0, event.size.width, event.size.height);

					sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
					m_window.setView(sf::View(visibleArea));
				}
			}

			// Clear the depth buffer
			glClear(GL_DEPTH_BUFFER_BIT);
			// Remove old content
			m_window.clear();

			glClearColor(0.3f, 0.3f, 0.3f, 1.f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			sf::Vector2u wsize = m_window.getSize();
			glViewport(0, 0, wsize.x, wsize.y);
			gluPerspective(60, (float)wsize.x / (float)wsize.y, 0.1f, 512.f);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			glPushMatrix();

			float x = 0;
			float y = 0;
			glTranslatef(x, y, -100.f);
			glRotatef(runtimeClock.getElapsedTime().asSeconds() * 50.f, 1.f, 0.f, 0.f);
			glRotatef(runtimeClock.getElapsedTime().asSeconds() * 30.f, 0.f, 1.f, 0.f);
			glRotatef(runtimeClock.getElapsedTime().asSeconds() * 90.f, 0.f, 0.f, 1.f);

			cube(20.f);

			glPopMatrix();

			// TODO unused variable
			// GLenum err = glGetError();

			m_window.setView(standard);
			// Draw 'GUI' elements with fixed positions
			m_window.setView(fixed);

			fpstext.setString(fps.toString());
			m_window.pushGLStates();
			m_window.draw(fpstext);
			m_window.popGLStates();

			// Restore default view
			m_window.setView(fixed);

			// Show everything
			m_window.display();
		}
}

} /* namespace Fastcraft */
