# CppMaestro

A simple package to communicate with the Pololu Maestro Servo Controller, using Boost's ASIO library.
https://www.pololu.com/docs/pdf/0J40/maestro.pdf

## Testing
Uses GTest for unit tests. Note that you'd have to change `device_name` to match your Pololu device or the tests might 
fail.