#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#define ASIO_STANDALONE
#include <string>
#include <asio.hpp>
#include <memory>
#include <iostream>
class serial_port {
public:
	void read(char* buffer, int count_of_bytes) const;
	void write(const char* message, const int size) const;
	bool open(const std::string& port_name, int baud_rate);
	void close() const;
private:
	asio::io_service m_io_service;
	std::shared_ptr<asio::serial_port> m_port;
	asio::error_code m_error;
};

#endif

