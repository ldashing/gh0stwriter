#!/bin/bash
printf "Starting a sh shell on ttyUSB0 with a baud rate of 9600\n"
stty -F /dev/ttyUSB0 9600
export PS1='gh0st>'
sh > /dev/ttyUSB0 2>&1

