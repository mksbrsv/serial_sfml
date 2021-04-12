#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "serial_port.h"

enum class quarter {
	FIRST = 1,
	SECOND = 2,
	THIRD = 3,
	FOURTH = 4,
	CENTER = 5
};

enum class direction {
	UP = 1,
	DOWN = 2,
	RIGHT = 3,
	LEFT = 4,
	STAY = 5

};

// a representation of arduino joystick module
class joystick {
	joystick(std::string& port_name);
	[[nodiscard]] std::pair<int, int> get_coords() const;
	[[nodiscard]] quarter get_quarter() const;
	[[nodiscard]] direction get_direction() const;
	~joystick();
private:
	void parse_coords(std::string&& str);
	serial_port m_port;
	std::pair<int, int> m_coords;
};
#endif

