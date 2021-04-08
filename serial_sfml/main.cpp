#include "serial_port.h"
#include "window.h"
#include <iostream>
#include <regex>
int main() {
//	serial_port port;
//	port.open("COM4", 9600);
//	char s[12];
//	while (true) {
//		port.read(s, 20);
//		std::string a(s);
//		std::cout << a;
//	}
	game window("hello", 1000, 1000);
	window.display();
//	"\r\n505\r\n518\r\nÌÌÌÌÌÌÌÌøzÿ"


}