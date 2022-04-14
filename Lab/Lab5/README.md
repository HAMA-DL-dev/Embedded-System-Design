## Lab5: Building Linux Kernel
- 폴링(polling)을 이용하는 gpio_button 드라이버가 아닌, Linux signal을 사용하는(~=인터럽트) gpio_signal 을 이용
- VMware(우분투 환경) 에서 크로스 컴파일러를 설치한 뒤, SmarTTY(라즈베리파이 환경)에서 마운트를 한다.
<br>
```bash
mkdir ~/mnt 
sudo mount -t nfs 192.168.0.120:/home/control/nfsroot ~/mnt
```
<br>
Lab5 안의 파일은 원래 라즈베리파이의 home directory에 있는 mnt 폴더였다.
<br>
따라서 코드를 실행해보고 싶으면 우분투 환경에 c 파일을 추가하고서 크로스컴파일을 하면 된다.
<br>
```bash
arm-linux-gnueabihf-gcc {실행 파일}
```
