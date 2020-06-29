make && avrdude -p m328p -c arduino -P /dev/ttyACM0 -U flash:w:main.hex -v -v -v -v && exec picocom /dev/ttyACM0
