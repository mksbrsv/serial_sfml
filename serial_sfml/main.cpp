#include "serial_port.h"
#include "window.h"
#include <iostream>
int main() {
//	serial_port port;
//	port.open("COM4", 9600);
//	char s[10];
//	while (true) {
//		port.read(s, 10);
//		std::string buf(s);
//		auto i = std::find_if(buf.begin(), buf.end(), isdigit);
//		std::string a;
//		std::copy(buf.begin(), i, std::back_inserter(a));
//		std::cout << a;
//	}
	window window("hello", 500, 500);
	window.display();


}