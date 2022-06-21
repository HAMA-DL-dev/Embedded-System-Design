#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* say_hello(void* data){
    char *str;
    str = (char*)data;
    while(1){
        
        if(str == "hello from thread 1"){
            printf("%s\n",str);
            sleep(1);
        }
        else if(str == "hello from thread 2"){
            printf("%s\n",str);
            sleep(2);
        }
    }
}

void main(){
    pthread_t t1,t2;

    pthread_create(&t1,NULL,say_hello,"hello from thread 1");
    pthread_create(&t2,NULL,say_hello,"hello from thread 2");

    pthread_join(t1,NULL);
}