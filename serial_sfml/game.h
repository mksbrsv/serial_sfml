#ifndef GAME_H
#define GAME_H
#include "joystick.h"
#include <SFML/Graphics.hpp>
class game {
public:
	game(std::string&& window_name, int width = 1280, int height = 720);
	void start();
private:
	sf::RenderWindow m_window;
	joystick m_joystick;
};
#endif

