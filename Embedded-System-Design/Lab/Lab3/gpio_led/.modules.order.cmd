cmd_/home/pi/work/gpio_led/modules.order := {   echo /home/pi/work/gpio_led/gpio_led_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/work/gpio_led/modules.order
