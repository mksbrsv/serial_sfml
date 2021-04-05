#include <iostream>
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#define ASIO_STANDALONE
#include <asio.hpp>
#include <SFML/Graphics.hpp>
#include "window.h"

using namespace sf;

int main() {
	window window("hello", 500, 500);
	window.display();
 
//	asio::io_service io;
//	asio::serial_port port(io);
//	asio::error_code ec;
//	port.open("COM4", ec);
//	if (!ec) {
//		std::cout << "success";
//	}
//	char p[9];
//	while (true) {
//		auto a = asio::buffer(p, 9);
//		port.read_some(a);
//		std::cout << p << "\n";
//	}
	return 0;
	
}