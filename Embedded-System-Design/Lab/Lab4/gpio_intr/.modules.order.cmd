cmd_/home/pi/work/gpio_intr/modules.order := {   echo /home/pi/work/gpio_intr/gpio_intr_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/work/gpio_intr/modules.order
