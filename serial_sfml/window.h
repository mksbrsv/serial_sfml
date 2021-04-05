#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include "serial_port.h"
class window
{
public:
	window(const std::string& window_name, int width, int height);

	void display();
private:
	//void loop();
	void close(sf::Event& event);
	sf::RenderWindow m_window;
	serial_port m_port;

};

#endif

