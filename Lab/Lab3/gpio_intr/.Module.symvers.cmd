cmd_/home/pi/work/gpio_intr/Module.symvers := sed 's/ko$$/o/' /home/pi/work/gpio_intr/modules.order | scripts/mod/modpost -m -a   -o /home/pi/work/gpio_intr/Module.symvers -e -i Module.symvers   -T -
