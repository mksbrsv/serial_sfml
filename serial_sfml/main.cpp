#include "game.h"

int main() {
	std::string name("hello");
	std::string port("COM4");
	game game(std::move(name), port);
	game.start();
}