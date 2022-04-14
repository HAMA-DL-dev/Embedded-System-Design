#!/bin/sh

module="gpio_button_driver.ko"
device="gpio_button"

sudo /sbin/insmod $module 

major=`cat /proc/devices | awk "{if(\\$2==\"$device\")print \\$1}"`
sudo rm -f /dev/${device} c $major 0

sudo mknod /dev/${device} c $major 0

sudo chmod 666 /dev/${device}
