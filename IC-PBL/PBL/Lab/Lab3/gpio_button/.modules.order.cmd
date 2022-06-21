cmd_/home/pi/work/gpio_button/modules.order := {   echo /home/pi/work/gpio_button/gpio_button_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/work/gpio_button/modules.order
