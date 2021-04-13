#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>

enum class direction {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	STAY,
};

class game_object {
public:
	game_object(float radius, sf::Color color);
	void draw(sf::RenderWindow& window) const;
	void move(direction dir, sf::Vector2f velocity = sf::Vector2f(1.f, 1.f));
	void move(sf::Vector2f point);
	void set_velocity(sf::Vector2f velocity);
	void set_object(sf::CircleShape&& object);
	void set_color(sf::Color color);
	sf::Vector2f get_position() const;
	sf::FloatRect get_global_bounds() const;
	void set_position(int x, int y);
private:
	sf::CircleShape m_object;
	sf::Vector2f m_velocity;
};

#endif

