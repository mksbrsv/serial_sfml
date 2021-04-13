#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H
#include "entity.h"
class main_player : public entity {
public:
	main_player(std::string&& texture_file);
	void set_position(float x, float y) override;
	sf::FloatRect get_bounds() override;
	sf::Vector2f get_position() override;
	sf::Sprite& get_own() override;
	void set_texture() override;
	void move(sf::Vector2f move) override;
	void move(direction dir, quarter quart) override;
	void collision_with() override;
	
};
#endif

