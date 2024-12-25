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
pio run -t upload
or:
    make -f makefile upload
```

# Prepare and run entity tests 

```bash
./setup.sh
./run_entity.sh
```

# Images - robot on a test bench

![image info](./images/robot1.jpg)
![image info](./images/robot2.jpg)
![image info](./images/robot3.jpg)
![image info](./images/robot4.jpg)

