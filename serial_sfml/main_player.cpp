#include "main_player.h"

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

void main_player::move(sf::Vector2f move) {
}

void main_player::move(direction dir) {
}
