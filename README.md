# Robot
Robot car with nodemcu v2

Source: 

https://www.instructables.com/id/Simplest-Wifi-Car-Using-ESP8266-Motorshield/

https://www.instructables.com/id/WiFi-Car-Using-NodeMCU/

![image info](./images/robot1.jpg)

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

