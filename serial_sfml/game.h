#ifndef GAME_H
#define GAME_H
#include "joystick.h"
#include "main_player.h"

class game {
public:
	game(std::string&& window_name, std::string& port_name, int width = 1280, int height = 720);
	void start();
private:
	sf::RenderWindow m_window;
	joystick m_joystick;
};
#endif

