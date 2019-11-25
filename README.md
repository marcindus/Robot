# Robot
Robot car with nodemcu v2

Source: 

https://www.instructables.com/id/Simplest-Wifi-Car-Using-ESP8266-Motorshield/

https://www.instructables.com/id/WiFi-Car-Using-NodeMCU/



# Building tests

mkdir build
cd build
cmake ../../../<path to CMakeList.txt>
make
./tests

# Building binary

pio run
pio run -t upload

