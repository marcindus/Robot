/usr/bin/python3 /home/pi/.platformio/packages/tool-esptoolpy/esptool.py --before default_reset --after hard_reset --chip esp8266 --port /dev/ttyUSB0 --baud 115200 write_flash 0x0 .pio/build/esp8266/firmware.bin

