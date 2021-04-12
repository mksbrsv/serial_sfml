#include "joystick.h"
namespace {
	int x_default = 506;
	int y_default = 517;
}

joystick::joystick(std::string& port_name) {
	m_port.open(port_name, 9600);
}

void joystick::parse_coords(std::string&& str) {
	int x;
	int y;
	std::istringstream(str) >> x;
	str.erase(0, 6);
	std::istringstream(str) >> y;
	m_coords = std::make_pair(x, y);
}

std::pair<int, int> joystick::get_coords() const {
	return m_coords;
}

quarter joystick::get_quarter() const {
	const auto& [x, y] = m_coords;
	quarter quart = quarter::CENTER;
	if (x > x_default && y > y_default)
		quart = quarter::FIRST;
	if (x < x_default && y > y_default)
		quart = quarter::SECOND;
	if (x < x_default && y < y_default)
		quart = quarter::THIRD;
	if (x > x_default && y < y_default)
		quart = quarter::FOURTH;
	return quart;
}

direction joystick::get_direction() const {
	const auto& [x, y] = m_coords;
	direction dir = direction::STAY;
	if (x > x_default)
		dir = direction::LEFT;
	if (y > y_default)
		dir = direction::UP;
	if (y < y_default)
		dir = direction::DOWN;
	if (x < x_default)
		dir = direction::RIGHT;
	return dir;
}

joystick::~joystick() {
	m_port.close();
}
