#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int time_counter = 0;

pthread_mutex_t my_mutex;

void *heartrate_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("heart rate moniter are starting...\n");
    sleep(4);
    time_counter += 4;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *oxygen_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("oxygen_moniter is starting...\n");
    sleep(3);
    time_counter += 3;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *bloodpressure_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("blood_pressure_moniter is starting...\n");
    sleep(10);
    time_counter += 10;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *glucose_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("glucose_moniter is starting...\n");
    sleep(3);
    time_counter += 3;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *respiratory_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("respiratory function is starting...\n");
    sleep(5);
    time_counter += 5;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}


int main()
{
    pthread_t heartrate , oxygen , bloodpressure, glucose, respiratory;
    printf("Starting all the applications... \n ");

    pthread_create(&heartrate, NULL, heartrate_function, NULL);
    pthread_create(&oxygen, NULL, oxygen_function, NULL);
    pthread_create(&bloodpressure, NULL,bloodpressure_function , NULL);
    pthread_create(&glucose, NULL,glucose_function, NULL);
    pthread_create(&respiratory, NULL, respiratory_function, NULL);

    pthread_join(heartrate, NULL);
    pthread_join(oxygen, NULL);
    pthread_join(bloodpressure, NULL);
    pthread_join(glucose, NULL);
    pthread_join(respiratory, NULL);

    printf(" APPLICATIONS STATUSES . \n");
    printf("The total time taken by applications %d .\n", time_counter);

    pthread_mutex_destroy(&my_mutex);
    exit(0);
    
    return 0;
}