#include "serial_port.h"

void serial_port::read(std::string& buffer, int count_of_bytes) const {
	assert(m_port);
	m_port->read_some(asio::buffer(buffer.c_str(), count_of_bytes));
}

void serial_port::write(const std::string& message) const {
	assert(m_port);
	m_port->write_some(asio::buffer(message.c_str(), message.size()));
}

bool serial_port::open(const std::string& port_name, int baud_rate) {
	if (m_port) {
		std::cout << "port " << port_name << "is already open\n";
		return false;
	}
	m_port = std::make_shared<asio::serial_port>(m_io_service);
	m_port->open(port_name);
	m_port->set_option(asio::serial_port_base::baud_rate(baud_rate));
	return true;

}

void serial_port::close() const {
	if (!m_port) {
		std::cout << "Port isn't opened\n";
	}
	m_port->close();
}
