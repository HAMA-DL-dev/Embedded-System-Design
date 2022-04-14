#include <unistd.h>     
#include <sys/types.h>  
#include <errno.h>      
#include <stdio.h>      
#include <stdlib.h>    
#include <pthread.h>   
#include <string.h>    
#include <semaphore.h>

sem_t binaySemphore;

void* thread_1_function(void *ptr);
void* thread_2_function(void *ptr);

int main()
{
    int iRet;
    pthread_t thread_1;
    pthread_t thread_2;
    unsigned char ucBuff[10];
    /* second param = 0  - semaphore is local() */
    /* second param = 1  - semaphore is global*/
    /* third param  = n  - semaphore count value*/
    sem_init(&binaySemphore, 0, 1);    

    strcpy(ucBuff,"thread_1");
    iRet=pthread_create(&thread_1, NULL,thread_1_function,(void *)ucBuff); // return 0 if successfuly executed.
    if(iRet == 0)
    {
        printf("pthread 1 created...\n");
    }
    sleep(1);
    strcpy(ucBuff,"thread_2");
    iRet=pthread_create(&thread_2, NULL,thread_2_function,(void *)ucBuff);
    if(iRet == 0)
    {
        printf("pthread 2 created...\n");
    }

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    sem_destroy(&binaySemphore); /* destroy semaphore */
    exit(0);
}


/* prototype for thread routine */
void* thread_1_function(void *ptr) // ptr will be ucBuff at int main(), so it is thread_1
{
    unsigned char* ucBuffPtr,ucThreadBuff[10];
    ucBuffPtr = (unsigned char *) ptr; // thread_1 to ucBuffPtr
    strcpy(ucThreadBuff,ucBuffPtr);   // and finally ucTrheadBuff
    printf("thread_1_function entered\n");
    while(1){
        sem_wait(&binaySemphore);
        printf("Semaphore is with %s\n",ucThreadBuff);
        sleep(5);
        sem_post(&binaySemphore);
        sleep(1);
    }
    pthread_exit(0); /* exit thread */
}

void* thread_2_function(void *ptr)
{
    unsigned char* ucBuffPtr,ucThreadBuff[10];
    ucBuffPtr = (unsigned char *) ptr;
    strcpy(ucThreadBuff,ucBuffPtr);
    printf("thread_2_function entered\n");
    while(1){

        sem_wait(&binaySemphore);      /* down semaphore */
        printf("Semaphore is with %s\n",ucThreadBuff);
        sleep(10);
        sem_post(&binaySemphore);       /* up semaphore */
        sleep(1);

    }
    pthread_exit(0); /* exit thread */
}
