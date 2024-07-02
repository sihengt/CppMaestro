#ifndef CPPMAESTRO_H
#define CPPMAESTRO_H

#include <boost/asio.hpp>
#include <vector>

class CppMaestro {
public:
    CppMaestro(const std::string& port, unsigned int baud_rate = 9600, unsigned char device_number = 0x0c);
    void setTarget(unsigned char channel, unsigned short target);
    void setSpeed(unsigned char channel, unsigned short speed);
    void setAccel(unsigned char channel, unsigned short accel);
    bool isConnected();

private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;
    std::vector<unsigned char> pololu_cmd;

    void sendCommand(const std::vector<unsigned char>& command);
};

#endif // CPPMAESTRO_H