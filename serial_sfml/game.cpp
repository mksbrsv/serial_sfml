#include "game.h"

game::game(std::string&& window_name, std::string& port_name, int width, int height) : m_window(sf::VideoMode(width, height), window_name), m_joystick(port_name) {
}

void game::start() {
	// player
	main_player player("resourses/main_player_sprite.png");
	player.set_position(0.f, 0.f);

	// background
	sf::Texture back_texture;
	back_texture.loadFromFile("resourses/sprite_background.jpg");
	sf::Sprite background(back_texture);

	
//	player.set_texture();
	while(m_window.isOpen()) {
		sf::Event event;
		while(m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
		m_window.clear(sf::Color::Black);
		m_window.draw(background);
		m_window.draw(player.get_own());
		player.move(m_joystick.get_direction(), quarter::CENTER);
		m_window.display();
	}

}
