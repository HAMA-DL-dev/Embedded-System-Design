cmd_/home/pi/work/lcd1602driver/modules.order := {   echo /home/pi/work/lcd1602driver/lcd1602driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/work/lcd1602driver/modules.order
