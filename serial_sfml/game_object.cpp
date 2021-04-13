#include "game_object.h"

game_object::game_object(float radius, sf::Color color) : m_object(radius), m_velocity(0.f, 0.f) {
	m_object.setFillColor(color);
}

void game_object::draw(sf::RenderWindow& window) const {
	window.draw(m_object);
}
// moving without velocity (velocity = 0) is moving by 5 pixels
void game_object::move(direction dir, sf::Vector2f velocity) {
	// TODO: add frame time
	velocity.x = std::clamp(velocity.x, 0.f, 15.f);
	velocity.y = std::clamp(velocity.y, 0.f, 15.f);
	set_velocity(velocity);
	switch(dir) {
	case direction::UP :
		m_object.move(0.f * velocity.x, -3.f * velocity.y);
		break;
	case direction::DOWN :
		m_object.move(0.f * velocity.x, 3.f * velocity.y);
		break;
	case direction::RIGHT :
		m_object.move(3.f * velocity.x, 0.f * velocity.y);
		break;
	case direction::LEFT :
		m_object.move(-3.f * velocity.x, 0.f * velocity.y);
		break;
	case direction::STAY :
		break;
	}
}

void game_object::move(sf::Vector2f point) {
	m_object.move(point);
}

void game_object::set_velocity(sf::Vector2f velocity) {
	m_velocity = velocity;
}

void game_object::set_object(sf::CircleShape&& object) {
	m_object = object;
}

void game_object::set_color(sf::Color color) {
	m_object.setFillColor(color);
}

sf::Vector2f game_object::get_position() const {
	return m_object.getPosition();
}

sf::FloatRect game_object::get_global_bounds() const {
	return m_object.getGlobalBounds();
}

void game_object::set_position(int x, int y) {
	m_object.setPosition(x, y);
}
