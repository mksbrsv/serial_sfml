#include "window.h"

window::window(const std::string& window_name, int width, int height) :
	m_window(sf::VideoMode(width, height), window_name) {
}

void window::close(sf::Event& event) {
	if (event.type == sf::Event::Closed) {
		m_window.close();
	}
}


void window::display() {
	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			close(event);
		}
		m_window.clear(sf::Color::Black);
		sf::CircleShape circle(50.f);
		circle.setFillColor(sf::Color::Red);
		m_window.draw(circle);
		bool lol = event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right;
		std::cout << lol;
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
			circle.move(5, 0);
		}
			
		m_window.display();
	}
}


