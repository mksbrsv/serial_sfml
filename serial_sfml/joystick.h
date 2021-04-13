#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "serial_port.h"

enum class quarter {
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	CENTER
};

enum class direction {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	STAY

};

// a representation of arduino joystick module
class joystick {
public:
	joystick(std::string& port_name);
	[[nodiscard]] std::pair<int, int> get_coords();
	[[nodiscard]] quarter get_quarter() const;
	[[nodiscard]] direction get_direction();
	~joystick();
private:
	void parse_coords(std::string&& str);
	serial_port m_port;
	std::pair<int, int> m_coords;
};
#endif

