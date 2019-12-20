# Robot
Robot car with nodemcu v2

Source: 

https://www.instructables.com/id/Simplest-Wifi-Car-Using-ESP8266-Motorshield/

https://www.instructables.com/id/WiFi-Car-Using-NodeMCU/



# Building tests

```bash
mkdir build
cd build
cmake ..
make
./tests
```

# Building with platformio (and upload)

```bash
pio run
pio run -t upload
```

