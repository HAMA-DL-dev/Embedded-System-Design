cmd_/home/pi/work/gpio_led/Module.symvers := sed 's/ko$$/o/' /home/pi/work/gpio_led/modules.order | scripts/mod/modpost -m -a   -o /home/pi/work/gpio_led/Module.symvers -e -i Module.symvers   -T -
