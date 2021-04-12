//#include "window.h"
//#include <algorithm>
//
////explanation of speed
///*
// * so, as we know default coordinates of joystick is (506, 517) i decided that speed should depends on coordinates
// * 1. step will be 100, after every 100 i increase our speed
// * 2. default speed is 1
// * 3. the formula of the speed is coordinate*0.1 - test
// */
//
//namespace {
//	int x_default = 506;
//	int y_default = 517;
//	int vel_step = 100;
//	int y_line = 800;
//}
//
//game::game(const std::string& window_name, int width, int height) :
//	m_game(sf::VideoMode(width, height), window_name), m_player(0, sf::Color::Black),
//	m_width(width),
//	m_height(height) {
//	m_game.setFramerateLimit(144);
//}
//
//void game::set_player(sf::CircleShape&& object) {
//	m_player.set_object(std::move(object));
//}
//
//void game::close(sf::Event& event) {
//	if (event.type == sf::Event::Closed) {
//		m_game.close();
//	}
//}
//
//// "\r\n505\r\n518\r\nÌÌÌÌÌÌÌÌøzÿ" - idk why, but asio return this string from serial port, thats why i have to parse coordinates from string
//std::pair<int, int> game::parse_coordinates(std::string&& str) {
//	int x;
//	std::istringstream(str) >> x;
//	str.erase(0, 6);
//	int y;
//	std::istringstream(str) >> y;
//	
//	return {x, y};
//}
//
//// gets collision with the frame, and with the floor
//void game::collision() {
//	if (m_player.get_position().x < 0)
//		m_player.set_position(0, m_player.get_position().y);
//	if (m_player.get_position().y < 0)
//		m_player.set_position(m_player.get_position().x, 0);
//	if (m_player.get_position().x + m_player.get_global_bounds().width > m_width)
//		m_player.set_position(m_width - m_player.get_global_bounds().width, m_player.get_position().y);
//	if (m_player.get_position().y + m_player.get_global_bounds().height > m_height)
//		m_player.set_position(m_player.get_position().x, m_height - m_player.get_global_bounds().height);
//	if (m_player.get_position().y + m_player.get_global_bounds().height > y_line)
//		m_player.set_position(m_player.get_position().x, y_line - m_player.get_global_bounds().height);
//}
//
//// 506 is default for x, 517 is default for y
//direction game::get_direction(std::pair<int, int>& coordinates) {
//	direction direc = direction::STAY;
//	auto& [x, y] = coordinates;
//	fmt::print("coords: x: {0}, y:{1}", x, y);
//	if (y >= y_default+2) {
//		direc = direction::UP;
//	}
//	if (y <= y_default-2) {
//		direc = direction::DOWN;
//	}
//	if (x <= x_default-2) {
//		direc = direction::RIGHT;
//	}
//	if (x >= x_default+2) {
//		direc = direction::LEFT;
//	}
//	return direc;
//}
//
//sf::Vector2f game::get_velocity(std::pair<int, int>& coordinates) {
//	auto& [x, y] = coordinates;
//	int x_vel = x * 0.1;
//	int y_vel = y * 0.1;
//	if (x < x_default-2) {
//		int xtmp = 1023 - x;
//		x_vel = xtmp * 0.1;
//	}
//	if (y < y_default-2) {
//		int ytmp = 1023 - y;
//		y_vel = ytmp * 0.1;
//	}
//	if (y > y_default+2) {
//		x_vel = x * 0.1;
//	}
//	if (x > x_default+2) {
//		y_vel = y * 0.1;
//	}
//	return sf::Vector2f(x_vel, y_vel);
//		
//}
//
//void game::display() {
//	// serial
//	m_port.open("COM4", 9600);
//
//	// prepare player
//	set_player(sf::CircleShape(25.f));
//	m_player.set_color(sf::Color::Red);
//	m_player.set_position(0, y_line - 25);
//
//	// background	
//	sf::Texture bg_texture;
//	bg_texture.loadFromFile("resourses/background.jpeg");
//	sf::Sprite bg_sprite;
//	bg_sprite.setTexture(bg_texture);
//	bg_sprite.setPosition(0, 0);
//
//	// transparent line - floor
//	sf::RectangleShape line;
//	line.setFillColor(sf::Color::Transparent);
//	line.setSize(sf::Vector2f(1000, 3));
//	line.setPosition(0, y_line);
//
//	
//	char a[12];
//	while (m_game.isOpen()) {
//		// close event section
//		sf::Event event;
//		while (m_game.pollEvent(event)) {
//			close(event);
//		}
//
//		// draw section
//		m_game.clear(sf::Color::Black);
//		m_game.draw(bg_sprite);
//		m_game.draw(line);
//		m_player.draw(m_game);
//
//		// get coords section
//		m_port.read(a, 12);
//		std::string buf(a);
//		auto coords = parse_coordinates(std::move(buf));
//
//		// move section
//		direction dir = get_direction(coords);
//		sf::Vector2f velocity = get_velocity(coords);
//		m_player.move(dir, velocity);
//		collision();
//		
//		m_game.display();
//	}
//}
//
//
