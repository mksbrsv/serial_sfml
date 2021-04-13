#include "main_player.h"

#include "game_object.h"

main_player::main_player(std::string&& texture_file) {
	m_texture.loadFromFile(texture_file);
	m_sprite.setTexture(m_texture);
}

void main_player::set_position(float x, float y) {
	m_sprite.setPosition(x, y);
}

sf::FloatRect main_player::get_bounds() {
	return m_sprite.getGlobalBounds();
}

sf::Vector2f main_player::get_position() {
	return m_sprite.getPosition();
}

sf::Sprite& main_player::get_own() {
	return m_sprite;
}

void main_player::set_texture() {
	m_sprite.setTextureRect(sf::IntRect(0, 7, 40, 58));
}

void main_player::move(sf::Vector2f move) {
	m_sprite.move(move);
}

void main_player::move(direction dir, quarter quart) {
	if (dir == direction::UP)
		m_sprite.move(0.f, -5.f);
	if (dir == direction::DOWN)
		m_sprite.move(0.f, 5.f);
	if (dir == direction::LEFT)
		m_sprite.move(-5.f, 0.f);
	if (dir == direction::RIGHT)
		m_sprite.move(5.f, 0.f);
}

void main_player::collision_with() {
	
}

