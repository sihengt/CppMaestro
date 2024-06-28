#include "CppMaestro/CppMaestro.hpp"

CppMaestro::CppMaestro(const std::string& port, unsigned int baud_rate = 9600, unsigned char device_number = 0x0c) 
    : serial(io, port)
{
    serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
    pololu_cmd = {0xaa, device_number};
}

void CppMaestro::setTarget(unsigned char channel, unsigned short target)
{
    // TODO: min / max clamps
    unsigned char lsb = target & 0x7f;
    unsigned char msb = (target >> 7) & 0x7f;
    std::vector<unsigned char> command = {0x04, channel, lsb, msb};
    sendCommand(command);
}

void CppMaestro::setSpeed(unsigned char channel, unsigned short speed)
{
    // TODO: min / max clamps
    unsigned char lsb = target & 0x7f;
    unsigned char msb = (target >> 7) & 0x7f;
    std::vector<unsigned char> command = {0x07, channel, lsb, msb};
    sendCommand(command);
}

void CppMaestro::setAccel(unsigned char channel, unsigned short accel)
{
    // TODO: min / max clamps
    unsigned char lsb = target & 0x7f;
    unsigned char msb = (target >> 7) & 0x7f;
    std::vector<unsigned char> command = {0x09, channel, lsb, msb};
    sendCommand(command);
}

void CppMaestro::sendCommand(const std::vector<unsigned char>& command)
{
    std::vector<unsigned char> full_command = pololu_cmd;
    full_command.insert(full_command.end(), command.begin(), command.end());
    boost::asio::write(serial, boost::asio::buffer(full_command));
}