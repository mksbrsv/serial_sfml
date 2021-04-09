#include "serial_port.h"

void serial_port::read(char* buffer, int count_of_bytes) const {
	assert(m_port);
	m_port->read_some(asio::buffer(buffer, count_of_bytes));
}

void serial_port::write(const char* message, const int size) const {
	assert(m_port);
	m_port->write_some(asio::buffer(message, size));
}

bool serial_port::open(const std::string& port_name, int baud_rate) {
	if (m_port) {
		std::cout << "port " << port_name << "is already open\n";
		return false;
	}
	m_port = std::make_shared<asio::serial_port>(m_io_service);
	asio::error_code ec;
	m_port->open(port_name, m_error);
	if (m_error)
		std::cout << "Can't open " << port_name;
	m_port->set_option(asio::serial_port_base::baud_rate(baud_rate));
	return true;

}

void serial_port::close() const {
	if (!m_port) {
		std::cout << "Port isn't opened\n";
	}
	m_port->close();
}
