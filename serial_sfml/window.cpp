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
	sf::CircleShape circle(50.f);
	circle.setFillColor(sf::Color::Red);
	m_port.open("COM4", 9600);
	char a[10];
	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			close(event);
		}
		m_window.clear(sf::Color::Black);
		m_window.draw(circle);
		bool lol = event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right;
		std::cout << lol;
		m_port.read(a, 10);
		std::string buf(a);
		auto i = std::find_if(buf.begin(), buf.end(), isdigit);
		std::string s;
		std::copy(buf.begin(), i, std::back_inserter(s));

		if (s == "right") {
			circle.move(2.f, 0);
		}
		if (s == "left") {
			circle.move(-2.f, 0);
		}
		if (s == "up") {
			circle.move(0, -2.f);
		}
		if (s == "down") {
			circle.move(0, 2.f);
		}
			
		m_window.display();
	}
}


