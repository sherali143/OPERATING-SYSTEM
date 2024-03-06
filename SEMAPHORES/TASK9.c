#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_PRINTERS 3

sem_t printerSemaphore;

void *printDocument(void *userID) 
{
    int user = *((int *)userID);
    sem_wait(&printerSemaphore);
    printf("User %d is printing a document...\n", user);
    sleep(2);
    sem_post(&printerSemaphore);
    pthread_exit(NULL);
}

int main() 
{
   
    sem_init(&printerSemaphore, 0, MAX_PRINTERS);
    pthread_t userThread[5];

    for (int i = 0; i < 5; ++i) {
        int *userID = malloc(sizeof(int));
        *userID = i + 1;
        int result = pthread_create(&userThread[i], NULL, printDocument, userID);

        if (result != 0) {
            fprintf(stderr, "Error creating thread for User %d\n", i + 1);
            return 1;
        }
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(userThread[i], NULL);
    }

    sem_destroy(&printerSemaphore);

    return 0;
}

