#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include "serial_port.h"
#include "game_object.h"

class game {
public:
	game(const std::string& window_name, int width, int height);
	void set_player(sf::CircleShape&& object);
	void display();
	static std::pair<int, int> parse_coordinates(std::string&& str);

private:
	void collision();
	static direction get_direction(std::pair<int, int>& coordinates);
	static sf::Vector2f get_velocity(std::pair<int, int>& coordinates);
	void close(sf::Event& event);

private:
	sf::RenderWindow m_game;
	game_object m_player;
	float m_width;
	float m_height;
	serial_port m_port;

};

#endif

