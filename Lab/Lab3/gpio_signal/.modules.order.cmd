cmd_/home/pi/work/gpio_signal/modules.order := {   echo /home/pi/work/gpio_signal/gpio_signal_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/work/gpio_signal/modules.order
