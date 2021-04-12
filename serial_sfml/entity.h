#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

//forward declaration for direction
enum class direction;

// abstract class for representing every object in game
class entity {
public:
	virtual void set_position(float x, float y) = 0;
	virtual sf::FloatRect get_bounds() = 0;
	virtual sf::Vector2f get_position() = 0;
	virtual void move(sf::Vector2f move) = 0;
	virtual void move(direction dir) = 0;
	virtual sf::Sprite& get_own() = 0;
	virtual ~entity() = default;
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
#endif

