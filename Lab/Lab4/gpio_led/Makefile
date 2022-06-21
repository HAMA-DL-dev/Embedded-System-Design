
obj-m := gpio_led_driver.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

#all: app 

#app:	gpio_led_test.c

#	gcc  -o gpio_led_test gpio_led_test.c -lpthread
