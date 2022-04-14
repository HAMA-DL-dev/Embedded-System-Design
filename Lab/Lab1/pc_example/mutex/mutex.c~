#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t lock;
int shared_data;

void *thread_function(void *arg)
{
	int i;
	for (i=0;i<10000;i++) {
		pthread_mutex_lock(&lock);
		shared_data++;
		pthread_mutex_unlock(&lock);
		usleep(1000);
	}
	return NULL;
}

int main(void)
{
	pthread_t thread_ID;
	void *exit_status;
	int i;

	pthread_mutex_init(&lock,NULL);
	pthread_create(&thread_ID, NULL, thread_function, NULL);
	sleep(1);
	for(i=0;i<10;i++) {		
		//pthread_mutex_lock(&lock);
		printf("\rShared integer's value = %d before\n", shared_data);
		sleep(1);
		printf("\rShared integer's value = %d after\n", shared_data);
		//pthread_mutex_unlock(&lock);
		sleep(1);
	}
	printf("\n");

	pthread_join(thread_ID, &exit_status);

	pthread_mutex_destroy(&lock);
	return 0;
}
